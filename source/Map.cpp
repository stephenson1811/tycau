/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#include "Map.h"

TkMap::TkMap(void){
    initMap(TkType::InGiantMap);
}
TkMap::TkMap(TkType::SceneType type){
    initMap(type);
}
TkMap::~TkMap(void){
    for (std::vector<TkPrimitive*>::iterator it = m_Tiles.begin();
        it != m_Tiles.end();it++){
            delete (*it);
    }
}
void TkMap::initMap(TkType::SceneType){
    m_Type = mapWidget;
    initGiantMap();
}
void TkMap::draw(SDL_Surface* dst ){
    for (std::vector<TkPrimitive*>::iterator it = m_Tiles.begin();
        it != m_Tiles.end();it++){
            (*it)->draw(dst);
    }
}
void TkMap::draw(SDL_Surface* dst, TkRect& ){
}
bool TkMap::inRect(SDL_Event* e){
    return true;
}
TkPrimitive* TkMap::whichMapPrimitive(SDL_Event* e){
    for (std::vector<TkPrimitive*>::iterator it = m_Tiles.begin();
        it != m_Tiles.end();it++){
            if ((*it)->inRect(e)){
                return (*it);
            }
    }
    return NULL;
}
void TkMap::initGiantMap(){
    std::vector<MapIndex> v;
    v.push_back(MapIndex(0,0));
    v.push_back(MapIndex(1,0));
    v.push_back(MapIndex(2,0));
    v.push_back(MapIndex(3,0));
    v.push_back(MapIndex(4,0));
    v.push_back(MapIndex(5,0));
    v.push_back(MapIndex(6,0));
    v.push_back(MapIndex(7,0));

    for (int i = 5;i<5+8;i++){
        std::ostringstream total, os;
        os.width(4);
        os.fill('0');
        os<<i;
        total<<"D:\\data\\task_map\\JapanMap_"<<os.str()<<"-1.bmp"; 
        m_Tiles.push_back(new TkPrimitive(std::string(total.str()),v[i-5]));
    }




}
void TkMap::initMiniMap(){}
void TkMap::initFieldBattleMap(){}
void TkMap::initNavyBattleMap(){}
void TkMap::initSiegeBattleMap(){}
