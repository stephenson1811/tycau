/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#include "Primitive.h"


TkPrimitive::TkPrimitive(void){
    //m_x = 0;
    //m_y = 0;
    //m_width = 100;
    //m_height = 150;
}
TkPrimitive::TkPrimitive(std::string& name):TkGraphicsObject(name){
    //m_x = 0;
    //m_y = 0;
    //m_width = 100;
    //m_height = 150;
}
TkPrimitive::~TkPrimitive(void){
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