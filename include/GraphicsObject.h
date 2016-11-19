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
 * 
 * 
 * 
 * 
 * 
 * 
 */
class TkGraphicsObject{
public:
    TkGraphicsObject(void);
    TkGraphicsObject(std::string&);
    TkGraphicsObject(TkRect&,std::string&);
    ~TkGraphicsObject(void);
public:
    void draw(SDL_Surface* src,SDL_Surface* dst);
    void draw(SDL_Surface* dst );
    void load(std::string&);
    void setCoord(TkRect& r){m_Rect = r;}
    void setScreen(SDL_Surface*);
    void setSize(int w, int h){m_Rect.setW(w);m_Rect.setH(h);}
    bool transparent(SDL_Surface* Surf_Dest, int R, int G, int B);
protected:
    void init();
    void init(TkRect&);
protected:
    std::string m_Name; // picture to shown
    TkRect m_Rect;    // pic coord and size
    SDL_Surface* m_SrcDvc; // pic convert to sdl surface
};

