
#ifndef _CEVENT_H_
#define _CEVENT_H_

#include "SDL.h"

/* * * * * * * * * * * * * * * *
@
@
@
* * * * * * * * * * * * * * * */
class TkEvent{
public:
	TkEvent();
	~TkEvent();
	void dispatch(SDL_Event* Event);
	void OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle);
	void OnLButtonDown(int mX, int mY);
	void OnLButtonUp(int mX, int mY);
	void OnRButtonDown(int mX, int mY);
};



#endif
