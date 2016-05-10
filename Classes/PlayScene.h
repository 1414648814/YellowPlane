//
//  PlayScene.h
//  YellowPlane
//
//  Created by George on 15/5/31.
//
//
//display the scene
#ifndef __YellowPlane__PlayScene__
#define __YellowPlane__PlayScene__

#include <stdio.h>
#include "cocos2d.h"
#include "PlayLayer.h"
#include "MapManager.h"
#include "StatusLayer.h"
#include "PopLayer.h"
#include "BackgroundLayer.h"


USING_NS_CC;
using namespace cocos2d;
class PlayScene :public Scene
{
public:
    virtual bool init();
    CREATE_FUNC(PlayScene);

private:
    
};

#endif /* defined(__YellowPlane__PlayScene__) */
