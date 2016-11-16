/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#pragma once
#include "config.h"
#include "Event.h"
#include "GraphicsObject.h"
#include "Scene.h"
/* * * * * * * * * * * * * * * *
@
@
@
* * * * * * * * * * * * * * * */
const int WIDTH = 800;	//��Ļ���
const int HEIGHT = 600;	//��Ļ�߶�
const int BPP = 32;		//�������



class GameRes{
    // ����ͼƬ������Դ
    // 
    // 
};
/* 
 * 
 * 
 * 
 * 
 * 
 * 
 */
class Game:public TkEvent{		//����Ϸ��
public:
	Game();								//���캯��
	~Game();							//��������
	bool loadGame();					//������Ϸ����ʼ����
	bool startGame();					//��ʼ��Ϸ
	void InitVideo();					//��ʼ������
	bool endGame();				        //��Ϸ��������
	void InitAudio();					//��ʼ����Ч
	
private:
	SDL_Surface* m_Display;				//��ĻDstDvc
	TkScene* m_Scene;
};

