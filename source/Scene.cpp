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

void TkAbstractScene::init(SDL_Surface*d ){ 
    if (d != NULL){
        //m_DstDvc = d;
    }
}
void TkAbstractScene::pushSDLEvent(int type, int usercode){
    SDL_Event e;
    e.type = type;
    e.user.code = usercode;
    SDL_PushEvent(&e);
}
TkAbstractScene* TkSceneFactory::getScene(TkType::SceneType type,SDL_Surface* d){
    TkAbstractScene* scene = NULL;
    switch(type){
    case TkType::InHouse:
        scene = new TkSingleScene(type);
        break;
    case TkType::InGiantMap:
        scene = new TkMapScene(type);
        break;
    }
    scene->init(d);
    return scene;
}





