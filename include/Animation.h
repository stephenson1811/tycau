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
/* * * * * * * * * * * * * * * *
@ process many static image pieces from one picture.
@
@
* * * * * * * * * * * * * * * */
class TkAnimation: public TkGraphicsObject{
private:
    int    m_CurrentFrame; // current id
    int    m_FrameRate;    //Milliseconds
public:
    int    m_MaxFrames; // a pic is composed from many pieces
    bool   m_Oscillate; // 
public:
    TkAnimation(int MaxFrame = 0);
public:
    void play();
    int GetCurrentFrame();
};

