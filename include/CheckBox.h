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
 * 
 * 
 * 
 * 
 * 
 * 
 */
class TkCheckBox : public TkGraphicsObject{
public:

    TkCheckBox();

    void clicked();// 按下之后松开
    void pressed(); // 按下不松开
    void keyPressed( ); // 点击按钮


};

