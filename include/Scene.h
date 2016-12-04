/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#pragma once
#include "config.h"
#include "public.h"
#include "event.h"
#include "Sound.h"
#include "BackGround.h"
#include "StatusWidget.h"
#include "TaskWidget.h"
#include "Label.h"
#include "Menu.h"
#include "Button.h"
#include "RolesItem.h"
#include "DialogBox.h"
#include "Map.h"
/* 
 * basic type.
 * abstract class.
 * 
 * 
 */
class TkAbstractScene{
public:
    TkAbstractScene(){}
    TkAbstractScene(TkType::SceneType){}
    ~TkAbstractScene(){}
public:
    virtual void run() = 0; // draw image, play music.
    virtual void init(SDL_Surface*d = 0); // initial dest surface and picture name.
    virtual void dispatch(SDL_Event*) = 0;
    int getType(){return type;}
protected:
    virtual TkObject* whichControl(SDL_Event*) = 0; // which control/picture is selected, pressed or clicked.
    void pushSDLEvent(int type, int usercode);
    //void handle();
protected:
    SDL_Surface* m_DstDvc;           // destination device surface.
    int type;
    TkDialogBox* m_Dialog;  // dialog pictures and words
    std::vector<TkObject*> m_Members;
    TkObject* m_CurrentControl;
};
/* 
 * for showing only one bkg piture. such as in house, in castle, in battle.
 * integrate image, music and etc.. 
 * change scene type for switch.
 * 
 * 
 */
class TkSingleScene:public TkAbstractScene{
public:
    TkSingleScene();
    TkSingleScene(TkType::SceneType);
    ~TkSingleScene();
    void run();
    void init(SDL_Surface*d = 0);
    TkObject* whichControl(SDL_Event*); // which control/picture is selected, pressed or clicked.
     
    void dispatch(SDL_Event*);
private:
    TkBackGround* m_Bkgrd;           // back-ground picyture
    TkTaskWidget* m_Task;            // personnel task widget 
    TkStatusWidget* m_Status;        // personnel status
    TkLabel* m_HouseType;  // left bottom label
    TkMenu* m_Information; // left menu
    TkMenu* m_Function;    // right menu
    TkButton* m_OutDoor;   // button, outdoor function
    TkRolesList* m_Persons;// persons in house, in right part of background
};
/* 
 * the background composed by many pictures.
 * such as in field, in war.
 * 
 * 
 * 
 * 
 */
class TkMapScene:public TkAbstractScene{
public: 
    TkMapScene();
    TkMapScene(TkType::SceneType);
    ~TkMapScene();
    void run();
    void init(SDL_Surface*d = 0);
    TkObject* whichControl(SDL_Event*); // which control/picture is selected, pressed or clicked.
     
    void dispatch(SDL_Event*);
    void moveMap(SDL_MouseMotionEvent&);
private:
    TkMap* m_Map;
    bool m_LeftButonPressed;
};
/* 
 * 
 * 
 * 
 * 
 * 
 * 
 */
class TkOpeningScene{
};
/* 
 * for selecting a role to play
 * 
 * 
 * 
 * 
 * 
 */
class TkSelectScene{
};

class TkSceneFactory{
public:
    static TkAbstractScene* getScene(TkType::SceneType, SDL_Surface* d = 0);
private:
};

#define deleteWidget(w) {\
    if (w != NULL){\
    delete w;\
    w = NULL;\
    }\
}