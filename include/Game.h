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
#include "Scene.h"

/* 
 * 
 * 
 * 
 * 
 * 
 * 
 */
class Game{
public:
    Game();
    ~Game();
    bool isRunning(){return m_Running;}
    bool loadGame();                    //load game, the initial view
    bool runGame();                    //start game
    bool endGame();                        //end game
    void processEvent(SDL_Event*);         // process events        
private:
    void initVideo();                    //init view
    void initAudio();                    //init audio
    void changeScene(TkType::SceneType); // player in another place, scene must be changed.
    void pushSDLEvent(int type, int usercode);
private:
    SDL_Surface* m_Display;                //destination screen device
    TkAbstractScene* m_Scene;
    int WIDTH;    // for screen
    int HEIGHT;    
    int BPP;
    bool m_Running;
};

