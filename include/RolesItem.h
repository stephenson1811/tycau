/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#pragma once
#include "graphicsobject.h"
/* 
 * 
 * 
 * 
 * 
 * 
 * 
 */
class TkRolesItem: public TkGraphicsObject{
public:
    TkRolesItem(void);
    ~TkRolesItem(void);
private:
    TkGraphicsObject m_Image;
};

/* 
 * 
 * 
 * 
 * 
 * 
 * 
 */
class TkRolesList: public TkObject{
public:
    TkRolesList(void);
    ~TkRolesList(void);
    void draw(SDL_Surface* dst );
    void draw(SDL_Surface* dst, TkRect& );
    bool inRect(SDL_Event*);
    int getType(){return m_Type;}
private:
    std::vector<TkRolesItem*> m_Person;
};

