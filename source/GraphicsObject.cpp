/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#include "GraphicsObject.h"


TkGraphicsObject::TkGraphicsObject(void):m_Point(0,0),m_SrcDvc(NULL){
    m_Type = graphicObject;
}
TkGraphicsObject::TkGraphicsObject(const std::string& name):m_Point(0,0),m_Name(name),m_SrcDvc(NULL){
    m_Type = graphicObject;
    load(name);
    //SDLGUI* g_gui;           
    //g_gui=new SDLGUI(SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP,WHITE);
    //g_gui->SetFont( "arial.ttf", ARIAL, 26, TTF_STYLE_NORMAL );
    //atexit( SDL_Quit );
}
TkGraphicsObject::TkGraphicsObject(const std::string& name,const TkPoint& p, bool isText)
    :m_Point(p),m_Name(name),m_SrcDvc(NULL){
    m_Type = graphicObject;
    load(name);
}
void TkGraphicsObject::init(){
}
void TkGraphicsObject::init(TkRect&){
}
TkRect TkGraphicsObject::getRect(){
    return TkRect(m_Point.getX(), m_Point.getY(), m_SrcDvc->w, m_SrcDvc->h);
}
TkGraphicsObject::~TkGraphicsObject(void){
    SDL_FreeSurface(m_SrcDvc);
}
bool TkGraphicsObject::inRect(SDL_Event* e){
    TkRect rect(m_Point.getX(), m_Point.getY(), m_SrcDvc->w, m_SrcDvc->h);
    if (rect.inRect(e->button.x,e->button.y)){ 
        return true;
    }
    return false;
}
void TkGraphicsObject::load(const std::string& name){
    if (m_SrcDvc != NULL){
        SDL_FreeSurface(m_SrcDvc);
    }
    //SDL_Surface* Surf_Temp = NULL;

    //if((m_SrcDvc = SDL_LoadBMP(name.c_str())) == NULL) {
    //     return ;
    // }
    if((m_SrcDvc = IMG_Load(name.c_str())) == NULL) {
        return ;
    }
    //m_SrcDvc = SDL_DisplayFormat(Surf_Temp);
    //setSize(m_SrcDvc->w, m_SrcDvc->h);
    //m_Mask.r = 0x00;
    //m_Mask.g = 0xFF;
    //m_Mask.b = 0x00;
    //SDL_FreeSurface(Surf_Temp);
}
void TkGraphicsObject::setMask(SDL_Color& mask){
    m_Mask = mask;
}
TkEvent TkGraphicsObject::handle(SDL_Event*){
    // highlight, if hovered.
    return TkEvent();
}
//------------------------------------------------------------------------------
void TkGraphicsObject::draw(SDL_Surface* dst){
    SDL_Rect DstR;
    DstR.x = m_Point.getX();
    DstR.y = m_Point.getY();
    DstR.w = m_SrcDvc->w;
    DstR.h = m_SrcDvc->h;

    SDL_Rect SrcR;
    SrcR.x = 0;
    SrcR.y = 0;
    SrcR.w = m_SrcDvc->w;
    SrcR.h = m_SrcDvc->h;

    SDL_BlitSurface(m_SrcDvc, NULL, dst, &DstR);
    SDL_SetColorKey(m_SrcDvc, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(m_SrcDvc->format, m_Mask.r, m_Mask.g, m_Mask.b));
}
void TkGraphicsObject::draw(SDL_Surface* dst, TkRect& rect ){
    SDL_Rect DstR;
    DstR.x = m_Point.getX();
    DstR.y = m_Point.getY();

    SDL_Rect SrcR;
    SrcR.x = rect.getX();
    SrcR.y = rect.getY();
    SrcR.w = rect.getW();
    SrcR.h = rect.getH();

    SDL_BlitSurface(m_SrcDvc, &SrcR, dst, &DstR);
    SDL_SetColorKey(m_SrcDvc, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(m_SrcDvc->format, m_Mask.r, m_Mask.g, m_Mask.b));
}

//