//
//  WelComeLayer.h
//  YellowPlane
//
//  Created by George on 15/6/1.
//
//

#ifndef __YellowPlane__WelComeLayer__
#define __YellowPlane__WelComeLayer__

#include <stdio.h>
#include "cocos2d.h"
#include "YellowPlane.h"
#include "GroundItem.h"
#include "ImgLoader.h"
#include "YellowPlane.h"
#include "GameData.h"
#include "PlayScene.h"
#include "chipmunk.h"
using namespace cocos2d;
using namespace std;

class WelComeLayer : public Layer
{
public:
    virtual bool init();
    CREATE_FUNC(WelComeLayer);
private:
    
    Sprite * sand;
    Sprite * plane;
    Sprite * shinei;
    Sprite * background;
    Label *labelStart;
    
    EventListenerTouchOneByOne *listener;
    
    void StartGameCallBack();
    void MoveRight(float dt);
    bool CheckTouchLabelStart(Touch *touch,Event *pEvent);
};
#endif /* defined(__YellowPlane__WelComeLayer__) */
