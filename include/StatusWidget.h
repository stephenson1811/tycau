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
 * task widget in left panel
 * 
 * 
 * 
 * 
 * 
 */
class TkStatusWidget : public TkObject {
public:
    TkStatusWidget(void);
    ~TkStatusWidget(void);
public:
    void init();
    void draw(SDL_Surface* dst );
    void draw(SDL_Surface* dst, TkRect& );
    bool inRect(SDL_Event*);
    int getType(){return m_Type;}
private:
    TkLabel* m_BackGround;
    TkLabel* m_Portraits;   // player image
    TkLabel* m_Weather;
    TkLabel* m_HP;
    TkLabel* m_ProtagonistName;   // player name
    TkLabel* m_Date;
    TkLabel* m_Place;
    TkLabel* m_Money;
    TkLabel* m_Career;  // 
};

