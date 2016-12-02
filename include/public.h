/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#pragma once
#include "Rect.h"
/* 
 * it defines public module in this file
 * 
 * 
 * 
 * 
 * 
 */
namespace TkType{
    /* 
     * the scene protagonist in
     * 
     * 
     * 
     * 
     * 
     */
    enum SceneType{
        Null = 0,
        InHouse = 1,
        InGiantMap = 2,
        InMiniMap = 3,
        InBattle = 6,
    };
    enum SeasonType{
        Spring = 1,
        Summer = 2,
        Autumn = 3,
        Winter = 4,
    };
    enum TimeType{
        Morning = 1,
        Noon = 2,
        Afternoon = 3,
        Evening = 4,
    };
    enum Health{
        Heal = 1,
        Ill = 3,
    };
};

/* 
 * which state should be set after event came up
 * 
 * 
 * 
 * 
 * 
 */
namespace TkGameStatusType{
    /* 
     * game status
     * 
     * 
     * 
     * 
     * 
     */
    enum GameStatus
    {
        /*CHANGE_SCREEN_RESOLUTION = 1,*/
        RETURN_TO_MAIN_MENU = 2,
        STOP_CLIENT = 3,
        RESTART_GAME,
        RETURN_TO_MENU_LOAD,
        FULLSCREEN_TOGGLED,
        PREPARE_RESTART_CAMPAIGN
    };
};






/* 
 * 
 * 
 * 
 * 
 * 
 * 
 */
namespace TkGui{
    enum ControlStatus{
        Null = 0,
        pressed = 1,
        released = 2,
        hover = 3,
        click = 4,
        doubleClick = 5,
    };
    enum Type{
        TypeMap = 1,    // composed by many primitives
        TypeBkGrd = 2,  // back-ground filled with single pic
        TypeItem = 3,   // single pic, such as a person portrait 
    };
};

/* 
 * which state should be set after event came up
 * 
 * 
 * 
 * 
 * 
 */
namespace TkEventType{
    const int CHANGE_SCENE = SDL_USEREVENT +1;
};
namespace TkUserCode{
    const int DEFINED = 10000;
    const int IN_HOUSE = DEFINED + 1;
};
class TkEvent{
public:
    TkEvent(){EventType = 0;UserCode = 0;}
    TkEvent(int a,int b){EventType = a;UserCode = b;}
    ~TkEvent(){}
    int EventType;
    int UserCode;
};
/* 
 * used as interface of all Gui components,
 * include derived class of graphicobject and not.
 * 
 * 
 * 
 * 
 */
class TkObject{
public:
    virtual void draw(SDL_Surface* dst ) = 0;
    virtual void draw(SDL_Surface* dst, TkRect& ) = 0;
    virtual bool inRect(SDL_Event*) = 0;
    int getType(){return m_Type;}
    TkEvent handle(SDL_Event*){return TkEvent();}
    void setObjectName(std::string& name){m_ObjectName = name;}
    std::string& getObjectName(){return m_ObjectName;}
protected:
    int m_Type;
    std::string m_ObjectName;
};
const int graphicObject = 1;
const int rolesList = 2;
const int statusWidget = 3;
const int taskWidget = 4;
const int menuWidget = 5;
const int mapWidget = 6;






