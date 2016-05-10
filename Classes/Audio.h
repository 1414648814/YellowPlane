//
//  Audio.h
//  YellowPlane
//
//  Created by George on 15/5/31.
//
//
//store the audio info
#ifndef __YellowPlane__Audio__
#define __YellowPlane__Audio__

#include <stdio.h>
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
class Audio{
public:
    Audio();
    ~Audio();
    virtual bool init();
    static Audio* getInstance();
    static void destroyInstance();
    void LoadAllMusic();
private:
    static Audio *audio;
};

#endif /* defined(__YellowPlane__Audio__) */
