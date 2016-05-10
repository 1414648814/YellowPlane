//
//  StatusLayer.h
//  YellowPlane
//
//  Created by George on 15/6/1.
//
//

#ifndef __YellowPlane__StatusLayer__
#define __YellowPlane__StatusLayer__

#include <stdio.h>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "ImgLoader.h"
#include "GameData.h"
#include "PopLayer.h"
using namespace cocos2d;

USING_NS_CC;
USING_NS_CC_EXT;

class StatusLayer : public cocos2d::Layer
{
public:
    virtual bool init();
    void addCoin(int addnum);
    void updateMeter(int meter);
    void updateRevive(int reviveIndex,bool isdead);
    
    void pauseGame2(Ref *sender);
    
    CREATE_FUNC(StatusLayer);
private:
    Label * labelCoin;
    Label * labelMeter;
    Sprite * coinSprite;
    Sprite * meterSprite;
    Sprite * reviveSprite01;
    Sprite * reviveSprite02;
    Sprite * reviveSprite03;
    Sprite * reviveSprite04;
    Sprite * reviveSprite05;
    Camera * camera;
    unsigned long int coins;
};

#endif /* defined(__YellowPlane__StatusLayer__) */
