/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#pragma once
const int CHANGE_SCENE = SDL_USEREVENT +1;
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
namespace TkGameStatusType{
    /* 
     * which state should be set after event came up
     * 
     * 
     * 
     * 
     * 
     */
    enum Status{
        Null = 0,
        ChangeScene = 1,
    };
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
namespace TkStatus{};
/* 
 * 
 * 
 * 
 * 
 * 
 * 
 */
namespace TkGui{
    enum Type{
        TypeMap = 1,    // composed by many primitives
        TypeBkGrd = 2,  // back-ground filled with single pic
        TypeItem = 3,   // single pic, such as a person portrait 
    };
};
class TkRect{
public:
    TkRect(void){w = 0;h = 0;x = 0;y = 0;}
    TkRect(int x, int y, int w = 0, int h = 0){this->w = w;this->h = h;this->x = x;this->y = y;}
    TkRect(const TkRect& r){
        this->x = r.x;
        this->y = r.y;
        this->w = r.w;
        this->h = r.h;    
    }
    ~TkRect(void){}
    void operator =(const TkRect& r){
        this->x = r.x;
        this->y = r.y;
        this->w = r.w;
        this->h = r.h;
    }
    const TkRect& operator+=(const TkRect& r){
        this->x += r.x;
        this->y += r.y;
        this->w += r.w;
        this->h += r.h;  
        return *this;
    }
    const TkRect& operator-=(const TkRect& r){
        this->x -= r.x;
        this->y -= r.y;
        this->w -= r.w;
        this->h -= r.h;
        return *this;    
    }
    friend TkRect operator+(const TkRect& l, const TkRect& r){
        TkRect tmp;
        tmp.x = l.x + r.x;
        tmp.y = l.y + r.y;
        tmp.w = l.w + r.w;
        tmp.h = l.h + r.h;  
        return tmp;
    }
    friend TkRect operator - (const TkRect& l, const TkRect& r){
        TkRect tmp;
        tmp.x = l.x - r.x;
        tmp.y = l.y - r.y;
        tmp.w = l.w - r.w;
        tmp.h = l.h - r.h; 
        return tmp;    
    }
    int getX(){return x;}
    int getY(){return y;}
    int getW(){return w;}
    int getH(){return h;}
    void setX(int v){ x = v;}
    void setY(int v){ y = v;}
    void setW(int v){ w = v;}
    void setH(int v){ h = v;}
private:
    int w,h,x,y;
};
