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

void TkButton::clicked(){
}
 
void TkButton::keyPressed(){
    return;
}
