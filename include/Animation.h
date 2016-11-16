
// Animation Class

#ifndef _CANIMATION_H_
#define _CANIMATION_H_
/* * * * * * * * * * * * * * * *
@������ž�̬ͼƬ������ʾ
@
@
* * * * * * * * * * * * * * * */
#include "SDL.h"
#include "GraphicsObject.h"
class Animation {
private:
	TkGraphicsObject m_Primitive;
	int	    m_CurrentFrame; // ��̬ͼƬ�ĵ�ǰ�ֶκ�
    int     m_FrameRate;    //Milliseconds
public:
    int	    m_MaxFrames; // һ����̬ͼƬ�м����ֶ�
	bool	m_Oscillate; // 
public:
	Animation(int MaxFrame = 0);
public:
	void play();
	int GetCurrentFrame();
};

#endif
