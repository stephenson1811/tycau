/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */

#include "scene.h"


TkMapScene::TkMapScene(){
}
TkMapScene::TkMapScene(TkType::SceneType){
}
TkMapScene::~TkMapScene(){}


void TkMapScene::run(){
    m_Map->draw(m_DstDvc);
    SDL_Flip(m_DstDvc);
}
void TkMapScene::init(SDL_Surface*d ){
    m_Map = new TkMap();
    m_DstDvc = d;
    m_Members.push_back(m_Map);
}
TkObject* TkMapScene::whichControl(SDL_Event* e){ // which control/picture is selected, pressed or clicked.
    TkGraphicsObject* control = NULL;
    for (std::vector<TkObject*>::iterator it = m_Members.begin();
        it != m_Members.end(); it ++){
            if ((*it)->inRect(e)){
                if((*it)->getType() == mapWidget){
                    TkMap* m = dynamic_cast<TkMap*> (*it);
                    TkPrimitive* mp = m->whichMapPrimitive(e);
                    return static_cast<TkObject*>(mp); 
                }
            }
    }
    return NULL;
}
void TkMapScene::moveMap(int dx, int dy){}
// a msg dispatcher/processor
void TkMapScene::dispatch(SDL_Event* e ){
    TkObject* control = whichControl(e);
    if (!control){
        return; 
    }
    if (control->getType() == buttonWidget){
        TkEvent t=control->handle(e);
        pushSDLEvent(t.EventType,t.UserCode);
    }else if(control->getType() == mapPrimitive){
        switch(e->type){
            case SDL_MOUSEMOTION:
                switch(e->button.button) {
                    case SDL_BUTTON_LEFT: { // move the map
                        moveMap(e->motion.x, e->motion.y);
                        std::cout<<"xrel="<<e->motion.xrel<<",yrel="<<e->motion.yrel<<std::endl;
                        break;
                    }
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                switch(e->button.button) {
                    case SDL_BUTTON_LEFT: { // move the map
                        moveMap(e->motion.x, e->motion.y);
                        std::cout<<"xrel="<<e->motion.xrel<<",yrel="<<e->motion.yrel<<std::endl;
                        break;
                    }
                }
                break;
            case SDL_MOUSEBUTTONUP:
                break;
        }
    }
}