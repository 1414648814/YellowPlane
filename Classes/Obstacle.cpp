//
//  Obstacle.cpp
//  YellowPlane
//
//  Created by George on 15/5/31.
//
//
//store the obstacle 
#include "Obstacle.h"

/*
 obstacleItem，各种障碍物的对象
 */
ObstacleItem* ObstacleItem::create(cpSpace *space ,ObstacleType type,Point pos){
    ObstacleItem * item = new ObstacleItem(space, type, pos);
    item->autorelease();
    return item;
}

const Size* ObstacleItem::getContentSize(ObstacleType type){
    const Size * size;
    switch (type) {
        case Type_Laser1:
            size = getLaser1ContentSize();
            break;
        case Type_Laser2:
            size = getLaser2ContentSize();
            break;
        case Type_Lasers_export:
            size = getLasers_exportContentSize();
            break;
        case Type_Mine_chain_export:
            size = getMine_chain_exportContentSize();
            break;
        case Type_Mine_chains:
            size = getMine_chainContentSize();
            break;
        case Type_Naval_mine:
            size = getNaval_mineContentSize();
            break;
        case Type_Torpedo_export:
            size = getTorpedo_exportContentSize();
            break;
        case Type_Torpedo_fire1:
            size = getTorpedo_fire1ContentSize();
            break;
        case Type_Torpedo_fire2:
            size = getTorpedo_fire2ContentSize();
            break;
        case Type_Coin:
            size = getCoinContentSize();
            break;
        case a:
            break;
    }
    return size;
}

ObstacleItem::ObstacleItem(cpSpace *space, ObstacleType type,Vec2 pos){
    this->pSpace = space;
    
    switch (type) {
        case Type_Laser1:
            createLaser1(pos);
            break;
        case Type_Laser2:
            createLaser2(pos);
            break;
        case Type_Lasers_export:
            createLasers_export(pos);
            break;
        case Type_Mine_chain_export:
            createMine_chain_export(pos);
            break;
        case Type_Mine_chains:
            createMine_chain(pos);
            break;
        case Type_Naval_mine:
            createNaval_mine(pos);
            break;
        case Type_Torpedo_export:
            createTorpedo_export(pos);
            break;
        case Type_Torpedo_fire1:
            createTorpedo_fire1(pos);
            break;
        case Type_Torpedo_fire2:
            createTorpedo_fire2(pos);
            break;
        case Type_Coin:
            createCoin(pos);
            break;
        case a:
            createOther(pos);
            break;

    }
    
    this->pShape->sensor = true;
    cpSpaceAddStaticShape(this->pSpace, this->pShape);
    
    // for collision
    cpShapeSetUserData(this->pShape, this);
    
}

void ObstacleItem::removeFromParent(){
    cpSpaceRemoveStaticShape(this->pSpace, this->pShape);
    cpShapeFree(this->pShape);
    cpBodyFree(this->pBody);
    PhysicsSprite::removeFromParent();
}

//Laser1
const Size* ObstacleItem::getLaser1ContentSize(){
    PhysicsSprite * sprite = PhysicsSprite::createWithSpriteFrameName("laser1.png");
    return &sprite->getContentSize();
}

void ObstacleItem::createLaser1(Vec2 pos){
    this->initWithSpriteFrameName("laser1.png");
    this->pBody = cpBodyNewStatic();
    this->setCPBody(this->pBody);
    this->pShape = cpBoxShapeNew(this->pBody, this->getContentSize(Type_Laser1)->width, this->getContentSize(Type_Laser1)->height);
    setBodyPos(Point(pos.x,pos.y));
    cpShapeSetCollisionType(this->pShape,SpriteLaser1);
}

//Laser2
const Size* ObstacleItem::getLaser2ContentSize(){
    PhysicsSprite * sprite = PhysicsSprite::createWithSpriteFrameName("laser2.png");
    return &sprite->getContentSize();
}

void ObstacleItem::createLaser2(Vec2 pos){
    this->initWithSpriteFrameName("laser2.png");
    this->pBody = cpBodyNewStatic();
    this->setCPBody(this->pBody);
    this->pShape = cpBoxShapeNew(this->pBody, this->getContentSize(Type_Laser2)->width, this->getContentSize(Type_Laser2)->height);
    setBodyPos(Point(pos.x,pos.y));
    cpShapeSetCollisionType(this->pShape,SpriteLaser2);
}

//Lasers_export
const Size* ObstacleItem::getLasers_exportContentSize(){
    PhysicsSprite * sprite = PhysicsSprite::createWithSpriteFrameName("lasers_export.png");
    return &sprite->getContentSize();
}

void ObstacleItem::createLasers_export(Vec2 pos){
    this->initWithSpriteFrameName("lasers_export.png");
    float radius = 0.95 * this->getContentSize(Type_Lasers_export)->width / 2;
    this->pBody = cpBodyNewStatic();
    this->setCPBody(this->pBody);
    setBodyPos(Point(pos.x,pos.y));
    this->pShape = cpCircleShapeNew(this->pBody, radius, cpvzero);
    cpShapeSetCollisionType(this->pShape,SpriteLasers_export);
}

//Mine_chain_export
const Size* ObstacleItem::getMine_chain_exportContentSize(){
    PhysicsSprite * sprite = PhysicsSprite::createWithSpriteFrameName("mine_chain_export.png");
    return &sprite->getContentSize();
}

void ObstacleItem::createMine_chain_export(Vec2 pos){
    this->initWithSpriteFrameName("mine_chain_export.png");
    float radius = 0.95 * this->getContentSize(Type_Mine_chain_export)->width / 2;
    this->pBody = cpBodyNewStatic();
    this->setCPBody(this->pBody);
    setBodyPos(Point(pos.x,pos.y));
    this->pShape = cpCircleShapeNew(this->pBody, radius, cpvzero);
    cpShapeSetCollisionType(this->pShape,SpriteMine_chain_export);
}

//Mine_chains
const Size* ObstacleItem::getMine_chainContentSize(){
    PhysicsSprite * sprite = PhysicsSprite::createWithSpriteFrameName("mine_chains.png");
    return &sprite->getContentSize();
}

void ObstacleItem::createMine_chain(Vec2 pos){
    this->initWithSpriteFrameName("mine_chains.png");
    float radius = 0.95 * this->getContentSize(Type_Mine_chains)->width / 2;
    this->pBody = cpBodyNewStatic();
    this->setCPBody(this->pBody);
    setBodyPos(Point(pos.x,pos.y));
    this->pShape = cpCircleShapeNew(this->pBody, radius, cpvzero);
    cpShapeSetCollisionType(this->pShape,SpriteMine_chains);
}

//Naval_mine
const Size* ObstacleItem::getNaval_mineContentSize(){
    PhysicsSprite * sprite = PhysicsSprite::createWithSpriteFrameName("naval_mine.png");
    return &sprite->getContentSize();
}

void ObstacleItem::createNaval_mine(Vec2 pos){
    this->initWithSpriteFrameName("naval_mine.png");
    float radius = 0.95 * this->getContentSize(Type_Naval_mine)->width / 2;
    this->pBody = cpBodyNewStatic();
    this->setCPBody(this->pBody);
    setBodyPos(Point(pos.x,pos.y));
    this->pShape = cpCircleShapeNew(this->pBody, radius, cpvzero);
    cpShapeSetCollisionType(this->pShape,SpriteNaval_mine);
}

//Torpedo_export
const Size* ObstacleItem::getTorpedo_exportContentSize(){
    PhysicsSprite * sprite = PhysicsSprite::createWithSpriteFrameName("torpedo_export.png");
    return &sprite->getContentSize();
}

void ObstacleItem::createTorpedo_export(Vec2 pos){
    this->initWithSpriteFrameName("torpedo_export.png");
    this->pBody = cpBodyNewStatic();
    this->setCPBody(this->pBody);
    setBodyPos(Point(pos.x,pos.y));
    this->pShape = cpBoxShapeNew(this->pBody, this->getContentSize(Type_Torpedo_export)->width, this->getContentSize(Type_Torpedo_export)->height);
    cpShapeSetCollisionType(this->pShape,SpriteTorpedo_export);
}

//Torpedo_fire1
const Size* ObstacleItem::getTorpedo_fire1ContentSize(){
    PhysicsSprite * sprite = PhysicsSprite::createWithSpriteFrameName("torpedo_fire1.png");
    return &sprite->getContentSize();
}

void ObstacleItem::createTorpedo_fire1(Vec2 pos){
    this->initWithSpriteFrameName("torpedo_fire1.png");
    this->pBody = cpBodyNewStatic();
    setBodyPos(Point(pos.x,pos.y));
    this->setCPBody(this->pBody);
    this->pShape = cpBoxShapeNew(this->pBody, this->getContentSize(Type_Torpedo_fire1)->width, this->getContentSize(Type_Torpedo_fire1)->height);
    cpShapeSetCollisionType(this->pShape,SpriteTorpedo_fire1);
}

//Torpedo_fire2
const Size* ObstacleItem::getTorpedo_fire2ContentSize(){
    PhysicsSprite * sprite = PhysicsSprite::createWithSpriteFrameName("torpedo_fire2.png");
    return &sprite->getContentSize();
}

void ObstacleItem::createTorpedo_fire2(Vec2 pos){
    this->initWithSpriteFrameName("torpedo_fire2.png");
    this->pBody = cpBodyNewStatic();
    setBodyPos(Point(pos.x,pos.y));
    this->setCPBody(this->pBody);
    this->pShape = cpBoxShapeNew(this->pBody, this->getContentSize(Type_Laser2)->width, this->getContentSize(Type_Laser2)->height);
    cpShapeSetCollisionType(this->pShape,SpriteTorpedo_fire2);
    
}

//coin
const Size* ObstacleItem::getCoinContentSize(){
    PhysicsSprite *sprite = PhysicsSprite::createWithSpriteFrameName("submarine_mockup_coin.png");
    return &sprite->getContentSize();
}

void ObstacleItem::createCoin(Vec2 pos){
    this->initWithSpriteFrameName("submarine_mockup_coin.png");
    float radius = 0.95 * this->getContentSize(Type_Coin)->width / 2;
    this->pBody = cpBodyNewStatic();
    this->setCPBody(this->pBody);
    setBodyPos(Point(pos.x,pos.y));
    this->pShape = cpCircleShapeNew(this->pBody, radius, cpvzero);
    cpShapeSetCollisionType(this->pShape,SpriteCoin);
}

//other
void ObstacleItem::createOther(Vec2 pos){
    
    this->initWithSpriteFrameName("submarine_mockup_coin.png");
    float radius = 0.95 * this->getContentSize(Type_Coin)->width / 2;
    this->pBody = cpBodyNewStatic();
    this->setCPBody(this->pBody);
    this->pShape = cpCircleShapeNew(this->pBody, radius, cpvzero);
    cpShapeSetCollisionType(this->pShape,SpriteCoin);
    setBodyPos(Point(pos.x,pos.y));
}


cpSpace * ObstacleItem::getSpace(){
    return this->pSpace;
}

cpShape * ObstacleItem::getShape(){
    return this->pShape;
}

void ObstacleItem::setBodyPos(Point pos){
    cpBodySetPos(this->pBody, cpv(pos.x, pos.y));
}













