    //
//  ObstacleGroup.cpp
//  YellowPlane
//
//  Created by George on 15/6/9.
//
//
/*
 将多个障碍物的对象加入到group中
 
 
 */
#include "ObstacleGroup.h"

ObstacleGroup::ObstacleGroup(){
    
}

ObstacleGroup::~ObstacleGroup(){
    list<ObstacleItem *>::iterator itList;
    for (itList = delobjects.begin(); itList != delobjects.end(); itList++) {
        ObstacleItem *sprite = (ObstacleItem *)*itList;
        sprite->removeFromParent();
    }

}

void ObstacleGroup::updateObstacleGroup1Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth){
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    int randomCoinFactor = CCRANDOM_0_1()*(CCRANDOM_0_1()*5 + 1);
    float coinHeight = ObstacleItem::getContentSize(Type_Coin)->height;
    float coinWidth = ObstacleItem::getContentSize(Type_Coin)->width;
    //next coin's position
    float coinPoint_x = randomCoinFactor + mapWidth * mapIndex;
    //next coin's start position
    float startx = coinPoint_x;
    float xIncrement = coinWidth/2*3;
    
    float firstRowHeight = visibleSize.height - coinHeight;
    float secondRowHeight = firstRowHeight - coinHeight;
    //CCLOG("load mapindex:%d",mapIndex);
    
    int initCoinNum = 15;
    //add coins
    ObstacleItem * coin = NULL;
    for (int i=0; i<initCoinNum/3; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + i * xIncrement,firstRowHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup1.push_back(coin);
        delobjects.push_back(coin);
    }
    
    for (int i=0; i<initCoinNum/3; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + i * xIncrement,secondRowHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup1.push_back(coin);
        delobjects.push_back(coin);
    }
    
    for (int i=0; i<initCoinNum/3; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + i * xIncrement,secondRowHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup1.push_back(coin);
        delobjects.push_back(coin);
    }
}


void ObstacleGroup::updateObstacleGroup2Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth){
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    int randomCoinFactor = CCRANDOM_0_1()*(CCRANDOM_0_1()*5 + 1);
    float coinHeight = ObstacleItem::getContentSize(Type_Coin)->height;
    float coinWidth = ObstacleItem::getContentSize(Type_Coin)->width;
    //next coin's position
    float coinPoint_x = randomCoinFactor + mapWidth * mapIndex;
    //next coin's start position
    float startx = coinPoint_x;
    float xIncrement = coinWidth/2*3;
    
    float firstRowHeight = visibleSize.height - coinHeight;
    float secondRowHeight = firstRowHeight - coinHeight;
    float thirdRowHeight = coinHeight*3 + MAP::getSandHeight();
    float forthRowHeight = thirdRowHeight - coinHeight;
    //CCLOG("load mapindex:%d",mapIndex);
    
    int initCoinNum = 20;
    //add coins
    ObstacleItem * coin = NULL;
    for (int i=0; i<initCoinNum/4; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + i * xIncrement,firstRowHeight));
        node->addChild(coin);
        coin->setTag(1);
        this->obstaclegroup2.push_back(coin);
        delobjects.push_back(coin);
    }

    for (int i=0; i<initCoinNum/4; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + i * xIncrement,secondRowHeight));
        node->addChild(coin);
        coin->setTag(2);
        this->obstaclegroup2.push_back(coin);
        delobjects.push_back(coin);
    }

    for (int i=0; i<initCoinNum/4; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + i * xIncrement,thirdRowHeight));
        node->addChild(coin);
        coin->setTag(3);
        obstaclegroup2.push_back(coin);
        delobjects.push_back(coin);
    }

    for (int i=0; i<initCoinNum/4; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + i * xIncrement,forthRowHeight));
        node->addChild(coin);
        coin->setTag(4);
        obstaclegroup2.push_back(coin);
        delobjects.push_back(coin);
    }

}

void ObstacleGroup::updateObstacleGroup3Pos(SpriteBatchNode * node, cpSpace *space ,int mapIndex, float mapWidth){
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    int randomCoinFactor = CCRANDOM_0_1()*(CCRANDOM_0_1()*5 + 1);
    float coinHeight = ObstacleItem::getContentSize(Type_Coin)->height;
    float coinWidth = ObstacleItem::getContentSize(Type_Coin)->width;
    //next coin's position
    float coinPoint_x = randomCoinFactor + mapWidth * mapIndex;
    //next coin's start position
    float startx = coinPoint_x;
    float xIncrement = coinWidth/5*6;
    float yIncrement = coinHeight/5*6;
    
    float firstRowHeight = visibleSize.height - yIncrement;
    float secondRowHeight = firstRowHeight - yIncrement;
    float thirdRowHeight = secondRowHeight - yIncrement;
    float forthRowHeight = thirdRowHeight - yIncrement;
    float fifthRowHeight = forthRowHeight - yIncrement;
    float sixthRowHeight = fifthRowHeight - yIncrement;
    //CCLOG("load mapindex:%d",mapIndex);
    
    //add coins
    ObstacleItem * coin = NULL;
    for (int i=0; i<10; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + i * xIncrement,firstRowHeight));
        node->addChild(coin);
        coin->setTag(1);
        obstaclegroup3.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<10; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + i * xIncrement,secondRowHeight));
        node->addChild(coin);
        coin->setTag(2);
        obstaclegroup3.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<8; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+4) * xIncrement,thirdRowHeight));
        node->addChild(coin);
        coin->setTag(3);
        obstaclegroup3.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<8; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+4) * xIncrement,forthRowHeight));
        node->addChild(coin);
        coin->setTag(4);
        obstaclegroup3.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<4; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+8) * xIncrement ,fifthRowHeight));
        node->addChild(coin);
        coin->setTag(5);
        obstaclegroup3.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<4; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+8) * xIncrement ,sixthRowHeight));
        node->addChild(coin);
        coin->setTag(6);
        obstaclegroup3.push_back(coin);
        delobjects.push_back(coin);
    }

}


void ObstacleGroup::updateObstacleGroup4Pos(SpriteBatchNode * node, cpSpace *space ,int mapIndex, float mapWidth){
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    int randomCoinFactor = CCRANDOM_0_1()*(CCRANDOM_0_1()*5 + 1);
    float coinHeight = ObstacleItem::getContentSize(Type_Coin)->height;
    float coinWidth = ObstacleItem::getContentSize(Type_Coin)->width;
    float chainsHeight = ObstacleItem::getContentSize(Type_Mine_chains)->width;
    float chainsWidth = ObstacleItem::getContentSize(Type_Mine_chains)->height;
    float mineHeight = ObstacleItem::getContentSize(Type_Mine_chain_export)->height;
    float mineWidth = ObstacleItem::getContentSize(Type_Mine_chain_export)->width;
    //next coin's position
    float coinPoint_x = randomCoinFactor + mapWidth * mapIndex;
    //next coin's start position
    float startx = coinPoint_x;
    float xIncrement = coinWidth/2*3;
    
    float coinRowHeight = visibleSize.height/2;
    //mine
    float firstmineHeight = visibleSize.height - mineHeight/2;
    float secondmineHeight = firstmineHeight - mineHeight;
    float thirdmineHeight = mineHeight/2;
    float forthmineHeight = thirdmineHeight + mineHeight;
    
    float firstRowHeight = visibleSize.height - mineHeight/2;
    float secondRowHeight = coinRowHeight + mineHeight;
    float thirdRowHeight = mineHeight/2 + MAP::getSandHeight();
    
    //CCLOG("load mapindex:%d",mapIndex);
    ObstacleItem * coin = NULL;
    ObstacleItem * mine = NULL;
    ObstacleItem * chains = NULL;
    //mine
    for (int i=1; i<=4; i++) {
        mine = NULL;
        if (i==1) {
            mine = ObstacleItem::create(space, Type_Mine_chain_export,Vec2(startx + xIncrement,firstmineHeight));
        }
        else if(i==2){
            mine = ObstacleItem::create(space, Type_Mine_chain_export,Vec2(startx + xIncrement,secondmineHeight));
        }
        else if(i==3){
            mine = ObstacleItem::create(space, Type_Mine_chain_export,Vec2(startx + xIncrement,thirdmineHeight));
        }
        else{
            mine = ObstacleItem::create(space, Type_Mine_chain_export,Vec2(startx + xIncrement,forthmineHeight));
        }
        mine->setTag(mapIndex);
        node->addChild(mine);
        obstaclegroup4.push_back(mine);
        delobjects.push_back(mine);
    }

    //chains
//    for (int i=0; i<4; i++) {
//        chains = NULL;
//        chains = ObstacleItem::create(space, Type_Mine_chains,Vec2(startx + xIncrement + chainsWidth + i*chainsWidth/2,firstmineHeight - chainsHeight/2 - i*chainsHeight/2));
//        chains->setTag(mapIndex);
//        chains->setRotation(45);
//        node->addChild(chains);
//        obstaclegroup4.push_back(chains);
//        delobjects.push_back(chains);
//    }
//    for (int i=0; i<4; i++) {
//        chains = NULL;
//        chains = ObstacleItem::create(space, Type_Mine_chains,Vec2(startx + xIncrement + chainsWidth + i*chainsWidth/2,thirdmineHeight + chainsHeight/2 + i*chainsHeight/2));
//        chains->setTag(mapIndex);
//        chains->setRotation(125);
//        node->addChild(chains);
//        obstaclegroup4.push_back(chains);
//        delobjects.push_back(chains);
//    }
    //coin
    for (int i=0; i<=4; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+5) * xIncrement,coinRowHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup4.push_back(coin);
        delobjects.push_back(coin);
    }

}

void ObstacleGroup::updateObstacleGroup5Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth){
    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    int randomCoinFactor = CCRANDOM_0_1()*(CCRANDOM_0_1()*5 + 1);
    float coinHeight = ObstacleItem::getContentSize(Type_Coin)->height;
    float coinWidth = ObstacleItem::getContentSize(Type_Coin)->width;
    
    //next coin's position
    float coinPoint_x = randomCoinFactor + mapWidth * mapIndex;
    //next coin's start position
    float startx = coinPoint_x;
    float xIncrement = coinWidth/2*3;
    
    float firstRowHeight = visibleSize.height - coinHeight;
    float secondRowHeight = firstRowHeight - coinHeight;
    
    ObstacleItem * coin = NULL;
    for (int i=0; i<8; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + i * xIncrement, firstRowHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup5.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<8; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + i * xIncrement, secondRowHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup5.push_back(coin);
        delobjects.push_back(coin);
    }

}

void ObstacleGroup::updateObstacleGroup6Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth){
    //
    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    int randomCoinFactor = CCRANDOM_0_1()*(CCRANDOM_0_1()*5 + 1);
    float coinHeight = ObstacleItem::getContentSize(Type_Coin)->height;
    float coinWidth = ObstacleItem::getContentSize(Type_Coin)->width;
    
    //next coin's position
    float coinPoint_x = randomCoinFactor + mapWidth * mapIndex;
    //next coin's start position
    float startx = coinPoint_x;
    float xIncrement = coinWidth/2*3;
    
    float firstRowHeight = visibleSize.height - coinHeight;
    float secondRowHeight = firstRowHeight - coinHeight/2;
    float thirdRowHeight = secondRowHeight - coinHeight/2;
    float forthRowHeight = thirdRowHeight - coinHeight/2;
    float fifthRowHeight = forthRowHeight - coinHeight/2;
    float sixthRowHeight = fifthRowHeight - coinHeight/2;
    float seventhRowHeight = sixthRowHeight - coinHeight/2;
    float eighthRowHeight = seventhRowHeight - coinHeight/2;
    float nineRowHeight = eighthRowHeight - coinHeight/2;
    float tenthRowHeight = nineRowHeight - coinHeight/2;
    
    ObstacleItem * coin = NULL;
    
    for (int i=0; i<7; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + i * xIncrement,firstRowHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        //obstaclegroup6.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<8; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + i * xIncrement,secondRowHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        //obstaclegroup6.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<3; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+5) * xIncrement,thirdRowHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        //obstaclegroup6.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<3; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+6) * xIncrement,forthRowHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        //obstaclegroup6.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<3; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+7) * xIncrement,fifthRowHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        //obstaclegroup6.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<3; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+8) * xIncrement,sixthRowHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        //obstaclegroup6.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<3; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+9) * xIncrement,seventhRowHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        //obstaclegroup6.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<3; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+10) * xIncrement,eighthRowHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        //obstaclegroup6.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<8; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+11) * xIncrement,nineRowHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        //obstaclegroup6.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<7; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+11) * xIncrement,tenthRowHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        //obstaclegroup6.push_back(coin);
        delobjects.push_back(coin);
    }

}

void ObstacleGroup::updateObstacleGroup7Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth){
    
    int randomCoinFactor = CCRANDOM_0_1()*(CCRANDOM_0_1()*5 + 1);
    float coinHeight = ObstacleItem::getContentSize(Type_Coin)->height;
    float coinWidth = ObstacleItem::getContentSize(Type_Coin)->width;
    
    //next coin's position
    float coinPoint_x = randomCoinFactor + mapWidth * mapIndex;
    //next coin's start position
    float startx = coinPoint_x;
    float xIncrement = coinWidth/2*3;
    
    float firstRowHeight = 72 + coinHeight;
    float secondRowHeight = firstRowHeight + coinHeight/2;
    float thirdRowHeight = secondRowHeight + coinHeight/2;
    float forthRowHeight = thirdRowHeight + coinHeight/2;
    float fifthRowHeight = forthRowHeight + coinHeight/2;
    float sixthRowHeight = fifthRowHeight + coinHeight/2;
    float seventhRowHeight = sixthRowHeight + coinHeight/2;
    float eighthRowHeight = seventhRowHeight + coinHeight/2;
    float nineRowHeight = eighthRowHeight + coinHeight/2;
    float tenthRowHeight = nineRowHeight + coinHeight/2;
    
    ObstacleItem * coin = NULL;

    for (int i=0; i<7; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + i * xIncrement,firstRowHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup7.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<8; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + i * xIncrement,secondRowHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup7.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<3; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+5) * xIncrement,thirdRowHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup7.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<3; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+6) * xIncrement,forthRowHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup7.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<3; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+7) * xIncrement,fifthRowHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup7.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<3; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+8) * xIncrement,sixthRowHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup7.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<3; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+9) * xIncrement,seventhRowHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup7.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<3; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+10) * xIncrement,eighthRowHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup7.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<8; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+11) * xIncrement,nineRowHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup7.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<7; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+11) * xIncrement,tenthRowHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup7.push_back(coin);
        delobjects.push_back(coin);
    }
    
}

void ObstacleGroup::updateObstacleGroup8Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth){
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    int randomCoinFactor = CCRANDOM_0_1()*(CCRANDOM_0_1()*5 + 1);
    float coinHeight = ObstacleItem::getContentSize(Type_Coin)->height;
    float coinWidth = ObstacleItem::getContentSize(Type_Coin)->width;
    float chainsHeight = ObstacleItem::getContentSize(Type_Mine_chains)->width;
    float chainsWidth = ObstacleItem::getContentSize(Type_Mine_chains)->height;
    float mineHeight = ObstacleItem::getContentSize(Type_Mine_chain_export)->height;
    float mineWidth = ObstacleItem::getContentSize(Type_Mine_chain_export)->width;
    //next coin's position
    float coinPoint_x = randomCoinFactor + mapWidth * mapIndex;
    //next coin's start position
    float startx = coinPoint_x;
    float xIncrement = coinWidth/2*3;

    float firstRowMineHeight = visibleSize.height-mineHeight;
    float secondRowMineHeight = mineHeight;
    float firstRowChainsHeight = visibleSize.height-chainsHeight;
    float secondRowChainsHeight = chainsHeight;
    
    float firstMineX = startx;
    float secondMineX = firstMineX + 8 * chainsWidth;
    float thirdMineX = secondMineX + 8 * chainsWidth;
    
    float firstChainsX = firstMineX + chainsWidth/2;
    float secondChainsX = secondMineX + chainsWidth/2;
    
    float firstCoinHeight = firstRowMineHeight - mineHeight;
    float secondCoinHeight = secondRowMineHeight + mineHeight;
    
    ObstacleItem * coin = NULL;
    ObstacleItem * mine = NULL;
    ObstacleItem * chains = NULL;
    
    //mine
    for (int i=0; i<6; i++) {
        mine = NULL;
        if (i==0) {
            mine = ObstacleItem::create(space, Type_Mine_chain_export,Vec2(firstMineX,firstRowMineHeight));
        }
        else if(i==1){
            mine = ObstacleItem::create(space, Type_Mine_chain_export,Vec2(secondMineX,firstRowMineHeight));
        }
        else if(i==2){
            mine = ObstacleItem::create(space, Type_Mine_chain_export,Vec2(thirdMineX,firstRowMineHeight));
        }
        else if(i==3){
            mine = ObstacleItem::create(space, Type_Mine_chain_export,Vec2(firstMineX,secondRowMineHeight));
        }
        else if (i==4){
            mine = ObstacleItem::create(space, Type_Mine_chain_export,Vec2(secondMineX,secondRowMineHeight));
        }
        else if (i==5){
            mine = ObstacleItem::create(space, Type_Mine_chain_export,Vec2(thirdMineX,secondRowMineHeight));
        }
        mine->setTag(mapIndex);
        node->addChild(mine);
        obstaclegroup8.push_back(mine);
        delobjects.push_back(mine);
    }

    //chains
    for (int i=0; i<8; i++) {
        chains = NULL;
        chains = ObstacleItem::create(space, Type_Mine_chains,Vec2(firstChainsX + i* chainsWidth/2, firstRowChainsHeight));
        chains->setTag(mapIndex);
        node->addChild(chains);
        obstaclegroup8.push_back(chains);
        delobjects.push_back(chains);
    }
    for (int i=0; i<8; i++) {
        chains = NULL;
        chains = ObstacleItem::create(space, Type_Mine_chains,Vec2(secondChainsX + i*chainsWidth/2,firstRowChainsHeight));
        chains->setTag(mapIndex);
        node->addChild(chains);
        obstaclegroup8.push_back(chains);
        delobjects.push_back(chains);
    }
    for (int i=0; i<8; i++) {
        chains = NULL;
        chains = ObstacleItem::create(space, Type_Mine_chains,Vec2(firstChainsX + i*chainsWidth/2,secondRowChainsHeight));
        chains->setTag(mapIndex);
        node->addChild(chains);
        obstaclegroup8.push_back(chains);
        delobjects.push_back(chains);
    }
    for (int i=0; i<8; i++) {
        chains = NULL;
        chains = ObstacleItem::create(space, Type_Mine_chains,Vec2(secondChainsX + i*chainsWidth/2,secondRowChainsHeight));
        chains->setTag(mapIndex);
        node->addChild(chains);
        obstaclegroup8.push_back(chains);
        delobjects.push_back(chains);
    }
    
    //coin
    for (int i=0; i<=10; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(firstMineX,firstCoinHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup8.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<=10; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(firstMineX,secondCoinHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup8.push_back(coin);
        delobjects.push_back(coin);
    }

}

void ObstacleGroup::updateObstacleGroup9Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth){
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    int randomCoinFactor = CCRANDOM_0_1()*(CCRANDOM_0_1()*5 + 1);
    float coinHeight = ObstacleItem::getContentSize(Type_Coin)->height;
    float coinWidth = ObstacleItem::getContentSize(Type_Coin)->width;
    float lasers_exportHeight = ObstacleItem::getContentSize(Type_Lasers_export)->width;
    float lasers_exportWidth = ObstacleItem::getContentSize(Type_Lasers_export)->height;
    float laser1Height = ObstacleItem::getContentSize(Type_Laser1)->height;
    float laser1Width = ObstacleItem::getContentSize(Type_Laser1)->width;
    //next coin's position
    float coinPoint_x = randomCoinFactor + mapWidth * mapIndex;
    //next coin's start position
    float startx = coinPoint_x;
    float xIncrement = coinWidth/2*3;
    
    float firstCoinHeight = visibleSize.height/2 - coinHeight/2;
    float secondCoinHeight = visibleSize.height/2 + coinHeight/2;
    
    float firstlasers_exportHeight = visibleSize.height - (visibleSize.height - 3 * laser1Height)/2 - lasers_exportHeight * 3/2;
    float secondlasers_exportHeight = (visibleSize.height - 3 * laser1Height)/2 - lasers_exportHeight * 3/2;
    float lasers_exportX = startx + 15 * xIncrement;
    
    
    ObstacleItem * coin = NULL;
    ObstacleItem * lasers_export = NULL;
    ObstacleItem * laser;
    //coins
    for (int i=0; i<10; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+4)*xIncrement ,firstCoinHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup9.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<10; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+4)*xIncrement ,secondCoinHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup9.push_back(coin);
        delobjects.push_back(coin);
    }
    //lasers_export
    for (int i=0; i<2; i++) {
        lasers_export = NULL;
        if (i==0) {
            lasers_export = ObstacleItem::create(space, Type_Lasers_export, Vec2(lasers_exportX,firstlasers_exportHeight));
        }
        else if(i==1){
            lasers_export = ObstacleItem::create(space, Type_Lasers_export, Vec2(lasers_exportX,secondlasers_exportHeight));
        }
        node->addChild(lasers_export);
        lasers_export->setTag(mapIndex);
        obstaclegroup9.push_back(lasers_export);
        delobjects.push_back(lasers_export);
    }
    //laser
    for (int i=0; i<3; i++) {
        laser = NULL;
        laser = ObstacleItem::create(space, Type_Laser1, Vec2(lasers_exportX,firstlasers_exportHeight + i*laser1Height/2));
        node->addChild(laser);
        laser->setTag(mapIndex);
        obstaclegroup9.push_back(laser);
        delobjects.push_back(laser);
    }
    

}

void ObstacleGroup::updateObstacleGroup10Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth){
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    int randomCoinFactor = CCRANDOM_0_1()*(CCRANDOM_0_1()*5 + 1);
    float coinHeight = ObstacleItem::getContentSize(Type_Coin)->height;
    float coinWidth = ObstacleItem::getContentSize(Type_Coin)->width;

    //next coin's position
    float coinPoint_x = randomCoinFactor + mapWidth * mapIndex;
    //next coin's start position
    float startx = coinPoint_x;
    float xIncrement = coinWidth/2*3;
    
    float firstRowCoinHeight = visibleSize.height-coinHeight;
    float secondRowCoinHeight = firstRowCoinHeight - coinHeight;
    float thirdRowCoinHeight = secondRowCoinHeight - coinHeight;
    float forthRowCoinHeight = thirdRowCoinHeight - coinHeight;
    float fifthRowCoinHeight = forthRowCoinHeight - coinHeight;
    float sixthRowCoinHeight = fifthRowCoinHeight - coinHeight;
    float seventhRowCoinHeight = sixthRowCoinHeight - coinHeight;
    float eighthRowCoinHeight = seventhRowCoinHeight - coinHeight;
    float ninethRowCoinHeight = eighthRowCoinHeight - coinHeight;
    float tenthRowCoinHeight = ninethRowCoinHeight - coinHeight;
    
    ObstacleItem *coin = NULL;
    //coins
    for (int i=0; i<8; i++) {
        if (i%2==0) {
            continue;
        }
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+4)*xIncrement ,firstRowCoinHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup10.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<8; i++) {
        if (i%2!=0) {
            continue;
        }
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+4)*xIncrement ,secondRowCoinHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup10.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<8; i++) {
        if (i%2==0) {
            continue;
        }
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+4)*xIncrement ,thirdRowCoinHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup10.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<8; i++) {
        if (i%2!=0) {
            continue;
        }
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+4)*xIncrement ,forthRowCoinHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup10.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<8; i++) {
        if (i%2==0) {
            continue;
        }
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+4)*xIncrement ,fifthRowCoinHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup10.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<8; i++) {
        if (i%2!=0) {
            continue;
        }
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+4)*xIncrement ,sixthRowCoinHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup10.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<8; i++) {
        if (i%2==0) {
            continue;
        }
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+4)*xIncrement ,seventhRowCoinHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup10.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<8; i++) {
        if (i%2!=0) {
            continue;
        }
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+4)*xIncrement ,eighthRowCoinHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup10.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<8; i++) {
        if (i%2==0) {
            continue;
        }
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+4)*xIncrement ,ninethRowCoinHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup10.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<8; i++) {
        if (i%2!=0) {
            continue;
        }
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+4)*xIncrement ,tenthRowCoinHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup10.push_back(coin);
        delobjects.push_back(coin);
    }
    
}

void ObstacleGroup::updateObstacleGroup11Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth){
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    int randomCoinFactor = CCRANDOM_0_1()*(CCRANDOM_0_1()*5 + 1);
    float coinHeight = ObstacleItem::getContentSize(Type_Coin)->height;
    float coinWidth = ObstacleItem::getContentSize(Type_Coin)->width;
    
    //next coin's position
    float coinPoint_x = randomCoinFactor + mapWidth * mapIndex;
    //next coin's start position
    float startx = coinPoint_x;
    float xIncrement = coinWidth/2*3;
    
    float firstRowCoinHeight = visibleSize.height-coinHeight;
    float secondRowCoinHeight = firstRowCoinHeight - coinHeight;
    float thirdRowCoinHeight = secondRowCoinHeight - coinHeight;
    float forthRowCoinHeight = thirdRowCoinHeight - coinHeight;

    
    ObstacleItem *coin = NULL;
    //coins
    for (int i=0; i<5; i++) {
        if (i%2==0) {
            continue;
        }
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+6)*xIncrement ,firstRowCoinHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup11.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<5; i++) {
        if (i%2==0) {
            continue;
        }
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+6)*xIncrement ,secondRowCoinHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup11.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<5; i++) {
        if (i%2==0) {
            continue;
        }
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+6)*xIncrement ,thirdRowCoinHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup11.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<5; i++) {
        if (i%2==0) {
            continue;
        }
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+6)*xIncrement ,forthRowCoinHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup11.push_back(coin);
        delobjects.push_back(coin);
    }

    
}

void ObstacleGroup::updateObstacleGroup12Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth){
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    int randomCoinFactor = CCRANDOM_0_1()*(CCRANDOM_0_1()*5 + 1);
    float coinHeight = ObstacleItem::getContentSize(Type_Coin)->height;
    float coinWidth = ObstacleItem::getContentSize(Type_Coin)->width;
    float chainsHeight = ObstacleItem::getContentSize(Type_Mine_chains)->width;
    float chainsWidth = ObstacleItem::getContentSize(Type_Mine_chains)->height;
    float mineHeight = ObstacleItem::getContentSize(Type_Mine_chain_export)->height;
    float mineWidth = ObstacleItem::getContentSize(Type_Mine_chain_export)->width;
    //next coin's position
    float coinPoint_x = randomCoinFactor + mapWidth * mapIndex;
    //next coin's start position
    float startx = coinPoint_x;
    float xIncrement = coinWidth/2*3;
    
    float firstMineX = startx + 4 * xIncrement;
    float secondMinex = startx + 10 * xIncrement;
    
    float firstRowMineHeight = visibleSize.height - mineHeight;
    float secondRowMineHeight = firstRowMineHeight - 5 * chainsHeight;
    float thirdRowMineHeight = mineHeight + 72;
    float forthRowMindeHeight = thirdRowMineHeight + 5 * chainsHeight;
    
    ObstacleItem * coin = NULL;
    ObstacleItem * mine = NULL;
    ObstacleItem * chains = NULL;
    
    //mine
    for (int i=0; i<4; i++) {
        mine = NULL;
        if (i==0) {
            mine = ObstacleItem::create(space, Type_Mine_chain_export,Vec2(firstMineX,firstRowMineHeight));
        }
        else if(i==1){
            mine = ObstacleItem::create(space, Type_Mine_chain_export,Vec2(firstMineX,firstRowMineHeight));
        }
        else if(i==2){
            mine = ObstacleItem::create(space, Type_Mine_chain_export,Vec2(secondMinex,firstRowMineHeight));
        }
        else if(i==3){
            mine = ObstacleItem::create(space, Type_Mine_chain_export,Vec2(secondMinex,secondRowMineHeight));
        }
        mine->setTag(mapIndex);
        node->addChild(mine);
        obstaclegroup12.push_back(mine);
        delobjects.push_back(mine);
    }
    
    //chains
    for (int i=0; i<8; i++) {
        chains = NULL;
        chains = ObstacleItem::create(space, Type_Mine_chains,Vec2(firstMineX ,firstRowMineHeight - i*chainsHeight/2));
        chains->setTag(mapIndex);
        node->addChild(chains);
        obstaclegroup12.push_back(chains);
        delobjects.push_back(chains);
    }
    for (int i=0; i<8; i++) {
        chains = NULL;
        chains = ObstacleItem::create(space, Type_Mine_chains,Vec2(secondMinex , thirdRowMineHeight + i*chainsHeight/2));
        chains->setTag(mapIndex);
        node->addChild(chains);
        obstaclegroup12.push_back(chains);
        delobjects.push_back(chains);
    }

    
}

void ObstacleGroup::updateObstacleGroup13Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth){
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    int randomCoinFactor = CCRANDOM_0_1()*(CCRANDOM_0_1()*5 + 1);
    float coinHeight = ObstacleItem::getContentSize(Type_Coin)->height;
    float coinWidth = ObstacleItem::getContentSize(Type_Coin)->width;
    float chainsHeight = ObstacleItem::getContentSize(Type_Mine_chains)->width;
    float chainsWidth = ObstacleItem::getContentSize(Type_Mine_chains)->height;
    float mineHeight = ObstacleItem::getContentSize(Type_Mine_chain_export)->height;
    float mineWidth = ObstacleItem::getContentSize(Type_Mine_chain_export)->width;
    //next coin's position
    float coinPoint_x = randomCoinFactor + mapWidth * mapIndex;
    //next coin's start position
    float startx = coinPoint_x;
    float xIncrement = coinWidth/2*3;
    
    
    float firstRowCoinHeight;
    float secondRowCoinHeight;
    float thirdRowCoinHeight;
    float forthRowCoinHeight;
    
    float firstRowMineHeight = visibleSize.height - mineHeight;
    float secondRowMineHeight = firstRowMineHeight - 2.5 * chainsHeight;
    float thirdRowMineHeight = mineHeight + 72;
    float forthRowMindeHeight = thirdRowMineHeight + 2.5 * chainsHeight;
    
    float firstRowMineX = startx + xIncrement * 4;
    float secondRowMineX = startx + 92.78 * 5 + mineWidth/2;
    float thirdRowMineX = secondRowMineX + 8*chainsWidth + mineWidth/2;
    float forthRowMineX = thirdRowMineHeight + 92.78 * 5 + mineWidth/2;
    
    ObstacleItem * coin = NULL;
    ObstacleItem * mine = NULL;
    ObstacleItem * chains = NULL;
    
//    //coins
//    for (int i=0; i<5; i++) {
//        if (i%2==0) {
//            continue;
//        }
//        coin = NULL;
//        coin = ObstacleItem::create(space, Type_Coin,Vec2(startx + (i+6)*xIncrement ,firstRowCoinHeight));
//        node->addChild(coin);
//        coin->setTag(mapIndex);
//        obstaclegroup13.push_back(coin);
//        delobjects.push_back(coin);
//    }
    
    //mine
    for (int i=0; i<8; i++) {
        mine = NULL;
        if (i==0) {
            mine = ObstacleItem::create(space, Type_Mine_chain_export,Vec2(firstRowMineX,secondRowMineHeight));
        }
        else if(i==1){
            mine = ObstacleItem::create(space, Type_Mine_chain_export,Vec2(secondRowMineX,firstRowMineHeight));
        }
        else if(i==2){
            mine = ObstacleItem::create(space, Type_Mine_chain_export,Vec2(thirdRowMineX,firstRowMineHeight));
        }
        else if(i==3){
            mine = ObstacleItem::create(space, Type_Mine_chain_export,Vec2(forthRowMineX,secondRowMineHeight));
        }
        else if(i==4){
            mine = ObstacleItem::create(space, Type_Mine_chain_export,Vec2(firstRowMineX,secondRowMineHeight));
        }
        else if(i==5){
            mine = ObstacleItem::create(space, Type_Mine_chain_export,Vec2(secondRowMineX,firstRowMineHeight));
        }
        else if(i==6){
            mine = ObstacleItem::create(space, Type_Mine_chain_export,Vec2(thirdRowMineX,firstRowMineHeight));
        }
        else if(i==7){
            mine = ObstacleItem::create(space, Type_Mine_chain_export,Vec2(forthRowMineX,secondRowMineHeight));
        }
        mine->setTag(mapIndex);
        node->addChild(mine);
        obstaclegroup13.push_back(mine);
        delobjects.push_back(mine);
    }
    
    //chains
//    for (int i=0; i<8; i++) {
//        chains = NULL;
//        chains = ObstacleItem::create(space, Type_Mine_chains,Vec2(firstMineX ,firstRowMineHeight - i*chainsHeight/2));
//        chains->setTag(mapIndex);
//        node->addChild(chains);
//        obstaclegroup13.push_back(chains);
//        delobjects.push_back(chains);
//    }
    
    
}

void ObstacleGroup::updateObstacleGroup14Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth){
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    int randomCoinFactor = CCRANDOM_0_1()*(CCRANDOM_0_1()*5 + 1);
    float coinHeight = ObstacleItem::getContentSize(Type_Coin)->height;
    float coinWidth = ObstacleItem::getContentSize(Type_Coin)->width;
    float chainsHeight = ObstacleItem::getContentSize(Type_Mine_chains)->width;
    float chainsWidth = ObstacleItem::getContentSize(Type_Mine_chains)->height;
    float mineHeight = ObstacleItem::getContentSize(Type_Mine_chain_export)->height;
    float mineWidth = ObstacleItem::getContentSize(Type_Mine_chain_export)->width;
    //next coin's position
    float coinPoint_x = randomCoinFactor + mapWidth * mapIndex;
    //next coin's start position
    float startx = coinPoint_x;
    float xIncrement = coinWidth/2*3;
    
    float firstMineX = startx + 4 * xIncrement;
    float secondMineX = firstMineX + 8 * chainsWidth + mineWidth/2;
    float thirdMineX = secondMineX + 2 * xIncrement;
    float forthMineX = thirdMineX + 8 * chainsWidth + mineWidth/2;
    
    float firstRowMineHeight = visibleSize.height/2;
    float secondRowMineHeight = visibleSize.height - mineHeight;
    float thirdRowMineHeight = 72 + mineHeight;
    
    float firstChainsX = firstMineX + chainsWidth/2;
    float secondChainsX = thirdMineX + chainsWidth/2;
    
    ObstacleItem * mine = NULL;
    ObstacleItem * chains = NULL;
    
    //mine
    for (int i=0; i<6; i++) {
        mine = NULL;
        if (i==0) {
            mine = ObstacleItem::create(space, Type_Mine_chain_export,Vec2(firstMineX,firstRowMineHeight));
        }
        else if(i==1){
            mine = ObstacleItem::create(space, Type_Mine_chain_export,Vec2(secondMineX,firstRowMineHeight));
        }
        else if(i==2){
            mine = ObstacleItem::create(space, Type_Mine_chain_export,Vec2(thirdMineX,secondRowMineHeight));
        }
        else if(i==3){
            mine = ObstacleItem::create(space, Type_Mine_chain_export,Vec2(thirdMineX,thirdRowMineHeight));
        }
        else if(i==4){
            mine = ObstacleItem::create(space, Type_Mine_chain_export,Vec2(forthMineX,secondRowMineHeight));
        }
        else if(i==5){
            mine = ObstacleItem::create(space, Type_Mine_chain_export,Vec2(forthMineX,firstRowMineHeight));
        }
        mine->setTag(mapIndex);
        node->addChild(mine);
        obstaclegroup14.push_back(mine);
        delobjects.push_back(mine);
    }
    
    //chains
    for (int i=0; i<8; i++) {
        chains = NULL;
        chains = ObstacleItem::create(space, Type_Mine_chains,Vec2(firstChainsX + i*chainsWidth/2 ,firstRowMineHeight));
        chains->setTag(mapIndex);
        node->addChild(chains);
        obstaclegroup14.push_back(chains);
        delobjects.push_back(chains);
    }
    for (int i=0; i<8; i++) {
        chains = NULL;
        chains = ObstacleItem::create(space, Type_Mine_chains,Vec2(secondChainsX + i*chainsWidth/2, secondRowMineHeight));
        chains->setTag(mapIndex);
        node->addChild(chains);
        obstaclegroup14.push_back(chains);
        delobjects.push_back(chains);
    }
    for (int i=0; i<8; i++) {
        chains = NULL;
        chains = ObstacleItem::create(space, Type_Mine_chains,Vec2(secondChainsX + i*chainsWidth/2, thirdRowMineHeight));
        chains->setTag(mapIndex);
        node->addChild(chains);
        obstaclegroup14.push_back(chains);
        delobjects.push_back(chains);
    }
    
}

void ObstacleGroup::updateObstacleGroup15Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth){
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    int randomCoinFactor = CCRANDOM_0_1()*(CCRANDOM_0_1()*5 + 1);
    float coinHeight = ObstacleItem::getContentSize(Type_Coin)->height;
    float coinWidth = ObstacleItem::getContentSize(Type_Coin)->width;
    float naval_mineHeight = ObstacleItem::getContentSize(Type_Naval_mine)->height;
    float naval_mineWidth = ObstacleItem::getContentSize(Type_Naval_mine)->width;
    //next coin's position
    float coinPoint_x = randomCoinFactor + mapWidth * mapIndex;
    //next coin's start position
    float startx = coinPoint_x;
    float xIncrement = coinWidth/2*3;

    float firstCoinX = startx + 2 * xIncrement;
    float secondCoinX =  firstCoinX + 2 * xIncrement;
    float thirdCoinX = startx + xIncrement;
    
    float firstnaval_mineX = (secondCoinX - firstCoinX) /2;
    float secondnaval_mineX = firstCoinX;
    float thirdnaval_mineX = secondCoinX + 6 * coinWidth;
    
    float firstnaval_mineHeight = visibleSize.height - naval_mineHeight;
    float secondnaval_mineHeight = 72 + naval_mineHeight;
    
    
    ObstacleItem * naval_mine;
    ObstacleItem * coin;
    //naval_mine
    for (int i=0; i<3; i++) {
        naval_mine = NULL;
        if (i==0) {
            naval_mine = ObstacleItem::create(space, Type_Naval_mine,Vec2(firstnaval_mineX,firstnaval_mineHeight));
        }
        else if(i==1){
            naval_mine = ObstacleItem::create(space, Type_Naval_mine,Vec2(secondnaval_mineX,secondnaval_mineHeight));
        }
        else if(i==2){
            naval_mine = ObstacleItem::create(space, Type_Naval_mine,Vec2(thirdnaval_mineX,secondnaval_mineHeight));
        }
        naval_mine->setTag(mapIndex);
        node->addChild(naval_mine);
        obstaclegroup15.push_back(naval_mine);
        delobjects.push_back(naval_mine);
    }
    
    //coin
    for (int i=0; i<6; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(firstCoinX + i*xIncrement ,firstnaval_mineHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup15.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<6; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(secondCoinX + i*xIncrement ,firstnaval_mineHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup15.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<12; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(thirdCoinX + i*xIncrement ,firstnaval_mineHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup15.push_back(coin);
        delobjects.push_back(coin);
    }
    
}

void ObstacleGroup::updateObstacleGroup16Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth){
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    int randomCoinFactor = CCRANDOM_0_1()*(CCRANDOM_0_1()*5 + 1);
    float coinHeight = ObstacleItem::getContentSize(Type_Coin)->height;
    float coinWidth = ObstacleItem::getContentSize(Type_Coin)->width;
    float naval_mineHeight = ObstacleItem::getContentSize(Type_Naval_mine)->height;
    float naval_mineWidth = ObstacleItem::getContentSize(Type_Naval_mine)->width;
    //next coin's position
    float coinPoint_x = randomCoinFactor + mapWidth * mapIndex;
    //next coin's start position
    float startx = coinPoint_x;
    float xIncrement = coinWidth/2*3;
    
    float firstNaval_mineX = startx + xIncrement;
    float secondNaval_mineX = firstNaval_mineX + 3*xIncrement;
    float thirdNaval_mineX = secondNaval_mineX + 3*xIncrement;
    
    float firstNaval_mineHeight = visibleSize.height-naval_mineHeight;
    float secondNaval_mineHeight = 72 + naval_mineHeight;

    
    float firstCoinX = startx + xIncrement;
    float firstCoinHeight = visibleSize.height + coinHeight/2;
    float secondCoinHeight = visibleSize.height - coinHeight/2;
    
    ObstacleItem *naval_mine;
    ObstacleItem *coin;
    
    //naval_mine
    for (int i=0; i<6; i++) {
        naval_mine = NULL;
        if (i==0) {
            naval_mine = ObstacleItem::create(space, Type_Naval_mine,Vec2(firstNaval_mineX,firstNaval_mineHeight));
        }
        else if(i==1){
            naval_mine = ObstacleItem::create(space, Type_Naval_mine,Vec2(secondNaval_mineX,firstNaval_mineHeight));
        }
        else if(i==2){
            naval_mine = ObstacleItem::create(space, Type_Naval_mine,Vec2(thirdNaval_mineX,firstNaval_mineHeight));
        }
        else if(i==3){
            naval_mine = ObstacleItem::create(space, Type_Naval_mine,Vec2(firstNaval_mineX,secondNaval_mineHeight));
        }
        else if(i==4){
            naval_mine = ObstacleItem::create(space, Type_Naval_mine,Vec2(secondNaval_mineX,secondNaval_mineHeight));
        }
        else if(i==5){
            naval_mine = ObstacleItem::create(space, Type_Naval_mine,Vec2(thirdNaval_mineX,secondNaval_mineHeight));
        }
        naval_mine->setTag(mapIndex);
        node->addChild(naval_mine);
        obstaclegroup16.push_back(naval_mine);
        delobjects.push_back(naval_mine);
    }
    
    //coins
    for (int i=0; i<12; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(firstCoinX + i*xIncrement ,firstCoinHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup16.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<12; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(firstCoinX + i*xIncrement ,secondCoinHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup16.push_back(coin);
        delobjects.push_back(coin);
    }

}

void ObstacleGroup::updateObstacleGroup17Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth){
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    int randomCoinFactor = CCRANDOM_0_1()*(CCRANDOM_0_1()*5 + 1);
    float coinHeight = ObstacleItem::getContentSize(Type_Coin)->height;
    float coinWidth = ObstacleItem::getContentSize(Type_Coin)->width;
    float lasers_exportHeight = ObstacleItem::getContentSize(Type_Lasers_export)->height;
    float lasers_exportWidth = ObstacleItem::getContentSize(Type_Lasers_export)->width;
    float laser1Height = ObstacleItem::getContentSize(Type_Laser1)->height;
    float laser1Width = ObstacleItem::getContentSize(Type_Laser1)->width;
    //next coin's position
    float coinPoint_x = randomCoinFactor + mapWidth * mapIndex;
    //next coin's start position
    float startx = coinPoint_x;
    float xIncrement = coinWidth/2*3;
    
    float firstlasers_exportX = startx + xIncrement;
    float secondlasers_exportX = firstlasers_exportX + 4 * laser1Width + lasers_exportWidth/2;
    float thirdlasers_exportX = startx + 5 * xIncrement;
    float forthlasers_exportX = thirdlasers_exportX + 4 * laser1Width + lasers_exportWidth/2;
    
    float firstlasers_exportHeight = visibleSize.height - 2* lasers_exportHeight;
    float secondlasers_exportHeight = 72 + 2 * lasers_exportHeight;
    float thirdlasers_exportHeight = visibleSize.height/2;
    
    float firstCoinX = firstlasers_exportX + coinWidth;
    float secondCoinX = thirdlasers_exportX + coinWidth;
    
    float firstCoinHeight = visibleSize.height/2 + coinHeight/2;
    float secondCoinHeight = visibleSize.height/2 - coinHeight/2;
    float thirdCoinHeight = visibleSize.height/2 - coinHeight * 2;
    float forthCoinHeight = 72 + coinHeight* 2;
    
    ObstacleItem *lasers_export;
    ObstacleItem *laser1;
    ObstacleItem *coin;
    
    //lasers_export
    for (int i=0; i<6; i++) {
        lasers_export = NULL;
        if (i==0) {
            lasers_export = ObstacleItem::create(space, Type_Lasers_export,Vec2(firstlasers_exportX,firstlasers_exportHeight));
        }
        else if(i==1){
            lasers_export = ObstacleItem::create(space, Type_Lasers_export,Vec2(secondlasers_exportX,firstlasers_exportHeight));
        }
        else if(i==2){
            lasers_export = ObstacleItem::create(space, Type_Lasers_export,Vec2(firstlasers_exportX,secondlasers_exportHeight));
        }
        else if(i==3){
            lasers_export = ObstacleItem::create(space, Type_Lasers_export,Vec2(secondlasers_exportX,secondlasers_exportHeight));
        }
        else if(i==4){
            lasers_export = ObstacleItem::create(space, Type_Lasers_export,Vec2(thirdlasers_exportX,thirdlasers_exportHeight));
        }
        else if(i==5){
            lasers_export = ObstacleItem::create(space, Type_Lasers_export,Vec2(forthlasers_exportX,thirdlasers_exportHeight));
        }
        lasers_export->setTag(mapIndex);
        node->addChild(lasers_export);
        obstaclegroup17.push_back(lasers_export);
        delobjects.push_back(lasers_export);
    }
    //laser1
    for (int i=0; i<3; i++) {
        laser1 = NULL;
        laser1 = ObstacleItem::create(space, Type_Coin,Vec2(firstlasers_exportX + lasers_exportWidth+ laser1Width/2 + i*laser1Width/2 ,firstlasers_exportHeight));
        node->addChild(laser1);
        laser1->setTag(mapIndex);
        obstaclegroup17.push_back(laser1);
        delobjects.push_back(laser1);
    }
    for (int i=0; i<3; i++) {
        laser1 = NULL;
        laser1 = ObstacleItem::create(space, Type_Coin,Vec2(firstlasers_exportX + lasers_exportWidth + i*laser1Width/2 ,secondlasers_exportHeight));
        node->addChild(laser1);
        laser1->setTag(mapIndex);
        obstaclegroup17.push_back(laser1);
        delobjects.push_back(laser1);
    }
    for (int i=0; i<3; i++) {
        laser1 = NULL;
        laser1 = ObstacleItem::create(space, Type_Coin,Vec2(thirdlasers_exportX + lasers_exportWidth + i*laser1Width/2 ,thirdlasers_exportHeight));
        node->addChild(laser1);
        laser1->setTag(mapIndex);
        obstaclegroup17.push_back(laser1);
        delobjects.push_back(laser1);
    }
    
    //coins
    for (int i=0; i<6; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(firstCoinX + i*xIncrement ,firstCoinHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup17.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<6; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(firstCoinX + i*xIncrement ,secondCoinHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup17.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<6; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(secondCoinX + i*xIncrement ,thirdCoinHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup17.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<6; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(secondCoinX + i*xIncrement ,forthCoinHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup17.push_back(coin);
        delobjects.push_back(coin);
    }

}

void ObstacleGroup::updateObstacleGroup18Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth){
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    int randomCoinFactor = CCRANDOM_0_1()*(CCRANDOM_0_1()*5 + 1);
    float coinHeight = ObstacleItem::getContentSize(Type_Coin)->height;
    float coinWidth = ObstacleItem::getContentSize(Type_Coin)->width;
    float lasers_exportHeight = ObstacleItem::getContentSize(Type_Lasers_export)->height;
    float lasers_exportWidth = ObstacleItem::getContentSize(Type_Lasers_export)->width;
    float laser1Height = ObstacleItem::getContentSize(Type_Laser1)->height;
    float laser1Width = ObstacleItem::getContentSize(Type_Laser1)->width;
    float naval_mineWidth = ObstacleItem::getContentSize(Type_Naval_mine)->width;
    float naval_mineHeight = ObstacleItem::getContentSize(Type_Naval_mine)->width;
    //next coin's position
    float coinPoint_x = randomCoinFactor + mapWidth * mapIndex;
    //next coin's start position
    float startx = coinPoint_x;
    float xIncrement = coinWidth/2*3;
    
    float firstNaval_mineX = startx + xIncrement;
    float secondNaval_mineX = firstNaval_mineX + 8 * xIncrement;
    float firstNaval_mineHeight = visibleSize.height - naval_mineHeight;;
    float secondNaval_mineHeight = 72 + naval_mineHeight;
    
    float firstLasers_exportX = startx + 3 * xIncrement;
    float secondLasers_exportX = firstLasers_exportX + 4 * laser1Width + lasers_exportWidth/2;
    float firstLasers_exportHeight = visibleSize.height/2;
    
    float firstLaser1X = firstLasers_exportX + lasers_exportWidth+ laser1Width/2;
    
    float firstCoinX = firstNaval_mineX + xIncrement;
    float secondCoinX = secondNaval_mineX + xIncrement;
    
    float firstCoinHeight = visibleSize.height/2 + coinHeight/2;
    float secondCoinHeight = visibleSize.height/2 - coinHeight/2;
    
    ObstacleItem *naval_mine;
    ObstacleItem *lasers_export;
    ObstacleItem *laser1;
    ObstacleItem *coin;
    
    //naval_mine
    for (int i=0; i<4; i++) {
        naval_mine = NULL;
        if (i==0) {
            naval_mine = ObstacleItem::create(space, Type_Naval_mine,Vec2(firstNaval_mineX,firstNaval_mineHeight));
        }
        else if(i==1){
            naval_mine = ObstacleItem::create(space, Type_Naval_mine,Vec2(firstNaval_mineX,secondNaval_mineHeight));
        }
        else if(i==2){
            naval_mine = ObstacleItem::create(space, Type_Naval_mine,Vec2(secondNaval_mineX,firstNaval_mineHeight));
        }
        else if(i==3){
            naval_mine = ObstacleItem::create(space, Type_Naval_mine,Vec2(secondNaval_mineX,secondNaval_mineHeight));
        }
        naval_mine->setTag(mapIndex);
        node->addChild(naval_mine);
        obstaclegroup18.push_back(naval_mine);
        delobjects.push_back(naval_mine);
    }
    
    //lasers_export
    for (int i=0; i<2; i++) {
        lasers_export = NULL;
        if (i==0) {
            lasers_export = ObstacleItem::create(space, Type_Lasers_export,Vec2(firstLasers_exportX,firstLasers_exportHeight));
        }
        else if(i==1){
            lasers_export = ObstacleItem::create(space, Type_Lasers_export,Vec2(secondLasers_exportX,firstLasers_exportHeight));
        }
        lasers_export->setTag(mapIndex);
        node->addChild(lasers_export);
        obstaclegroup18.push_back(lasers_export);
        delobjects.push_back(lasers_export);
    }
    //laser
    for (int i=0; i<4; i++) {
        laser1 = NULL;
        laser1 = ObstacleItem::create(space, Type_Coin,Vec2(firstLaser1X + i*laser1Width/2 ,firstLasers_exportHeight));
        node->addChild(laser1);
        laser1->setTag(mapIndex);
        obstaclegroup18.push_back(laser1);
        delobjects.push_back(laser1);
    }
    //coin
    for (int i=0; i<6; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(firstCoinX + i*xIncrement ,firstCoinHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup18.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<6; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(firstCoinX + i*xIncrement ,secondCoinHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup18.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<6; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(secondCoinX + i*xIncrement ,firstCoinHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup18.push_back(coin);
        delobjects.push_back(coin);
    }
    for (int i=0; i<6; i++) {
        coin = NULL;
        coin = ObstacleItem::create(space, Type_Coin,Vec2(secondCoinX + i*xIncrement ,secondCoinHeight));
        node->addChild(coin);
        coin->setTag(mapIndex);
        obstaclegroup18.push_back(coin);
        delobjects.push_back(coin);
    }

    
}

void ObstacleGroup::updateObstacleGroup19Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth){
    
    
}

void ObstacleGroup::updateObstacleGroup20Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth){
    
    
}

//void ObstacleGroup::updateOther(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth){
//    auto visibleSize = Director::getInstance()->getVisibleSize();
//    auto origin = Director::getInstance()->getVisibleOrigin();
//    
//    int randomCoinFactor = CCRANDOM_0_1()*(CCRANDOM_0_1()*5 + 1);
//    float coinWidth = ObstacleItem::getContentSize(Type_Coin)->width;
//    float mineHeight = ObstacleItem::getContentSize(Type_Mine_chain_export)->height;
//    //next coin's position
//    float coinPoint_x = randomCoinFactor + mapWidth * mapIndex;
//    //next coin's start position
//    float startx = coinPoint_x;
//    float xIncrement = coinWidth/2*3;
//    
//    float firstRowHeight = visibleSize.height - mineHeight/2;
//
//    ObstacleItem * coin = NULL;
//    for (int i=0; i<8; i++) {
//        coin = NULL;
//        coin = ObstacleItem::create(space, a,Point(startx + i*xIncrement,firstRowHeight));
//        coin->setTag(mapIndex);
//        node->addChild(coin);
//        obstaclegroup5.push_back(coin);
//        delobjects.push_back(coin);
//    }
//
//}
int ObstacleGroup::getdelObsNum(){
    return (int)delobjects.size();
}


void ObstacleGroup::remove(ObstacleItem *obj)
{
    obj->removeFromParent();
    delobjects.remove(obj);
}

void ObstacleGroup::removeObjectOfMap(int mapIndex)
{
    // 正确的遍历删除方法
    list<ObstacleItem *>::iterator itList;
    for (itList = delobjects.begin(); itList != delobjects.end();/*Not ++ here*/) {
        ObstacleItem *sprite = (ObstacleItem *)*itList;
        if(mapIndex == sprite->getTag()) {
            sprite->removeFromParent();
            itList = delobjects.erase(itList);
        } else {
            itList++;
        }
    }

}