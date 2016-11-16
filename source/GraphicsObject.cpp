/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#include "GraphicsObject.h"


TkGraphicsObject::TkGraphicsObject(void){
    m_Rect.h = 0;
    m_Rect.w = 0;
    m_Rect.x = 0;
    m_Rect.y = 0;
}
TkGraphicsObject::TkGraphicsObject(std::string& name){
    m_Rect.h = 0;
    m_Rect.w = 0;
    m_Rect.x = 0;
    m_Rect.y = 0;
    m_Name = name;
    //SDL_Flip(m_Display);
    //SDL_Delay(1000);        //退出时延
    //SDL_ShowCursor(1);        //允许光标
    //SDLGUI* g_gui;            //显示得分界面
    //g_gui=new SDLGUI(SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP,WHITE);
    //g_gui->SetFont( "arial.ttf", ARIAL, 26, TTF_STYLE_NORMAL );
    //atexit( SDL_Quit );
}
TkGraphicsObject::~TkGraphicsObject(void){
    //SDL_FreeSurface(m_DstDvc);
    SDL_FreeSurface(m_SrcDvc);
}
void TkGraphicsObject::load(std::string& name){
    if (m_SrcDvc != NULL){
        SDL_FreeSurface(m_SrcDvc);
    }
    SDL_Surface* Surf_Temp = NULL;

    if((Surf_Temp = SDL_LoadBMP(name.c_str())) == NULL) {
         return ;
     }
    //if((Surf_Temp = IMG_Load(File)) == NULL) {
    //    return NULL;
    //}
    m_SrcDvc = SDL_DisplayFormat(Surf_Temp);
    SDL_FreeSurface(Surf_Temp);
}

//------------------------------------------------------------------------------
void TkGraphicsObject::draw(){
    //if (!m_Image.IsNull()){
        //m_Image.BitBlt(pDC->m_hDC, m_x, m_y, SRCCOPY);
        //m_Image.StretchBlt(pDC->m_hDC, m_x, m_y, m_width, m_height,
        //    100, 150, 100, 150, SRCCOPY );
        //m_Image.Draw(pDC->m_hDC, m_x, m_y);
    //}
    if(m_DstDvc == NULL || m_SrcDvc == NULL) {
        return ;
    }

    SDL_Rect DstR;
    DstR.x = m_Rect.x;
    DstR.y = m_Rect.y;

    SDL_Rect SrcR;
    SrcR.x = m_Rect.x;
    SrcR.y = m_Rect.y;
    SrcR.w = m_SrcDvc->w;
    SrcR.h = m_SrcDvc->h;

    SDL_BlitSurface(m_SrcDvc, &SrcR, m_DstDvc, &DstR);
}
void TkGraphicsObject::draw(SDL_Surface* Surf_Src) {
    if(m_DstDvc == NULL || Surf_Src == NULL) {
        return ;
    }

    SDL_Rect DstR;
    DstR.x = m_Rect.x;
    DstR.y = m_Rect.y;

    SDL_Rect SrcR;
    SrcR.x = m_Rect.x;
    SrcR.y = m_Rect.y;
    SrcR.w = Surf_Src->w;
    SrcR.h = Surf_Src->h;

    SDL_BlitSurface(Surf_Src, &SrcR, m_DstDvc, &DstR);
}

//------------------------------------------------------------------------------
bool TkGraphicsObject::transparent(SDL_Surface* Surf_Dest, int R, int G, int B) {
    if(Surf_Dest == NULL) {
        return false;
    }

    SDL_SetColorKey(Surf_Dest, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(Surf_Dest->format, R, G, B));

    return true;
}

