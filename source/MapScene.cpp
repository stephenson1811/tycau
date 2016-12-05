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
    m_LeftButonPressed = false;
}
TkMapScene::TkMapScene(TkType::SceneType){
    m_LeftButonPressed = false;
}
TkMapScene::~TkMapScene(){}


void TkMapScene::run(){
    m_Bkgrd->draw(m_DstDvc);
    m_Map->draw(m_DstDvc);

}
void TkMapScene::init(SDL_Surface*d ){
    TkAbstractScene::init(d);
    m_Map = new TkMap();
    m_Bkgrd = new TkBackGround(std::string("D:\\data\\background\\Room_3-1.bmp")); 
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
void TkMapScene::moveMap(SDL_MouseMotionEvent& me){
    if (m_LeftButonPressed){ // could move map
        //std::cout<<"moveMap, xrel="<<me.xrel<<",yrel="<<me.yrel;
        m_Map->move(me.xrel, me.yrel);
        //SDL_Flip(m_DstDvc);
    }
}
void TkMapScene::moveMap(int x, int y){
    m_Map->move(x, y);
}
// a msg dispatcher/processor
void TkMapScene::dispatch(SDL_Event* e ){
    TkObject* control = whichControl(e);
#ifdef Control
    if (!control){
        return; 
    }
    if (control->getType() == buttonWidget){
        //TkEvent t=control->handle(e);
        //pushSDLEvent(t.EventType,t.UserCode);
    }else if(control->getType() == mapPrimitive)
#endif
    {
        switch(e->type){
            case SDL_MOUSEMOTION:
                switch(e->button.button) {
                    case SDL_BUTTON_LEFT: { // move the map
                        moveMap(e->motion);
                        //std::cout<<"xrel="<<e->motion.xrel<<",yrel="<<e->motion.yrel<<std::endl;
                        break;
                    }
                }
                //if (e->motion.x < 100){
                //    moveMap(-10,0);
                //}
                break;
            case SDL_MOUSEBUTTONUP:
                switch(e->button.button) {
                    case SDL_BUTTON_LEFT: { // move the map
                        m_LeftButonPressed = false;
                        std::cout<<"leftreleased,xrel="<<e->motion.xrel<<",yrel="<<e->motion.yrel<<std::endl;
                        break;
                    }
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                switch(e->button.button) {
                    case SDL_BUTTON_LEFT: { // move the map
                        m_LeftButonPressed = true;
                        //std::cout<<"leftpressed,xrel="<<e->motion.xrel<<",yrel="<<e->motion.yrel<<std::endl;
                        break;
                    }
                }
                break;
        }
    }
}