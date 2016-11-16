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
/* 
 * 
 * 
 * 
 * 
 * 
 * 
 */
class TkGraphicsObject{
public:
    TkGraphicsObject(void);
    TkGraphicsObject(std::string&);
    TkGraphicsObject(SDL_Surface*,std::string&);
    ~TkGraphicsObject(void);
public:
    void draw();
    void draw(SDL_Surface* Surf_Src );
    void load(std::string&);
    void setCoord(SDL_Rect & r){m_Rect = r;}
    bool transparent(SDL_Surface* Surf_Dest, int R, int G, int B);
protected:
    std::string m_Name; // ����ʾͼƬ��
    SDL_Rect m_Rect; // ����ʾͼƬ������
    SDL_Surface* m_DstDvc; // Ŀ����ʾ����
    SDL_Surface* m_SrcDvc; // Ŀ��ͼԪ
};

