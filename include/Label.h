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
 * this class is uses for showing texts or pictures.
 * 
 * if both picture and text appended, this pic used as background.
 * 
 * 
 * 
 */
class TkLabel : public TkGraphicsObject{
public:
    TkLabel(void);
    TkLabel(const std::string&);
    TkLabel(const std::string&,const TkPoint&,bool isText = false);
    ~TkLabel(void);
};


