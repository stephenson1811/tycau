/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#pragma once
/* 
 * shows persons in giant map.
 * 
 * it would shows person move behaviors.
 * 
 * it's different in warrior, merchants, ninjas, pirates.
 * 
 */
#include "Animation.h"

class TkPerson : public TkAnimation{
public:
    TkPerson();
    TkPerson(std::string&);
    ~TkPerson();
    void move(int x, int y);
    void draw(SDL_Surface* dst );
};






