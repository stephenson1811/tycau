/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */

#include "scene.h"
#include "Sound.h"

TkMapScene::TkMapScene(){}
TkMapScene::TkMapScene(TkType::SceneType){}
TkMapScene::~TkMapScene(){}


void TkMapScene::run(){}
void TkMapScene::init(SDL_Surface*d ){}
TkObject* TkMapScene::whichControl(SDL_Event*){ // which control/picture is selected, pressed or clicked.
    return NULL;
}
void TkMapScene::dispatch(SDL_Event*){}