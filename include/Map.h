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
#include "boost/thread/thread.hpp"
//#include <list>
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
    bool onXBoard(int);
    bool onYBoard(int);
    void initGiantMap();
    void initMiniMap();
    void initFieldBattleMap();
    void initNavyBattleMap();
    void initSiegeBattleMap();
    std::vector<int> split(std::string&);
    int str2int(const std::string&);
    void reFresh();
private:
    std::vector<TkPrimitive*> m_TilesToShow;
    std::vector<TkCity*> m_CitiesToShow; // ninjas' , pirates', samurais' castles, villages.
    std::vector<TkPerson*> m_PersonsToShow; // ninjas , pirates, samurais.
    std::vector<TkPrimitive*> m_Tiles;
    std::vector<TkCity*> m_Cities; // all cities
    std::vector<TkPerson*> m_Persons; // all persons
    TkPoint m_TopLftPnt; // top left point of screen
    TkRect m_ScreenRect;
    boost::mutex m_Mutex;
};

