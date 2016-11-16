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
    InitVideo();            //��ʼ������
    InitAudio();            //��ʼ����Ч
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
    //���ع��
    SDL_ShowCursor(0);
    SDL_WM_SetCaption("̫����־��", 0);
}
void Game::InitAudio(){//init audio
}

