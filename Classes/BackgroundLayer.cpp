//
//  BackgroundLayer.cpp
//  YellowPlane
//
//  Created by George on 15/6/8.
//
//
/*
 背景层
 
 
 */
#include "BackgroundLayer.h"

bool BackgroundLayer::init(){
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
 
    this->bgSprite = ImgLoader::getInstance()->getSpriteFramesByName("deepocean_background_strip.png");
    bgSprite->setScale(visibleSize.width/bgSprite->getContentSize().width, visibleSize.height/bgSprite->getContentSize().height);
    this->bgSprite->setPosition(origin.x + visibleSize.width/2,origin.y + visibleSize.height/2);
    this->addChild(this->bgSprite);
    
    
//    this->bubble_particle = CCParticleSystemQuad::create("res/PowerUps/bubble_particle.plist");
//    this->bubble_particle->retain();
//    ParticleBatchNode *batch = ParticleBatchNode::createWithTexture(this->bubble_particle->getTexture());
//    batch->addChild(bubble_particle);
//    this->bubble_particle->setAutoRemoveOnFinish(false);
//    this->addChild(batch);
//    batch->setPosition(0,100);
    
    this->camera= Camera::create();
    this->camera->setCameraFlag(CameraFlag::USER1);
    this->addChild(camera);
    this->setCameraMask(2);  //设置为可见
    
    return true;
}

void BackgroundLayer::updateMeter(int px)
{

}