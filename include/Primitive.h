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
    MapIndex(){x = 0;y = 0;}
    MapIndex(int x, int y){this->x = x;this->y = y;}
    MapIndex& operator()(int x, int y){this->x = x;this->y = y;}
    int x; // x-coord index
    int y; // y-coord index
};
class TkPrimitive :public TkGraphicsObject{
public:
    TkPrimitive(void);
    TkPrimitive(std::string&,MapIndex&);
    ~TkPrimitive(void);
    void setDstRect(int x, int y, int w, int h);
    //void getSize(SIZE&);
private:
    MapIndex m_Index; // this pic showing in m_Index.x column, and m_Index.y row.
};

