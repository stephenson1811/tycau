/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#pragma once
#include "graphicsobject.h"
/* 
 * 
 * 
 * 
 * 
 * 
 * 
 */
class MapIndex{
public:
    MapIndex(){r = 0;c = 0;}
    MapIndex(int r, int c){this->r = r;this->c = c;}
    MapIndex& operator()(int r, int c){this->r = r;this->c = c;}
    int c; // column index, x-orient
    int r; // row index, y-orient
};
class TkPrimitive :public TkGraphicsObject{
public:
    TkPrimitive(void);
    TkPrimitive(std::string&,MapIndex&);
    ~TkPrimitive(void);
    void setDstRect(int x, int y, int w, int h);
    void move(int x, int y);
    void draw(SDL_Surface* dst );
    void draw(SDL_Surface* dst ,TTF_Font*);
    //void getSize(SIZE&);
    MapIndex getIndex(){return m_Index;}
private:
    MapIndex m_Index; // this pic showing in m_Index.x column, and m_Index.y row.
    std::string m_test;
};

