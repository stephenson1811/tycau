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
#define deleteWidget(w) {\
	if (w != NULL){\
	delete w;\
	w = NULL;\
	}\
}


TkScene::TkScene(TkScene::Type /*type*/){
	m_Bkgrd=NULL;
	m_Task=NULL;
	m_Status=NULL;
}
TkScene::~TkScene(){
	deleteWidget(m_Bkgrd) ;
	deleteWidget(m_Task);
	deleteWidget(m_Status);
}
void TkScene::draw(SDL_Surface*){
	m_Bkgrd->draw();
}
void TkScene::init(){
	m_Bkgrd = new TkBackGround();
	// load back-ground picture
	m_Bkgrd->load(std::string("graphics\\bk.png"));
	m_Task = new TkTaskWidget ;		    // personnel task widget 
	m_Status = new TkStatusWidget ;		// personnel status
}


