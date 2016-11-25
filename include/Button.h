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
/* 
 * buttons with variate performance.
 * such as clicked, pressed, hovered etc..
 * 
 * 
 * 
 * 
 */
class TkButton : public TkGraphicsObject {
public:
    TkButton(void);
    TkButton(const std::string&);
    TkButton(const TkRect&, const std::string&, bool isText = false);
    ~TkButton(void);

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