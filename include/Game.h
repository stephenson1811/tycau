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
#include "Scene.h"
/* * * * * * * * * * * * * * * *
@
@
@
* * * * * * * * * * * * * * * */

/* 
 * 
 * 
 * 
 * 
 * 
 * 
 */
class Game{
public:
    Game();
    ~Game();
    bool loadGame();                    //load game, the initial view
    bool startGame();                    //start game
    void InitVideo();                    //init view
    bool endGame();                        //end game
    void InitAudio();                    //init audio
private:
    SDL_Surface* m_Display;                //destination screen device
    TkScene* m_Scene;
    int WIDTH;    // for screen
    int HEIGHT;    
    int BPP;
};

