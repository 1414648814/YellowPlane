//
//  ObjiectManager.h
//  YellowPlane
//
//  Created by George on 15/6/3.
//
//

#ifndef __YellowPlane__ObjiectManager__
#define __YellowPlane__ObjiectManager__

#include <stdio.h>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "chipmunk.h"
#include "ObstacleGroup.h"
#include "GroundItemGroup.h"
#include "ObstacleGroup.h"
#include "Obstacle.h"
#include<time.h>
#define random(x) (rand()%x)
USING_NS_CC;

class ObjectManager
{
private:
    cpSpace *pSpace;
    SpriteBatchNode *pSpriteSheet;
    Layer *player;
    float mapwidth;
    int currgroup;
    
public:
    ObstacleGroup *obstaclegroup;
    
    ObjectManager(Layer *layer,SpriteBatchNode *spriteSheet,cpSpace *space,float mapwidth);
    ~ObjectManager();
    
    void updateObstacleGroup1(int mapIndex, float mapWidth,ObstacleGroup * temp);
    void updateObstacleGroup2(int mapIndex, float mapWidth,ObstacleGroup * temp);
    void updateObstacleGroup3(int mapIndex, float mapWidth,ObstacleGroup * temp);
    void updateObstacleGroup4(int mapIndex, float mapWidth,ObstacleGroup * temp);
    void updateObstacleGroup5(int mapIndex, float mapWidth,ObstacleGroup * temp);
    void updateObstacleGroup6(int mapIndex, float mapWidth,ObstacleGroup * temp);
    void updateObstacleGroup7(int mapIndex, float mapWidth,ObstacleGroup * temp);
    void updateObstacleGroup8(int mapIndex, float mapWidth,ObstacleGroup * temp);
    void updateObstacleGroup9(int mapIndex, float mapWidth,ObstacleGroup * temp);
    void updateObstacleGroup10(int mapIndex, float mapWidth,ObstacleGroup * temp);
    void updateObstacleGroup11(int mapIndex, float mapWidth,ObstacleGroup * temp);
    void updateObstacleGroup12(int mapIndex, float mapWidth,ObstacleGroup * temp);
    void updateObstacleGroup13(int mapIndex, float mapWidth,ObstacleGroup * temp);
    void updateObstacleGroup14(int mapIndex, float mapWidth,ObstacleGroup * temp);
    void updateObstacleGroup15(int mapIndex, float mapWidth,ObstacleGroup * temp);
    void updateObstacleGroup16(int mapIndex, float mapWidth,ObstacleGroup * temp);
    void updateObstacleGroup17(int mapIndex, float mapWidth,ObstacleGroup * temp);
    void updateObstacleGroup18(int mapIndex, float mapWidth,ObstacleGroup * temp);
    void updateObstacleGroup19(int mapIndex, float mapWidth,ObstacleGroup * temp);
    void updateObstacleGroup20(int mapIndex, float mapWidth,ObstacleGroup * temp);
    
    void updateObstacle(int mapIndex, ObstacleGroup * temp);
    float getMapWidth(){return mapwidth;};
    int getCurrentObj(){return currgroup;};
    bool scrollItem(float planeX);
    void updateOther(int mapIndex, float mapWidth);
    void generateBrokenParticle(ObstacleItem * item);
    
    void remove(ObstacleItem *item);
    void removeObjectOfMap(int mapIndex);
    
    int getdelObjs();
    
};

#endif /* defined(__YellowPlane__ObjiectManager__) */
