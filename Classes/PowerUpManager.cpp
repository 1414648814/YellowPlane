//
//  PowerUpManager.cpp
//  YellowPlane
//
//  Created by George on 15/7/2.
//
//

#include "PowerUpManager.h"
PowerUpManager::PowerUpManager(Layer * layer,cpSpace *space){
    this->pSpace = space;
    this->player = layer;
}

PowerUpManager::~PowerUpManager(){
    

}

/*
 power
 */
PowerUp * PowerUpManager::getPowerUp(){
    return this->powerup;
}

void PowerUpManager::createPowerUp(int mapindex,float mapwidth){
    srand((int)time(0));
    int powernum = 1;//random(4);
    this->powerup = PowerUp::create(this->pSpace, (PowerUpIconType)powernum,Vec2(mapindex * mapwidth,400));
    this->powerup->setTag(mapindex);
    this->player->addChild(this->powerup,6);
    delpowerups.push_back(this->powerup);
}

void PowerUpManager::update(float dt){
    
    this->powerup->step(dt);
}

void PowerUpManager::remove(PowerUp *item){
    item->removeFromParent();
    delpowerups.remove(item);
}

//delete the powerup
void PowerUpManager::removeObjectOfMap(int mapIndex){
    // 正确的遍历删除方法
    std::list<PowerUp *>::iterator itList;
    for (itList = delpowerups.begin(); itList != delpowerups.end();/*Not ++ here*/) {
        PowerUp *sprite = (PowerUp *)*itList;
        if(mapIndex == sprite->getTag()) {
            sprite->removeFromParent();
            itList = delpowerups.erase(itList);
        } else {
            itList++;
        }
    }
}


/*
 particle
 */
void PowerUpManager::createPowerUpParticle(PowerUpParticleType type,Vec2 pos){
    this->particle = PowerUpParticle::create(this->pSpace, type,pos);
    this->player->addChild(this->particle,6);
}

void PowerUpManager::createObstacle_Torpedo_export(int mapinex,float mapwidth){
    this->particle = PowerUpParticle::create(this->pSpace, Type_Obstacle_Torpedo_export, Vec2(mapinex * mapwidth, this->Torpedo_export_Height));
    this->player->addChild(this->particle,6);

}

void PowerUpManager::createBack_Torpedo_export(){
    Vector<SpriteFrame*> animFrames;
    for (int i = 1; i <= 2; i++)
    {
        auto name = String::createWithFormat("res/Obstacles/torpedo_fire%d.png",i);
        SpriteFrame *frame = ImgLoader::getInstance()->getSpriteFrameByName(name->getCString(), Rect(0, 0, 78, 44));
        animFrames.pushBack(frame);
    }
    auto animation = Animation::createWithSpriteFrames(animFrames,0.15f);//0.15s一帧
    auto runningAction =CCRepeatForever::create(CCAnimate::create(animation));
    runningAction->retain();
    this->backTorpedo_export = ImgLoader::getInstance()->getSpriteFramesByName("torpedo_fire1.png");
    this->backTorpedo_export->runAction(runningAction);
    this->backTorpedo_export->setPosition(Vec2(this->particle->getPositionX() + this->particle->getContentSize(Type_Obstacle_Torpedo_export).width, this->particle->getPositionY()));
    this->backTorpedo_export->setScale(2);
    this->player->addChild(this->backTorpedo_export);
}


void PowerUpManager::createTorpedo_export_info(){
    this->Torpedo_export_info = ImgLoader::getInstance()->getSpriteFramesByName("torpedo_info.png");
    ActionInterval * blink = Blink::create(1, 1);
    Action * action = RepeatForever::create(Sequence::create(blink, NULL));
    this->Torpedo_export_info->runAction(action);
    this->player->addChild(this->Torpedo_export_info);
}

void PowerUpManager::updateParticle(float dt){
    

}

PowerUpParticle * PowerUpManager::getPowerUpParticle(){
    return this->particle;
}

Sprite * PowerUpManager::getBack_Torpedo_export(){
    return this->backTorpedo_export;
}

Sprite * PowerUpManager::getTorpedo_export_info(){
    return this->Torpedo_export_info;
}

float PowerUpManager::getTorpedo_export_Height(){
    return this->Torpedo_export_Height;

}

void PowerUpManager::setTorpedo_export_Height(float height){
    this->Torpedo_export_Height = height;
}


void PowerUpManager::remove(PowerUpParticle *item){
    item->removeFromParent();
}

void PowerUpManager::removeObstacle_Torpedo_export(PowerUpParticle *item){
    item->removeObstacle_Torpedo_export();
}

void PowerUpManager::removeBack_Torpedo_export(){
    this->backTorpedo_export->removeFromParent();
}

void PowerUpManager::removeTorpedo_export_info(){
    this->Torpedo_export_info->removeFromParent();
}
