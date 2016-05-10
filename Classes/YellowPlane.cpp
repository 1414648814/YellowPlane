//
//  YelloPlane.cpp
//  YellowPlane
//
//  Created by George on 15/5/31.
//
//
//潜艇类
#include "YellowPlane.h"

YellowPlane *YellowPlane::create(cpSpace *space)
{
    YellowPlane *plane = new YellowPlane(space);
    plane->autorelease();
    return plane;
}

YellowPlane::YellowPlane(cpSpace *space) : m_offsetPx(150.0)
{
    this->shape = NULL;
    this->space = space;
    
    //_ignoreBodyRotation
    this->_ignoreBodyRotation = true;
    Sprite::initWithSpriteFrameName("submarine_mockup_sub.png");
    this->normalSize = this->getContentSize();
    this->isMoveRight = false;
    this->speed = 150;
    initBody();
    initBubble();
    initShape("normal");// start with normal shape
    initAction();
    this->setCPBody(this->body);
    checkState(StateNormal);
    checkStatus(Status_Idle);
    checkActon(Action_Swing);
    
}

YellowPlane::~YellowPlane()
{
    this->swingAction->release();
    this->jumpUpAction->release();
    this->jumpDownAction->release();
//    this->bubble_particle->release();
    cpBodyFree(this->body);
    cpShapeFree(this->shape);
    
}

//set the plane body
void YellowPlane::initBody()
{
    // create chipmunk body
    this->body = cpBodyNew(1, cpMomentForBox(1,this->normalSize.width, this->normalSize.height));
    this->body->p = cpv(m_offsetPx, this->normalSize.height / 2);
    this->body->v = cpv(speed, 0);//run speed
    cpSpaceAddBody(this->space, this->body);
}

//init the shape
void YellowPlane::initShape(const char* type)
{
    if (this->shape) {
        cpSpaceRemoveShape(this->space, this->shape);
    }
    float radius = this->normalSize.width/ 2;
    
    //if (0 == strcmp(type, "normal")) {
        this->shape = cpCircleShapeNew(this->body, radius, cpvzero);
    //} else {
        
    //}
    cpSpaceAddShape(this->space, this->shape);
    cpShapeSetCollisionType(this->shape,SpriteYelloPlane);
}

//init the action
void YellowPlane::initAction(){

    ActionInterval * up = MoveBy::create(0.4f, Point(0,8));
    ActionInterval * upBack = up->reverse();
    this->swingAction = RepeatForever::create(Sequence::create(up,upBack, NULL));
    this->runAction(swingAction);
    this->swingAction->retain();
    
    ActionInterval * rotateup = RotateBy::create(0.2f, -30);
    //ActionInterval * moveup = MoveBy::create(0.2, Vec2(this->getPhysicsBody()->getVelocity().x + 20,this->getPhysicsBody()->getVelocity().y + 30));
    this->jumpUpAction = Sequence::create(rotateup,NULL);
    this->jumpUpAction->retain();
    
    ActionInterval * rotatedown = RotateBy::create(0.4f, 20);
    this->jumpDownAction = Sequence::create(rotatedown, NULL);
    this->jumpDownAction->retain();
    
}

//set the bubble of plane
void YellowPlane::initBubble(){
    
}

//set the demaged plane
void YellowPlane::planeDemage(){
    checkState(StateDamage);
    this->setSpriteFrame("submarine_damaged.png");
}

//check the state
bool YellowPlane::checkState(ActionState newstate){
    currentState = newstate;
    return true;
}

//check the status
bool YellowPlane::checkStatus(PlaneStatus status){
    planestatus = status;
    return true;
}

//check the action
bool YellowPlane::checkActon(PlaneAction action){
    curAction = action;
    return true;
}

//set the plane rotation
void YellowPlane::setPlaneRotation(float angle){
    currentangle = angle;
    cpBodySetAngle(this->body,currentangle);
}

//get the plane rotation angle
float YellowPlane::getPlaneRotation(){
    return currentangle;
}

PlaneAction YellowPlane::getCurAction(){
    return this->curAction;
}

//rotate the plane
void YellowPlane::rotatePlane(){
//    float verticalSpeed = this->getPhysicsBody()->getVelocity().y;
//    this->setRotation(min(max(-90, (verticalSpeed*0.2 + 60)), 30));
}

//set the plane fly action
void YellowPlane::fly(){
    if (checkStatus(Status_Fly)) {
        this->_ignoreBodyRotation = false;
        cpBodyApplyImpulse(this->body, cpv(0, 450), cpv(0, 100));
        this->stopAllActions();
        this->runAction(this->jumpUpAction);
        checkActon(Action_JumpUp);
    }
}

void YellowPlane::removeShape(){
    cpSpaceRemoveShape(this->space, this->shape);

}

void YellowPlane::removeBody(){
    cpSpaceRemoveBody(this->space, this->body);

}

cpBody * YellowPlane::getCpBody(){
    return this->body;
}

//check the plane's state
void YellowPlane::step(float dt)
{
    //刚体重心的位置
    cpVect vel = cpBodyGetVel(this->body);
    if (curAction == Action_JumpUp) {
        if (vel.y < 0.1) {
            this->stopAllActions();
            this->runAction(this->jumpDownAction);
            checkActon(Action_JumpDown);
            //CCLOG("vel.y==%f",vel.y);
        }
        return;
    }
    if (curAction == Action_JumpDown) {
        if (vel.y == 0) {
            this->stopAllActions();
            //cpBodyApplyForce(body, cpv(0, 100.0), cpv(0, 0));//将力作用上
            this->runAction(this->swingAction);
            this->_ignoreBodyRotation = true;
            checkActon(Action_Swing);
            //CCLOG("vel.y==%f",vel.y);
        }
        return;
    }
    
}



