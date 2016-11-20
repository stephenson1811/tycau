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

TkSingleScene::TkSingleScene(){}
TkSingleScene::TkSingleScene(TkType::SceneType /*type*/){
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
    //m_Task->draw(m_DstDvc);
    m_Status->draw(m_DstDvc);
    m_HouseType->draw(m_DstDvc);
/*    m_Information->draw(m_DstDvc);
    m_Function->draw(m_DstDvc);
    m_OutDoor->draw(m_DstDvc);
    m_Persons->draw(m_DstDvc)*/;
    SDL_Flip(m_DstDvc);
    // music and other audio effect.
}
void TkSingleScene::init(SDL_Surface*d){
    TkAbstractScene::init(d);

    m_Bkgrd = new TkBackGround(std::string("D:\\data\\background\\Room_3-1.bmp"));
    m_Task = new TkTaskWidget() ;            // personnel task widget 
    m_Status = new TkStatusWidget() ;        // personnel status 
    m_HouseType = new TkLabel(TkRect(10,430),std::string("D:\\data\\infrastructure\\KyotenBtn_46-1.bmp")) ;  // left bottom label
    m_Information = new TkMenu ; // left menu
    m_Function = new TkMenu ;    // right menu
    m_OutDoor = new TkButton ;   // button, outdoor function
    m_Persons = new TkRolesList ;// persons in house, in right part of background
    // load back-ground picture
    //m_Task->load(std::string("D:\\data\\background\\Room_3-1.bmp"));
    //m_Status->load(std::string("D:\\data\\background\\Room_3-1.bmp"));
    //m_Information->load(std::string("D:\\data\\background\\Room_3-1.bmp"));
    //m_Function->load(std::string("D:\\data\\background\\Room_3-1.bmp"));
    //m_OutDoor->load(std::string("D:\\data\\background\\Room_3-1.bmp"));
    //m_Persons->load(std::string("D:\\data\\background\\Room_3-1.bmp"));
}
void TkSingleScene::which(SDL_Event*){}
void TkSingleScene::handle(){}


// a msg dispatcher/processor
TkGameStatusType::Status TkSingleScene::dispatch(SDL_Event*e){
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
    return TkGameStatusType::ChangeScene;
}
