//
//  GroundItemGroup.cpp
//  YellowPlane
//
//  Created by George on 15/6/9.
//
//
/*
 将多个item进行装到group中
 
 
 */
#include "GroundItemGroup.h"

GroundItemGroup::GroundItemGroup(){

    
}
GroundItemGroup::~GroundItemGroup(){


}

void GroundItemGroup::updateForeGroundGroup1Pos(SpriteBatchNode * node,int mapIndex, float mapWidth){
    
    int randomCoinFactor = CCRANDOM_0_1()*(CCRANDOM_0_1()*5 + 1);

    float startx = randomCoinFactor + mapWidth * mapIndex;
    
    float snailHeight = GameData::getInstance()->getSandHeight()/2;
    float plantHeight = GameData::getInstance()->getSandHeight()/2;
    float stoneHeight = GameData::getInstance()->getSandHeight()/2;
    float xIncrement = 150;
    
    Sprite *item = ForeGroundItem::create(Fore_Snail);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + xIncrement,snailHeight));
    node->addChild(item,2);
    fore_elements1.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Plant1);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 2 * xIncrement,plantHeight));
    node->addChild(item,2);
    fore_elements1.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Plant2);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 3 * xIncrement,plantHeight));
    node->addChild(item,2);
    fore_elements1.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Plant3);
    item->setPosition(Vec2(startx + 4 * xIncrement,plantHeight));
    item->setTag(mapIndex);
    node->addChild(item,2);
    fore_elements1.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone1);
    item->setPosition(Vec2(startx + 5 * xIncrement,stoneHeight));
    item->setTag(mapIndex);
    node->addChild(item,2);
    fore_elements1.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone3);
    item->setPosition(Vec2(startx + 6 * xIncrement,stoneHeight));
    item->setTag(mapIndex);
    node->addChild(item,2);
    fore_elements1.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone4);
    item->setPosition(Vec2(startx + 7 * xIncrement,stoneHeight));
    item->setTag(mapIndex);
    node->addChild(item,2);
    fore_elements1.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone4);
    item->setPosition(Vec2(startx + 8 * xIncrement,stoneHeight));
    item->setTag(mapIndex);
    node->addChild(item,2);
    fore_elements1.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone6);
    item->setPosition(Vec2(startx + 9 * xIncrement,stoneHeight));
    item->setTag(mapIndex);
    node->addChild(item,2);
    fore_elements1.push_back(item);
    delobjects.push_back(item);

}

void GroundItemGroup::updateForeGroundGroup2Pos(SpriteBatchNode * node,int mapIndex, float mapWidth){
    int randomCoinFactor = CCRANDOM_0_1()*(CCRANDOM_0_1()*5 + 1);
    
    float startx = randomCoinFactor + mapWidth * mapIndex;
    
    float chestHeight = GameData::getInstance()->getSandHeight()/2;
    float plantHeight = GameData::getInstance()->getSandHeight()/2;
    float stoneHeight = GameData::getInstance()->getSandHeight()/2;
    float xIncrement = 140;
    
    Sprite *item = NULL;
    item = ForeGroundItem::create(Fore_Plant2);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + xIncrement,plantHeight));
    node->addChild(item,2);
    fore_elements2.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Plant3);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 2* xIncrement,plantHeight));
    node->addChild(item,2);
    fore_elements2.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone1);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 3 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements2.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone2);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 4 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements2.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone2);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 5 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements2.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone3);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 6 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements2.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Chest);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 7 * xIncrement,chestHeight));
    node->addChild(item,2);
    fore_elements2.push_back(item);
    delobjects.push_back(item);
    
}

void GroundItemGroup::updateForeGroundGroup3Pos(SpriteBatchNode * node,int mapIndex, float mapWidth){
    int randomCoinFactor = CCRANDOM_0_1()*(CCRANDOM_0_1()*5 + 1);
    
    float startx = randomCoinFactor + mapWidth * mapIndex;
    
    float sailHeight = GameData::getInstance()->getSandHeight()/2;
    float plantHeight = GameData::getInstance()->getSandHeight()/2;
    float stoneHeight = GameData::getInstance()->getSandHeight()/2;
    float xIncrement = 135;
    
    Sprite *item = NULL;
    item = ForeGroundItem::create(Fore_Plant1);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 1 * xIncrement,plantHeight));
    node->addChild(item,2);
    fore_elements3.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Plant2);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 2 * xIncrement,plantHeight));
    node->addChild(item,2);
    fore_elements3.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Plant3);
    item->setPosition(Vec2(startx + 3 * xIncrement,plantHeight));
    item->setTag(mapIndex);
    node->addChild(item,2);
    fore_elements3.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone2);
    item->setPosition(Vec2(startx + 4 * xIncrement,stoneHeight));
    item->setTag(mapIndex);
    node->addChild(item,2);
    fore_elements3.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone1);
    item->setPosition(Vec2(startx + 5 * xIncrement,stoneHeight));
    item->setTag(mapIndex);
    node->addChild(item,2);
    fore_elements3.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone3);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 6 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements3.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone4);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 7 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements3.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone4);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 8 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements3.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone4);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 9 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements3.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone6);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 10 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements3.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Snail);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 11 * xIncrement,sailHeight));
    node->addChild(item,2);
    fore_elements3.push_back(item);
    delobjects.push_back(item);
    
}


void GroundItemGroup::updateForeGroundGroup4Pos(SpriteBatchNode * node,int mapIndex, float mapWidth){
    
    int randomCoinFactor = CCRANDOM_0_1()*(CCRANDOM_0_1()*5 + 1);
    
    float startx = randomCoinFactor + mapWidth * mapIndex;
    
    float sailHeight = GameData::getInstance()->getSandHeight()/2;
    float plantHeight = GameData::getInstance()->getSandHeight()/2;
    float stoneHeight = GameData::getInstance()->getSandHeight()/2;
    float chestHeight = GameData::getInstance()->getSandHeight()/2;
    float xIncrement = 160;
    
    Sprite *item = NULL;
    item = ForeGroundItem::create(Fore_Plant1);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 1 * xIncrement,plantHeight));
    node->addChild(item);
    fore_elements4.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Plant2);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 2 * xIncrement,plantHeight));
    node->addChild(item,2);
    fore_elements4.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Plant3);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 3 * xIncrement,plantHeight));
    node->addChild(item,2);
    fore_elements4.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone1);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 4 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements4.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone2);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 5 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements4.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone3);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 6 * xIncrement,sailHeight));
    node->addChild(item,2);
    fore_elements4.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Snail);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 7 * xIncrement,plantHeight));
    node->addChild(item,2);
    fore_elements4.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Chest);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 8 * xIncrement,chestHeight));
    node->addChild(item,2);
    fore_elements4.push_back(item);
    delobjects.push_back(item);
}

void GroundItemGroup::updateForeGroundGroup5Pos(SpriteBatchNode * node,int mapIndex, float mapWidth){
    
    int randomCoinFactor = CCRANDOM_0_1()*(CCRANDOM_0_1()*5 + 1);
    
    float startx = randomCoinFactor + mapWidth * mapIndex;
    
    float sailHeight = GameData::getInstance()->getSandHeight()/2;
    float plantHeight = GameData::getInstance()->getSandHeight()/2;
    float stoneHeight = GameData::getInstance()->getSandHeight()/2;
    float xIncrement = 130;
    
    Sprite *item = NULL;
    item = ForeGroundItem::create(Fore_Plant1);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 1 * xIncrement,plantHeight));
    node->addChild(item,2);
    fore_elements5.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Plant3);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 2 * xIncrement,plantHeight));
    node->addChild(item,2);
    fore_elements5.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone1);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 3 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements5.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone2);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 4 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements5.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone4);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 5 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements5.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone4);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 6 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements5.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone4);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 7 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements5.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone5);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 8 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements5.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone1);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 9 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements5.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Snail);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 10 * xIncrement,sailHeight));
    node->addChild(item,2);
    fore_elements5.push_back(item);
    delobjects.push_back(item);
    
}

void GroundItemGroup::updateForeGroundGroup6Pos(SpriteBatchNode * node,int mapIndex, float mapWidth){
    
    int randomCoinFactor = CCRANDOM_0_1()*(CCRANDOM_0_1()*5 + 1);
    
    float startx = randomCoinFactor + mapWidth * mapIndex;
    
    float starHeight = GameData::getInstance()->getSandHeight()/2;
    float plantHeight = GameData::getInstance()->getSandHeight()/2;
    float stoneHeight = GameData::getInstance()->getSandHeight()/2;
    float xIncrement = 130;
    
    Sprite *item = NULL;
    item = ForeGroundItem::create(Fore_Plant1);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 1 * xIncrement,plantHeight));
    node->addChild(item);
    fore_elements6.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Plant2);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 1 * xIncrement,plantHeight));
    node->addChild(item,2);
    fore_elements6.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone2);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 2 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements6.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone2);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 3 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements6.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone4);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 4 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements6.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone4);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 5 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements6.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone6);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 6 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements6.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone5);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 7 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements6.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Startfish);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 8 * xIncrement,starHeight));
    node->addChild(item,2);
    fore_elements6.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Startfish);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 9 * xIncrement,starHeight));
    node->addChild(item,2);
    fore_elements6.push_back(item);
    delobjects.push_back(item);
}

void GroundItemGroup::updateForeGroundGroup7Pos(SpriteBatchNode * node,int mapIndex, float mapWidth){
    int randomCoinFactor = CCRANDOM_0_1()*(CCRANDOM_0_1()*5 + 1);
    
    float startx = randomCoinFactor + mapWidth * mapIndex;
    
    float chestHeight = GameData::getInstance()->getSandHeight()/2;
    float plantHeight = GameData::getInstance()->getSandHeight()/2;
    float stoneHeight = GameData::getInstance()->getSandHeight()/2;
    float xIncrement = 140;
    
    Sprite *item = NULL;
    item = ForeGroundItem::create(Fore_Plant2);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 1 * xIncrement,plantHeight));
    node->addChild(item,2);
    fore_elements7.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Plant3);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 2 * xIncrement,plantHeight));
    node->addChild(item,2);
    fore_elements7.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone1);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 3 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements7.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone1);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 4 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements7.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone3);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 5 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements7.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone3);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 6 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements7.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone4);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 7 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements7.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone6);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 8 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements7.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Chest);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 9 * xIncrement,chestHeight));
    node->addChild(item,2);
    fore_elements7.push_back(item);
    delobjects.push_back(item);
    
}

void GroundItemGroup::updateForeGroundGroup8Pos(SpriteBatchNode * node,int mapIndex, float mapWidth){
    
    int randomCoinFactor = CCRANDOM_0_1()*(CCRANDOM_0_1()*5 + 1);
    
    float startx = randomCoinFactor + mapWidth * mapIndex;
    
    float sailHeight = GameData::getInstance()->getSandHeight()/2;
    float starHeight = GameData::getInstance()->getSandHeight()/2;
    float plantHeight = GameData::getInstance()->getSandHeight()/2;
    float stoneHeight = GameData::getInstance()->getSandHeight()/2;
    float xIncrement = 125;
    Sprite *item = NULL;
    item = ForeGroundItem::create(Fore_Plant3);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 1 * xIncrement,plantHeight));
    node->addChild(item,2);
    fore_elements8.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Plant3);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 2 * xIncrement,plantHeight));
    node->addChild(item,2);
    fore_elements8.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone2);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 3 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements8.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone2);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 4 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements8.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone3);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 5 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements8.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone4);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 6 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements8.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone5);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 7 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements8.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone6);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 8 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements8.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Stone6);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 9 * xIncrement,stoneHeight));
    node->addChild(item,2);
    fore_elements8.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Snail);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 10 * xIncrement,sailHeight));
    node->addChild(item,2);
    fore_elements8.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = ForeGroundItem::create(Fore_Startfish);
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + 11 * xIncrement,starHeight));
    node->addChild(item,2);
    fore_elements8.push_back(item);
    delobjects.push_back(item);
    
}

//middle
void GroundItemGroup::updateMidGroundGroup1Pos(SpriteBatchNode * node,int mapIndex, float mapWidth){
    int randomCoinFactor = CCRANDOM_0_1()*(CCRANDOM_0_1()*5 + 1);
    float MidHeight = GameData::getInstance()->getSandHeight()-60;
    float startx = randomCoinFactor + mapWidth * mapIndex;
    float xIncrement = 200;
    Sprite * item = NULL;
    MiddleGroundItemType type;
    for (int i=0; i<6; i++) {
        item = NULL;
        type = (MiddleGroundItemType)i;
        item = MiddleGroundItem::create(type);
        item->setAnchorPoint(Vec2(0,0));
        if (type==2 || type==5) {
            item->setPosition(Vec2(startx + i * xIncrement,MidHeight));
        }
        else {
            item->setPosition(Vec2(startx + i * xIncrement,MidHeight + 20));
        }
        item->setTag(mapIndex);
        node->addChild(item,-1);
        mid_elements1.push_back(item);
        delobjects.push_back(item);
    }

    
}

void GroundItemGroup::updateMidGroundGroup2Pos(SpriteBatchNode * node,int mapIndex, float mapWidth){
    int randomCoinFactor = CCRANDOM_0_1()*(CCRANDOM_0_1()*5 + 1);
    float MidHeight = GameData::getInstance()->getSandHeight()-60;
    float startx = randomCoinFactor + mapWidth * mapIndex;
    float xIncrement = 210;
    
    Sprite * item = NULL;
    item = MiddleGroundItem::create(Mid_Plant1);
    item->setAnchorPoint(Vec2(0,0));
    item->setTag(mapIndex);
    item->setPosition(Vec2(startx + xIncrement,MidHeight + 20));
    node->addChild(item,-1);
    mid_elements2.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = MiddleGroundItem::create(Mid_Plant6);
    item->setAnchorPoint(Vec2(0,0));
    item->setPosition(Vec2(startx + 2 * xIncrement,MidHeight));
    item->setTag(mapIndex);
    node->addChild(item,-1);
    mid_elements2.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = MiddleGroundItem::create(Mid_Plant3);
    item->setAnchorPoint(Vec2(0,0));
    item->setPosition(Vec2(startx + 3 * xIncrement,MidHeight));
    item->setTag(mapIndex);
    node->addChild(item,-1);
    mid_elements2.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = MiddleGroundItem::create(Mid_Plant5);
    item->setAnchorPoint(Vec2(0,0));
    item->setPosition(Vec2(startx + 3 * xIncrement,MidHeight + 20));
    item->setTag(mapIndex);
    node->addChild(item,-1);
    mid_elements2.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = MiddleGroundItem::create(Mid_Plant4);
    item->setAnchorPoint(Vec2(0,0));
    item->setPosition(Vec2(startx + 4 * xIncrement,MidHeight + 20));
    item->setTag(mapIndex);
    node->addChild(item,-1);
    mid_elements2.push_back(item);
    delobjects.push_back(item);

}

void GroundItemGroup::updateMidGroundGroup3Pos(SpriteBatchNode * node,int mapIndex, float mapWidth){
    int randomCoinFactor = CCRANDOM_0_1()*(CCRANDOM_0_1()*5 + 1);
    float MidHeight = GameData::getInstance()->getSandHeight()-60;
    float startx = randomCoinFactor + mapWidth * mapIndex;
    float xIncrement = 190;
    
    Sprite * item = NULL;
    item = MiddleGroundItem::create(Mid_Plant5);
    item->setAnchorPoint(Vec2(0,0));
    item->setPosition(Vec2(startx + xIncrement,MidHeight + 20));
    item->setTag(mapIndex);
    node->addChild(item,-1);
    mid_elements3.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = MiddleGroundItem::create(Mid_Plant3);
    item->setAnchorPoint(Vec2(0,0));
    item->setPosition(Vec2(startx + 2 * xIncrement,MidHeight));
    item->setTag(mapIndex);
    node->addChild(item,-1);
    mid_elements3.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = MiddleGroundItem::create(Mid_Plant6);
    item->setAnchorPoint(Vec2(0,0));
    item->setPosition(Vec2(startx + 3 * xIncrement,MidHeight));
    item->setTag(mapIndex);
    item->addChild(item,-1);
    mid_elements3.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = MiddleGroundItem::create(Mid_Plant3);
    item->setAnchorPoint(Vec2(0,0));
    item->setPosition(Vec2(startx + 4 * xIncrement,MidHeight));
    item->setTag(mapIndex);
    node->addChild(item,-1);
    mid_elements3.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = MiddleGroundItem::create(Mid_Plant4);
    item->setAnchorPoint(Vec2(0,0));
    item->setPosition(Vec2(startx + 5 * xIncrement,MidHeight + 20));
    item->setTag(mapIndex);
    node->addChild(item,-1);
    mid_elements3.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = MiddleGroundItem::create(Mid_Plant2);
    item->setAnchorPoint(Vec2(0,0));
    item->setPosition(Vec2(startx + 6 * xIncrement,MidHeight + 20));
    item->setTag(mapIndex);
    node->addChild(item,-1);
    mid_elements3.push_back(item);
    delobjects.push_back(item);
}

void GroundItemGroup::updateMidGroundGroup4Pos(SpriteBatchNode * node,int mapIndex, float mapWidth){
    int randomCoinFactor = CCRANDOM_0_1()*(CCRANDOM_0_1()*5 + 1);
    float MidHeight = GameData::getInstance()->getSandHeight()-60;
    float startx = randomCoinFactor + mapWidth * mapIndex;
    float xIncrement = 180;
    
    Sprite * item = NULL;
    item = MiddleGroundItem::create(Mid_Plant3);
    item->setAnchorPoint(Vec2(0,0));
    item->setPosition(Vec2(startx + 1 * xIncrement,MidHeight));
    item->setTag(mapIndex);
    node->addChild(item,-1);
    mid_elements4.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = MiddleGroundItem::create(Mid_Plant1);
    item->setAnchorPoint(Vec2(0,0));
    item->setPosition(Vec2(startx + 2 * xIncrement,MidHeight + 20));
    item->setTag(mapIndex);
    node->addChild(item,-1);
    mid_elements4.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = MiddleGroundItem::create(Mid_Plant5);
    item->setAnchorPoint(Vec2(0,0));
    item->setPosition(Vec2(startx + 3 * xIncrement,MidHeight + 20));
    item->setTag(mapIndex);
    node->addChild(item,-1);
    mid_elements4.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = MiddleGroundItem::create(Mid_Plant5);
    item->setAnchorPoint(Vec2(0,0));
    item->setPosition(Vec2(startx + 4 * xIncrement,MidHeight + 20));
    item->setTag(mapIndex);
    node->addChild(item,-1);
    mid_elements4.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = MiddleGroundItem::create(Mid_Plant2);
    item->setAnchorPoint(Vec2(0,0));
    item->setPosition(Vec2(startx + 5 * xIncrement,MidHeight + 20));
    item->setTag(mapIndex);
    node->addChild(item,-1);
    mid_elements4.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = MiddleGroundItem::create(Mid_Plant6);
    item->setAnchorPoint(Vec2(0,0));
    item->setPosition(Vec2(startx + 6 * xIncrement,MidHeight));
    item->setTag(mapIndex);
    node->addChild(item,-1);
    mid_elements4.push_back(item);
    delobjects.push_back(item);

}

void GroundItemGroup::updateMidGroundGroup5Pos(SpriteBatchNode * node,int mapIndex, float mapWidth){
    int randomCoinFactor = CCRANDOM_0_1()*(CCRANDOM_0_1()*5 + 1);
    float MidHeight = GameData::getInstance()->getSandHeight()-60;
    float startx = randomCoinFactor + mapWidth * mapIndex;
    float xIncrement = 220;
    
    Sprite * item = NULL;
    item = MiddleGroundItem::create(Mid_Plant4);
    item->setAnchorPoint(Vec2(0,0));
    item->setPosition(Vec2(startx + 1 * xIncrement,MidHeight));
    item->setTag(mapIndex);
    node->addChild(item,-1);
    mid_elements5.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = MiddleGroundItem::create(Mid_Plant2);
    item->setAnchorPoint(Vec2(0,0));
    item->setPosition(Vec2(startx + 2 * xIncrement,MidHeight + 20));
    item->setTag(mapIndex);
    node->addChild(item,-1);
    mid_elements5.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = MiddleGroundItem::create(Mid_Plant6);
    item->setAnchorPoint(Vec2(0,0));
    item->setPosition(Vec2(startx + 3 * xIncrement,MidHeight + 20));
    item->setTag(mapIndex);
    node->addChild(item,-1);
    mid_elements5.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = MiddleGroundItem::create(Mid_Plant1);
    item->setAnchorPoint(Vec2(0,0));
    item->setPosition(Vec2(startx + 4 * xIncrement,MidHeight + 20));
    item->setTag(mapIndex);
    node->addChild(item,-1);
    mid_elements5.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = MiddleGroundItem::create(Mid_Plant3);
    item->setAnchorPoint(Vec2(0,0));
    item->setPosition(Vec2(startx + 5 * xIncrement,MidHeight + 20));
    item->setTag(mapIndex);
    node->addChild(item,-1);
    mid_elements5.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = MiddleGroundItem::create(Mid_Plant2);
    item->setAnchorPoint(Vec2(0,0));
    item->setPosition(Vec2(startx + 6 * xIncrement,MidHeight));
    item->setTag(mapIndex);
    node->addChild(item,-1);
    mid_elements5.push_back(item);
    delobjects.push_back(item);
    
}

void GroundItemGroup::updateMidGroundGroup6Pos(SpriteBatchNode * node,int mapIndex, float mapWidth){
    int randomCoinFactor = CCRANDOM_0_1()*(CCRANDOM_0_1()*5 + 1);
    float MidHeight = GameData::getInstance()->getSandHeight()-60;
    float startx = randomCoinFactor + mapWidth * mapIndex;
    float xIncrement = 230;
    
    Sprite * item = NULL;
    item = MiddleGroundItem::create(Mid_Plant2);
    item->setAnchorPoint(Vec2(0,0));
    item->setPosition(Vec2(startx + 1 * xIncrement,MidHeight + 20));
    item->setTag(mapIndex);
    node->addChild(item,-1);
    mid_elements6.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = MiddleGroundItem::create(Mid_Plant4);
    item->setAnchorPoint(Vec2(0,0));
    item->setPosition(Vec2(startx + 2 * xIncrement,MidHeight + 20));
    item->setTag(mapIndex);
    node->addChild(item,-1);
    mid_elements6.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = MiddleGroundItem::create(Mid_Plant4);
    item->setAnchorPoint(Vec2(0,0));
    item->setPosition(Vec2(startx + 3 * xIncrement,MidHeight + 20));
    item->setTag(mapIndex);
    node->addChild(item,-1);
    mid_elements6.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = MiddleGroundItem::create(Mid_Plant5);
    item->setAnchorPoint(Vec2(0,0));
    item->setPosition(Vec2(startx + 4 * xIncrement,MidHeight + 20));
    item->setTag(mapIndex);
    node->addChild(item,-1);
    mid_elements6.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = MiddleGroundItem::create(Mid_Plant3);
    item->setAnchorPoint(Vec2(0,0));
    item->setPosition(Vec2(startx + 5 * xIncrement,MidHeight));
    item->setTag(mapIndex);
    node->addChild(item,-1);
    mid_elements6.push_back(item);
    delobjects.push_back(item);
    
    item = NULL;
    item = MiddleGroundItem::create(Mid_Plant6);
    item->setAnchorPoint(Vec2(0,0));
    item->setPosition(Vec2(startx + 6 * xIncrement,MidHeight));
    item->setTag(mapIndex);
    node->addChild(item,-1);
    mid_elements6.push_back(item);
    delobjects.push_back(item);

}

//background
void GroundItemGroup::updateBackGroundGroup1Pos(SpriteBatchNode * node,int mapIndex, float mapWidth){
    Sprite * item  = NULL;
    item = BackGroundItem::create(Back_Rock1);
    item->setAnchorPoint(Vec2(0,0));
    item->setTag(mapIndex);
    item->setPosition(Vec2(mapIndex * mapWidth + item->getContentSize().width ,0));
    node->addChild(item,-2);
    back_elements1.push_back(item);
    delobjects.push_back(item);
}

void GroundItemGroup::updateBackGroundGroup2Pos(SpriteBatchNode * node,int mapIndex, float mapWidth){
    Sprite * item  = NULL;
    item = BackGroundItem::create(Back_Rock2);
    item->setAnchorPoint(Vec2(0,0));
    item->setTag(mapIndex);
    item->setPosition(Vec2(mapIndex * mapWidth + item->getContentSize().width,0));
    node->addChild(item,-2);
    back_elements2.push_back(item);
    delobjects.push_back(item);
}

void GroundItemGroup::updateBackGroundGroup3Pos(SpriteBatchNode * node,int mapIndex, float mapWidth){
    Sprite * item  = NULL;
    item = BackGroundItem::create(Back_Wreck);
    item->setAnchorPoint(Vec2(0,0));
    item->setPosition(Vec2(mapIndex * mapWidth + item->getContentSize().width,0));
    node->addChild(item,-2);
    back_elements3.push_back(item);
    delobjects.push_back(item);
}

void GroundItemGroup::updateBackGroundGroup4Pos(SpriteBatchNode * node,int mapIndex, float mapWidth){
    Sprite * item  = NULL;
    item = BackGroundItem::create(Back_Rock2);
    item->setAnchorPoint(Vec2(0,0));
    item->setTag(mapIndex);
    item->setPosition(Vec2(mapIndex * mapWidth + item->getContentSize().width,0));
    node->addChild(item,-2);
    back_elements4.push_back(item);
    delobjects.push_back(item);
}

void GroundItemGroup::removeObjectOfMap(int mapIndex){
    // 正确的遍历删除方法
    std::list<Sprite *>::iterator itList;
    for (itList = delobjects.begin(); itList != delobjects.end();/*Not ++ here*/) {
        Sprite *sprite = (Sprite *)*itList;
        if(mapIndex == sprite->getTag()) {
            sprite->removeFromParent();
            itList = delobjects.erase(itList);
        } else {
            itList++;
        }
    }


}