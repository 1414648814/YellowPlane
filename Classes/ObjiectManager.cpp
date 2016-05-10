//
//  ObjiectManager.cpp
//  YellowPlane
//
//  Created by George on 15/6/3.
//
//

#include "ObjiectManager.h"
ObjectManager::ObjectManager(Layer *layer, SpriteBatchNode *spriteSheet, cpSpace *space,float mapwidth):currgroup(0)
{
    this->pSpace = space;
    this->pSpriteSheet = spriteSheet;
    this->player = layer;
    this->mapwidth = mapwidth;
    
    this->obstaclegroup = new ObstacleGroup();

}

ObjectManager::~ObjectManager()
{

}

//1
void ObjectManager::updateObstacleGroup1(int mapIndex, float mapWidth,ObstacleGroup * temp){
    temp->updateObstacleGroup1Pos(this->pSpriteSheet, this->pSpace,mapIndex, mapWidth);
}
//2
void ObjectManager::updateObstacleGroup2(int mapIndex, float mapWidth,ObstacleGroup * temp){
    temp->updateObstacleGroup2Pos(this->pSpriteSheet, this->pSpace,mapIndex, mapWidth);
}
//3
void ObjectManager::updateObstacleGroup3(int mapIndex, float mapWidth,ObstacleGroup * temp){
    temp->updateObstacleGroup3Pos(this->pSpriteSheet, this->pSpace,mapIndex, mapWidth);
}
//4
void ObjectManager::updateObstacleGroup4(int mapIndex, float mapWidth,ObstacleGroup * temp){
    temp->updateObstacleGroup4Pos(this->pSpriteSheet, this->pSpace,mapIndex, mapWidth);
}
//5
void ObjectManager::updateObstacleGroup5(int mapIndex, float mapWidth,ObstacleGroup * temp){
    temp->updateObstacleGroup5Pos(this->pSpriteSheet, this->pSpace,mapIndex, mapWidth);
}
//6
void ObjectManager::updateObstacleGroup6(int mapIndex, float mapWidth,ObstacleGroup * temp){
    temp->updateObstacleGroup6Pos(this->pSpriteSheet, this->pSpace,mapIndex, mapWidth);
}
//7
void ObjectManager::updateObstacleGroup7(int mapIndex, float mapWidth,ObstacleGroup * temp){
    temp->updateObstacleGroup3Pos(this->pSpriteSheet, this->pSpace,mapIndex, mapWidth);
}
//8
void ObjectManager::updateObstacleGroup8(int mapIndex, float mapWidth,ObstacleGroup * temp){
    temp->updateObstacleGroup8Pos(this->pSpriteSheet, this->pSpace,mapIndex, mapWidth);
}
//9
void ObjectManager::updateObstacleGroup9(int mapIndex, float mapWidth,ObstacleGroup * temp){
    temp->updateObstacleGroup9Pos(this->pSpriteSheet, this->pSpace,mapIndex, mapWidth);
}
//10
void ObjectManager::updateObstacleGroup10(int mapIndex, float mapWidth,ObstacleGroup * temp){
    temp->updateObstacleGroup10Pos(this->pSpriteSheet, this->pSpace,mapIndex, mapWidth);
}
//11
void ObjectManager::updateObstacleGroup11(int mapIndex, float mapWidth,ObstacleGroup * temp){
    temp->updateObstacleGroup11Pos(this->pSpriteSheet, this->pSpace,mapIndex, mapWidth);
}
//12
void ObjectManager::updateObstacleGroup12(int mapIndex, float mapWidth,ObstacleGroup * temp){
    temp->updateObstacleGroup12Pos(this->pSpriteSheet, this->pSpace,mapIndex, mapWidth);
}
//13
void ObjectManager::updateObstacleGroup13(int mapIndex, float mapWidth,ObstacleGroup * temp){
    temp->updateObstacleGroup13Pos(this->pSpriteSheet, this->pSpace,mapIndex, mapWidth);
}
//14
void ObjectManager::updateObstacleGroup14(int mapIndex, float mapWidth,ObstacleGroup * temp){
    temp->updateObstacleGroup14Pos(this->pSpriteSheet, this->pSpace,mapIndex, mapWidth);
}
//15
void ObjectManager::updateObstacleGroup15(int mapIndex, float mapWidth,ObstacleGroup * temp){
    temp->updateObstacleGroup15Pos(this->pSpriteSheet, this->pSpace,mapIndex, mapWidth);
}
//16
void ObjectManager::updateObstacleGroup16(int mapIndex, float mapWidth,ObstacleGroup * temp){
    temp->updateObstacleGroup16Pos(this->pSpriteSheet, this->pSpace,mapIndex, mapWidth);
}
//17
void ObjectManager::updateObstacleGroup17(int mapIndex, float mapWidth,ObstacleGroup * temp){
    temp->updateObstacleGroup17Pos(this->pSpriteSheet, this->pSpace,mapIndex, mapWidth);
}
//18
void ObjectManager::updateObstacleGroup18(int mapIndex, float mapWidth,ObstacleGroup * temp){
    temp->updateObstacleGroup18Pos(this->pSpriteSheet, this->pSpace,mapIndex, mapWidth);
}
//19
void ObjectManager::updateObstacleGroup19(int mapIndex, float mapWidth,ObstacleGroup * temp){
    temp->updateObstacleGroup19Pos(this->pSpriteSheet, this->pSpace,mapIndex, mapWidth);
}
//20
void ObjectManager::updateObstacleGroup20(int mapIndex, float mapWidth,ObstacleGroup * temp){
    temp->updateObstacleGroup20Pos(this->pSpriteSheet, this->pSpace,mapIndex, mapWidth);
}

//void ObjectManager::updateOther(int mapIndex, float mapWidth){
//    this->obstaclegroup->updateOther(this->pSpriteSheet,this->pSpace,mapIndex, mapWidth);
//}

//更新障碍物
void ObjectManager::updateObstacle(int mapIndex, ObstacleGroup * temp){
    srand((int)time(0));
    int groupnum = 6;//random(5) + 1;
    log("groupnum---%d",groupnum);
    switch (groupnum) {
        case 1:
            this->updateObstacleGroup1(mapIndex,this->mapwidth,temp);
            break;
        case 2:
            this->updateObstacleGroup2(mapIndex,this->mapwidth,temp);
            break;
        case 3:
            this->updateObstacleGroup3(mapIndex,this->mapwidth,temp);
            break;
        case 4:
            this->updateObstacleGroup4(mapIndex,this->mapwidth,temp);
            break;
        case 5:
            this->updateObstacleGroup5(mapIndex,this->mapwidth,temp);
            break;
        case 6:
            this->updateObstacleGroup6(mapIndex,this->mapwidth,temp);
            break;
        case 7:
            this->updateObstacleGroup7(mapIndex,this->mapwidth,temp);
            break;
        case 8:
            this->updateObstacleGroup8(mapIndex,this->mapwidth,temp);
            break;
        case 9:
            this->updateObstacleGroup9(mapIndex,this->mapwidth,temp);
            break;
        case 10:
            this->updateObstacleGroup10(mapIndex,this->mapwidth,temp);
            break;
        case 11:
            this->updateObstacleGroup11(mapIndex,this->mapwidth,temp);
            break;
        case 12:
            this->updateObstacleGroup12(mapIndex,this->mapwidth,temp);
            break;
        case 13:
            this->updateObstacleGroup13(mapIndex,this->mapwidth,temp);
            break;
        case 14:
            this->updateObstacleGroup14(mapIndex,this->mapwidth,temp);
            break;
        case 15:
            this->updateObstacleGroup15(mapIndex,this->mapwidth,temp);
            break;
        case 16:
            this->updateObstacleGroup16(mapIndex,this->mapwidth,temp);
            break;
        case 17:
            this->updateObstacleGroup17(mapIndex,this->mapwidth,temp);
            break;
        case 18:
            this->updateObstacleGroup18(mapIndex,this->mapwidth,temp);
            break;
        case 19:
            this->updateObstacleGroup19(mapIndex,this->mapwidth,temp);
            break;
        case 20:
            this->updateObstacleGroup20(mapIndex,this->mapwidth,temp);
            break;
    }

}

//产生损坏的粒子
void ObjectManager::generateBrokenParticle(ObstacleItem * item){
    if (this->player) {
        ParticleSystemQuad *broken = ParticleSystemQuad::create("res/Particles/BrokenParticle.plist");
        broken->setPositionType(ParticleSystem::PositionType::FREE);
        broken->setAutoRemoveOnFinish(true);
        ParticleBatchNode *batch = ParticleBatchNode::createWithTexture(broken->getTexture());
        batch->addChild(broken);
        batch->setPosition(item->getPositionX(), item->getPositionY());
        this->player->addChild(batch);
    }
}

// delete the item
void ObjectManager::remove(ObstacleItem * item){
    this->obstaclegroup->remove(item);
}

//delete all the items of the map
void ObjectManager::removeObjectOfMap(int mapIndex)
{
    this->obstaclegroup->removeObjectOfMap(mapIndex);
    
}

//移动
bool ObjectManager::scrollItem(float planeX){
    int newCur = planeX/mapwidth;
    if (currgroup == newCur) {
        return false;
    }
//    if (newCur%2==0) {
//        this->updateObstacle(newCur+1, this->obstaclegroup);
//    }
//    else{
//        this->updateObstacle(newCur+1, this->obstaclegroup);
//    }
    this->updateObstacle(newCur+1, this->obstaclegroup);
    currgroup = newCur;
    CCLOG("now loadImg::%d",currgroup);
    return true;
    
}

int ObjectManager::getdelObjs(){
    return this->obstaclegroup->getdelObsNum();

}


