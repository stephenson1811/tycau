/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#pragma once

#include "SDL_thread.h"
#include "SDL_mutex.h"
#include "scene.h"
/* * * * * * * * * * * * * * * *
@
@ use for show game view 
@
* * * * * * * * * * * * * * * */
class TkThread{
public:
    TkThread();
    ~TkThread();
    void run() ;
    void start(TkScene*);
    void stop();
private:
    void kill();
protected:
    SDL_mutex *m_Lock;
    int m_ThrID;   // thread id
    SDL_Thread* m_Thread;
};


