/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#pragma once

#include "SDL.h"
#include "GraphicsObject.h"
/* * * * * * * * * * * * * * * *
@处理多张静态图片连续显示
@
@
* * * * * * * * * * * * * * * */
class Animation {
private:
    TkGraphicsObject m_Primitive;
    int    m_CurrentFrame; // 静态图片的当前分段号
    int    m_FrameRate;    //Milliseconds
public:
    int    m_MaxFrames; // 一幅静态图片有几个分段
    bool   m_Oscillate; // 
public:
    Animation(int MaxFrame = 0);
public:
    void play();
    int GetCurrentFrame();
};

