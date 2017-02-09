/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */

#include "scene.h"


TkSingleScene::TkSingleScene(){}
TkSingleScene::TkSingleScene(TkType::SceneType type ){
    m_Bkgrd=NULL;
    m_Task=NULL;
    m_Status=NULL;
    m_CurrentControl=NULL;
    m_SceneType = type;
    m_OutDoor=NULL;
    m_Persons=NULL;
    m_HouseType=NULL;
}
TkSingleScene::~TkSingleScene(){
    deleteWidget(m_Bkgrd) ;
    deleteWidget(m_Task);
    deleteWidget(m_Status);
}
void TkSingleScene::run(SDL_Surface* d){
    if (m_Bkgrd){ 
        m_Bkgrd->draw(d);
    }
   
    //m_Task->draw(d);
    if(m_Status){
        m_Status->draw(d);
    }

    if(m_HouseType){  
        m_HouseType->draw(d);
    }
    if(m_OutDoor){ 
        m_OutDoor->draw(d);
    }
  
/*    m_Information->draw(d);
    m_Function->draw(d);
    */
    if(m_Persons){ 
        m_Persons->draw(d);
    }
    SDL_Flip(d);
  
    // music and other audio effect.
}
void TkSingleScene::init(SDL_Surface*d){
    TkAbstractScene::init(d);

    m_Bkgrd = new TkBackGround(std::string("D:\\data\\background\\Room_3-1.bmp"));
    m_Task = new TkTaskWidget() ;            // personnel task widget 
    m_Status = new TkStatusWidget() ;        // personnel status 
    m_HouseType = new TkLabel(std::string("D:\\data\\infrastructure\\KyotenBtn_46-1.bmp"), TkPoint(10,430) ) ;  // left bottom label
    m_Information = new TkMenu ; // left menu
    m_Function = new TkMenu ;    // right menu
    std::vector< std::string> vbi ;
    vbi.push_back("D:\\data\\UI\\Parts_N_4-1.bmp");
    vbi.push_back("D:\\data\\UI\\Parts_N_5-1.bmp");
    vbi.push_back("D:\\data\\UI\\Parts_N_6-1.bmp");
    m_OutDoor = new TkButton(vbi,TkRect(200,300,100,50/*722,545,96,40*/),4) ;   // button, outdoor function
    m_OutDoor->setObjectName(std::string("goOutDoor"));
    m_OutDoor->addStatus(TkGui::click,1);
    m_OutDoor->addStatus(TkGui::released,0);
    m_OutDoor->addStatus(TkGui::hover,2);
    m_OutDoor->addStatus(TkGui::pressed,1);
    m_Persons = new TkRolesList ;// persons in house, in right part of background
    //m_Persons->addRoles();
    // load back-ground picture
    //m_Task->load(std::string("D:\\data\\background\\Room_3-1.bmp"));
    //m_Status->load(std::string("D:\\data\\background\\Room_3-1.bmp"));
    //m_Information->load(std::string("D:\\data\\background\\Room_3-1.bmp"));
    //m_Function->load(std::string("D:\\data\\background\\Room_3-1.bmp"));
    //m_OutDoor->load(std::string("D:\\data\\background\\Room_3-1.bmp"));
    //m_Persons->load(std::string("D:\\data\\background\\Room_3-1.bmp"));
    //m_Members.push_back(m_Bkgrd);
    m_Members.push_back(m_OutDoor);
}
TkObject* TkSingleScene::whichControl(SDL_Event* e){
    TkGraphicsObject* control = NULL;
    for (std::vector<TkObject*>::iterator it = m_Members.begin();
        it != m_Members.end(); it ++){
            if ((*it)->inRect(e)){
                if((*it)->getType() == buttonWidget){
                    return static_cast<TkObject*>(*it);
                }
            }

            /*if ( (*it)->getType() == graphicObject){
                if ((*it)->inRect(e)){
                    return static_cast<TkObject*>(*it);
                }
            }else */
    }
    return NULL;
}

// a msg dispatcher/processor
void TkSingleScene::dispatch(SDL_Event* e){
    TkObject* control = whichControl(e);
    if (control){
        if (control->getType() == buttonWidget){
            TkButton* b = dynamic_cast<TkButton*>(control);

            TkEvent t = b->handle(e);
            pushSDLEvent(t.EventType,t.UserCode);        
        }
    }
}



