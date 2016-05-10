//
//  StatusLayer.cpp
//  YellowPlane
//
//  Created by George on 15/6/1.
//
//
/*
 状态信息层
 
 
 */
#include "StatusLayer.h"

bool StatusLayer::init(){
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    //coin
    this->coinSprite = ImgLoader::getInstance()->getSpriteFramesByName("menu_shop_top_coin_icon.png");
    this->coinSprite->setPosition(Vec2(origin.x + this->coinSprite->getContentSize().width, origin.y + visibleSize.height-this->coinSprite->getContentSize().height));
    this->addChild(this->coinSprite,1);
    
    this->labelCoin = Label::createWithTTF("0", "fonts/Marker Felt.ttf", 40);
    this->labelCoin->setPosition(Point(this->coinSprite->getPositionX() + 60, this->coinSprite->getPositionY()));
    this->addChild(this->labelCoin,1);
    //meter
    this->meterSprite = ImgLoader::getInstance()->getSpriteFramesByName("meter.png");
    this->meterSprite->setPosition(Vec2(origin.x + this->meterSprite->getContentSize().width, origin.y + this->coinSprite->getPositionY() - this->meterSprite->getContentSize().height));
    this->addChild(meterSprite);
    this->labelMeter = Label::createWithTTF("0", "fonts/Marker Felt.ttf", 40);
    this->labelMeter->setPosition(Point(this->meterSprite->getPositionX() + 100, this->meterSprite->getPositionY()));
    this->addChild(this->labelMeter);
    //revive
    this->reviveSprite01 = ImgLoader::getInstance()->getSpriteFramesByName("revive_icon.png");
    this->reviveSprite01->setPosition(Vec2(visibleSize.width - this->reviveSprite01->getContentSize().width,origin.y+visibleSize.height - this->reviveSprite01->getContentSize().height));
    this->reviveSprite01->setVisible(true);
    this->addChild(reviveSprite01,1);
    
    this->reviveSprite02 = ImgLoader::getInstance()->getSpriteFramesByName("revive_icon.png");
    this->reviveSprite02->setPosition(Vec2(this->reviveSprite01->getPositionX() - this->reviveSprite02->getContentSize().width,origin.y+visibleSize.height - this->reviveSprite02->getContentSize().height));
    this->reviveSprite02->setVisible(true);
    this->addChild(reviveSprite02,1);
    
    this->reviveSprite03 = ImgLoader::getInstance()->getSpriteFramesByName("revive_icon.png");
    this->reviveSprite03->setPosition(Vec2(this->reviveSprite02->getPositionX() - this->reviveSprite03->getContentSize().width,origin.y+visibleSize.height - this->reviveSprite03->getContentSize().height));
    this->reviveSprite03->setVisible(true);
    this->addChild(reviveSprite03,1);
    
    this->reviveSprite04 = ImgLoader::getInstance()->getSpriteFramesByName("revive_icon.png");
    this->reviveSprite04->setPosition(Vec2(this->reviveSprite03->getPositionX() - this->reviveSprite04->getContentSize().width,origin.y+visibleSize.height - this->reviveSprite04->getContentSize().height));
    this->reviveSprite04->setVisible(true);
    this->addChild(reviveSprite04,1);
    
    this->reviveSprite05 = ImgLoader::getInstance()->getSpriteFramesByName("revive_icon.png");
    this->reviveSprite05->setPosition(Vec2(this->reviveSprite04->getPositionX() - this->reviveSprite01->getContentSize().width,origin.y+visibleSize.height - this->reviveSprite05->getContentSize().height));
    this->reviveSprite05->setVisible(true);
    this->addChild(reviveSprite05,1);
    
    MenuItemImage * pause_img = MenuItemImage::create("res/GUI/menu_square_backdrop.png", "res/GUI/menu_square_backdrop.png", CC_CALLBACK_1(StatusLayer::pauseGame2, this));
    
    Menu * pause_menu = Menu::create(pause_img, NULL);
    pause_menu->setAnchorPoint(Vec2(0, 0));
    pause_menu->setPosition(Vec2(origin.x + visibleSize.width - pause_img->getContentSize().width,origin.y + visibleSize.height -pause_img->getContentSize().height * 2));
    this->addChild(pause_menu,1);
    
    //camera
    this->camera= Camera::create();
    this->camera->setCameraFlag(CameraFlag::USER3);
    this->addChild(camera);
    this->setCameraMask(6);  //设置为可见
    
    return true;
}

//add the coin
void StatusLayer::addCoin(int addnum){
    coins += addnum;
    this->labelCoin->setString(CCString::createWithFormat("%ld",coins)->getCString());
}

//add the meter
void StatusLayer::updateMeter(int meter){
    this->labelMeter->setString(CCString::createWithFormat("%d:%s", meter/10, "M")->getCString());
}

//update the revive's info ,include the add an del
void StatusLayer::updateRevive(int reviveIndex,bool isdead){
    if(isdead == true){
        if (reviveIndex==1) {
            this->reviveSprite01->setVisible(false);
        }
        else if(reviveIndex==2){
            this->reviveSprite02->setVisible(false);
        }
        else if(reviveIndex==3){
            this->reviveSprite03->setVisible(false);
        }
        else if(reviveIndex==4){
            this->reviveSprite04->setVisible(false);
        }
        else{
            this->reviveSprite05->setVisible(false);
        }
    }
    else{
        if (reviveIndex==1) {
            this->reviveSprite01->setVisible(true);
        }
        else if(reviveIndex==2){
            this->reviveSprite02->setVisible(true);
        }
        else if(reviveIndex==3){
            this->reviveSprite03->setVisible(true);
        }
        else if(reviveIndex==4){
            this->reviveSprite04->setVisible(true);
        }
        else{
            this->reviveSprite05->setVisible(true);
        }
    
    }
}

void StatusLayer::pauseGame2(Ref *sender){
    Director::getInstance()->pause();
    GameData::getInstance()->setGameStatus(Game_Resume);
    
    auto size = Director::getInstance()->getVisibleSize();
    
    if (Director::getInstance()->isPaused()) {
        PopLayer * layer = PopLayer::create();
        layer->setAnchorPoint(Vec2(0, 0));
        layer->setPosition(Vec2(0, 0));
        layer->setContentSize(Size(size.width,size.height));
        layer->createPauseLayer();
        
        this->getParent()->addChild(layer,8);
    }
    
}


