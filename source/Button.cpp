/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#include "Button.h"

/* * * * * * * * * * * * * * * *
@ Name:
@ Description:
@ Arguments:
@ Return:
* * * * * * * * * * * * * * * */
TkButton::TkButton(void):TkGraphicsObject(){
}

TkButton::TkButton(const std::string& name):TkGraphicsObject(name){
}
TkButton::TkButton(const TkRect& r,const std::string& name, bool isText):TkGraphicsObject(r,name,isText){
}
/* * * * * * * * * * * * * * * *
@ Name:
@ Description:
@ Arguments:
@ Return:
* * * * * * * * * * * * * * * */
TkButton::~TkButton(){
}
void TkButton::setStatus(TkGui::ControlStatus type){
    for (std::vector<TkAnimation*>::iterator it = m_Primitives.begin();
        it != m_Primitives.end(); it ++){
            (*it)->setCurrentPieces(m_StatusMap[type]);
    }
}
void TkButton::clicked(){
    setStatus(TkGui::click);
}
 
void TkButton::hovered(){
    setStatus(TkGui::click);
    return;
}
void TkButton::pressed(){
    setStatus(TkGui::click);
}
void TkButton::addStatus(TkGui::ControlStatus status, int index){
    m_StatusMap.insert(std::make_pair(TkGui::click,1));
}