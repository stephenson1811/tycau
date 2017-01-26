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
/* 
 * graphics object
 * it is a fundamental component of all graphics
 * it contains only one picture.
 * 
 * sometimes it is treated as controls.
 * 
 */
class TkGraphicsObject: public TkObject{
public:
    TkGraphicsObject(void);
    TkGraphicsObject(const std::string&);
    TkGraphicsObject(const std::string&,const TkPoint&,bool isText = false);
    ~TkGraphicsObject(void);
public:
    void draw(SDL_Surface* dst ); // show all area of picture. 
    void draw(SDL_Surface* dst, TkRect& ); // show part of pic.
    void load(const std::string&);
    void setCoord(const TkPoint& p){m_Point = p;}
    void setCoord(int x, int y){m_Point.setX(x);m_Point.setY(y);}
    void setMask(SDL_Color& mask);
    bool inRect(SDL_Event*);
    void setSize(int w, int h){/*m_Rect.setW(w);m_Rect.setH(h);*/}
    TkPoint& getPoint(){return m_Point;}
    TkRect getRect();
    TkEvent handle(SDL_Event*);
protected:
    void init();
    void init(TkRect&);
protected:
    std::string m_Name; // picture to shown
    TkPoint m_Point;    // pic coord, topleft corner.
    SDL_Surface* m_SrcDvc; // pic convert to sdl surface.
    SDL_Color m_Mask;
};

