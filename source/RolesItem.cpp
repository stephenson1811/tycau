/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#include "RolesItem.h"


TkRolesItem::TkRolesItem(void){

}
TkRolesItem::~TkRolesItem(void){

}
TkRolesList::TkRolesList(void){

}
TkRolesList::~TkRolesList(void){

}


void TkRolesList::draw(SDL_Surface* d){
    std::vector<TkRolesItem*>::iterator it = m_Person.begin();
    for(;it != m_Person.end();it++){
        (*it)->draw(d);
    }
}
