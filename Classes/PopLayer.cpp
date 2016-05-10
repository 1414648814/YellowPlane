//
//  PopLayer.cpp
//  YellowPlane
//
//  Created by George on 15/5/31.
//
//
/*
 弹框层
 
 
 */
#include "PopLayer.h"

bool PopLayer::init(){
    
    if (!LayerColor::initWithColor(Color4B(0, 0, 0, 0x80))) {
        return false;
    }
    
    tankuang_touchListener = EventListenerTouchOneByOne::create();
    tankuang_touchListener->onTouchBegan = CC_CALLBACK_2(PopLayer::onTouchBegan, this);
    tankuang_touchListener->onTouchCancelled = CC_CALLBACK_2(PopLayer::onTouchCancelled, this);
    
    tankuang_touchListener->setSwallowTouches(true);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(tankuang_touchListener, this);
    _eventDispatcher->setPriority(tankuang_touchListener, 256);

    return true;
}

bool PopLayer::onTouchBegan(Touch* touch, Event* event){
    m_touchPoint = Director::getInstance()->convertToGL(touch->getLocationInView());
    
    return true;
}

void PopLayer::onTouchCancelled(Touch *touch, Event *event){
    

}

void PopLayer::createPauseLayer(){
    auto size = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    this->menu_topbar = ImgLoader::getInstance()->getSpriteFramesByName("menu_top_bar.png");
    this->addChild(menu_topbar,1);
    this->tankuangbg = ImgLoader::getInstance()->getSpriteFramesByName("menu_current_missions.png");
    this->addChild(tankuangbg,1);
    
    this->menu_topbar->setScale(size.width/this->menu_topbar->getContentSize().width, size.height/this->menu_topbar->getContentSize().height);
    this->menu_topbar->setAnchorPoint(Vec2(0, 0));
    this->menu_topbar->setPosition(Vec2(0, size.height + this->menu_topbar->getContentSize().height));
    MoveBy * movedown = MoveBy::create(0.5, Vec2(0, size.height));
    this->menu_topbar->runAction(Sequence::create(movedown, NULL));
    
    this->tankuangbg->setAnchorPoint(Vec2(0, 0));
    this->tankuangbg->setPosition(Vec2(0, 0));
    MoveTo * moveup = MoveTo::create(0.5, Vec2(size.width/2 - this->tankuangbg->getContentSize().width/2,size.height - this->menu_topbar->getContentSize().height));
    
    this->tankuangbg->runAction(Sequence::create(moveup, NULL));
    
    Scale9Sprite * scale_quit = Scale9Sprite::createWithSpriteFrameName("menu_button_quit.png");
    ControlButton * control_quit = ControlButton::create(scale_quit);
    control_quit->setAnchorPoint(Vec2(0, 0));
    control_quit->setContentSize(Size(214,96));
    control_quit->setPosition(Vec2(0, -control_quit->getContentSize().height/2));
    control_quit->setPreferredSize(Size(control_quit->getContentSize().width,control_quit->getContentSize().height));
    control_quit->addTargetWithActionForControlEvents(this, cccontrol_selector(PopLayer::quitGame), Control::EventType::TOUCH_UP_INSIDE);
    this->tankuangbg->addChild(control_quit,1);
    
    Scale9Sprite * scale_retry = Scale9Sprite::createWithSpriteFrameName("menu_button_retry.png");
    ControlButton * control_retry = ControlButton::create(scale_retry);
    control_retry->setAnchorPoint(Vec2(0, 0));
    control_retry->setContentSize(Size(214,96));
    control_retry->setPosition(Vec2(this->tankuangbg->getContentSize().width/2 - control_retry->getContentSize().width/2, -control_retry->getContentSize().height/2));
    control_retry->setPreferredSize(Size(control_retry->getContentSize().width,control_retry->getContentSize().height));
    control_retry->addTargetWithActionForControlEvents(this, cccontrol_selector(PopLayer::quitGame), Control::EventType::TOUCH_UP_INSIDE);
    this->tankuangbg->addChild(control_retry,1);
    
    Scale9Sprite * scale_resume = Scale9Sprite::createWithSpriteFrameName("menu_button_resume.png");
    ControlButton * control_resume = ControlButton::create(scale_resume);
    control_resume->setAnchorPoint(Vec2(0, 0));
    control_resume->setContentSize(Size(214,96));
    control_resume->setPosition(Vec2(this->tankuangbg->getContentSize().width - control_resume->getContentSize().width, -control_quit->getContentSize().height/2));
    control_resume->setPreferredSize(Size(control_resume->getContentSize().width,control_resume->getContentSize().height));
    control_resume->addTargetWithActionForControlEvents(this, cccontrol_selector(PopLayer::quitGame), Control::EventType::TOUCH_UP_INSIDE);
    this->tankuangbg->addChild(control_resume,1);
    
}

void PopLayer::quitGame(Ref *sender,Control::EventType controlEvent){
    

}

void PopLayer::retryGame(Ref *sender,Control::EventType controlEvent){


}

void PopLayer::resumeGame(Ref *sender,Control::EventType controlEvent){
    Director::getInstance()->resume();
    this->removeAllChildrenWithCleanup(true);
    this->removeFromParentAndCleanup(true);
}



