/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */

#include "scene.h"
#include "Sound.h"
#define deleteWidget(w) {\
    if (w != NULL){\
    delete w;\
    w = NULL;\
    }\
}
void TkAbstractScene::init(SDL_Surface*d ){ 
    if (d != NULL){
        m_DstDvc = d;
    }
}
TkSingleScene::TkSingleScene(){}
TkSingleScene::TkSingleScene(TkType::Type /*type*/){
    m_Bkgrd=NULL;
    m_Task=NULL;
    m_Status=NULL;
}
TkSingleScene::~TkSingleScene(){
    deleteWidget(m_Bkgrd) ;
    deleteWidget(m_Task);
    deleteWidget(m_Status);
}
void TkSingleScene::run(){
    m_Bkgrd->draw(m_DstDvc);
    SDL_Flip(m_DstDvc);
    // music and other audio effect.
}
void TkSingleScene::init(SDL_Surface*d){
    TkAbstractScene::init(d);

    m_Bkgrd = new TkBackGround();
    // load back-ground picture
    m_Bkgrd->load(std::string("assets\\graphics\\load.bmp"));
    m_Task = new TkTaskWidget ;            // personnel task widget 
    m_Status = new TkStatusWidget ;        // personnel status
}
void TkSingleScene::which(SDL_Event*){}
void TkSingleScene::handle(){}
// a msg dispatcher/processor
TkStatusType::Status TkSingleScene::dispatch(SDL_Event*e){
    switch(e->type) {
        case SDL_ACTIVEEVENT: {
            switch(e->active.state) {
                case SDL_APPACTIVE:    {
                    break;
                }
            }
            break;
        }

        case SDL_KEYDOWN: {
            break;
        }
        case SDL_MOUSEMOTION: {
            break;
        }
        case SDL_MOUSEBUTTONDOWN: {
            switch(e->button.button) {
                case SDL_BUTTON_LEFT: {
                    break;
                }
            }
            break;
        }
        case SDL_MOUSEBUTTONUP:    {
            switch(e->button.button) {
                case SDL_BUTTON_LEFT: {
                    break;
                }
            }
            break;
        }
        case SDL_QUIT: {
            break;
        }
        default: {
            break;
        }
    }
    return TkStatusType::ChangeScene;
}
TkAbstractScene* TkSceneFactory::getScene(TkType::Type type,SDL_Surface* d){
    TkAbstractScene* scene = NULL;
    switch(type){
    case TkType::InHouse:
        scene =  new TkSingleScene(type);
        break;
    }
    scene->init(d);
    return scene;
}





