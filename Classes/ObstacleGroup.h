//
//  ObstacleGroup.h
//  YellowPlane
//
//  Created by George on 15/6/9.
//
//

#ifndef __YellowPlane__ObstacleGroup__
#define __YellowPlane__ObstacleGroup__

#include <stdio.h>
#include "cocos2d.h"
#include "chipmunk.h"
#include "ImgLoader.h"
#include "Obstacle.h"
#include "Map.h"
#include "cocos-ext.h"

using namespace std;

class ObstacleGroup{
public:

    ObstacleGroup();
    ~ObstacleGroup();
    
    
    void updateObstacleGroup1Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth);
    void updateObstacleGroup2Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth);
    void updateObstacleGroup3Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth);
    void updateObstacleGroup4Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth);
    void updateObstacleGroup5Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth);
    void updateObstacleGroup6Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth);
    void updateObstacleGroup7Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth);
    void updateObstacleGroup8Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth);
    void updateObstacleGroup9Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth);
    void updateObstacleGroup10Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth);
    void updateObstacleGroup11Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth);
    void updateObstacleGroup12Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth);
    void updateObstacleGroup13Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth);
    void updateObstacleGroup14Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth);
    void updateObstacleGroup15Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth);
    void updateObstacleGroup16Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth);
    void updateObstacleGroup17Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth);
    void updateObstacleGroup18Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth);
    void updateObstacleGroup19Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth);
    void updateObstacleGroup20Pos(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth);
    void remove(ObstacleItem *obj);
    void removeObjectOfMap(int mapIndex);
    void updateOther(SpriteBatchNode * node, cpSpace *space,int mapIndex, float mapWidth);
    int getdelObsNum();
    
private:
    list<ObstacleItem *> obstaclegroup1;
    list<ObstacleItem *> obstaclegroup2;
    list<ObstacleItem *> obstaclegroup3;
    list<ObstacleItem *> obstaclegroup4;
    list<ObstacleItem *> obstaclegroup5;
    //list<ObstacleItem *> obstaclegroup6;
    list<ObstacleItem *> obstaclegroup7;
    list<ObstacleItem *> obstaclegroup8;
    list<ObstacleItem *> obstaclegroup9;
    list<ObstacleItem *> obstaclegroup10;
    list<ObstacleItem *> obstaclegroup11;
    list<ObstacleItem *> obstaclegroup12;
    list<ObstacleItem *> obstaclegroup13;
    list<ObstacleItem *> obstaclegroup14;
    list<ObstacleItem *> obstaclegroup15;
    list<ObstacleItem *> obstaclegroup16;
    list<ObstacleItem *> obstaclegroup17;
    list<ObstacleItem *> obstaclegroup18;
    list<ObstacleItem *> obstaclegroup19;
    list<ObstacleItem *> obstaclegroup20;
    
    list<ObstacleItem *> delobjects;

};

#endif /* defined(__YellowPlane__ObstacleGroup__) */
