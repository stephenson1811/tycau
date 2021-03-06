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
public:
    TkAnimation();
    TkAnimation(const std::string&, int TotalPieces = 1);
    TkAnimation(const std::string&, const TkPoint&, int TotalPieces = 1);
    ~TkAnimation();
public:
    void draw(SDL_Surface* dst);
    void play(SDL_Surface* );
    int getCurrentPieces();
    void setCurrentPieces(int);
    TkRect& getRect(){return m_Rect;}
private:
    void nextIndex();
    void init(int);
private:
    int m_CurrentPiece; // current image piece id
    int m_PlayDelay;    // Milliseconds
    int m_TotalPieces;  // a pic is composed from many pieces 
    // status, this image in playing or static display status.
    // it's different in button and grapghic drawing.
    bool m_Playing;
    bool m_Quit;
    bool horizontal; // direction, horizontal or vertical
    TkRect m_Rect; // to be shown after clipping.
};

