/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#include "tkthread.h"
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
    TkThread thread;
    Game game;
    game.loadGame();
    
    SDL_Event e;
    //show game view thread
    thread.start(&game);
    SDL_mutex *lock = SDL_CreateMutex();
    // start a mouse/key events listening loop
    while(game.isRunning()){
        SDL_WaitEvent(&e);
        // process messages in its inner loop.
        SDL_mutexP(lock);
        game.processEvent(&e);
        SDL_mutexV(lock);
        SDL_Delay(100);
    }
    // To play ending animation 
    return 0;
}