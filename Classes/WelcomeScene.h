//
//  WelcomeScene.h
//  YellowPlane
//
//  Created by George on 15/5/31.
//
//

#ifndef __YellowPlane__WelcomeScene__
#define __YellowPlane__WelcomeScene__

#include <stdio.h>
#include "cocos2d.h"
#include "WelComeLayer.h"
USING_NS_CC;
class WelcomeScene : public cocos2d::Layer{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
private:
    void startPlayCallBack(cocos2d::Ref* pSender);
    
};

#endif /* defined(__YellowPlane__WelcomeScene__) */
