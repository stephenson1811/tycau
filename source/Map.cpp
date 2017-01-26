/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#include "Map.h"
#include <fstream>
#include <algorithm>

TkMap::TkMap(void){
    initMap(TkType::InGiantMap);
}
TkMap::TkMap(TkType::SceneType type){
    initMap(type);
}
TkMap::~TkMap(void){
    for (std::vector<TkPrimitive*>::iterator it = m_TilesToShow.begin();
        it != m_TilesToShow.end();it++){
            delete (*it);
            (*it) = NULL;
    }
}
void TkMap::initMap(TkType::SceneType){
    m_Type = mapWidget;   
    // screen would changed, when mouse move.
    m_TopLftPnt = TkPoint(12000,1000);
    m_ScreenRect = TkRect(m_TopLftPnt.getX(),m_TopLftPnt.getY(),800,600);
    initGiantMap();
}
void TkMap::draw(SDL_Surface* dst ){
    boost::lock_guard<boost::mutex> lock(m_Mutex); 
    //std::cout<<"enter read"<<std::endl;
    for ( std::vector<TkPrimitive* >::iterator it = m_TilesToShow.begin(); 
        it != m_TilesToShow.end(); it++ ){  
            (*it)->draw(dst);
    }
    //std::cout<<"quit read"<<std::endl<<std::endl;
}
void TkMap::draw(SDL_Surface* dst, TkRect& ){
}
bool TkMap::inRect(SDL_Event* e){
    return true;
}
TkPrimitive* TkMap::whichMapPrimitive(SDL_Event* e){
    for (std::vector<TkPrimitive*>::iterator it = m_TilesToShow.begin();
        it != m_TilesToShow.end();it++){
            if ((*it)->inRect(e)){
                return (*it);
            }
    }
    return NULL;
}
void TkMap::move(int x, int y){
    m_TopLftPnt+=TkPoint(x,y);
    m_ScreenRect.locTo(m_TopLftPnt);
    std::vector<TkPrimitive*> t ;

    for (std::vector<TkPrimitive*>::iterator it = m_Tiles.begin();
        it != m_Tiles.end(); it++){ //
            (*it)->move(x,y);
            MapIndex index = (*it)->getIndex();
            if(onBoard( index)){
                t.push_back((*it));
            }
    }
    boost::lock_guard<boost::mutex> lock(m_Mutex);   
    //std::cout<<"enter write"<<std::endl;
    m_TilesToShow.swap(t);
    //std::cout<<"quit write"<<std::endl<<std::endl;
}
void TkMap::reFresh(){
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
    //std::vector<MapIndex> v;
    //std::vector<std::vector<int> > m;
    //// 1 - 5
    //int u = -14;//33
    //F1( 14+u ,7);
    //F1( 14+u , 9);
    //F1( 14+u ,10);
    //F1( 14+u , 11);
    //F1( 14+u , 11);
    //// 6 - 10
    //F1( 14+u , 11);
    //F1( 14+u , 11);
    //F1( 14+u , 11);
    //F1( 13+u , 12);
    //F1( 13+u , 11);
    //// 11 -15
    //F1( 13+u , 12);
    //F1( 13+u , 11);
    //F1( 12+u , 12);
    //F1( 11+u , 13);
    //F1( 11+u , 13);
    //// 16 -20
    //F1( 11+u , 13);
    //F1( 10+u , 14);
    //F1( 10+u , 14); // now
    //F1( 6+u , 18);
    //F1( 0+u , 24);
    //// 21 - 25
    //F1( 0+u , 24);
    //F1( -6+u , 30);
    //F1( -8+u , 32);
    //F1( -13+u , 37);
    //F1( 12 , 45);
    //// 26 - 30
    //F1( 11 , 45);
    //F1( 8 , 47);
    //F1( 7 , 47);
    //F1( 7 , 46);
    //F1( 6 , 46);
    //// 31 - 35
    //F1( 6 , 46);
    //F1( 4 , 48);
    //F1( 4 , 48);
    //F1( 4 , 47);
    //F1( 3 , 46);
    //// 36 - 40
    //F1( 2 , 47);
    //F1( 2 , 46);
    //F1( 2 , 45);
    //F1( 2 , 44);
    //F1( 2 , 44);
    //// 41 - 45
    //F1( 2 , 44);
    //F1( 3 , 44);
    //F1( 5 , 41);
    //F1( 5 , 27);
    //F1( 5 , 21);
    //// 46 - 50
    //F1( 5 , 12);
    //F1( 5 , 12);
    //F1( 6 , 10);
    //F1( 5 , 10);
    //F1( 5 , 9);
    ////51
    //F1( 5 , 7);
    //int y = 0;


    // load map primitives
    std::ifstream ifs;
    std::string line;
    ifs.open("./data/map.txt", std::ios::in);
    int i = 5, row = 0;
    for (;ifs>>line;){
        std::vector<int> vi = split(line);
        if(!vi.empty()){
            for ( std::vector<int>::iterator it = vi.begin();it != vi.end(); i ++, it++){
                std::ostringstream total, os;
                os.width(4);
                os.fill('0');
                os<<i;
                total<<"D:\\data\\task_map\\JapanMap_"<<os.str()<<"-1.bmp";
                TkPrimitive* p = new TkPrimitive(total.str(),MapIndex(row,(*it) ));
                m_Tiles.push_back(p);  
            }
            row ++;
        }
    }
    // map primitives could be seen.
    for ( std::vector<TkPrimitive*>::iterator it = m_Tiles.begin();it != m_Tiles.end(); it++ ){
        TkPrimitive* p = (*it); 
        MapIndex index = p->getIndex();
        if(onBoard( index)){
            p->move( -m_TopLftPnt.getX(), -m_TopLftPnt.getY() );
            m_TilesToShow.push_back(p);
        }
    }
}
int TkMap::str2int(const std::string& str){
    return atoi(str.c_str());
}
std::vector<int> TkMap::split(std::string& str){
    std::vector<int> v;
    std::string s;
    for (std::string::iterator it = str.begin();it != str.end(); it ++){
        if ((*it) == ','){
            v.push_back(str2int(s));
            s .clear();
        }else if ((*it) != ' '){
            s.push_back((*it));
        }
    };
    return v;
}
bool TkMap::onBoard(MapIndex& index){
    return onXBoard(index.c) || onYBoard(index.r);
}
bool TkMap::onXBoard(int c){
    int dx = 256;
    int left = c*dx;
    int right = (c+1)*dx;
    int x = m_ScreenRect.getX();
    int w = m_ScreenRect.getW();
    if (left <= x && x <= left){// left < x < right
        return true;
    }else if (left <= x + w && x + w <= right){ // left < x + w < right
        return true;
    }else if (x <= left && right <= x + w){ // x < left < right < x + w  
        return true;
    }
    return false;
}
bool TkMap::onYBoard(int r){
    int dy = 160;
    int top = r*dy;
    int bottom = (r+1)*dy;
    int y = m_ScreenRect.getY();
    int h = m_ScreenRect.getH();
    if (top <= y && y <= bottom){
        return true;
    }else if (top <= y + h && y + h <= bottom){
        return true;
    }else if (y <= top && bottom <= y + h){
        return true;
    }
    return false;
}
void TkMap::initMiniMap(){}
void TkMap::initFieldBattleMap(){}
void TkMap::initNavyBattleMap(){}
void TkMap::initSiegeBattleMap(){}
