/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#include "tkthread.h"


TkThread::TkThread(){
    m_Event = NULL;
}
TkThread::~TkThread(){
}
int eventLoop(void *data){
    //m_Event = new TkEvent();
    while(1){ //main SDL events loop
        SDL_Event ev;
        int ret = SDL_WaitEvent(&ev);
        //m_Event->dispatch(ev);
        //
        //if (ret == 0 || (ev.type==SDL_QUIT) ||
        //    (ev.type == SDL_KEYDOWN && ev.key.keysym.sym==SDLK_F4 && (ev.key.keysym.mod & KMOD_ALT))){
        //    handleQuit();
        //    continue;
        //}else if(/*LOCPLINT && */ev.type == SDL_KEYDOWN && ev.key.keysym.sym==SDLK_F4){
        //    Settings full = settings.write["video"]["fullscreen"];
        //    full->Bool() = !full->Bool();
        //    continue;
        //}else if(ev.type == SDL_USEREVENT){
        //    switch(ev.user.code){
        //    case RETURN_TO_MAIN_MENU:
        //        {
  //                  endGame();
  //                  GH.curInt = CGPreGame::create();;
  //                  GH.defActionsDef = 63;
        //        }
        //        break;
        //    case STOP_CLIENT:
        //        client->endGame(false);
        //        break;
        //    case RESTART_GAME:
        //        {
        //            StartInfo si = *client->getStartInfo(true);
        //            endGame();
        //            startGame(&si);
        //        }
        //        break;
        //    case PREPARE_RESTART_CAMPAIGN:
        //        {
        //            auto si = reinterpret_cast<StartInfo *>(ev.user.data1);
        //            endGame();
        //            startGame(si);
        //        }
        //        break;
        //    case RETURN_TO_MENU_LOAD:
        //        endGame();
        //        CGPreGame::create();
        //        GH.defActionsDef = 63;
        //        CGP->update();
        //        CGP->menu->switchToTab(vstd::find_pos(CGP->menu->menuNameToEntry, "load"));
        //        GH.curInt = CGP;
        //        break;
        //    case FULLSCREEN_TOGGLED:
        //        fullScreenChanged();
        //        break;
        //    default:
  //              logGlobal->errorStream() << "Error: unknown user event. Code " << ev.user.code;
        //    }
        //    continue;
        //}
        //{
        //    //boost::unique_lock<boost::mutex> lock(eventsM);
        //    SDL_mutex *lock = (SDL_mutex *)data;
        //    SDL_mutexP(lock);
        //    events.push(ev);
        //    SDL_mutexV(lock);
        //}
    }

    return 0;
}
void TkThread::start(){
    /* 创建同步锁 */
    m_Lock = SDL_CreateMutex();
    m_Thread = SDL_CreateThread(eventLoop, m_Lock);
    if (m_Thread == NULL){
        SDL_GetError();
    }
}
void TkThread::stop(){
    SDL_DestroyMutex(m_Lock);
}

void TkThread::run(){
    int status = 0;
    SDL_WaitThread(m_Thread, &status);
}
void TkThread::kill(){
    SDL_KillThread(m_Thread);
}

