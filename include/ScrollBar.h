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
 * if both picture and text append, this pic used as background.
 * 
 * 
 * 
 */
class TkScrollBar : public TkGraphicsObject{
public:
    TkScrollBar();
    ~TkScrollBar();
    void clicked( );
protected:
    std::string m_Text;
};