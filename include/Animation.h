/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#pragma once

#include "SDL.h"
#include "GraphicsObject.h"
/* * * * * * * * * * * * * * * *
@������ž�̬ͼƬ������ʾ
@
@
* * * * * * * * * * * * * * * */
class Animation {
private:
    TkGraphicsObject m_Primitive;
    int    m_CurrentFrame; // ��̬ͼƬ�ĵ�ǰ�ֶκ�
    int    m_FrameRate;    //Milliseconds
public:
    int    m_MaxFrames; // һ����̬ͼƬ�м����ֶ�
    bool   m_Oscillate; // 
public:
    Animation(int MaxFrame = 0);
public:
    void play();
    int GetCurrentFrame();
};

