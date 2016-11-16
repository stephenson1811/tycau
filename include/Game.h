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
const int WIDTH = 800;	//屏幕宽度
const int HEIGHT = 600;	//屏幕高度
const int BPP = 32;		//像素深度



class GameRes{
    // 加载图片动画资源
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
class Game:public TkEvent{		//主游戏类
public:
	Game();								//构造函数
	~Game();							//析构函数
	bool loadGame();					//载入游戏：起始画面
	bool startGame();					//开始游戏
	void InitVideo();					//初始化参数
	bool endGame();				        //游戏结束画面
	void InitAudio();					//初始化音效
	
private:
	SDL_Surface* m_Display;				//屏幕DstDvc
	TkScene* m_Scene;
};

