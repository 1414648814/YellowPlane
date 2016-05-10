//
//  GroundItemGroup.h
//  YellowPlane
//
//  Created by George on 15/6/9.
//
//

#ifndef __YellowPlane__GroundItemGroup__
#define __YellowPlane__GroundItemGroup__

#include <stdio.h>

#include "cocos2d.h"
#include "chipmunk.h"
#include "GameData.h"
#include "ImgLoader.h"
#include "GroundItem.h"

using namespace std;

class GroundItemGroup{
public:

    GroundItemGroup();
    ~GroundItemGroup();
    
    void updateForeGroundGroup1Pos(SpriteBatchNode * node,int mapIndex, float mapWidth);
    void updateForeGroundGroup2Pos(SpriteBatchNode * node,int mapIndex, float mapWidth);
    void updateForeGroundGroup3Pos(SpriteBatchNode * node,int mapIndex, float mapWidth);
    void updateForeGroundGroup4Pos(SpriteBatchNode * node,int mapIndex, float mapWidth);
    void updateForeGroundGroup5Pos(SpriteBatchNode * node,int mapIndex, float mapWidth);
    void updateForeGroundGroup6Pos(SpriteBatchNode * node,int mapIndex, float mapWidth);
    void updateForeGroundGroup7Pos(SpriteBatchNode * node,int mapIndex, float mapWidth);
    void updateForeGroundGroup8Pos(SpriteBatchNode * node,int mapIndex, float mapWidth);
    
    void updateMidGroundGroup1Pos(SpriteBatchNode * node,int mapIndex, float mapWidth);
    void updateMidGroundGroup2Pos(SpriteBatchNode * node,int mapIndex, float mapWidth);
    void updateMidGroundGroup3Pos(SpriteBatchNode * node,int mapIndex, float mapWidth);
    void updateMidGroundGroup4Pos(SpriteBatchNode * node,int mapIndex, float mapWidth);
    void updateMidGroundGroup5Pos(SpriteBatchNode * node,int mapIndex, float mapWidth);
    void updateMidGroundGroup6Pos(SpriteBatchNode * node,int mapIndex, float mapWidth);
    
    void updateBackGroundGroup1Pos(SpriteBatchNode * node,int mapIndex, float mapWidth);
    void updateBackGroundGroup2Pos(SpriteBatchNode * node,int mapIndex, float mapWidth);
    void updateBackGroundGroup3Pos(SpriteBatchNode * node,int mapIndex, float mapWidth);
    void updateBackGroundGroup4Pos(SpriteBatchNode * node,int mapIndex, float mapWidth);
    
    void removeObjectOfMap(int mapIndex);
    list<Sprite*> delobjects;
private:
    list<Sprite*> fore_elements1;
    list<Sprite*> fore_elements2;
    list<Sprite*> fore_elements3;
    list<Sprite*> fore_elements4;
    list<Sprite*> fore_elements5;
    list<Sprite*> fore_elements6;
    list<Sprite*> fore_elements7;
    list<Sprite*> fore_elements8;
    
    list<Sprite*> mid_elements1;
    list<Sprite*> mid_elements2;
    list<Sprite*> mid_elements3;
    list<Sprite*> mid_elements4;
    list<Sprite*> mid_elements5;
    list<Sprite*> mid_elements6;
    
    list<Sprite*> back_elements1;
    list<Sprite*> back_elements2;
    list<Sprite*> back_elements3;
    list<Sprite*> back_elements4;
    
    
};

#endif /* defined(__YellowPlane__GroundItemGroup__) */
