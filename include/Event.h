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

/* * * * * * * * * * * * * * * *
@
@
@
* * * * * * * * * * * * * * * */
class TkEvent{
public:
    TkEvent();
    ~TkEvent();
    void dispatch(SDL_Event* Event);
    void OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle);
    void OnLButtonDown(int mX, int mY);
    void OnLButtonUp(int mX, int mY);
    void OnRButtonDown(int mX, int mY);
};
