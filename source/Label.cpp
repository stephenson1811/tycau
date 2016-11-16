/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#include "Label.h"

/* * * * * * * * * * * * * * * *
@ Name: 
@ Description: c-tor
@ Arguments: 
@ Return:
* * * * * * * * * * * * * * * */
TkLabel::TkLabel(){
}
/* * * * * * * * * * * * * * * *
@ Name: setPicture
@ Description: set picture's absolute directory, in base class load it for control.
@ Arguments: picture's name
@ Return: N/A
* * * * * * * * * * * * * * * */

void TkLabel::setPicture(std::string& name){
    load(name);
}
/* * * * * * * * * * * * * * * *
@ Name: setText
@ Description: set text which to be shown. 
@ Arguments: text
@ Return: N/A
* * * * * * * * * * * * * * * */
void TkLabel::setText(std::string& name){
    m_Text = name;

}