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
    init();
}
TkGraphicsObject::TkGraphicsObject(std::string& name){
    init();
    m_Name = name;
    
    //SDLGUI* g_gui;           
    //g_gui=new SDLGUI(SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP,WHITE);
    //g_gui->SetFont( "arial.ttf", ARIAL, 26, TTF_STYLE_NORMAL );
    //atexit( SDL_Quit );
}
void TkGraphicsObject::init(){
    m_Rect.h = 0;
    m_Rect.w = 0;
    m_Rect.x = 0;
    m_Rect.y = 0;
    m_SrcDvc = NULL;
}
TkGraphicsObject::~TkGraphicsObject(void){
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
void TkGraphicsObject::draw(SDL_Surface* dst){
    if(dst == NULL || m_SrcDvc == NULL) {
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

    SDL_BlitSurface(m_SrcDvc, &SrcR, dst, &DstR);
}
void TkGraphicsObject::draw(SDL_Surface* src,SDL_Surface* dst) {
    if(dst == NULL || src == NULL) {
        return ;
    }

    SDL_Rect DstR;
    DstR.x = m_Rect.x;
    DstR.y = m_Rect.y;
    DstR.w = src->w;
    DstR.h = src->h;

    SDL_Rect SrcR;
    SrcR.x = m_Rect.x;
    SrcR.y = m_Rect.y;
    SrcR.w = src->w;
    SrcR.h = src->h;

    SDL_BlitSurface(src, &SrcR, dst, &DstR);
}

//------------------------------------------------------------------------------
bool TkGraphicsObject::transparent(SDL_Surface* dst, int R, int G, int B) {
    if(dst == NULL) {
        return false;
    }

    SDL_SetColorKey(dst, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(dst->format, R, G, B));

    return true;
}

