/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#pragma once
#include "config.h"
/* 
 * 
 * 
 * 
 * 
 * 
 * 
 */
class SoundManager{
public:
    SoundManager();
    ~SoundManager();
    int init(); 
    int play(std::string&);
private:
    void MusicEffect(int type);            //play music effect
};
