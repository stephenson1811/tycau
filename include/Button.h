/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#pragma once

#include "GraphicsObject.h"
#include "Animation.h"
#include <map>
struct ButtonInfo{
    ButtonInfo(void){m_Dir;m_Rect;m_Pieces = 1;}
    ButtonInfo(const char* name,TkRect& rect,int p = 1){m_Dir = name;m_Rect = rect;m_Pieces = p;} 
    ButtonInfo(std::string& name,TkRect& rect,int p = 1){m_Dir = name;m_Rect = rect;m_Pieces = p;} 
    ~ButtonInfo(){}
    std::string m_Dir;
    TkRect m_Rect;
    int m_Pieces;
};
/* 
 * buttons with variate performance.
 * such as clicked, pressed, hovered etc..
 * 
 * 
 * 
 * 
 */
class TkButtonPrimitive : public TkGraphicsObject {
public:
    TkButtonPrimitive(void);
    TkButtonPrimitive(const std::string&);
    TkButtonPrimitive(const std::string&, const TkRect&, int status = 1, bool isText = false);
    ~TkButtonPrimitive(void);
    void draw(SDL_Surface* dst ) ;
    void pressed();
    void clicked();
    void hovered();
    void released();
    void addStatus(TkGui::ControlStatus,int index /*for animation class*/);
    TkEvent handle(SDL_Event*); // make a specific TkEvent according to SDL_Event variable;
private:
    void setStatus(TkGui::ControlStatus);
private:
    std::vector<TkAnimation*> m_Primitives;
    std::map<TkGui::ControlStatus, int> m_StatusMap;
};
class TkButton : public TkObject{
public: 
    TkButton();
    TkButton(std::vector<ButtonInfo> &, int status = 1);
    ~TkButton();
public:
    void draw(SDL_Surface* dst ) ;
    void draw(SDL_Surface* dst, TkRect& );
    bool inRect(SDL_Event*) ;
    void addStatus(TkGui::ControlStatus, int index /*for animation class*/);
private:
    void init(std::vector<ButtonInfo> &, int status );
private:
    std::vector<TkButtonPrimitive*> m_Primitives;
};

/* 
 * use for function and information buttons.
 * they usually located on TopRight corner.
 * 
 * 
 * 
 * 
 */
class TkMenu;
class TkButtonWithMenu : public TkButton{ //
    TkButtonWithMenu();
    ~TkButtonWithMenu();
private:
    // not every button contain menu, only information and function buttons have menu.
    TkMenu* m_Menu; 
};