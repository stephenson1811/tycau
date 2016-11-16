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

// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�
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
		TypeMap = 1,    // �ܶ�ͼԪ�޷����ӣ�Ҫ֪��ͼԪ��С
		TypeBkGrd = 2,  // ����ͼƬ��������ͻ���
		TypeItem = 3,   // ����ͼƬ������֪��ͼԪ��С
	};
};