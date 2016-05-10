//
//  PlayScene.cpp
//  YellowPlane
//
//  Created by George on 15/5/31.
//
//

#include "PlayScene.h"
USING_NS_CC;

bool PlayScene::init()
{
//    ImgLoader::getInstance()->removeUnusedFrameCache();
    ImgLoader::getInstance()->removeUnusedTexture();
    
    if (Scene::initWithPhysics()) {
        //the background layer,just include the moving background
        auto backgroundLayer = BackgroundLayer::create();
        if (backgroundLayer) {
            backgroundLayer->setTag(TAG_PlayLayer);
            this->addChild(backgroundLayer,0);
        }
        //the player layer ,include the player
        auto playeLayer = PlayLayer::create();
        if (playeLayer) {
            playeLayer->setTag(TAG_PlayLayer);
            this->addChild(playeLayer,1);
        }
        //the status layer ,include status info, score life
        auto statusLayer = StatusLayer::create();
        if (statusLayer) {
            statusLayer->setTag(TAG_StatusLayer);
            this->addChild(statusLayer,2);
        }
        
        return true;
    }
    return false;
}

