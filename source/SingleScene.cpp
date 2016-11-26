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
    m_CurrentControl=NULL;
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
    m_OutDoor->draw(m_DstDvc);
/*    m_Information->draw(m_DstDvc);
    m_Function->draw(m_DstDvc);
    */
    m_Persons->draw(m_DstDvc);
    SDL_Flip(m_DstDvc);
    // music and other audio effect.
}
void TkSingleScene::init(SDL_Surface*d){
    TkAbstractScene::init(d);

    m_Bkgrd = new TkBackGround(std::string("D:\\data\\background\\Room_3-1.bmp"));
    m_Task = new TkTaskWidget() ;            // personnel task widget 
    m_Status = new TkStatusWidget() ;        // personnel status 
    m_HouseType = new TkLabel(std::string("D:\\data\\infrastructure\\KyotenBtn_46-1.bmp"), TkRect(10,430) ) ;  // left bottom label
    m_Information = new TkMenu ; // left menu
    m_Function = new TkMenu ;    // right menu
    std::vector<ButtonInfo> vbi ;
    vbi.push_back(ButtonInfo ("D:\\data\\UI\\Parts_N_4-1.bmp", TkRect(400,300,136,40) , 4));
    vbi.push_back(ButtonInfo ("D:\\data\\UI\\Parts_N_5-1.bmp", TkRect(722,545,96,40) , 4));
    vbi.push_back(ButtonInfo ("D:\\data\\UI\\Parts_N_6-1.bmp", TkRect(722,545,152,40) , 4));
    m_OutDoor = new TkButton(vbi,4) ;   // button, outdoor function
    m_OutDoor->addStatus(TkGui::click,2);
    m_OutDoor->addStatus(TkGui::released,3);
    m_Persons = new TkRolesList ;// persons in house, in right part of background
    // load back-ground picture
    //m_Task->load(std::string("D:\\data\\background\\Room_3-1.bmp"));
    //m_Status->load(std::string("D:\\data\\background\\Room_3-1.bmp"));
    //m_Information->load(std::string("D:\\data\\background\\Room_3-1.bmp"));
    //m_Function->load(std::string("D:\\data\\background\\Room_3-1.bmp"));
    //m_OutDoor->load(std::string("D:\\data\\background\\Room_3-1.bmp"));
    //m_Persons->load(std::string("D:\\data\\background\\Room_3-1.bmp"));
    m_Members.push_back(m_Bkgrd);
}
TkObject* TkSingleScene::whichControl(SDL_Event* e){
    TkGraphicsObject* control = NULL;
    for (std::vector<TkObject*>::iterator it = m_Members.begin();
        it != m_Members.end(); it ++){
            if ( (*it)->getType() == graphicObject){
                if ((*it)->inRect(e)){
                    return static_cast<TkObject*>(*it);
                }
            }
            if((*it)->getType() == mapWidget){
                //TkMap* m = dynamic_cast<TkMap*> (*it);
                //if ((*it)->inRect(e, control)){
                //}
            }
    }
    return NULL;
}

// a msg dispatcher/processor
void TkSingleScene::dispatch(SDL_Event* e){
    TkObject* control = whichControl(e);
    if (control){
        TkEvent t=control->handle(e);
        pushSDLEvent(t.EventType,t.UserCode);
    }
}



