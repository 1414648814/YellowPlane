//
//  PlayLayer.h
//  YellowPlane
//
//  Created by George on 15/6/1.
//
//

#ifndef __YellowPlane__PlayLayer__
#define __YellowPlane__PlayLayer__

#include <stdio.h>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "chipmunk.h"
#include "MapManager.h"
#include "YellowPlane.h"
#include "BackgroundLayer.h"
#include "StatusLayer.h"
#include "GameData.h"
#include "ObjiectManager.h"
#include "PowerUpManager.h"
#include "PowerUp.h"
#include "ImgLoader.h"
using namespace cocos2d;
USING_NS_CC;
USING_NS_CC_EXT;

#define NOTIFI_MEET_COIN "NOTIFI_MEET_COIN"
#define NOTIFI_MEET_Mine_chain_export "NOTIFI_MEET_Mine_chain_export"
#define NOTIFI_MEET_Mine_chains "NOTIFI_MEET_Mine_chains"
#define NOTIFI_MEET_Lasers_export "NOTIFI_MEET_Lasers_export"
#define NOTIFI_Naval_mine "NOTIFI_Naval_mine"
#define NOTIFI_MEET_Laser1 "NOTIFI_MEET_Laser1"
#define NOTIFI_MEET_Laser2 "NOTIFI_MEET_Laser2"
#define NOTIFI_MEET_Torpedo_export "NOTIFI_MEET_Torpedo_export"
#define NOTIFI_MEET_Torpedo_fire1 "NOTIFI_MEET_Torpedo_fire1"
#define NOTIFI_MEET_Torpedo_fire2 "NOTIFI_MEET_Torpedo_fire2"
#define NOTIFI_MEET_Revive "NOTIFI_MEET_Revive"
#define NOTIFI_MEET_Shield "NOTIFI_MEET_Shield"
#define NOTIFI_MEET_Sonicwave "NOTIFI_MEET_Sonicwave"
#define NOTIFI_MEET_Speeds "NOTIFI_MEET_Speeds"

#define NOTIFI_MEET_Particle "NOTIFI_MEET_Particle"


class PlayLayer : public Layer{
public:
    virtual bool init();
    virtual void update(float dt);
    virtual bool onTouchBegan(Touch *touch, Event *event);
    float getVisibleWidth();
    void setPhyWorld(PhysicsWorld* world){this->world = world;}
    void onExit();
    void notifiCoin(EventCustom* event);
    void notifiMine_chain_export(EventCustom* event);
    void notifiMine_chains(EventCustom* event);
    void notifiLasers_export(EventCustom* event);
    void notifiNaval_mine(EventCustom* event);
    void notifiLaser1(EventCustom* event);
    void notifiLaser2(EventCustom* event);
    void notifiTorpedo_export(EventCustom* event);
    void notifiTorpedo_fire1(EventCustom* event);
    void notifiTorpedo_fire2(EventCustom* event);
    void notifiRevive(EventCustom* event);
    void notifiShield(EventCustom* event);
    void notifiSonicWave(EventCustom* event);
    void notifiSpeeds(EventCustom* event);
    void notifiParticle(EventCustom* event);
    void initCollisonHandler();
    void removeforespeeds_particle();
    void removebackspeeds_particle();
    void initDepatcher();
    CREATE_FUNC(PlayLayer);
private:
    cpSpace *space;
    cpShape *sandbottom;
    cpShape *upshape;

    MapManager *mapmanger;
    ObjectManager * objmanager;
    PowerUpManager * powerupmanager;
    SpriteBatchNode *objNode;
    SpriteBatchNode *mapNode;
    SpriteBatchNode *foreMapNode;
    ParticleSystem * bubble_particle;
    ParticleBatchNode *batch;
    float lastEyeX;
    YellowPlane *plane;
    PowerUp *powerup;
    PowerUpParticle *shildbubble_particle;
    PowerUpParticle *sonicwave_particle;
    PowerUpParticle *Torpedo_export;
    Sprite *forespeeds_particle;
    Sprite *backspeeds_particle;
    Sprite *backTorpedo_export;
    Sprite *Torpedo_export_info;
    Camera* camera;
    float visiblewidth;
    PhysicsWorld *world;
    
    EventListenerTouchOneByOne * _listener;
};

#endif /* defined(__YellowPlane__PlayLayer__) */
