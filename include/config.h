/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

// TODO: 在此处引用程序需要的其他头文件
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
//#include "../SDL/SDL_ffmpeg.h"

#pragma comment(lib,"SDL.lib")
#pragma comment(lib,"SDLmain.lib")
#pragma comment(lib,"SDL_image.lib")
#pragma comment(lib,"SDL_ttf.lib")
#pragma comment(lib,"SDL_mixer.lib")
//#pragma comment(lib,"SDL_ffmpeg.lib")
/* 
 * 
 * 
 * 
 * 
 * 
 * 
 */
namespace Gui{
	enum Type{
		TypeMap = 1,    // 很多图元无缝连接，要知道图元大小
		TypeBkGrd = 2,  // 单张图片填充整个客户端
		TypeItem = 3,   // 单张图片，不需知道图元大小
	};
};