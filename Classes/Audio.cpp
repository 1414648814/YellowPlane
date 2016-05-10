//
//  Audio.cpp
//  YellowPlane
//
//  Created by George on 15/5/31.
//
//

#include "Audio.h"
Audio * Audio::audio = NULL;
Audio::Audio(){

}

Audio::~Audio(){


}

bool Audio::init(){
    return true;
}

Audio* Audio::getInstance(){
    if (audio==NULL) {
        audio = new Audio();
        if (!audio->init()) {
            delete audio;
            audio = NULL;
        }
    }
    return audio;
}

void Audio::destroyInstance(){


}

void Audio::LoadAllMusic(){
    SimpleAudioEngine::getInstance()->preloadBackgroundMusic("");
    SimpleAudioEngine::getInstance()->preloadEffect("");
}
