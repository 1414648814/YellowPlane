//
//  PopLayer.h
//  YellowPlane
//
//  Created by George on 15/5/31.
//
//
//store pop layer ,include win and lose
#ifndef __YellowPlane__PopLayer__
#define __YellowPlane__PopLayer__

#include <stdio.h>
#include "cocos2d.h"
#include "ImgLoader.h"
#include "cocos-ext.h"
using namespace cocos2d;
USING_NS_CC;
USING_NS_CC_EXT;

class PopLayer : public LayerColor{
public:
    virtual bool init();
    virtual bool onTouchBegan(Touch* touch, Event* event);
    virtual void onTouchCancelled(Touch *touch, Event *event);
    
    void createPauseLayer();
    void quitGame(Ref *sender,Control::EventType controlEvent);
    void retryGame(Ref *sender,Control::EventType controlEvent);
    void resumeGame(Ref *sender,Control::EventType controlEvent);
    
    CREATE_FUNC(PopLayer);
    
private:
    Point m_touchPoint;
    EventListenerTouchOneByOne * tankuang_touchListener;
  
    Sprite * menu_topbar;
    Sprite * tankuangbg;
    
};

#endif /* defined(__YellowPlane__PopLayer__) */
