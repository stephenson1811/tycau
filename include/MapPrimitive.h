/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#pragma once
#include "graphicsobject.h"
class TkMapPrimitive :public TkGraphicsObject{
public:
	TkMapPrimitive(void);
	TkMapPrimitive(std::string&);
	~TkMapPrimitive(void);
	void setDstRect(int x, int y, int w, int h);
	//void getSize(SIZE&);
private:
	int m_width; // 图片显示宽度不超过m_width
	int m_height;// 图片显示高度不超过m_height
};

