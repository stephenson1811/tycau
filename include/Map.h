#pragma once
#include "MapPrimitive.h"
#include <vector>
class TkMap 
{
public:
	TkMap(void);
	~TkMap(void);
	void initMap();
	void draw();
private:
	std::vector<TkMapPrimitive*> m_Tiles;
};

