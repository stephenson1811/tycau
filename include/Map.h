/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#pragma once
#include "Primitive.h"
#include <vector>
/* 
 * 
 * 
 * 
 * 
 * 
 * 
 */
class TkMap : public TkObject{
public:
    TkMap(void);
    ~TkMap(void);
    void initMap();
    void draw();
    void draw(SDL_Surface* dst );
    void draw(SDL_Surface* dst, TkRect& );
    //bool inRect(SDL_Event*);
    bool inRect(SDL_Event*, TkPrimitive* );
private:
    std::vector<TkPrimitive*> m_Tiles;
};

