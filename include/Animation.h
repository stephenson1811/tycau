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
    int    m_CurrentPiece; // current image piece id
    int    m_FrameRate;    //Milliseconds
public:
    int    m_TotalPieces; // a pic is composed from many pieces
    bool   m_Playing; // 
public:
    TkAnimation(int TotalPieces = 0);
public:
    void play();
    int getStatus();
    void setStatus(int);
};

