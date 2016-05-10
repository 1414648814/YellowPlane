//
//  WelcomeScene.cpp
//  YellowPlane
//
//  Created by George on 15/5/31.
//
//

#include "WelcomeScene.h"

Scene * WelcomeScene::createScene()
{
    auto scene = Scene::create();
    auto layer = WelComeLayer::create();
    scene->addChild(layer);
    return scene;
}

bool WelcomeScene::init()
{
    return true;
}

void WelcomeScene::startPlayCallBack(cocos2d::Ref *pSender)
{
    
    
    
}

