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
	int m_width; // ͼƬ��ʾ��Ȳ�����m_width
	int m_height;// ͼƬ��ʾ�߶Ȳ�����m_height
};

