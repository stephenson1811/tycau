/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#include "boost/thread/thread.hpp"
#include "boost/bind.hpp"
#include "Game.h"
/* 
 * 
 * 
 * 
 * 
 * 
 * 
 */

int main(int argc, char* argv[]){

    Game game;
    game.loadGame();
    
    SDL_Event e;
    //show game view thread 
    boost::thread thread(&Game::runGame,&game);
    //thread.start();
    // start a mouse/key events listening loop
    while(game.isRunning()){
        SDL_WaitEvent(&e);
        // process messages in its inner loop.
        game.processEvent(&e);
        //SDL_Delay(5);
    }
    // To play ending animation 
    return 0;
}