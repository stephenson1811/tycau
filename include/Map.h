/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#pragma once
#include "MapPrimitive.h"
#include <vector>
/* 
 * 
 * 
 * 
 * 
 * 
 * 
 */
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

