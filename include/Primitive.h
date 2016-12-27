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
    bool operator == (MapIndex& index){
        if (index.c == this->c && index.r == this->r)
            return true;
        return false;
    }
    bool operator != (MapIndex& index){
        if (index.c == this->c && index.r == this->r)
            return false;
        return true;
    }
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
struct less{
    bool operator () (TkPrimitive* a,TkPrimitive* b){
        MapIndex na = a->getIndex();
        MapIndex nb = b->getIndex(); 
        if (na.r > nb.r){
            return true;
        }else if (na.r < nb.r){
            return false;
        }else{
            if (na.c > nb.c){
                return true;
            }else if(na.c < nb.c){
                return false;
            }
        }
        return false;
    }
};
