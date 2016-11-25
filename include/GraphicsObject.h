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
 * sometimes it is treat as controls.
 * 
 */
class TkGraphicsObject: public TkObject{
public:
    TkGraphicsObject(void);
    TkGraphicsObject(const std::string&);
    TkGraphicsObject(const TkRect&,const std::string&,bool isText = false);
    ~TkGraphicsObject(void);
public:
    void draw(SDL_Surface* dst );
    void draw(SDL_Surface* dst, TkRect& );
    void loadText(const std::string&);
    void load(const std::string&);
    void setCoord(TkRect& r){m_Rect = r;}
    void setMask(SDL_Color& mask);
    bool inRect(SDL_Event*);
    //void setScreen(SDL_Surface*);
    void setSize(int w, int h){m_Rect.setW(w);m_Rect.setH(h);}
    TkRect& getRect(){return m_Rect;}
    void handle(SDL_Event*);
protected:
    void init();
    void init(TkRect&);
protected:
    std::string m_Name; // picture to shown
    TkRect m_Rect;    // pic coord and size
    SDL_Surface* m_SrcDvc; // pic convert to sdl surface
    SDL_Color m_Mask;
};

