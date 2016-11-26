/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#include "TaskWidget.h"


TkTaskWidget::TkTaskWidget(void){
    m_Type = taskWidget;
    m_BackGround = new TkLabel();
}
TkTaskWidget::TkTaskWidget(std::string&){
    m_Type = taskWidget;
}
TkTaskWidget::TkTaskWidget(std::string&, TkRect& ){
    m_Type = taskWidget;
}

TkTaskWidget::~TkTaskWidget(void){

}
void TkTaskWidget::draw(SDL_Surface* dst ){
}
void TkTaskWidget::draw(SDL_Surface* dst, TkRect& ){
}
bool TkTaskWidget::inRect(SDL_Event* e){
    if ( m_BackGround->inRect(e) ){ 
        return true;
    }
    return false;
}