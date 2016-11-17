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
    m_SceneMaker = NULL;
    m_Scene = NULL;
}
Game::~Game(){
    SDL_FreeSurface(m_Display);
    //Mix_CloseAudio();   
    delete m_Scene;
    delete m_Thread;
    SDL_Quit();
}
bool Game::loadGame(){
    InitVideo();            //init view
    InitAudio();            //init audio effective
    //
    m_SceneMaker = new TkSceneFactory;
    m_Scene = m_SceneMaker->getScene(TkScene::InHouse,m_Display);
    //show game view thread
    m_Thread = new TkThread;
    m_Thread->start(m_Scene);

    return true;
}
void Game::change(TkScene::Type type){
    delete m_Scene;
    m_Scene = m_SceneMaker->getScene( type, m_Display);
}
bool Game::endGame(){// end game 
    m_Thread->stop();
    return true;
}
bool Game::startGame(){// start a mouse/key listening thread
    SDL_Event e;
    while(1){ //main SDL events loop
        SDL_WaitEvent(&e);
        m_Scene->dispatch(&e);
        SDL_Delay(1000);
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
    SDL_ShowCursor(1);
    // set window caption
    SDL_WM_SetCaption("taikou", 0);
}
void Game::InitAudio(){//init audio
}

