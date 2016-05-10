//
//  SaveData.cpp
//  YellowPlane
//
//  Created by George on 15/8/16.
//
//

#include "SaveData.h"

SaveData * SaveData::data = NULL;
SaveData::SaveData(){
    
    
}

bool SaveData::init(){
    return true;
}

SaveData * SaveData::getInstance()
{
    if (data==NULL) {
        data = new SaveData();
        if (!data->init()) {
            delete data;
            data = NULL;
        }
    }
    return data;
}

void SaveData::destroyInstance()
{
}

void SaveData::setIsFisrtPlayGame(bool isFirstPlayGame){
    UserDefault::getInstance()->setBoolForKey("IsFisrtPlayGame", isFirstPlayGame);
    return;
}

bool SaveData::getIsFisrtPlayGame(){
    return UserDefault::getInstance()->getBoolForKey("IsFisrtPlayGame");
    
}

void SaveData::setIsPlayBgMusic(bool value){
    UserDefault::getInstance()->setBoolForKey("IsPlayBgMusic", value);
    return;
}

bool SaveData::getIsPlayBgMusic(){
    return UserDefault::getInstance()->getBoolForKey("IsPlayBgMusic");
    
}

void SaveData::setIsPlayEffect(bool value){
    UserDefault::getInstance()->setBoolForKey("IsPlayEffect", value);
    
}

bool SaveData::getIsPlayEffect(){
    return UserDefault::getInstance()->getBoolForKey("IsPlayEffect");
    
}

void SaveData::setBestScore(int value){
    UserDefault::getInstance()->setIntegerForKey("BestScore", value);
    return;
}

int SaveData::getBestScore(){
    return UserDefault::getInstance()->getIntegerForKey("BestScore");
    
}

