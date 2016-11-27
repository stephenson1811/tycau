/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#include "StatusWidget.h"


TkStatusWidget::TkStatusWidget(void){
    init();
}
//TkStatusWidget::TkStatusWidget(std::string& name){
//}
//TkStatusWidget::TkStatusWidget(TkRect& r , std::string& name){
//    //Parts_A_73-1.bmp
//}
void TkStatusWidget::init(){
    m_Type = statusWidget;
    TkPoint p(9,9);
    m_BackGround = new TkLabel( std::string("D:\\data\\UI\\Parts_N_108-1.bmp"), p );
    TkPoint delta2(8,8);
    m_Portraits = new TkLabel(std::string("D:\\data\\little_portraits\\Face0_113-1.bmp"), p+delta2) ;   // player image
    TkPoint delta3(353,30);
    m_Weather = new TkLabel(std::string("D:\\data\\UI\\Parts_A_67-1.bmp"), p+delta3);
    TkPoint delta4(237,70);
    m_HP = new TkLabel(std::string("D:\\data\\UI\\Parts_A_73-1.bmp"), p+delta4);
    TkPoint delta5(9,9);
    m_ProtagonistName = new TkLabel();   // player name
    TkPoint delta6(9,9);
    m_Date = new TkLabel();
    TkPoint delta7(9,9);
    m_Place = new TkLabel();
    TkPoint delta8(9,9);
    m_Money = new TkLabel();
    TkPoint delta9(9,9);
    m_Career = new TkLabel();  // 
}
TkStatusWidget::~TkStatusWidget(void){
}
void TkStatusWidget::draw(SDL_Surface* dst){
    m_BackGround->draw(dst);
    m_Portraits->draw(dst);
    m_Weather->draw(dst);
    m_HP->draw(dst);
}
void TkStatusWidget::draw(SDL_Surface* dst, TkRect& ){
}
bool TkStatusWidget::inRect(SDL_Event* e){
    return false;
}


