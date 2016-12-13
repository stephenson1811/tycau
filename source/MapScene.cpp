/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */

#include "scene.h"


TkMapScene::TkMapScene(){
    m_LeftButonPressed = false;
}
TkMapScene::TkMapScene(TkType::SceneType type){
    m_LeftButonPressed = false;
    m_SceneType = type;
}
TkMapScene::~TkMapScene(){
    delete m_Map;
    for (std::vector<TkObject*>::iterator it = m_Members.begin();
        it != m_Members.end(); it ++){
            delete (*it);
            (*it) = NULL;
    }
}


void TkMapScene::run(SDL_Surface* d){
    if(m_Bkgrd){ 
        m_Bkgrd->draw(d);
    }
    if(m_Map){  
        m_Map->draw(d);
    }
    if(m_GoHome){  
        m_GoHome->draw(d);
    }
    if(m_GoTo){  
        m_GoTo->draw(d);
    }
    SDL_Flip(d);
}
void TkMapScene::init(SDL_Surface*d ){
    TkAbstractScene::init(d);
    m_Map = new TkMap();
    m_Bkgrd = new TkBackGround(std::string("D:\\data\\bk.bmp")); 
    m_Members.push_back(m_Map);
    m_Status = new TkStatusWidget;

    std::vector< std::string> vbi ;
    vbi.push_back("D:\\data\\UI\\Parts_N_136-1.bmp");
    vbi.push_back("D:\\data\\UI\\Parts_N_137-1.bmp");
    vbi.push_back("D:\\data\\UI\\Parts_N_138-1.bmp");
    m_GoHome = new TkButton (vbi,TkRect(400,300,100,50/*722,545,96,40*/),4);// button
    m_GoHome->setObjectName(std::string("goHome"));
    m_GoHome->addStatus(TkGui::click,2);
    m_GoHome->addStatus(TkGui::released,3);
    m_Members.push_back(m_GoHome);

    vbi.clear();
    vbi.push_back("D:\\data\\UI\\Parts_N_145-1.bmp");
    vbi.push_back("D:\\data\\UI\\Parts_N_146-1.bmp");
    vbi.push_back("D:\\data\\UI\\Parts_N_147-1.bmp");
    m_GoTo = new TkButton (vbi,TkRect(200,300,100,50/*722,545,96,40*/),4);// button, go to anywhere specific
    m_GoTo->addStatus(TkGui::click,2);
    m_GoTo->addStatus(TkGui::released,3);
    m_Members.push_back(m_GoTo);

    vbi.clear();
    vbi.push_back("D:\\data\\UI\\Parts_N_145-1.bmp");
    vbi.push_back("D:\\data\\UI\\Parts_N_146-1.bmp");
    vbi.push_back("D:\\data\\UI\\Parts_N_147-1.bmp");
    m_Wait = new TkButton (vbi,TkRect(200,400,100,50/*722,545,96,40*/),4);// button, waiting
    m_Wait->addStatus(TkGui::click,2);
    m_Wait->addStatus(TkGui::released,3);
    m_Members.push_back(m_Wait);
}
TkObject* TkMapScene::whichControl(SDL_Event* e){ // which control/picture is selected, pressed or clicked.
    TkGraphicsObject* control = NULL;
    for (std::vector<TkObject*>::iterator it = m_Members.begin();
        it != m_Members.end(); it ++){
            if ((*it)->inRect(e)){
                if((*it)->getType() == mapWidget||(*it)->getType() ==mapPrimitive ){
                    TkMap* m = dynamic_cast<TkMap*> (*it);
                    TkPrimitive* mp = m->whichMapPrimitive(e);
                    return static_cast<TkObject*>(mp); 
                }else if((*it)->getType() == buttonWidget){
                    return static_cast<TkObject*>(*it);
                }
            }
    }
    return NULL;
}
void TkMapScene::moveMap(SDL_MouseMotionEvent& me){
    if (m_LeftButonPressed){ // could move map
        m_Map->move(me.xrel, me.yrel);
    }
}
void TkMapScene::moveMap(int x, int y){
    m_Map->move(x, y);
}
// a msg dispatcher/processor
void TkMapScene::dispatch(SDL_Event* e ){
    TkObject* control = whichControl(e);
    if (!control){
        return; 
    }
    if (control->getType() == buttonWidget){
        TkButton* b = dynamic_cast<TkButton*>(control);
        TkEvent t = b->handle(e);
        pushSDLEvent(t.EventType,t.UserCode);  
    }else if(control->getType() == mapWidget || control->getType() == mapPrimitive ){
        switch(e->type){
            case SDL_MOUSEMOTION:
                switch(e->button.button) {
                    case SDL_BUTTON_LEFT: { // move the map
                        moveMap(e->motion);
                        //std::cout<<"xrel="<<e->motion.xrel<<",yrel="<<e->motion.yrel<<std::endl;
                        break;
                    }
                }
                //if (e->motion.x < 100){
                //    moveMap(-10,0);
                //}
                break;
            case SDL_MOUSEBUTTONUP:
                switch(e->button.button) {
                    case SDL_BUTTON_LEFT: { // move the map
                        m_LeftButonPressed = false;
                        std::cout<<"leftreleased,xrel="<<e->motion.xrel<<",yrel="<<e->motion.yrel<<std::endl;
                        break;
                    }
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                switch(e->button.button) {
                    case SDL_BUTTON_LEFT: { // move the map
                        m_LeftButonPressed = true;
                        //std::cout<<"leftpressed,xrel="<<e->motion.xrel<<",yrel="<<e->motion.yrel<<std::endl;
                        break;
                    }
                }
                break;
        }
    }
}








