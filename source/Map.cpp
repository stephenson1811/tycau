#include "Map.h"

TkMap::TkMap(void){
}
TkMap::~TkMap(void){
	for (std::vector<TkMapPrimitive*>::iterator it = m_Tiles.begin();
		it != m_Tiles.end();it++){
			delete (*it);
	}
}
void TkMap::initMap(){
	for (int i = 0 ; i < 50 ; i++){
		int x = 0, y = 0;
		for (int j = 0 ; j < 50 ; j++){
			TkMapPrimitive* m = new TkMapPrimitive(std::string("D:\\data\\task_map\\JapanMap_0026-1.bmp"));
			//SIZE s;
			//m->getSize(s);
			//m->setDstRect(x+s.cx*i, y+s.cy*j, s.cx, s.cy);
			m_Tiles.push_back(m);
		}
	}
}
void TkMap::draw(/*CDC*pDC*/){
	for (std::vector<TkMapPrimitive*>::iterator it = m_Tiles.begin();
		it != m_Tiles.end();it++){
			(*it)->draw();
	}
}