/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#include "BackGround.h"


TkBackGround::TkBackGround(void):TkGraphicsObject(){

}
TkBackGround::TkBackGround(std::string& name):TkGraphicsObject(name){
}
TkBackGround::TkBackGround(std::string& name, TkPoint& p):TkGraphicsObject(name,p){
}

TkBackGround::~TkBackGround(void){

}
