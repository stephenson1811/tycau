
// Animation Class

#ifndef _CANIMATION_H_
#define _CANIMATION_H_
/* * * * * * * * * * * * * * * *
@处理多张静态图片连续显示
@
@
* * * * * * * * * * * * * * * */
#include "SDL.h"
#include "GraphicsObject.h"
class Animation {
private:
	TkGraphicsObject m_Primitive;
	int	    m_CurrentFrame; // 静态图片的当前分段号
    int     m_FrameRate;    //Milliseconds
public:
    int	    m_MaxFrames; // 一幅静态图片有几个分段
	bool	m_Oscillate; // 
public:
	Animation(int MaxFrame = 0);
public:
	void play();
	int GetCurrentFrame();
};

#endif
