//
//  LoadingLayer.cpp
//  YellowPlane
//
//  Created by George on 15/8/16.
//
//
/*
 加载层，进行数据的预处理
 
 */
#include "LoadingLayer.h"

bool LoadingLayer::init(){
    if (!Layer::init()) {
        return false;
    }
    
    this->handleData();
    ImgLoader::getInstance()->addBackgroundFrameCache();
    
    auto size = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    this->bg = Sprite::createWithSpriteFrameName("submarine_mockup_background.png");
    this->bg->setPosition(Vec2(size.width/2, size.height/2));
    
    GameData::getInstance()->setScale(size.width/this->bg->getContentSize().width, size.height/this->bg->getContentSize().height);
    
    this->bg->setScale(GameData::getInstance()->getScaleX(), GameData::getInstance()->getScaleY());
    this->addChild(this->bg,1);
    
    DelayTime * delay02 = DelayTime::create(1.0f);
    this->runAction(Sequence::create(CallFunc::create([&]{
        ImgLoader::getInstance()->addGUIFrameCache();
    }),CallFunc::create([&]{
        ImgLoader::getInstance()->addObstacleFrameCache();
    }),CallFunc::create([&]{
        ImgLoader::getInstance()->addPowerFrameCache();
    }),CallFunc::create([&]{
        ImgLoader::getInstance()->addYelleowplaneFrameCache();
    }),delay02,CallFuncN::create(CC_CALLBACK_1(LoadingLayer::removeLoadingBg, this)),NULL));
    
    return true;
}

void LoadingLayer::handleData(){
    
    GameData::getInstance()->GameInit();
    GameData::getInstance()->setIsFirstPlayGame(SaveData::getInstance()->getIsFisrtPlayGame());
    
    if (!GameData::getInstance()->getIsFirstPlayGame()) {
        
        GameData::getInstance()->setIsPlayBgMusic(true);
        SaveData::getInstance()->setIsPlayBgMusic(true);
        
        GameData::getInstance()->setIsPlayEffect(true);
        SaveData::getInstance()->setIsPlayEffect(true);
        
        GameData::getInstance()->setBestScore(0);
        SaveData::getInstance()->setBestScore(0);
        
        GameData::getInstance()->setStartPlaying(false);
        
    }
    else{
        GameData::getInstance()->setIsPlayBgMusic(SaveData::getInstance()->getIsPlayBgMusic());
        GameData::getInstance()->setIsPlayEffect(SaveData::getInstance()->getIsPlayEffect());
        GameData::getInstance()->setBestScore(SaveData::getInstance()->getBestScore());
        GameData::getInstance()->setStartPlaying(false);
    }
    
}

void LoadingLayer::removeLoadingBg(Node * pNode){
    if (pNode==NULL) {
        return;
    }
    
    Layer * bg = (Layer *)pNode;
    bg->removeAllChildrenWithCleanup(true);
    bg->removeFromParentAndCleanup(true);
    
    auto scene = MenuScene::createScene();
    Director::getInstance()->replaceScene(scene);
    
}

