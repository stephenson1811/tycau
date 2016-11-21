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
}
TkThread::~TkThread(){
}
int eventLoop(void *temp){
    while(1){
        Game* game = (Game*)temp ;
        game ->runGame();
        SDL_Delay(1000);
        //TkSceneFactory::getScene( globleSceneType )->run();
        //
    }

    return 0;
}
void TkThread::start(Game* s){
    m_Thread = SDL_CreateThread(eventLoop, s);
    if (m_Thread == NULL){
        SDL_GetError();
    }
}
void TkThread::stop(){
    SDL_DestroyMutex(m_Lock);
}

void TkThread::run(){
    //int status = 0;
    //SDL_WaitThread(m_Thread, &status);
}
void TkThread::kill(){
    SDL_KillThread(m_Thread);
}

