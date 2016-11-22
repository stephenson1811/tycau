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
/* 
 * buttons with variate performance.
 * such as clicked, pressed, hovered etc..
 * 
 * 
 * 
 * 
 */
class TkButton : public TkGraphicsObject {
    enum BUTTONSTATE{
        BUTTONDOWN,
        BUTTONUP
    };
public:
    TkButton(void);
    TkButton(const std::string&);
    TkButton(const TkRect&,const std::string&,bool isText = false);
    ~TkButton(void);

    void pressed();
    void clicked();
    void hovered();
private:
    std::vector<TkAnimation*> m_Primitives;
};

