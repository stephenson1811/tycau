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
TkButtonPrimitive::TkButtonPrimitive(void):TkAnimation(){
    m_Type = buttonWidget ;
}

TkButtonPrimitive::TkButtonPrimitive(const std::string& name,const TkPoint& p, int index, int pieces )
    :TkAnimation(name,pieces ){
        //int w = m_Rect.getW()/pieces;
        //int h = m_Rect.getH();
        //int x = rect.getX() + index * w;
        //int y = rect.getY();
        //setCoord(x,y,w,h);
        m_Type = buttonWidget ;
}
/* * * * * * * * * * * * * * * *
@ Name: 
@ Description: 
@ Arguments: 
@ Return: 
* * * * * * * * * * * * * * * */
TkButtonPrimitive::~TkButtonPrimitive(){
}

TkButton::TkButton(){}
TkButton::TkButton(std::vector<std::string> &v, const TkRect& rect, int status):m_Rect(rect){ 
    init(v, rect, status);
}
TkButton::~TkButton(){}
void TkButton::init(std::vector<std::string> & vname, const TkRect& r, int pieces){
    int index = 0;
    TkRect rect = r;
    TkPoint point (rect.getX(),rect.getY());// point - topleft of button.
    int x = point.getX();
    for (std::vector<std::string>::iterator it = vname.begin();
        it != vname.end(); it ++, index++){
            TkButtonPrimitive* bp = new TkButtonPrimitive((*it), point, index, pieces);
            int w = bp->getRect().getW();
            point.setX(x);
            bp->setCoord(point);
            m_Primitives.push_back(bp);  
            x+=w;
    }
    m_Type = buttonWidget ;
}
void TkButton::draw(SDL_Surface* dst ) {
    for (std::vector<TkButtonPrimitive*>::iterator it = m_Primitives.begin();
        it != m_Primitives.end();it ++){
            (*it)->draw(dst);
    }
}
void TkButton::draw(SDL_Surface* dst, TkRect& ){
}
bool TkButton::inRect(SDL_Event* e) {
    return m_Rect.inRect(e->button.x,e->button.y);
}
void TkButton::addStatus(TkGui::ControlStatus status,int index ){
    m_StatusMap.insert(std::make_pair(status, index ));
}
void TkButton::setStatus(TkGui::ControlStatus type){
    for (std::vector<TkButtonPrimitive*>::iterator it = m_Primitives.begin();
        it != m_Primitives.end(); it ++){
            (*it)->setCurrentPieces(m_StatusMap[type]);
    }
}
TkEvent TkButton::handle(SDL_Event* e){
    switch(e->type) {
        case SDL_MOUSEMOTION: {
            hovered();
            break;
        }
        case SDL_MOUSEBUTTONDOWN: {
            switch(e->button.button) {
                case SDL_BUTTON_LEFT: {
                    return pressed();
                }
            }
        }
        case SDL_MOUSEBUTTONUP: {
            switch(e->button.button) {
                case SDL_BUTTON_LEFT: {
                    return released();
                }
            }
        }
        case TkEventType::BUTTON_CLICK:{
            break;
        }
    }
    return TkEvent();
}
TkEvent TkButton::clicked(){
    setStatus(TkGui::click);
    return TkEvent();
}
TkEvent TkButton::released(){
    setStatus(TkGui::released);
    if (m_ObjectName=="goOutDoor"){ 
        return TkEvent(TkEventType::CHANGE_SCENE,TkUserCode::OUT_HOUSE);
    }else if(m_ObjectName.compare("goHome") == 0){
        return TkEvent(TkEventType::CHANGE_SCENE,TkUserCode::IN_HOUSE);
    }
}
TkEvent TkButton::hovered(){
    setStatus(TkGui::hover);
    if (m_ObjectName.compare("") == 0){ // if it is go out button. it mustsend a event to scene object.
    }
    return TkEvent();
}
TkEvent TkButton::pressed(){
    setStatus(TkGui::pressed);
    return TkEvent();
}






