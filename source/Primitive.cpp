/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#include "Primitive.h"


TkPrimitive::TkPrimitive(void):TkGraphicsObject(){
    m_Type = mapPrimitive;
}
TkPrimitive::TkPrimitive(std::string& name, MapIndex& index):TkGraphicsObject(name){
    m_Index = index;
    int w = m_SrcDvc->w;
    int h = m_SrcDvc->h;
    int xbase = 0, ybase = 0;
    m_Point.setX(xbase + w*index.x) ;
    m_Point.setY(ybase + h*index.y) ;
    m_Type = mapPrimitive;
}
TkPrimitive::~TkPrimitive(void){
}
void TkPrimitive::move(int dx, int dy){
    int x = m_Point.getX();
    int y = m_Point.getY();
    m_Point.setX(x + dx) ;
    m_Point.setY(y + dy) ;
}
void TkPrimitive::setDstRect(int x, int y, int w, int h){
    //m_x = x;
    //m_y = y;
    //m_width = w;
    //m_height = h;
}
//void TkPrimitive::getSize(SIZE& size){
//    //if (!m_Image.IsNull()){
//    //    size.cx = m_Image.GetWidth();
//    //    size.cy = m_Image.GetHeight();
//    //}else{
//    //    size.cx = 0;size.cy = 0;
//    //}
//}