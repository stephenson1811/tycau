/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#pragma once
#include "graphicsobject.h"
/* 
 * 
 * 
 * 
 * 
 * 
 * 
 */
class TkTaskWidget: public TkGraphicsObject{
public:
    TkTaskWidget(void);
    TkTaskWidget(std::string&);
    TkTaskWidget(TkRect&, std::string&);
    ~TkTaskWidget(void);
private:
};

