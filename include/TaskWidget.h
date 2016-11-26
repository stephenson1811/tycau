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
#include "Label.h"
/* 
 * 
 * 
 * 
 * 
 * 
 * 
 */
class TkTaskWidget: public TkObject{
public:
    TkTaskWidget(void);
    TkTaskWidget(std::string&);
    TkTaskWidget(std::string&,TkRect& );
    ~TkTaskWidget(void);
public:
    void draw(SDL_Surface* dst );
    void draw(SDL_Surface* dst, TkRect& );
    bool inRect(SDL_Event*);
private:
    TkLabel* m_BackGround;
};

