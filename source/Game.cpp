/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#include "Game.h"
#include <iostream>

Game::Game(){
    m_Display=NULL;
    WIDTH = 800;
    HEIGHT = 600;
    BPP = 32;
}
Game::~Game(){
    Mix_CloseAudio();        
    SDL_Quit();
}
bool Game::loadGame(){
    InitVideo();            //初始化参数
    InitAudio();            //初始化音效
    // start a mouse/key listening thread
    return true;
}
bool Game::endGame(){// end game 
     return true;
}
bool Game::startGame(){//start game
    return true;
}
void Game::InitVideo(){//init game view
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return ;
    }
    if((m_Display = SDL_SetVideoMode(
        WIDTH, HEIGHT, BPP,SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
            return ;
    }
    //隐藏光标
    SDL_ShowCursor(0);
    SDL_WM_SetCaption("太阁立志传", 0);
}
void Game::InitAudio(){//init audio
}

