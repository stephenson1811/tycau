/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#include "Menu.h"

/* * * * * * * * * * * * * * * *
@ Name: 
@ Description: 
@ Arguments: 
@ Return: 
* * * * * * * * * * * * * * * */
TkMenu::TkMenu(){
    m_Type = menuWidget;
}


/* * * * * * * * * * * * * * * *
@ Name: 
@ Description: 
@ Arguments: 
@ Return: 
* * * * * * * * * * * * * * * */
TkMenu::~TkMenu(){
}

void TkMenu::clicked(){
}
void TkMenu::draw(SDL_Surface* dst ) {
}
void TkMenu::draw(SDL_Surface* dst, TkRect& ) {
}
bool TkMenu::inRect(SDL_Event*) {
    return true;
}



