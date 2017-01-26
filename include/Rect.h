/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#pragma once
class TkPoint{
public:
    TkPoint(void){}
    TkPoint(int x, int y){this->x = x;this->y = y;}
    TkPoint(const TkPoint& p){this->x = p.x;this->y = p.y;}
    ~TkPoint(void){}
    void setX(int v){this->x = v; }
    void setY(int v){this->y = v; }
    int getX(){return x;}
    int getY(){return y;}
    void operator = (const TkPoint& l){
        this->x = l.x;
        this->y = l.y;
    }
    friend TkPoint operator+(const TkPoint& l, const TkPoint& r){
        TkPoint tmp;
        tmp.x = l.x + r.x;
        tmp.y = l.y + r.y; 
        return tmp;
    }
    friend TkPoint operator - (const TkPoint& l, const TkPoint& r){
        TkPoint tmp;
        tmp.x = l.x - r.x;
        tmp.y = l.y - r.y;
        return tmp;    
    }
    void operator += (const TkPoint& r){
        this->x += r.x;
        this->y += r.y;
    }
    void operator -= (const TkPoint& r){
        this->x -= r.x;
        this->y -= r.y;
    }
private:
    int x;
    int y;
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
    void move(TkPoint& p){
        move(p.getX(),p.getY());
    }
    void move(int x , int y){
        this->x += x;
        this->y += y;
    }
    void locTo(TkPoint& p){
        locTo(p.getX(),p.getY());
    }
    void locTo(int x , int y){
        this->x = x;
        this->y = y;
    }
    friend TkRect operator /(const TkRect& r, int div){
        TkRect tmp(r);
        tmp.w = r.w / div;
        return tmp;
    }
    const TkRect& increaseSize(const TkRect& r){
        this->w += r.w;
        this->h += r.h;
        return *this;    
    }
    const TkRect& decreaseSize(const TkRect& r){
        this->w -= r.w;
        this->h -= r.h;
        return *this;    
    }
    const TkRect& increaseW(const TkRect& r){
        this->w += r.w;
        return *this;    
    }
    const TkRect& decreaseW(const TkRect& r){
        this->w -= r.w;
        return *this;    
    }
    const TkRect& increaseH(const TkRect& r){
        this->h += r.h;
        return *this;    
    }
    const TkRect& decreaseH(const TkRect& r){
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
    bool inRect(int x, int y){
        if ( (this->x < x && this->x + this->w > x)&&
            (this->y < y && this->y + this->h > y) ){
                return true;
        }
        return false;
    }
    bool inRect(TkRect& rect){
        if ( (this->x < rect.x && this->x + this->w > rect.x)&&
            (this->y < rect.y && this->y + this->h > rect.y) ){
                return true;
        }
        return false;
    }
private:
    int w,h,x,y;
};



