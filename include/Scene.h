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
#include "GraphicsObject.h"
#include "BackGround.h"
#include "StatusWidget.h"
#include "TaskWidget.h"
/* 
 * basic type.
 * for showing only one bkg piture. such as in house, in castle, in battle.
 * integrate image, music and etc.. 
 * change scene type for switch.
 * 
 * 
 */
class TkScene{
public:
    enum Type{
        InHouse = 1,
    };
public:
    TkScene(TkScene::Type);
    ~TkScene();
    void draw();
    void draw(SDL_Surface*);
    void init(SDL_Surface*d = 0);
private:
    TkBackGround* m_Bkgrd;           // back-ground picyture
    TkTaskWidget* m_Task;            // personnel task widget 
    TkStatusWidget* m_Status;        // personnel status
    SDL_Surface* m_DstDvc;
};
/* 
 * the background composed by many pictures.
 * such as in field, in war.
 * 
 * 
 * 
 * 
 */
class TkMapScene{
};
/* 
 * 
 * 
 * 
 * 
 * 
 * 
 */
class TkOpeningScene{
};
/* 
 * for selecting a role to play
 * 
 * 
 * 
 * 
 * 
 */
class TkSelectScene{
};