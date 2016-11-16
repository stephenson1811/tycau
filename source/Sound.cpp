/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#include "Sound.h"
SoundManager::SoundManager(){}
SoundManager::~SoundManager(){}
int SoundManager::init(){
    const int    TMP_FREQ = MIX_DEFAULT_FREQUENCY;   
    const Uint16 TMP_FORMAT = MIX_DEFAULT_FORMAT;   
    const int    TMP_CHAN = 2;   
    const int    TMP_CHUNK_SIZE = 512;   

    return Mix_OpenAudio(TMP_FREQ,TMP_FORMAT,TMP_CHAN,TMP_CHUNK_SIZE);   
}   

int SoundManager::play(std::string& name){
    Mix_Music *mix_music;   

    if((mix_music = Mix_LoadMUS(name.c_str())) == NULL)   
    {   
        std::cout<<"call Mix_LoadMUS failed:"<<Mix_GetError()<<std::endl;   
        return -1;   
    }   

    if(Mix_PlayMusic(mix_music,-1) == -1)   
    {   
        std::cout<<"call Mix_PlayMusic failed"<<std::endl;   
        return -1;   
    }   
    std::cout<<"after call Mix_PlayMusic"<<std::endl;   

    return 0;   
}  

void SoundManager::MusicEffect(int type){
    //Mix_PlayChannel( -1, type, 0 );
}