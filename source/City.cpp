/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#include "City.h"

TkCity::TkCity():TkGraphicsObject(){}
TkCity::TkCity(const std::string&name):TkGraphicsObject(name){}
TkCity::~TkCity(){}
void TkCity::move(int dx, int dy){
    int x = m_Point.getX();
    int y = m_Point.getY();
    m_Point.setX(x + dx) ;
    m_Point.setY(y + dy) ;
}
void TkCity::draw(SDL_Surface* dst ){
    TkGraphicsObject::draw(dst);
}