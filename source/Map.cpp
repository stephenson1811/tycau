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
    m_TestFont = TTF_OpenFont( "arial.ttf", 10/*size*/ );
    TTF_SetFontStyle(m_TestFont, TTF_STYLE_NORMAL );
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
void TkMap::move(int x, int y){
    for (std::vector<TkPrimitive*>::iterator it = m_Tiles.begin();
        it != m_Tiles.end(); it ++){
            (*it)->move(x,y);
    }
}
#define F(A,n) {\
    int *num = A;\
    std::vector<int> mx (num, num + n );\
    m.push_back(mx);  \
}
#define F1(s,n){\
    int a[n] ;\
    for (int i = 0;i < n; i++){a[i] = s+i;}\
    std::vector<int> mx (a, a + n );\
    m.push_back(mx);  \
}
void TkMap::initGiantMap(){
    std::vector<MapIndex> v;
    std::vector<std::vector<int> > m;
    // 1 - 5
    F1( 3 ,7);
    F1( 3 , 9);
    F1( 3 ,10);
    F1( 3 , 11);
    F1( 3 , 11);
    // 6 - 10
    F1( 3 , 11);
    F1( 3 , 11);
    F1( 3 , 11);
    F1( 2 , 11);
    F1( 1 , 11);
    // 11 -15
    F1( 0 , 12);
    F1( 0 , 11);
    F1( 0 , 11);
    F1( 0 , 12);
    F1( 0 , 14);
    // 16 -20
    F1( 0 , 14);
    F1( 0 , 14);
    F1( 0 , 13);
    F1( 0 , 19);
    F1( 0 , 23);
    // 21 - 25
    F1( 0 , 24);
    F1( 0 , 30);
    F1( 0 , 32);
    F1( 0 , 36);
    F1( 0 , 44);
    // 26 - 30
    F1( 0 , 46);
    F1( 0 , 46);
    F1( 0 , 48);
    F1( 0 , 48);
    // 31 - 35
    F1( 0 , 45);
    F1( 0 , 46);
    F1( 0 , 46);
    F1( 0 , 48);
    F1( 0 , 49);
    // 36 - 40
    F1( 0 , 46);
    F1( 0 , 47);
    F1( 0 , 48);
    F1( 0 , 45);
    F1( 0 , 43);
    // 41 - 45
    F1( 0 , 44);
    F1( 0 , 43);
    F1( 0 , 33);
    F1( 0 , 27);
    F1( 0 , 38);
    // 46 - 50
    F1( 0 , 30);
    F1( 0 , 29);
    F1( 0 , 19);
    F1( 0 , 18);
    F1( 0 , 15);

    int y = 0;
    for ( std::vector<std::vector<int> >::iterator it = m.begin(); it != m.end(); it++, y++){
        for ( std::vector<int>::iterator i = (*it).begin(); i != (*it).end(); i++){
            v.push_back(MapIndex((*i),y));
        }
    }

    int i = 5;
    for (std::vector<MapIndex>::iterator it = v.begin();
        it != v.end();it++,i++){
        std::ostringstream total, os;
        os.width(4);
        os.fill('0');
        os<<i;
        total<<"D:\\data\\task_map\\JapanMap_"<<os.str()<<"-1.bmp"; 
        m_Tiles.push_back(new TkPrimitive(std::string(total.str()),(*it)));
    }




}
void TkMap::initMiniMap(){}
void TkMap::initFieldBattleMap(){}
void TkMap::initNavyBattleMap(){}
void TkMap::initSiegeBattleMap(){}
