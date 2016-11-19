/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#pragma once
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
    enum Type{
        Null = 0,
        InHouse = 1,
    };
};
namespace TkStatusType{
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
