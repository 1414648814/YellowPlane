//
//  MenuScene.cpp
//  YellowPlane
//
//  Created by George on 15/6/1.
//
//

#include "MenuScene.h"

Scene * MenuScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MenuScene::create();
    scene->addChild(layer);
    return scene;
}

bool MenuScene::init()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Sprite* homeBg = Sprite::createWithSpriteFrameName("submarine_mockup_background.png");
    homeBg->setPosition(visibleSize.width/2 + origin.x,visibleSize.height/2 + origin.y);
    homeBg->setScale(visibleSize.width/homeBg->getContentSize().width, visibleSize.height/homeBg->getContentSize().height);

    MenuItemImage* homePlay = MenuItemImage::create("res/GUI/home_play.png", "res/GUI/home_play.png", CC_CALLBACK_1(MenuScene::homePlayCallBack, this));
    
    Menu * menu = Menu::create(homePlay,NULL);
    menu->setPosition(visibleSize.width/2 ,visibleSize.height/2);
    this->addChild(homeBg,0);
    this->addChild(menu,1);
    
    return true;
}

void MenuScene::homePlayCallBack(cocos2d::Ref *pSender)
{
    auto scene = PlayScene::create();
    Director::getInstance()->replaceScene(scene);
    this->removeAllChildren();
}
