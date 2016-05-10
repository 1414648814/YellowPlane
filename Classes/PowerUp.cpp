//
//  PowerUp.cpp
//  YellowPlane
//
//  Created by George on 15/6/11.
//
//
//能量的类
#include "PowerUp.h"

//PowerUpIcon
PowerUp::PowerUp(cpSpace *space, PowerUpIconType type,Vec2 pos){
    this->pShape = NULL;
    this->pSpace = space;
    
    this->_ignoreBodyRotation = true;
    this->speed = -50.0;
    
    switch (type) {
        case Type_Revive_Icon:
            createReviveIcon(pos);
            break;
        case Type_Bubble_Icon:
            createBubbleIcon(pos);
            break;
        case Type_Sonic_blast_Icon:
            createSonic_blastIcon(pos);
            break;
        case Type_Speed_Icon:
            createSpeedIcon(pos);
            break;
    }
    
}

PowerUp* PowerUp::create(cpSpace *space, PowerUpIconType type,Vec2 pos){
    PowerUp * powerup = new PowerUp(space,type,pos);
    powerup->autorelease();
    return powerup;
}

void PowerUp::removeFromParent(){
    this->swingAction->release();
    this->jumpDownAction->release();
    this->jumpUpAction->release();
    cpSpaceRemoveShape(this->pSpace, this->pShape);
    cpSpaceRemoveBody(this->pSpace, this->pBody);
    PhysicsSprite::removeFromParent();
}

const Size * PowerUp::getContentSize(PowerUpIconType type){
    const Size * size;
    switch (type) {
        case Type_Revive_Icon:
            size = &PhysicsSprite::createWithSpriteFrameName("revive_icon.png")->getContentSize();
            break;
        case Type_Bubble_Icon:
            size = &PhysicsSprite::createWithSpriteFrameName("shield_icon.png")->getContentSize();
            break;
        case Type_Sonic_blast_Icon:
            size = &PhysicsSprite::createWithSpriteFrameName("sonic_wave_icon.png")->getContentSize();
            break;
        case Type_Speed_Icon:
            size = &PhysicsSprite::createWithSpriteFrameName("speed_icon.png")->getContentSize();
            break;
    }
    return size;
}

float PowerUp::getSpeed(){
    return this->speed;

}
void PowerUp::setSpeed(float newspeed){
    this->speed = newspeed;
}
//revive
void PowerUp::createReviveIcon(Vec2 pos){
    this->initWithSpriteFrameName("revive_icon.png");
    this->normalSize = this->getContentSize(Type_Revive_Icon);
    initBody(Type_Revive_Icon);
    this->initShape(Type_Revive_Icon);
    initParticle(Type_Revive_Icon);
    initAction(Type_Revive_Icon);
    initStatus(Type_Revive_Icon);
    this->setCPBody(this->pBody);
    cpBodySetPos(this->pBody, cpv(pos.x, pos.y));
    cpShapeSetUserData(this->pShape, this);
    
}
//bubble
void PowerUp::createBubbleIcon(Vec2 pos){
    this->initWithSpriteFrameName("shield_icon.png");
    this->normalSize = this->getContentSize(Type_Bubble_Icon);
    initBody(Type_Bubble_Icon);
    this->initShape(Type_Bubble_Icon);
    initParticle(Type_Bubble_Icon);
    initAction(Type_Bubble_Icon);
    initStatus(Type_Bubble_Icon);
    this->setCPBody(this->pBody);
    cpBodySetPos(this->pBody, cpv(pos.x, pos.y));
    cpShapeSetUserData(this->pShape, this);
    
}
//sonic_wave
void PowerUp::createSonic_blastIcon(Vec2 pos){
    this->initWithSpriteFrameName("sonic_wave_icon.png");
    this->normalSize = this->getContentSize(Type_Sonic_blast_Icon);
    initBody(Type_Sonic_blast_Icon);
    this->initShape(Type_Sonic_blast_Icon);
    initParticle(Type_Sonic_blast_Icon);
    initAction(Type_Sonic_blast_Icon);
    initStatus(Type_Sonic_blast_Icon);
    this->setCPBody(this->pBody);
    cpBodySetPos(this->pBody, cpv(pos.x, pos.y));
    cpShapeSetUserData(this->pShape, this);
}
//speed
void PowerUp::createSpeedIcon(Vec2 pos){
    this->initWithSpriteFrameName("speed_icon.png");
    this->normalSize = this->getContentSize(Type_Speed_Icon);
    initBody(Type_Speed_Icon);
    this->initShape(Type_Speed_Icon);
    initParticle(Type_Speed_Icon);
    initAction(Type_Speed_Icon);
    initStatus(Type_Speed_Icon);
    this->setCPBody(this->pBody);
    cpBodySetPos(this->pBody, cpv(pos.x, pos.y));
    cpShapeSetUserData(this->pShape, this);
}

//init the action
void PowerUp::initAction(PowerUpIconType type){
    switch (type) {
        case Type_Revive_Icon:
            break;
        case Type_Bubble_Icon:
            break;
        case Type_Sonic_blast_Icon:
            break;
        case Type_Speed_Icon:
            break;
    }
    ActionInterval * up = MoveBy::create(0.4f, Point(0,5));
    ActionInterval * upBack = up->reverse();
    this->swingAction= RepeatForever::create(Sequence::create(up,upBack, NULL));
    this->runAction(swingAction);
    this->swingAction->retain();
    this->curAction = PowerUpIdle;
    
    ActionInterval * moveup = MoveBy::create(2, Vec2(0,400));
    this->jumpUpAction = Sequence::create(moveup,NULL);
    this->jumpUpAction->retain();
    
    ActionInterval * movedown = MoveBy::create(3, Vec2(0,100));
    this->jumpDownAction = Sequence::create(movedown, NULL);
    this->jumpDownAction->retain();

}
//init the body
void PowerUp::initBody(PowerUpIconType type)
{
    // create chipmunk body
    this->pBody = cpBodyNew(1, cpMomentForBox(1,this->normalSize->width, this->normalSize->height));
    this->pBody->v = cpv(speed, 0);//run speed
    cpSpaceAddBody(this->pSpace, this->pBody);
}

//init the shape
void PowerUp::initShape(PowerUpIconType type)
{
    if (this->pShape) {
        cpSpaceRemoveShape(this->pSpace, this->pShape);
    }
    float radius = this->normalSize->width/ 2;
    
    this->pShape = cpCircleShapeNew(this->pBody, radius, cpvzero);
    cpSpaceAddShape(this->pSpace, this->pShape);
    switch (type) {
        case Type_Revive_Icon:
            cpShapeSetCollisionType(this->pShape,SpriteRevive);
            break;
        case Type_Bubble_Icon:
            cpShapeSetCollisionType(this->pShape,SpriteShield);
            break;
        case Type_Sonic_blast_Icon:
            cpShapeSetCollisionType(this->pShape,SpriteSonicWave);
            break;
        case Type_Speed_Icon:
            cpShapeSetCollisionType(this->pShape,SpriteSpeed);
            break;
    }
    
}

//init the particle
void PowerUp::initParticle(PowerUpIconType type){
    switch (type) {
        case Type_Revive_Icon:
            break;
        case Type_Bubble_Icon:
            break;
        case Type_Sonic_blast_Icon:
            break;
        case Type_Speed_Icon:
            break;
    }
    this->particleSystem = ParticleSystemQuad::create("res/Particles/PowerLastParticle.plist");
    this->particleSystem->setPositionType(ParticleSystem::PositionType::RELATIVE);
    this->batch = ParticleBatchNode::createWithTexture(this->particleSystem->getTexture());
    this->batch->addChild(this->particleSystem);
}

void PowerUp::initStatus(PowerUpIconType type){
    this->curStatus = PowerUp_Idle;
}

PowerUpAction PowerUp::getCurAction(){
    return this->curAction;
}

void PowerUp::changeAction(PowerUpAction action){
    this->curAction = action;
}

void PowerUp::changeStatus(PowerUpStatus status){
    this->curStatus = status;
}

cpBody * PowerUp::getCpBody(){
    return this->pBody;
}

void PowerUp::fly(){
    if (this->curStatus == PowerUp_Idle) {
        cpBodyApplyImpulse(this->pBody, cpv(0, 450), cpv(0, 100));
        this->stopAllActions();
        this->runAction(this->jumpUpAction);
        this->curStatus = PowerUp_Fly;
        this->curAction = PowerUpJumpUp;
    }
}


void PowerUp::step(float dt){
    this->fly();
    cpVect vel = cpBodyGetVel(this->pBody);
    if (curAction == PowerUpJumpUp) {
        if (vel.y < 0.1) {
            this->stopAllActions();
            this->runAction(this->jumpDownAction);
            this->curAction = PowerUpJumpDown;
        }
        return;
    }
    if (curAction == PowerUpJumpDown) {
        if (vel.y == 0) {
            this->stopAllActions();
            //cpBodyApplyForce(body, cpv(0, 100.0), cpv(0, 0));//将力作用上
            this->runAction(this->swingAction);
            this->curAction = PowerUpIdle;
            this->curStatus = PowerUp_Idle;
        }
        return;
    }
//    this->batch->setPosition(Vec2(this->getPosition().x,this->getPosition().y));
}


/*
 
 PowerUpParticle
 
 */

float sonicwaveAngle;

PowerUpParticle::PowerUpParticle(cpSpace *space,PowerUpParticleType type,Vec2 pos){
    this->pShape = NULL;
    this->pSpace = space;
    
    this->_ignoreBodyRotation = true;
    switch (type) {
        case Type_Bubble_Particle:
            createBubbleParticle(pos);
            break;
        case Type_Sonic_blast_Particle:
            createSonic_blastParticle(pos);
            break;
        case Type_Speed_Front_Particle:
            createSpeedFrontParticle(pos);
            break;
        case Type_Obstacle_Torpedo_export:
            crateObstacle_Torpedo_export(pos);
            break;
    }
    
}

PowerUpParticle* PowerUpParticle::create(cpSpace *space,PowerUpParticleType type,Vec2 pos){
    PowerUpParticle * particle = new PowerUpParticle(space,type,pos);
    particle->autorelease();
    return particle;
}

void PowerUpParticle::removeFromParent(){
    cpSpaceRemoveShape(this->pSpace, this->pShape);
    cpSpaceRemoveBody(this->pSpace, this->pBody);
    PhysicsSprite::removeFromParent();
}

void PowerUpParticle::removeObstacle_Torpedo_export(){
    cpSpaceRemoveShape(this->pSpace, this->pShape);
    cpBodyFree(this->pBody);
    PhysicsSprite::removeFromParent();
}

cpBody * PowerUpParticle::getCpBody(){
    return this->pBody;

}

Size  PowerUpParticle::getContentSize(PowerUpParticleType type){
    Size  size;
    switch (type) {
        case Type_Bubble_Particle:
        {
            size = PhysicsSprite::createWithSpriteFrameName("shield_bubble.png")->getContentSize();
        }
        break;
        case Type_Sonic_blast_Particle:
        {
            float winheight = Director::getInstance()->getVisibleSize().height - 72;
            float itemheight = PhysicsSprite::createWithSpriteFrameName("sonic_blast.png")->getContentSize().height;
            sonicwaveAngle = winheight/itemheight;
            size = Size(Point(PhysicsSprite::createWithSpriteFrameName("sonic_blast.png")->getContentSize().width, winheight));
        }
        break;
        case Type_Speed_Front_Particle:
        {
            size = PhysicsSprite::createWithSpriteFrameName("speed_particle_front.png")->getContentSize();
        }
        break;
        case Type_Obstacle_Torpedo_export:
        {
            size = PhysicsSprite::createWithSpriteFrameName("torpedo_export.png")->getContentSize();
        }
        break;
    }
    return size;

}

float PowerUpParticle::getSpeed(){
    return this->speed;
    
}
void PowerUpParticle::setSpeed(float newspeed){
    this->speed = newspeed;
}

void PowerUpParticle::initBody(PowerUpParticleType type){
    // create chipmunk body
    this->pBody = cpBodyNew(1, cpMomentForBox(1,this->normalSize.width, this->normalSize.height));
    this->pBody->v = cpv(speed, 0);//run speed
    cpSpaceAddBody(this->pSpace, this->pBody);

}

void PowerUpParticle::initShape(PowerUpParticleType type){
    if (this->pShape) {
        cpSpaceRemoveShape(this->pSpace, this->pShape);
    }
    
    this->pShape = cpBoxShapeNew(this->pBody, this->getContentSize(type).width, this->getContentSize(type).height);
    cpSpaceAddShape(this->pSpace, this->pShape);
    switch (type) {
        case Type_Bubble_Particle:
            cpShapeSetCollisionType(this->pShape,SpriteShieldParticle);
            break;
        case Type_Sonic_blast_Particle:
            cpShapeSetCollisionType(this->pShape,SpriteSonicWaveParticle);
            break;
        case Type_Speed_Front_Particle:
            cpShapeSetCollisionType(this->pShape,SpriteSpeedFrontParticle);
            break;
        case Type_Obstacle_Torpedo_export:
            cpShapeSetCollisionType(this->pShape,SpriteTorpedo_export);
            break;
    }

}

void PowerUpParticle::initParticle(PowerUpParticleType type){


}

void PowerUpParticle::createBubbleParticle(Vec2 pos){
    this->speed = 100.0;
    this->initWithSpriteFrameName("shield_bubble.png");
    this->normalSize = this->getContentSize(Type_Bubble_Particle);
    initBody(Type_Bubble_Particle);
    this->initShape(Type_Bubble_Particle);
    this->setCPBody(this->pBody);
    cpBodySetPos(this->pBody, cpv(pos.x, pos.y));
    cpShapeSetUserData(this->pShape, this);
    
}

void PowerUpParticle::createSonic_blastParticle(Vec2 pos){
    this->speed = 400.0;
    this->initWithSpriteFrameName("sonic_blast.png");
    this->normalSize = this->getContentSize(Type_Sonic_blast_Particle);
    initBody(Type_Sonic_blast_Particle);
    this->initShape(Type_Sonic_blast_Particle);
    this->setCPBody(this->pBody);
    cpBodySetPos(this->pBody, cpv(pos.x, pos.y));
    this->setScale(1, sonicwaveAngle);
    cpShapeSetUserData(this->pShape, this);

}

void PowerUpParticle::createSpeedFrontParticle(Vec2 pos){
    this->speed = 100.0;
    this->initWithSpriteFrameName("speed_particle_front.png");
    this->normalSize = this->getContentSize(Type_Speed_Front_Particle);
    initBody(Type_Speed_Front_Particle);
    this->initShape(Type_Speed_Front_Particle);
    
    this->setCPBody(this->pBody);
    cpBodySetPos(this->pBody, cpv(pos.x, pos.y));
    cpShapeSetUserData(this->pShape, this);
}


void PowerUpParticle::crateObstacle_Torpedo_export(Vec2 pos){
    this->speed = -150.0;
    this->initWithSpriteFrameName("torpedo_export.png");
    this->normalSize = this->getContentSize(Type_Obstacle_Torpedo_export);
    //can't add body to space,but should add shape to space
    initBody(Type_Obstacle_Torpedo_export);
    initShape(Type_Obstacle_Torpedo_export);
    this->setCPBody(this->pBody);
    cpBodySetPos(this->pBody, cpv(pos.x,pos.y));
    cpBodySetForce(this->pBody,cpv(0, 550));
    cpShapeSetUserData(this->pShape, this);
}



