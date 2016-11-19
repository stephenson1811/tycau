/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#pragma once
#include "GraphicsObject.h"
/* 
 * it shows a single picture back-ground.
 * usually the width and height is equal to the picture's.
 * 
 * 
 * 
 * 
 */
class TkBackGround:public TkGraphicsObject{
public:
    TkBackGround(void);
    TkBackGround(std::string&);
    TkBackGround(TkRect&,std::string&);
    ~TkBackGround(void);
};

