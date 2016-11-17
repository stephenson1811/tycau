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
TkScene::TkScene(TkScene::Type /*type*/){
    m_Bkgrd=NULL;
    m_Task=NULL;
    m_Status=NULL;
}
TkScene::~TkScene(){
    deleteWidget(m_Bkgrd) ;
    deleteWidget(m_Task);
    deleteWidget(m_Status);
}
void TkScene::run(SDL_Surface* dst){
    m_Bkgrd->draw(dst);
    SDL_Flip(dst);
}
void TkScene::run(){
    m_Bkgrd->draw(m_DstDvc);
    SDL_Flip(m_DstDvc);
    // music and other audio effect.
}
void TkScene::init(SDL_Surface*d){
    
    m_DstDvc = d;

    m_Bkgrd = new TkBackGround();
    // load back-ground picture
    m_Bkgrd->load(std::string("assets\\graphics\\load.bmp"));
    m_Task = new TkTaskWidget ;            // personnel task widget 
    m_Status = new TkStatusWidget ;        // personnel status
}
// a msg dispatcher/processor
int TkScene::dispatch(SDL_Event*e){
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
    return 0;
}
TkScene* TkSceneFactory::getScene(TkScene::Type type,SDL_Surface* d){
    TkScene* scene = NULL;
    switch(type){
    case 1:
        scene = new TkScene(type);
        break;
    }
    scene->init(d);
    return scene;
}

TkSceneFactory::TkSceneFactory(){
}
TkSceneFactory::~TkSceneFactory(){
}