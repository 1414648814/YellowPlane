//
//  BackgroundLayer.h
//  YellowPlane
//
//  Created by George on 15/6/8.
//
//

#ifndef __YellowPlane__BackgroundLayer__
#define __YellowPlane__BackgroundLayer__

#include <stdio.h>
#include "ImgLoader.h"
using namespace cocos2d;

USING_NS_CC;
class BackgroundLayer : public Layer{
public:
    virtual bool init();
    void updateMeter(int px);
    CREATE_FUNC(BackgroundLayer);
private:
    Sprite* bgSprite;
    Camera* camera;
    ParticleSystem * bubble_particle;
};

#endif /* defined(__YellowPlane__BackgroundLayer__) */
