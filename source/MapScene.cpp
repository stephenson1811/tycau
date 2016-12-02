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
}
TkObject* TkMapScene::whichControl(SDL_Event*){ // which control/picture is selected, pressed or clicked.
    return NULL;
}
void TkMapScene::moveMap(int dx, int dy){}
// a msg dispatcher/processor
void TkMapScene::dispatch(SDL_Event* e ){
    TkObject* control = whichControl(e);
    if (control->getType() == buttonWidget){
        TkEvent t=control->handle(e);
        pushSDLEvent(t.EventType,t.UserCode);
    }else if(control->getType() == mapPrimitive){
        switch(e->type){
            case SDL_MOUSEMOTION:
                switch(e->button.button) {
                    case SDL_BUTTON_LEFT: { // move the map
                        moveMap(1,2);
                        break;
                    }
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                break;
        }
    }
}