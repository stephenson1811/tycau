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
class Game{
public:
	Game();
	~Game();
	bool loadGame();					//load game, the initial view
	bool startGame();					//start game
	void InitVideo();					//init view
	bool endGame();				        //end game
	void InitAudio();					//init audio
	
private:
	SDL_Surface* m_Display;				//destination screen device
	TkScene* m_Scene;
};

