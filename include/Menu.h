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
//#include "Button.h"
/* 
 * this class is uses for showing texts or pictures.
 * 
 * if both picture and text append, this pic used as background.
 * 
 * 
 * 
 */
class TkButton;
class TkMenu : public TkObject{
public:
    TkMenu();
    ~TkMenu();
    void clicked( );
    void draw(SDL_Surface* dst ) ;
    void draw(SDL_Surface* dst, TkRect& ) ;
    bool inRect(SDL_Event*) ;
protected:
    std::string m_Text;
private:
    std::vector<TkButton*> m_Buttons;
};