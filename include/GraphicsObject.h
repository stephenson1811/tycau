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
    TkGraphicsObject(SDL_Surface*,std::string&);
    ~TkGraphicsObject(void);
public:
    void draw(SDL_Surface* src,SDL_Surface* dst);
    void draw(SDL_Surface* dst );
    void load(std::string&);
    void setCoord(SDL_Rect & r){m_Rect = r;}
    void setScreen(SDL_Surface*);
    bool transparent(SDL_Surface* Surf_Dest, int R, int G, int B);
private:
    void init();
protected:
    std::string m_Name; // picture to shown
    SDL_Rect m_Rect;    // pic coord and size
    SDL_Surface* m_SrcDvc; // pic convert to sdl surface
};

