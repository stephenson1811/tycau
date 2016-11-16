#pragma once

#include "SDL_thread.h"
#include "SDL_mutex.h"
#include "Event.h"
/* * * * * * * * * * * * * * * *
@
@
@
* * * * * * * * * * * * * * * */
int potty = 0;
int gotta_go;

class TkThread{
public:
	TkThread();
	~TkThread();
	void run() ;
	void start();
	void stop();
private:
	void kill();
protected:
	SDL_mutex *m_Lock;
	int m_ThrID;   // Ïß³ÌºÅ
	SDL_Thread* m_Thread;
    TkEvent * m_Event;
};


