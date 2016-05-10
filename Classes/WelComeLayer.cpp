//
//  WelComeLayer.cpp
//  YellowPlane
//
//  Created by George on 15/6/1.
//
//
/*
 欢迎层
 
 
 */
#include "WelComeLayer.h"

bool WelComeLayer::init(){

    if (!Layer::init()) {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    background = ImgLoader::getInstance()->getSpriteFramesByName("deepocean_background_strip.png");
    background->setPosition(visibleSize.width/2 + origin.x,visibleSize.height/2 + origin.y);
    background->setScale(visibleSize.width/background->getContentSize().width, visibleSize.height/background->getContentSize().height);
    this->addChild(background,0);
    
    Sprite * wreckboard = ImgLoader::getInstance()->getSpriteFramesByName("deepocean_background_wreck1.png");
    wreckboard->setPosition(wreckboard->getContentSize().width/4 + visibleSize.width/2,visibleSize.height/2 + origin.y);
    wreckboard->setScale(1.5, visibleSize.height/wreckboard->getContentSize().height);
    this->addChild(wreckboard,1);
    
    shinei = ImgLoader::getInstance()->getSpriteFramesByName("mainMenuBackground.png");
    shinei->setPosition(visibleSize.width/2,visibleSize.height/2);
    shinei->setScale(visibleSize.width/shinei->getContentSize().width, visibleSize.height/shinei->getContentSize().height);
    this->addChild(shinei,3);
    
    Sprite * labellogo = ImgLoader::getInstance()->getSpriteFramesByName("submarine_logo1.png");
    labellogo->setPosition(shinei->getContentSize().width/9, visibleSize.height/2 + origin.y);
    labellogo->setScale(visibleSize.width/shinei->getContentSize().width , visibleSize.height/shinei->getContentSize().height);
    this->addChild(labellogo,2);
    
    this->sand = Sprite::createWithSpriteFrameName("deepocean_foreground_sand1.png");
    this->sand->setPosition(this->sand->getContentSize().width-10.0f,origin.y + this->sand->getContentSize().height/2);
    this->addChild(this->sand,2);
    
    Sprite * scoreboard = ImgLoader::getInstance()->getSpriteFramesByName("menu_best.png");
    scoreboard->setPosition(visibleSize.width/2-scoreboard->getContentSize().width/2,150);
    this->addChild(scoreboard,4);

    this->plane = ImgLoader::getInstance()->getSpriteFramesByName("submarine_mockup_sub.png");
    this->plane->setRotation(-10);
    ActionInterval * up = MoveBy::create(0.4f, Point(0,8));
    ActionInterval * upBack = up->reverse();
    Action *swingAction = RepeatForever::create(Sequence::create(up,upBack, NULL));
    this->plane->runAction(swingAction);
    this->plane->setPosition(Point(origin.x +this->plane->getContentSize().width/2 , origin.y + 100));
    this->addChild(this->plane,5);
    
    this->labelStart = Label::createWithTTF("click here to start", "fonts/Marker Felt.ttf", 25);
    this->labelStart->setPosition(visibleSize.width/2,visibleSize.height/2);
    ActionInterval *scale = ScaleTo::create(2, 2.5);
    ActionInterval *scaleback = ScaleTo::create(2, 1.5);
    Action * action = RepeatForever::create(Sequence::create(scale,scaleback,NULL));
    this->labelStart->runAction(action);
    this->addChild(this->labelStart,6);
    
    //this->setTouchEnabled(true);
    EventDispatcher* eventDispatcher = Director::getInstance()->getEventDispatcher();
    listener= EventListenerTouchOneByOne::create();
    //listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(WelComeLayer::CheckTouchLabelStart,this);
    eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);
    
    return true;
}

void WelComeLayer::StartGameCallBack(){
    this->removeChild(this->labelStart);
    this->schedule(schedule_selector(WelComeLayer::MoveRight), 0.01);
    
}

//检查是否点击label的开始
bool WelComeLayer::CheckTouchLabelStart(Touch *touch,Event *pEvent){
    
    int x = labelStart->getPosition().x-labelStart->getContentSize().width/2;
    int y = labelStart->getPosition().y-labelStart->getContentSize().height/2;
    int width = labelStart->getContentSize().width;
    int height = labelStart->getContentSize().height;
    Rect labelRect(x,y,width,height);
    if (labelRect.containsPoint(touch->getLocationInView())) {
        GameData::getInstance()->setStartPlaying(true);
        StartGameCallBack();
        return true;
    }
    return false;
}

//潜艇向右移动
void WelComeLayer::MoveRight(float dt)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

    int x = this->plane->getPosition().x;
    x += 20;
    Vec2 pos = Vec2(x,100);
    this->plane->setPosition(pos);
    if (plane->getPosition().x>visibleSize.width) {
        auto scene = PlayScene::create();
        TransitionScene *transition = TransitionFade::create(0.01, scene);
        Director::getInstance()->replaceScene(transition);
        //listener->release();
        //plane->release();
        this->unscheduleAllSelectors();
        this->removeAllChildren();
    }
}

