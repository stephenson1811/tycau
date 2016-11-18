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
#include "GraphicsObject.h"
#include "BackGround.h"
#include "StatusWidget.h"
#include "TaskWidget.h"
/* 
 * which state should be set after event came up
 * 
 * 
 * 
 * 
 * 
 */
class TkEvent{
public:
    TkEvent(){}
    ~TkEvent(){}
private:
};
/* 
 * basic type.
 * abstract class.
 * 
 * 
 */
class TkAbstractScene{
public:
    TkAbstractScene(){}
    TkAbstractScene(TkType::Type){}
    ~TkAbstractScene(){}
public:
    virtual void run() = 0; // draw image, play music.
    virtual void init(SDL_Surface*d = 0); // initial dest surface and picture name.
    virtual TkStatusType::Status dispatch(SDL_Event*) = 0;
    int getType(){return type;}
protected:
    virtual void which(SDL_Event*) = 0; // which control/picture is selected, pressed or clicked.
    virtual void handle() = 0; // make a specific TkEvent according to SDL_Event variable;
protected:
    SDL_Surface* m_DstDvc;           // destination device surface.
    int type;
    TkEvent m_Event;
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
    TkSingleScene(TkType::Type);
    ~TkSingleScene();
    void run();
    void init(SDL_Surface*d = 0);
    void which(SDL_Event*); // which control/picture is selected, pressed or clicked.
    void handle() ; // make a specific TkEvent according to SDL_Event variable;
    TkStatusType::Status dispatch(SDL_Event*);
private:
    TkBackGround* m_Bkgrd;           // back-ground picyture
    TkTaskWidget* m_Task;            // personnel task widget 
    TkStatusWidget* m_Status;        // personnel status

};
/* 
 * the background composed by many pictures.
 * such as in field, in war.
 * 
 * 
 * 
 * 
 */
class TkMapScene{
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
    static TkAbstractScene* getScene(TkType::Type, SDL_Surface* d = 0);
private:
};