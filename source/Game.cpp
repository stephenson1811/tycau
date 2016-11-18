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
    m_Scene = NULL;
}
Game::~Game(){
    SDL_FreeSurface(m_Display);
    //Mix_CloseAudio();   
    delete m_Scene;
    SDL_Quit();
}
bool Game::loadGame(){
    initVideo();            //init view
    initAudio();            //init audio effective
    //
    m_Scene = TkSceneFactory::getScene(TkType::InHouse,m_Display);
    return true;
}
void  Game::processEvent(SDL_Event*e){
    m_Scene->dispatch(e);
    //TkStatusType::Status status = m_Scene->dispatch(&e, &ev);
    //processEvent(status, &ev);
    //switch(status){
    //case TkStatusType::ChangeScene:
    //    //changeScene(1);
    //    break;
    //}
}
void Game::changeScene(TkType::Type type){
    if (m_Scene){
        delete m_Scene;
    }
    m_Scene = TkSceneFactory::getScene( type);
}

void Game::initVideo(){//init game view
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
void Game::initAudio(){//init audio
}

bool Game::endGame(){// end game 
    return true;
}


bool Game::runGame(){
    // 
    m_Scene->run();
    return true;
}