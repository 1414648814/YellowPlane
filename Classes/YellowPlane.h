//
//  YelloPlane.h
//  YellowPlane
//
//  Created by George on 15/5/31.
//
//
//store the actor
#ifndef __YellowPlane__YelloPlane__
#define __YellowPlane__YelloPlane__

#include <stdio.h>
#include "cocos2d.h"
#include "ImgLoader.h"
#include "chipmunk.h"
#include "cocos-ext.h"
#include "GameData.h"
using namespace cocos2d;
using namespace std;
USING_NS_CC;
#define min(X,Y) ((X) < (Y) ? (X) : (Y))
#define max(X,Y) ((X) > (Y) ? (X) : (Y))

typedef enum{
    StateNormal = 0,
    StateDamage = 1,
}ActionState;

typedef enum{
    Status_Idle,
    Status_Fly,
    Status_Die,
}PlaneStatus;

typedef enum{
    Action_Swing,
    Action_JumpUp,
    Action_JumpDown,
}PlaneAction;

class YellowPlane : public extension::PhysicsSprite{
public:
    
    YellowPlane(cpSpace *space);
    ~YellowPlane();

    void planeDemage();
    void setPlaneRotation(float angle);
    float getPlaneRotation();
    bool checkState(ActionState state);
    bool checkStatus(PlaneStatus status);
    bool checkActon(PlaneAction action);
    static YellowPlane *create(cpSpace *space);
    float getoffsetPx() {return m_offsetPx;}
    void MoveUp();
    void MoveDown();
    void MoveRight(float dt);
    void step(float dt);
    void initBody();
    void initShape(const char* type);
    void initAction();
    void rotatePlane();
    void fly();
    void initBubble();
    PlaneAction getCurAction();
    cpBody * getCpBody();
    void removeShape();
    void removeBody();
    float speed;
    bool isMoveRight;

private:
    float currentangle;
    Action * swingAction;
    Action * jumpUpAction;
    Action * jumpDownAction;
    ActionState currentState;
    PlaneStatus planestatus;
    PlaneAction curAction;;
    cpSpace *space;//current space;
    cpBody *body;// runner chipmunk body
    cpShape *shape;// runner chipmunk shape
    cocos2d::Size normalSize; // body size
    float m_offsetPx;

};
#endif /* defined(__YellowPlane__YelloPlane__) */
