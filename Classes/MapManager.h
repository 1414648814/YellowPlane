//
//  MapLayer.h
//  YellowPlane
//
//  Created by George on 15/5/31.
//
//
//store the maplayer which it haves many items
#ifndef __YellowPlane__MapLayer__
#define __YellowPlane__MapLayer__

#include <stdio.h>
#include "cocos2d.h"
#include "chipmunk.h"
#include "Map.h"
#include "GroundItemGroup.h"
#include<time.h>
#define random(x) (rand()%x)
using namespace cocos2d;

USING_NS_CC;

class MAP;

class MapManager : public Node{
private:
    int curmap; //displayed map
    float mapwidth;
    cpSpace *space;
    MAP *map0;
    MAP *map1;
    SpriteBatchNode *pSpriteSheet;
    SpriteBatchNode *forepSpriteSheet;
    
public:
    GroundItemGroup *groundGroup0;
    GroundItemGroup *groundGroup1;
    
    MapManager(Layer *parent, SpriteBatchNode * node,SpriteBatchNode * node2,cpSpace *pSpace);
    ~MapManager();
    int getCurrentMap(){return curmap;};
    float getMapWidth(){return mapwidth;};
    bool checkAndReload(float planeX);
    
    void initForeGround(float mapWidth,int mapIndex,GroundItemGroup * group);
    void initMidGround(float mapWidth,int mapIndex,GroundItemGroup * group);
    void initBackGround(float mapWidth,int mapIndex,GroundItemGroup * group);
    void removeObjectOfMap(int mapIndex);
};

#endif /* defined(__YellowPlane__MapLayer__) */
