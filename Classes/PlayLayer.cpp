//
//  PlayLayer.cpp
//  YellowPlane
//
//  Created by George on 15/6/1.
//
//

#include "PlayLayer.h"

bool isShield;
//删除的注册回调函数
static void postStepRemove(cpSpace *space, cpShape *shape, void *param)
{
    ObjectManager *objectManager = (ObjectManager *)param;
    switch (shape->collision_type) {
        case SpriteCoin:
        {
            Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(NOTIFI_MEET_COIN);
            objectManager->remove((ObstacleItem *)shape->data);
            CCLOG("yellowplane touch  a coin");
        }
            break;
        case SpriteMine_chain_export:
        {
            if (!isShield) {
                Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(NOTIFI_MEET_Mine_chain_export);
                
                CCLOG("yellowplane touch a Mine_chain_export");
            }
        }
            break;
        case SpriteMine_chains:
        {
            if (!isShield) {
                Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(NOTIFI_MEET_Mine_chains);
                CCLOG("yellowplane touch a Mine_chains");
            }
        }
            break;
        case SpriteLasers_export:
        {
            if (!isShield) {
                Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(NOTIFI_MEET_Lasers_export);
                
                CCLOG("yellowplane touch a Lasers_export");
            }
        }
            break;
        case SpriteNaval_mine:
        {
            if (!isShield) {
                Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(NOTIFI_Naval_mine);
                
                CCLOG("yellowplane touch a Naval_mine");
            }
        }
            break;
        case SpriteLaser1:
        {
            if (!isShield) {
                Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(NOTIFI_MEET_Laser1);
                
                CCLOG("yellowplane touch a Laser1");
            }
        }
            break;
        case SpriteLaser2:
        {
            if (!isShield) {
                Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(NOTIFI_MEET_Laser2);
                
                CCLOG("yellowplane touch a Laser2");
            }
        }
            break;
        case SpriteTorpedo_export:
        {
            if (!isShield) {
                Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(NOTIFI_MEET_Torpedo_export);
                
                CCLOG("yellowplane touch a Torpedo_export");
            }
        }
            break;
        case SpriteTorpedo_fire1:
        {
            if (!isShield) {
                Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(NOTIFI_MEET_Torpedo_fire1);
                
                CCLOG("yellowplane touch a Torpedo_fire1");
            }
        }
            break;
        case SpriteTorpedo_fire2:
        {
            if (!isShield) {
                Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(NOTIFI_MEET_Torpedo_fire2);
                
                CCLOG("yellowplane touch a Torpedo_fire2");
            }
        }
            break;
    }
}

//删除粒子效果的注册回调函数
static void postStepRemoveAndParticle(cpSpace *space, cpShape *shape, void *param){
    PowerUpManager * powerupManger = (PowerUpManager *)param;
    switch (shape->collision_type) {
        case SpriteRevive:
        {
            Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(NOTIFI_MEET_Revive);
            powerupManger->remove((PowerUp *)shape->data);
            CCLOG("yellowplane touch a Revive");
        }
            break;
        case SpriteShield:
        {
            Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(NOTIFI_MEET_Shield);
            powerupManger->remove((PowerUp *)shape->data);
            CCLOG("yellowplane touch a Shield");
        }
            break;
        case SpriteSonicWave:
        {
            Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(NOTIFI_MEET_Sonicwave);
            powerupManger->remove((PowerUp *)shape->data);
            CCLOG("yellowplane touch a Sonicwave");
        }
            break;
        case SpriteSpeed:
        {
            Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(NOTIFI_MEET_Speeds);
            powerupManger->remove((PowerUp *)shape->data);
            CCLOG("yellowplane touch a Speeds");
        }
            break;
    }
}

//
static void postStepRemoveParticle(cpSpace *space, cpShape *shape, void *param){
    ObjectManager *objectManager = (ObjectManager *)param;
    switch (shape->collision_type) {
        case SpriteMine_chain_export:
        {
            Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(NOTIFI_MEET_Particle);
            objectManager->remove((ObstacleItem *)shape->data);
            CCLOG("particle touch a Mine_chain_export");
        }
            break;
        case SpriteMine_chains:
        {
            Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(NOTIFI_MEET_Particle);
            objectManager->remove((ObstacleItem *)shape->data);
            CCLOG("particle touch a Mine_chains");
        }
            break;
        case SpriteLasers_export:
        {
            Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(NOTIFI_MEET_Particle);
            objectManager->remove((ObstacleItem *)shape->data);
            CCLOG("particle touch a Lasers_export");
        }
            break;
        case SpriteNaval_mine:
        {
            Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(NOTIFI_MEET_Particle);
            objectManager->remove((ObstacleItem *)shape->data);
            CCLOG("particle touch a Naval_mine");
        }
            break;
        case SpriteLaser1:
        {
            Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(NOTIFI_MEET_Particle);
            objectManager->remove((ObstacleItem *)shape->data);
            CCLOG("particle touch a Laser1");
        }
            break;
        case SpriteLaser2:
        {
            Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(NOTIFI_MEET_Particle);
            objectManager->remove((ObstacleItem *)shape->data);
            CCLOG("particle touch a Laser2");
        }
            break;
        case SpriteTorpedo_export:
        {
            Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(NOTIFI_MEET_Particle);
            objectManager->remove((ObstacleItem *)shape->data);
            CCLOG("particle touch a Torpedo_export");
        }
            break;
        case SpriteTorpedo_fire1:
        {
            Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(NOTIFI_MEET_Particle);
            objectManager->remove((ObstacleItem *)shape->data);
            CCLOG("particle touch a Torpedo_fire1");
        }
            break;
        case SpriteTorpedo_fire2:
        {
            Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(NOTIFI_MEET_Particle);
            objectManager->remove((ObstacleItem *)shape->data);
            CCLOG("particle touch a Torpedo_fire2");
        }
            break;
    }
    
}

//设置碰撞到障碍物的回调函数
static int collisionObstacleBegin(cpArbiter *arb, cpSpace *space, void *param)
{
    // we get shapes here, so postStepRemove's second param is cpShape
    CP_ARBITER_GET_SHAPES(arb, a, b);
    cpSpaceAddPostStepCallback(space, (cpPostStepFunc)postStepRemove, b, param);
    return 0;
}

//设置碰撞到能量的回调函数
static int collisionPowerUpBegin(cpArbiter *arb, cpSpace *space, void *param){
    CP_ARBITER_GET_SHAPES(arb, a, b);
    cpSpaceAddPostStepCallback(space, (cpPostStepFunc)postStepRemoveAndParticle, b, param);
    return 0;
}

//设置碰撞到能量粒子的回调函数
static int collisionPowerUpParticleBegin(cpArbiter *arb, cpSpace *space, void *param){
    CP_ARBITER_GET_SHAPES(arb, a, b);
    cpSpaceAddPostStepCallback(space, (cpPostStepFunc)postStepRemoveParticle, b, param);
    return 0;
}

bool PlayLayer::init(){
    if (!Layer::init()) {
        return false;
    }
    
//    setTouchEnabled(true);
//    setTouchMode(kCCTouchesOneByOne);
    
    _listener = EventListenerTouchOneByOne::create();
    _listener->onTouchBegan = CC_CALLBACK_2(PlayLayer::onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_listener, this);
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    isShield = false;
    
    this->space = cpSpaceNew();
    this->space->gravity = cpv(0, -550);
    
    this->visiblewidth = visibleSize.width;

    GameData::getInstance()->setGameStatus(Game_Run);
    
    //sand shape
    this->sandbottom = cpSegmentShapeNew(this->space->staticBody,
                                   cpv(0, 72),// start point
                                   cpv(4294967295, 72),// MAX INT:4294967295
                                   0);// thickness of wall
    cpSpaceAddStaticShape(this->space, sandbottom);
    cpShapeSetCollisionType(this->sandbottom,SpriteSand);

    //up shape
    this->upshape = cpSegmentShapeNew(this->space->staticBody, cpv(0, visibleSize.height), cpv(4294967295, visibleSize.height),0);
    cpSpaceAddStaticShape(this->space, upshape);
    cpShapeSetCollisionType(this->upshape,SpriteUp);
    
    this->setAnchorPoint(Vec2(0,0));
    
    //plane
    this->plane = YellowPlane::create(this->space);
    this->addChild(plane,6);
    
    //init spriteSheet
    this->objNode = SpriteBatchNode::create("res/Obstacles/Obstacle.png");
    this->addChild(this->objNode,5);
    
    this->mapNode = SpriteBatchNode::create("res/Background/background.png");
    this->addChild(this->mapNode,0);
    
    this->foreMapNode = SpriteBatchNode::create("res/Background/background.png");
    this->addChild(this->foreMapNode,2);
    
    //init the map and obj
    this->mapmanger = new MapManager(this,this->mapNode,this->foreMapNode,this->space);
    this->objmanager = new ObjectManager(this,this->objNode,this->space,this->mapmanger->getMapWidth());

    this->mapmanger->initBackGround(this->mapmanger->getMapWidth(), 0, this->mapmanger->groundGroup0);
    this->mapmanger->initBackGround(this->mapmanger->getMapWidth(), 1, this->mapmanger->groundGroup0);
    this->mapmanger->initMidGround(this->mapmanger->getMapWidth(), 0, this->mapmanger->groundGroup0);
    this->mapmanger->initMidGround(this->mapmanger->getMapWidth(), 1, this->mapmanger->groundGroup0);
    this->mapmanger->initForeGround(this->mapmanger->getMapWidth(), 0, this->mapmanger->groundGroup0);
    this->mapmanger->initForeGround(this->mapmanger->getMapWidth(), 1, this->mapmanger->groundGroup0);
    
    this->powerupmanager = new PowerUpManager(this,this->space);
    
    this->camera = Camera::createOrthographic(visibleSize.width, visibleSize.height, 0, 1);
    
    //default position is half width,height
    this->camera->setPosition3D(Vec3(this->camera->getPosition3D().x,this->camera->getPosition3D().y,this->camera->getPosition3D().z));
    
    this->addChild(camera);
    
    this->bubble_particle = ParticleSystemQuad::create("res/PowerUps/bubble_particle.plist");
    this->bubble_particle->setPositionType(ParticleSystem::PositionType::RELATIVE);
    this->batch = ParticleBatchNode::createWithTexture(this->bubble_particle->getTexture());
    this->batch->addChild(this->bubble_particle);
    this->plane->addChild(this->batch,1);
    
    scheduleUpdate();
    
    initCollisonHandler();
    
    initDepatcher();
    //user1==2 user2==4 ...,set the item is visible
//    this->camera->setCameraFlag(CameraFlag::USER2);
//    this->setCameraMask(4);
    
#if 1
    //CCPhysicsDebugNode是为了更方便debug的类，将它设置为显示之后，在场景内定义的精灵的碰撞形状块就显示出来了
    cocos2d::extension::PhysicsDebugNode* debugLayer = cocos2d::extension::PhysicsDebugNode::create(this->space);
    addChild(debugLayer, 100);
    debugLayer->setVisible(true);
#endif
    return true;
}

//更新游戏机制
void PlayLayer::update(float dt)
{
    if(GameData::getInstance()->getGameStatus()!=Game_Run){
        return;
    }
        
    cpSpaceStep(this->space, dt);
    //check the map and load obstacle
    if (mapmanger->checkAndReload(this->lastEyeX)) {
        this->mapmanger->removeObjectOfMap(this->mapmanger->getCurrentMap()-1);
        this->mapmanger->initBackGround(this->mapmanger->getMapWidth(), this->mapmanger->getCurrentMap()+1, this->mapmanger->groundGroup0);
        this->mapmanger->initMidGround(this->mapmanger->getMapWidth(), this->mapmanger->getCurrentMap()+1, this->mapmanger->groundGroup0);
        this->mapmanger->initForeGround(this->mapmanger->getMapWidth(), this->mapmanger->getCurrentMap()+1, this->mapmanger->groundGroup0);
        
        this->powerup = NULL;
        this->powerupmanager->removeObjectOfMap(this->mapmanger->getCurrentMap()-1);
        this->powerupmanager->createPowerUp(this->mapmanger->getCurrentMap()+1,this->mapmanger->getMapWidth());
        
        this->powerupmanager->createTorpedo_export_info();
        this->powerupmanager->setTorpedo_export_Height(this->plane->getPositionY());
        this->powerupmanager->createObstacle_Torpedo_export(this->mapmanger->getCurrentMap()+1, this->mapmanger->getMapWidth());
        this->powerupmanager->createBack_Torpedo_export();
        this->powerup = this->powerupmanager->getPowerUp();
        this->backTorpedo_export = this->powerupmanager->getBack_Torpedo_export();
        this->Torpedo_export = this->powerupmanager->getPowerUpParticle();
        this->Torpedo_export_info = this->powerupmanager->getTorpedo_export_info();
    }
    
    if(objmanager->scrollItem(this->lastEyeX)){
        CCLOG("%d",this->objmanager->getdelObjs());
        CCLOG("now delete obj %d",this->objmanager->getCurrentObj()-1);
        this->objmanager->removeObjectOfMap(this->objmanager->getCurrentObj()-1);
    }
    
    this->plane->step(dt);
    //update the particle's position
    this->batch->setPosition(Vec2(lastEyeX - this->plane->getContentSize().width,this->plane->getPositionY()-70));
    //update the particle's rotation
    if (this->plane->getCurAction()==Action_JumpUp) {
        this->batch->setRotation(-this->plane->getRotation() - 20);
    }
    else if(this->plane->getCurAction()==Action_JumpDown){
        this->batch->setRotation(-this->plane->getRotation() - 20);
    }
    else if(this->plane->getCurAction()==Action_Swing){
        this->batch->setRotation(-this->plane->getRotation());
    }
    
//    if (this->powerup!=NULL) {
//        this->powerupmanager->update(dt);
//    }
//    
//    if (this->shildbubble_particle!=NULL) {
//        this->shildbubble_particle->setPosition(Vec2(this->plane->getPositionX(),this->plane->getPositionY()));
//    }
//    if (this->forespeeds_particle!=NULL) {
//        this->forespeeds_particle->setPosition(Vec2(this->plane->getPositionX() + this->plane->getContentSize().width,this->plane->getPositionY()));
//    }
//    if (this->backspeeds_particle!=NULL) {
//        this->backspeeds_particle->setPosition(Vec2(this->plane->getPositionX() - this->plane->getContentSize().width,this->plane->getPositionY()));
//    }
//    if (this->backTorpedo_export!=NULL) {
//        this->backTorpedo_export->setPosition(Vec2(this->Torpedo_export->getPositionX()+this->Torpedo_export->getContentSize(Type_Obstacle_Torpedo_export).width,this->Torpedo_export->getPositionY()));
//    }
//    if (this->Torpedo_export_info!=NULL) {
//        this->Torpedo_export_info->setPosition(Vec2(this->plane->getPositionX() + 900,this->Torpedo_export->getPositionY()));
//    }
    //move camara
    lastEyeX = this->plane->getPositionX() - this->plane->getoffsetPx();
    Vec3 eyePosOld=camera->getPosition3D();
    Vec3 eyePos = Vec3(lastEyeX,eyePosOld.y,eyePosOld.z);
    this->camera->setPosition3D(eyePos);
    this->camera->lookAt(Vec3(eyePos.x,eyePos.y,0), Vec3(0, 0, 0));
    
    StatusLayer *statusLayer = (StatusLayer *)getParent()->getChildByTag(TAG_StatusLayer);
    statusLayer->updateMeter(lastEyeX);
}

bool PlayLayer::onTouchBegan(Touch *touch, Event *event){
    if (GameData::getInstance()->getGameStatus()==Game_Over) {
        return false;
    }
    if (GameData::getInstance()->getGameStatus()==Game_Run) {
        this->plane->fly();
    }
    return true;
}

float PlayLayer::getVisibleWidth(){
    return this->visiblewidth;
}

void PlayLayer::onExit()
{
    auto dispacher = Director::getInstance()->getEventDispatcher();
    dispacher->removeCustomEventListeners(NOTIFI_MEET_COIN);
    CCLayer::onExit();
}

//初始化分派器
void PlayLayer::initDepatcher(){
    //coin
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    auto customListener = EventListenerCustom::create(NOTIFI_MEET_COIN, CC_CALLBACK_1(PlayLayer::notifiCoin,this));
    dispatcher->addEventListenerWithFixedPriority(customListener,1);
    EventCustom event = EventCustom(NOTIFI_MEET_COIN);
    dispatcher->dispatchEvent(&event);
    //mine_chain_export
    customListener = EventListenerCustom::create(NOTIFI_MEET_Mine_chain_export, CC_CALLBACK_1(PlayLayer::notifiMine_chain_export, this));
    dispatcher->addEventListenerWithFixedPriority(customListener, 1);
    event = EventCustom(NOTIFI_MEET_Mine_chain_export);
    dispatcher->dispatchEvent(&event);
    //mine_chains
    customListener = EventListenerCustom::create(NOTIFI_MEET_Mine_chains, CC_CALLBACK_1(PlayLayer::notifiMine_chains, this));
    dispatcher->addEventListenerWithFixedPriority(customListener, 1);
    event = EventCustom(NOTIFI_MEET_Mine_chains);
    dispatcher->dispatchEvent(&event);
    //lasers_export
    customListener = EventListenerCustom::create(NOTIFI_MEET_Lasers_export, CC_CALLBACK_1(PlayLayer::notifiLasers_export, this));
    dispatcher->addEventListenerWithFixedPriority(customListener, 1);
    event = EventCustom(NOTIFI_MEET_Lasers_export);
    dispatcher->dispatchEvent(&event);
    //naval_mine
    customListener = EventListenerCustom::create(NOTIFI_Naval_mine, CC_CALLBACK_1(PlayLayer::notifiNaval_mine, this));
    dispatcher->addEventListenerWithFixedPriority(customListener, 1);
    event = EventCustom(NOTIFI_Naval_mine);
    dispatcher->dispatchEvent(&event);
    //laser1
    customListener = EventListenerCustom::create(NOTIFI_MEET_Laser1, CC_CALLBACK_1(PlayLayer::notifiLaser1, this));
    dispatcher->addEventListenerWithFixedPriority(customListener, 1);
    event = EventCustom(NOTIFI_MEET_Laser1);
    dispatcher->dispatchEvent(&event);
    //laser2
    customListener = EventListenerCustom::create(NOTIFI_MEET_Laser2, CC_CALLBACK_1(PlayLayer::notifiLaser2, this));
    dispatcher->addEventListenerWithFixedPriority(customListener, 1);
    event = EventCustom(NOTIFI_MEET_Laser2);
    dispatcher->dispatchEvent(&event);
    //torpedo_export
    customListener = EventListenerCustom::create(NOTIFI_MEET_Torpedo_export, CC_CALLBACK_1(PlayLayer::notifiTorpedo_export, this));
    dispatcher->addEventListenerWithFixedPriority(customListener, 1);
    event = EventCustom(NOTIFI_MEET_Torpedo_export);
    dispatcher->dispatchEvent(&event);
    //torpedo_fire1
    customListener = EventListenerCustom::create(NOTIFI_MEET_Torpedo_fire1, CC_CALLBACK_1(PlayLayer::notifiTorpedo_fire1, this));
    dispatcher->addEventListenerWithFixedPriority(customListener, 1);
    event = EventCustom(NOTIFI_MEET_Torpedo_fire1);
    dispatcher->dispatchEvent(&event);
    //torpedo_fire2
    customListener = EventListenerCustom::create(NOTIFI_MEET_Torpedo_fire2, CC_CALLBACK_1(PlayLayer::notifiTorpedo_fire2, this));
    dispatcher->addEventListenerWithFixedPriority(customListener, 1);
    event = EventCustom(NOTIFI_MEET_Torpedo_fire2);
    dispatcher->dispatchEvent(&event);
    //revive
    customListener = EventListenerCustom::create(NOTIFI_MEET_Revive, CC_CALLBACK_1(PlayLayer::notifiRevive, this));
    dispatcher->addEventListenerWithFixedPriority(customListener, 1);
    event = EventCustom(NOTIFI_MEET_Revive);
    dispatcher->dispatchEvent(&event);
    //shield
    customListener = EventListenerCustom::create(NOTIFI_MEET_Shield, CC_CALLBACK_1(PlayLayer::notifiShield, this));
    dispatcher->addEventListenerWithFixedPriority(customListener, 1);
    event = EventCustom(NOTIFI_MEET_Shield);
    dispatcher->dispatchEvent(&event);
    //sonicwave
    customListener = EventListenerCustom::create(NOTIFI_MEET_Sonicwave, CC_CALLBACK_1(PlayLayer::notifiSonicWave, this));
    dispatcher->addEventListenerWithFixedPriority(customListener, 1);
    event = EventCustom(NOTIFI_MEET_Sonicwave);
    dispatcher->dispatchEvent(&event);
    //speeds
    customListener = EventListenerCustom::create(NOTIFI_MEET_Speeds, CC_CALLBACK_1(PlayLayer::notifiSpeeds, this));
    dispatcher->addEventListenerWithFixedPriority(customListener, 1);
    event = EventCustom(NOTIFI_MEET_Speeds);
    dispatcher->dispatchEvent(&event);
    //particle
    customListener = EventListenerCustom::create(NOTIFI_MEET_Particle, CC_CALLBACK_1(PlayLayer::notifiParticle, this));
    dispatcher->addEventListenerWithFixedPriority(customListener, 1);
    event = EventCustom(NOTIFI_MEET_Particle);
    dispatcher->dispatchEvent(&event);
    
}

//初始化碰撞机制
void PlayLayer::initCollisonHandler(){
    //obstacle
    cpSpaceAddCollisionHandler(this->space, SpriteYelloPlane, SpriteCoin, collisionObstacleBegin, NULL
                               , NULL, NULL, this->objmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteYelloPlane, SpriteMine_chain_export, collisionObstacleBegin, NULL
                               , NULL, NULL, this->objmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteYelloPlane, SpriteMine_chains, collisionObstacleBegin, NULL
                               , NULL, NULL, this->objmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteYelloPlane, SpriteLasers_export, collisionObstacleBegin, NULL
                               , NULL, NULL, this->objmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteYelloPlane, SpriteNaval_mine, collisionObstacleBegin, NULL
                               , NULL, NULL, this->objmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteYelloPlane, SpriteLaser1, collisionObstacleBegin, NULL
                               , NULL, NULL, this->objmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteYelloPlane, SpriteLaser2, collisionObstacleBegin, NULL
                               , NULL, NULL, this->objmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteYelloPlane, SpriteTorpedo_export, collisionObstacleBegin, NULL
                               , NULL, NULL, this->objmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteYelloPlane, SpriteTorpedo_fire1, collisionObstacleBegin, NULL
                               , NULL, NULL, this->objmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteYelloPlane, SpriteTorpedo_fire2, collisionObstacleBegin, NULL
                               , NULL, NULL, this->objmanager);
    //powerup
    cpSpaceAddCollisionHandler(this->space,SpriteYelloPlane,SpriteRevive,collisionPowerUpBegin, NULL
                               , NULL, NULL, this->powerupmanager);
    cpSpaceAddCollisionHandler(this->space,SpriteYelloPlane,SpriteShield,collisionPowerUpBegin, NULL
                               , NULL, NULL, this->powerupmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteYelloPlane,SpriteSonicWave,collisionPowerUpBegin, NULL
                               , NULL, NULL, this->powerupmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteYelloPlane,SpriteSpeed,collisionPowerUpBegin, NULL
                               , NULL, NULL, this->powerupmanager);
    
    //powerup particle
    cpSpaceAddCollisionHandler(this->space, SpriteShieldParticle, SpriteMine_chain_export, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteShieldParticle, SpriteMine_chains, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteShieldParticle, SpriteLasers_export, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteShieldParticle, SpriteNaval_mine, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteShieldParticle, SpriteLaser1, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteShieldParticle, SpriteLaser2, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteShieldParticle, SpriteTorpedo_export, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteShieldParticle, SpriteTorpedo_fire1, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteShieldParticle, SpriteTorpedo_fire2, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteShieldParticle, SpriteRevive, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteShieldParticle, SpriteShield, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteShieldParticle, SpriteSonicWave, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteShieldParticle, SpriteSpeed, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
    
    cpSpaceAddCollisionHandler(this->space, SpriteSonicWaveParticle, SpriteYelloPlane, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteSonicWaveParticle, SpriteMine_chain_export, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteSonicWaveParticle, SpriteMine_chains, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteSonicWaveParticle, SpriteLasers_export, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteSonicWaveParticle, SpriteNaval_mine, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteSonicWaveParticle, SpriteLaser1, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteSonicWaveParticle, SpriteLaser2, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteSonicWaveParticle, SpriteTorpedo_export, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteSonicWaveParticle, SpriteTorpedo_fire1, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteSonicWaveParticle, SpriteTorpedo_fire2, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteSonicWaveParticle, SpriteRevive, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteSonicWaveParticle, SpriteShield, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteSonicWaveParticle, SpriteSonicWave, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
    cpSpaceAddCollisionHandler(this->space, SpriteSonicWaveParticle, SpriteSpeed, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
    

//    cpSpaceAddCollisionHandler(this->space, SpriteSpeedFrontParticle, SpriteMine_chain_export, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
//    cpSpaceAddCollisionHandler(this->space, SpriteSpeedFrontParticle, SpriteMine_chains, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
//    cpSpaceAddCollisionHandler(this->space, SpriteSpeedFrontParticle, SpriteLasers_export, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
//    cpSpaceAddCollisionHandler(this->space, SpriteSpeedFrontParticle, SpriteNaval_mine, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
//    cpSpaceAddCollisionHandler(this->space, SpriteSpeedFrontParticle, SpriteLaser1, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
//    cpSpaceAddCollisionHandler(this->space, SpriteSpeedFrontParticle, SpriteLaser2, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
//    cpSpaceAddCollisionHandler(this->space, SpriteSpeedFrontParticle, SpriteTorpedo_export, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
//    cpSpaceAddCollisionHandler(this->space, SpriteSpeedFrontParticle, SpriteTorpedo_fire1, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
//    cpSpaceAddCollisionHandler(this->space, SpriteSpeedFrontParticle, SpriteTorpedo_fire2, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
//    cpSpaceAddCollisionHandler(this->space, SpriteSpeedFrontParticle, SpriteRevive, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
//    cpSpaceAddCollisionHandler(this->space, SpriteSpeedFrontParticle, SpriteShield, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
//    cpSpaceAddCollisionHandler(this->space, SpriteSpeedFrontParticle, SpriteSonicWave, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
//    cpSpaceAddCollisionHandler(this->space, SpriteSpeedFrontParticle, SpriteSpeed, collisionPowerUpParticleBegin, NULL, NULL, NULL, this->objmanager);
    
}

//collision notification
//coin
void PlayLayer::notifiCoin(EventCustom* event)
{
    StatusLayer *statusLayer = (StatusLayer *)getParent()->getChildByTag(TAG_StatusLayer);
    statusLayer->addCoin(1);
}

//Mine_chain_export
void PlayLayer::notifiMine_chain_export(EventCustom* event){


}

//Mine_chains
void PlayLayer::notifiMine_chains(EventCustom* event){



}

//Lasers_export
void PlayLayer::notifiLasers_export(EventCustom* event){


}

//Naval_mine
void PlayLayer::notifiNaval_mine(EventCustom* event){


}

//Laser1
void PlayLayer::notifiLaser1(EventCustom* event){


}

//Laser2
void PlayLayer::notifiLaser2(EventCustom* event){


}

//Torpedo_export
void PlayLayer::notifiTorpedo_export(EventCustom* event){


}

//Torpedo_fire1
void PlayLayer::notifiTorpedo_fire1(EventCustom* event){


}

//Torpedo_fire2
void PlayLayer::notifiTorpedo_fire2(EventCustom* event){


}

//Revive
void PlayLayer::notifiRevive(EventCustom* event){
    

}

//Shield
void PlayLayer::notifiShield(EventCustom* event){
    CCLOG("notifiSonicWave");
    if (this->shildbubble_particle==NULL) {
        this->shildbubble_particle= NULL;
        this->powerupmanager->createPowerUpParticle(Type_Bubble_Particle, Vec2(this->plane->getPositionX(),this->plane->getPositionY()));
        this->shildbubble_particle = this->powerupmanager->getPowerUpParticle();
        isShield = true;
    }
    
}

//SonicWave
void PlayLayer::notifiSonicWave(EventCustom* event){
    CCLOG("notifiSonicWave");
    if (this->sonicwave_particle==NULL) {
        this->sonicwave_particle = NULL;
        this->powerupmanager->createPowerUpParticle(Type_Sonic_blast_Particle, Vec2(this->plane->getPositionX()-this->plane->getContentSize().width,this->plane->getPositionY()));
        this->sonicwave_particle = this->powerupmanager->getPowerUpParticle();
    }
}

//Speeds
void PlayLayer::notifiSpeeds(EventCustom* event){
    CCLOG("notifiSpeeds");
    if (this->forespeeds_particle==NULL&&this->backspeeds_particle==NULL) {
        this->forespeeds_particle = NULL;
        this->backspeeds_particle = NULL;
        this->forespeeds_particle = ImgLoader::getInstance()->getSpriteFramesByName("speed_particle_front.png");
        this->forespeeds_particle->setPosition(Vec2(this->plane->getPositionX() + this->plane->getContentSize().width,this->plane->getPositionY()));
        this->addChild(this->forespeeds_particle,6);
        this->backspeeds_particle = ImgLoader::getInstance()->getSpriteFramesByName("speed_particle.png");
        this->backspeeds_particle->setPosition(Vec2(this->plane->getPositionX() - this->plane->getContentSize().width,this->plane->getPositionY()));
        this->addChild(this->backspeeds_particle,6);
    }
}

//particle
void PlayLayer::notifiParticle(EventCustom* event){
    

}

void PlayLayer::removeforespeeds_particle(){
    this->forespeeds_particle = NULL;
    this->forespeeds_particle->removeFromParent();
}

void PlayLayer::removebackspeeds_particle(){
    this->backspeeds_particle = NULL;
    this->backspeeds_particle->removeFromParent();
}

