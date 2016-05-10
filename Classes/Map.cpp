//
//  Map.cpp
//  YellowPlane
//
//  Created by George on 15/6/3.
//
//
/*
 地图类
 
 
 */
#include "Map.h"

MAP::MAP(int index){
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

    this->initWithSpriteFrameName("deepocean_foreground_sand1.png");
    this->setAnchorPoint(Point(0, 0));
    this->setTag(3);
    this->setPosition(Point(this->getContentSize().width * index, 0));
    
    this->sandy = this->getContentSize().height;
    GameData::getInstance()->setSandHeight(this->sandy);
    
    this->visibleWidth = visibleSize.width;
    
}

MAP::~MAP(){
    
}

bool MAP::init(){
    return true;
}

MAP* MAP::create(int index){
    MAP *map = new MAP(index);
    map->autorelease();
    return map; 
}

float MAP::getVisibleWidth(){
    return this->visibleWidth;
}

void MAP::loadImg(int index){
    
    this->initWithSpriteFrameName("deepocean_foreground_sand1.png");
    this->setAnchorPoint(Point(0, 0));
    this->setPosition(Point(this->getContentSize().width * index, 0));

}
