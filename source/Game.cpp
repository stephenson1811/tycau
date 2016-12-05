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
    WIDTH = 1200;//800
    HEIGHT = 700;//600
    BPP = 32;
    m_Scene = NULL;
    m_Running = true;
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
    m_Scene = TkSceneFactory::getScene(TkType::InGiantMap,m_Display);
    return true;
}

void  Game::processEvent(SDL_Event*e){
    TkEvent ev;
    switch(e->type){
    case SDL_QUIT:{
            m_Running = false;
            break;
        }
    case SDL_ACTIVEEVENT: {
        switch(e->active.state) {
            case SDL_APPACTIVE:    {
                break;
            }
        }
        break;
    }
    case SDL_KEYDOWN: {
        break;
    }
    case SDL_USEREVENT:{
            switch(e->user.code){
            case TkGameStatusType::RETURN_TO_MAIN_MENU:{
                }
                break;
            case TkGameStatusType::STOP_CLIENT:
                break;
            case TkGameStatusType::RESTART_GAME:
                break;
            case TkGameStatusType::PREPARE_RESTART_CAMPAIGN:
                break;
            case TkGameStatusType::RETURN_TO_MENU_LOAD:
                break;
            case TkGameStatusType::FULLSCREEN_TOGGLED:
                break;
            default:
                std::cout << "Error: unknown user event. Code " << e->user.code;
            }
        }
    case TkEventType::CHANGE_SCENE:
        changeScene( (TkType::SceneType)(e->user.code));
    case SDL_MOUSEMOTION:
    case SDL_MOUSEBUTTONDOWN:
    case SDL_MOUSEBUTTONUP:
        m_Scene->dispatch(e);
        break;
    }
    SDL_Flip(m_Display);

    //m_Scene->dispatch(&e, &ev);
    //processEvent(status, &ev);
    //switch(status){
    //case TkGameStatusType::ChangeScene:
    //    //changeScene(1);
    //    break;
    //}
}
void Game::changeScene(TkType::SceneType type){
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
    SDL_FillRect(m_Display, 0, SDL_MapRGB(m_Display->format, 0xFF, 0xFF, 0xFF));
    // hide cursor
    SDL_ShowCursor(1);
    // load font
    TTF_Init();
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