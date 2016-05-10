//
//  PowerUp.h
//  YellowPlane
//
//  Created by George on 15/6/11.
//
//

#ifndef __YellowPlane__PowerUp__
#define __YellowPlane__PowerUp__

#include <stdio.h>
#include "cocos2d.h"
#include "ImgLoader.h"
#include "cocos-ext.h"
#include "chipmunk.h"
#include "GameData.h"
using namespace cocos2d;
using namespace std;
USING_NS_CC;

typedef enum{
    Type_Revive_Particle = 0,
    Type_Bubble_Particle = 1,
    Type_Sonic_blast_Particle = 2,
    Type_Speed_Front_Particle = 3,
    Type_Speed_Back_Particle = 4,
    Type_Obstacle_Torpedo_export = 5,
}PowerUpParticleType;

typedef enum{
    Type_Revive_Icon = 0,
    Type_Bubble_Icon = 1,
    Type_Sonic_blast_Icon = 2,
    Type_Speed_Icon = 3
}PowerUpIconType;

typedef enum {
    PowerUpJumpUp = 0,
    PowerUpJumpDown = 1,
    PowerUpIdle = 2,
}PowerUpAction;

typedef enum{
    PowerUp_Idle = 0,
    PowerUp_Fly = 1,
}PowerUpStatus;

class PowerUp : public extension::PhysicsSprite{
public:
    PowerUp(cpSpace *space, PowerUpIconType type,Vec2 pos);
    static PowerUp* create(cpSpace *space, PowerUpIconType type,Vec2 pos);
    virtual void removeFromParent();
    static const cocos2d::Size * getContentSize(PowerUpIconType type);
    void step(float dt);
    
private:
    cpSpace *pSpace;//weak ref
    cpShape *pShape;
    cpBody *pBody;
    float speed;
    Action * swingAction;
    Action * jumpUpAction;
    Action * jumpDownAction;
    const cocos2d::Size *normalSize; // body size
    PowerUpAction curAction;
    PowerUpStatus curStatus;
    ParticleSystem * particleSystem;
    ParticleBatchNode * batch;
    cpBody * getCpBody();
    void createReviveIcon(Vec2 pos);
    void createBubbleIcon(Vec2 pos);
    void createSonic_blastIcon(Vec2 pos);
    void createSpeedIcon(Vec2 pos);
    void changeAction(PowerUpAction action);
    void changeStatus(PowerUpStatus status);
    void initAction(PowerUpIconType type);
    void initBody(PowerUpIconType type);
    void initShape(PowerUpIconType type);
    void initParticle(PowerUpIconType type);
    void initStatus(PowerUpIconType type);
    void fly();
    float getSpeed();
    void setSpeed(float newspeed);
    PowerUpAction getCurAction();

};

class PowerUpParticle: public extension::PhysicsSprite{
public:
    PowerUpParticle(cpSpace *space,PowerUpParticleType type,Vec2 pos);
    static PowerUpParticle* create(cpSpace *space,PowerUpParticleType type,Vec2 pos);
    virtual void removeFromParent();
    void removeObstacle_Torpedo_export();
    static cocos2d::Size  getContentSize(PowerUpParticleType type);
private:
    cpSpace *pSpace;//weak ref
    cpShape *pShape;
    cpBody *pBody;
    float speed;
    ParticleBatchNode * batch;
    cpBody * getCpBody();
    cocos2d::Size normalSize; // body size
    
    void initBody(PowerUpParticleType type);
    void initShape(PowerUpParticleType type);
    void initParticle(PowerUpParticleType type);
    void createBubbleParticle(Vec2 pos);
    void createSonic_blastParticle(Vec2 pos);
    void createSpeedFrontParticle(Vec2 pos);
    void crateObstacle_Torpedo_export(Vec2 pos);
    float getSpeed();
    void setSpeed(float newspeed);

};



#endif /* defined(__YellowPlane__PowerUp__) */
