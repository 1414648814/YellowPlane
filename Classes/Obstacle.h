//
//  Obstacle.h
//  YellowPlane
//
//  Created by George on 15/5/31.
//
//

#ifndef __YellowPlane__Obstacle__
#define __YellowPlane__Obstacle__

#include <stdio.h>
#include "cocos2d.h"
#include "ImgLoader.h"
#include "cocos-ext.h"
#include "chipmunk.h"
#include "GameData.h"
using namespace cocos2d;
USING_NS_CC;

typedef enum{
    Type_Laser1 = 0,
    Type_Laser2 = 1,
    Type_Lasers_export = 2,
    Type_Mine_chain_export = 3,
    Type_Mine_chains = 4,
    Type_Naval_mine = 5,
    Type_Torpedo_export = 6,
    Type_Torpedo_fire1 = 7,
    Type_Torpedo_fire2 = 8,
    Type_Coin = 9,
    a =10,
}ObstacleType;

class ObstacleItem : public extension::PhysicsSprite{
public:
    ObstacleItem(cpSpace *space, ObstacleType type,Vec2 pos);
    static ObstacleItem* create(cpSpace *space, ObstacleType type,Vec2 pos);
    virtual void removeFromParent();
    static const cocos2d::Size * getContentSize(ObstacleType type);
    cpSpace * getSpace();
    cpShape * getShape();
    void setBodyPos(Vec2 pos);
    
private:
    cpSpace *pSpace;//weak ref
    cpShape *pShape;
    cpBody *pBody;
    void createLaser1(Vec2 pos);
    void createLaser2(Vec2 pos);
    void createLasers_export(Vec2 pos);
    void createMine_chain_export(Vec2 pos);
    void createMine_chain(Vec2 pos);
    void createNaval_mine(Vec2 pos);
    void createTorpedo_export(Vec2 pos);
    void createTorpedo_fire1(Vec2 pos);
    void createTorpedo_fire2(Vec2 pos);
    void createCoin(Vec2 pos);
    void createOther(Vec2 pos);

    static const cocos2d::Size* getLaser1ContentSize();
    static const cocos2d::Size* getLaser2ContentSize();
    static const cocos2d::Size* getLasers_exportContentSize();
    static const cocos2d::Size* getMine_chain_exportContentSize();
    static const cocos2d::Size* getMine_chainContentSize();
    static const cocos2d::Size* getNaval_mineContentSize();
    static const cocos2d::Size* getTorpedo_exportContentSize();
    static const cocos2d::Size* getTorpedo_fire1ContentSize();
    static const cocos2d::Size* getTorpedo_fire2ContentSize();
    static const cocos2d::Size* getCoinContentSize();
};



#endif /* defined(__YellowPlane__Obstacle__) */
