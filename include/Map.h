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
#include "City.h"
#include "Person.h"
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
    TkMap(TkType::SceneType);
    ~TkMap(void);
    void initMap(TkType::SceneType);
    void draw(SDL_Surface* dst );
    void draw(SDL_Surface* dst, TkRect& );
    bool inRect(SDL_Event*);
    TkPrimitive* whichMapPrimitive(SDL_Event*);
    void move(int x, int y);
private:
    bool onBoard(MapIndex&);
    void initGiantMap();
    void initMiniMap();
    void initFieldBattleMap();
    void initNavyBattleMap();
    void initSiegeBattleMap();
    std::vector<int> split(std::string&);
    int str2int(const std::string&);
private:
    std::vector<TkPrimitive*> m_Tiles;
    std::vector<TkCity*> m_Cities; // ninjas' , pirates', samurais' castles, villages.
    std::vector<TkPerson*> m_Persons; // ninjas , pirates, samurais.
    TTF_Font * m_TestFont;
    TkPoint m_TopLftPnt; // top left point of screen
    TkRect m_ScreenRect;
};

