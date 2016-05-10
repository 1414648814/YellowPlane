//
//  MapLayer.cpp
//  YellowPlane
//
//  Created by George on 15/5/31.
//
//

#include "MapManager.h"

MapManager::MapManager(Layer *parent, SpriteBatchNode * node,SpriteBatchNode * node2,cpSpace *pSpace):
curmap(0)
,mapwidth(0)
{
    this->space = pSpace;
    this->pSpriteSheet = node;
    this->forepSpriteSheet = node2;
    
    this->setAnchorPoint(Point::ZERO);
    
    this->pSpriteSheet->setAnchorPoint(Vec2(0,0));
    this->forepSpriteSheet->setAnchorPoint(Vec2(0,0));
    
    this->map0 = MAP::create(0);
    this->map0->setTag(0);
    this->map0->setPosition(0,0);
    parent->addChild(this->map0,1);
    
    mapwidth = this->map0->getContentSize().width;
    
    this->map1 = MAP::create(1);
    this->map1->setTag(1);
    this->map1->setPosition(mapwidth,0);
    parent->addChild(this->map1,1);
    
    this->groundGroup0 = new GroundItemGroup();
    
}

MapManager::~MapManager(){
    
}

//初始化fore的grounditem
void MapManager::initForeGround(float mapWidth,int mapIndex,GroundItemGroup * group){
    srand((int)time(0));
    int foreNum = random(1)+1;
    switch (foreNum) {
        case 1:
            group->updateForeGroundGroup1Pos(this->forepSpriteSheet,mapWidth,mapIndex);
            break;
        case 2:
            group->updateForeGroundGroup2Pos(this->forepSpriteSheet,mapIndex, mapWidth);
            break;
        case 3:
            group->updateForeGroundGroup3Pos(this->forepSpriteSheet,mapIndex, mapWidth);
            break;
        case 4:
            group->updateForeGroundGroup4Pos(this->forepSpriteSheet,mapIndex, mapWidth);
            break;
        case 5:
            group->updateForeGroundGroup5Pos(this->forepSpriteSheet,mapIndex, mapWidth);
            break;
        case 6:
            group->updateForeGroundGroup6Pos(this->forepSpriteSheet,mapIndex, mapWidth);
            break;
        case 7:
            group->updateForeGroundGroup7Pos(this->forepSpriteSheet,mapIndex, mapWidth);
            break;
        case 8:
            group->updateForeGroundGroup8Pos(this->forepSpriteSheet,mapIndex, mapWidth);
            break;
    }
}

//初始化mid的grounditem
void MapManager::initMidGround(float mapWidth,int mapIndex,GroundItemGroup * group){
    srand((int)time(0));
    int MidNum = random(1)+1;
    switch (MidNum) {
        case 1:
            group->updateMidGroundGroup1Pos(this->pSpriteSheet,mapIndex, mapWidth);
            break;
        case 2:
            group->updateMidGroundGroup2Pos(this->pSpriteSheet,mapIndex, mapWidth);
            break;
        case 3:
            group->updateMidGroundGroup3Pos(this->pSpriteSheet,mapIndex, mapWidth);
            break;
        case 4:
            group->updateMidGroundGroup4Pos(this->pSpriteSheet,mapIndex, mapWidth);
            break;
        case 5:
            group->updateMidGroundGroup5Pos(this->pSpriteSheet,mapIndex, mapWidth);
            break;
        case 6:
            group->updateMidGroundGroup6Pos(this->pSpriteSheet,mapIndex, mapWidth);
            break;
    }


}

//初始化back的grounditem
void MapManager::initBackGround(float mapWidth,int mapIndex,GroundItemGroup * group){
    srand((int)time(0));
    int BackNum = random(1)+1;
    switch (BackNum) {
        case 1:
            group->updateBackGroundGroup1Pos(this->pSpriteSheet,mapIndex, mapWidth);
            break;
        case 2:
            group->updateBackGroundGroup2Pos(this->pSpriteSheet,mapIndex, mapWidth);
            break;
        case 3:
            group->updateBackGroundGroup3Pos(this->pSpriteSheet,mapIndex, mapWidth);
            break;
        case 4:
            group->updateBackGroundGroup4Pos(this->pSpriteSheet,mapIndex, mapWidth);
            break;

    }

}

//根据map的index去删除地图
void MapManager::removeObjectOfMap(int mapIndex){
    this->groundGroup0->removeObjectOfMap(mapIndex);
}

//
bool MapManager::checkAndReload(float planeX)
{
    int newCur = planeX/mapwidth;
    if (curmap == newCur) {
        return false;
    }
    MAP * currentMap = NULL;
    if (newCur % 2==0) {
        currentMap = this->map1;
    }
    else{
        currentMap = this->map0;
    }
    curmap = newCur;
    currentMap->loadImg(curmap+1);
    return true;
}



