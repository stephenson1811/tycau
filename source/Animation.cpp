/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#include "Animation.h"

/* * * * * * * * * * * * * * * *
@
@
@
* * * * * * * * * * * * * * * */
TkAnimation::TkAnimation(void):TkGraphicsObject(){}
TkAnimation::TkAnimation(const std::string& name, int TotalPieces )
    :TkGraphicsObject(name){
    init(TotalPieces);
}
TkAnimation::TkAnimation(const std::string& name, const TkPoint& p, int TotalPieces)
    :TkGraphicsObject(name, p) {
    init(TotalPieces);
}
void TkAnimation::init(int tp){
    horizontal = true;
    m_PlayDelay = 800;
    m_Quit = false;
    m_TotalPieces = tp;
    m_CurrentPiece = 0;
    TkRect r(0,0,m_SrcDvc->w,m_SrcDvc->h);
    m_Rect = r;

    int x = r.getX();
    int w = r.getW() / m_TotalPieces;
    m_Rect.setX( x + w * m_CurrentPiece );
    m_Rect.setW( w );
}
TkAnimation::~TkAnimation(){
    m_Quit = true;
}
//------------------------------------------------------------------------------
void TkAnimation::play(SDL_Surface* dst) {
    while ( !m_Quit ){
        draw(dst);
        nextIndex();
        SDL_Delay(m_PlayDelay);
    }
}
void TkAnimation::nextIndex(){
    if (m_CurrentPiece > m_TotalPieces){
        m_CurrentPiece = 0;
    }
    m_CurrentPiece++;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
int TkAnimation::getCurrentPieces() {
    return m_CurrentPiece;
}
void TkAnimation::setCurrentPieces(int index) {
    m_CurrentPiece = index;
    TkRect r(0,0,m_SrcDvc->w,m_SrcDvc->h);
    m_Rect = r;
    //if ( r.getH() < r.getW() ){
        horizontal = true;
        int x = r.getX();
        int w = r.getW() / m_TotalPieces;
        m_Rect.setX( x + w * index );
        m_Rect.setW( w );
    //}else{
    //    horizontal = false;
    //    int y = r.getY();
    //    int h = r.getH() / m_TotalPieces;
    //    rect.setY( y + h * index );
    //    rect.setH( h );
    //}
    return ;
}

void TkAnimation::draw(SDL_Surface* dst){
    TkGraphicsObject::draw(dst,m_Rect);
}
