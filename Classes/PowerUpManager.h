//
//  PowerUpManager.h
//  YellowPlane
//
//  Created by George on 15/7/2.
//
//

#ifndef __YellowPlane__PowerUpManager__
#define __YellowPlane__PowerUpManager__

#include <stdio.h>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "chipmunk.h"
#include <time.h>
#include "PowerUp.h"
#define random(x) (rand()%x)
USING_NS_CC;
class PowerUpManager{
private:
    cpSpace *pSpace;
    PowerUp * powerup;
    PowerUpParticle * particle;
    Layer * player;
    Sprite * backTorpedo_export;
    Sprite * Torpedo_export_info;
    float Torpedo_export_Height;
public:
    list<PowerUp *> delpowerups;
    
    PowerUpManager(Layer * layer,cpSpace *space);
    ~PowerUpManager();
    void createPowerUp(int mapindex,float mapwidth);
    void createPowerUpParticle(PowerUpParticleType type,Vec2 pos);
    void createObstacle_Torpedo_export(int mapinex,float mapwidth);
    void createBack_Torpedo_export();
    void createTorpedo_export_info();
    
    void update(float dt);
    void updateParticle(float dt);
    
    PowerUp * getPowerUp();
    PowerUpParticle * getPowerUpParticle();
    Sprite * getBack_Torpedo_export();
    Sprite * getTorpedo_export_info();
    float getTorpedo_export_Height();
    void setTorpedo_export_Height(float height);
    
    void remove(PowerUp *item);
    void remove(PowerUpParticle *item);
    void removeObstacle_Torpedo_export(PowerUpParticle *item);
    void removeBack_Torpedo_export();
    void removeTorpedo_export_info();
    void removeObjectOfMap(int mapIndex);
};

#endif /* defined(__YellowPlane__PowerUpManager__) */
