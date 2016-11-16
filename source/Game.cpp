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
    SDL_FreeSurface(m_Display);
    //Mix_CloseAudio();        
    SDL_Quit();
}
bool Game::loadGame(){
    InitVideo();            //init view
    InitAudio();            //init audio effective
    //
    m_Scene = new TkScene(TkScene::InHouse);
    m_Scene->init();
    // start a mouse/key listening thread
    m_Thread = new TkThread;
    //m_Thread->start();
    //m_Thread->run();
    return true;
}
bool Game::endGame(){// end game 
    //m_Thread->stop();
    return true;
}
bool Game::startGame(){//start game
    while(1){
        m_Scene->draw(m_Display);
    }

    return true;
}
void Game::InitVideo(){//init game view
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return;
    }
    if((m_Display = SDL_SetVideoMode(
        WIDTH, HEIGHT, BPP,SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
            return;
    }
    // hide cursor
    SDL_ShowCursor(0);
    // set window caption
    SDL_WM_SetCaption("Ì«¸óÁ¢Ö¾´«", 0);
}
void Game::InitAudio(){//init audio
}

