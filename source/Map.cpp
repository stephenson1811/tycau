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
    int u = 25+2+2+2+2;
    F1( 14+u ,7);
    F1( 14+u , 9);
    F1( 14+u ,10);
    F1( 14+u , 11);
    F1( 14+u , 11);
    // 6 - 10
    F1( 14+u , 11);
    F1( 14+u , 11);
    F1( 14+u , 11);
    F1( 13+u , 12);
    F1( 13+u , 11);
    // 11 -15
    F1( 13+u , 12);
    F1( 13+u , 11);
    F1( 12+u , 12);
    F1( 11+u , 13);
    F1( 11+u , 13);
    // 16 -20
    F1( 11+u , 13);
    F1( 10+u , 14);
    F1( 10+u , 14); // now
    F1( 6+u , 18);
    F1( 0+u , 24);
    // 21 - 25
    F1( 0+u , 24);
    F1( -6+u , 30);
    F1( -8+u , 32);
    F1( -13+u , 37);
    F1( 12 , 45);
    // 26 - 30
    F1( 11 , 45);
    F1( 8 , 47);
    F1( 7 , 47);
    F1( 7 , 46);
    F1( 6 , 46);
    // 31 - 35
    F1( 6 , 46);
    F1( 4 , 48);
    F1( 4 , 48);
    F1( 4 , 47);
    F1( 3 , 46);
    // 36 - 40
    F1( 2 , 47);
    F1( 2 , 46);
    F1( 2 , 45);
    F1( 2 , 44);
    F1( 2 , 44);
    // 41 - 45
    F1( 2 , 44);
    F1( 3 , 44);
    F1( 5 , 41);
    F1( 5 , 27);
    F1( 5 , 21);
    // 46 - 50
    F1( 5 , 12);
    F1( 5 , 12);
    F1( 6 , 10);
    F1( 5 , 10);
    F1( 5 , 9);
    //51
    F1( 5 , 7);
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
