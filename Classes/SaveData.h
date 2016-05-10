//
//  SaveData.h
//  YellowPlane
//
//  Created by George on 15/8/16.
//
//

#ifndef __YellowPlane__SaveData__
#define __YellowPlane__SaveData__

#include <stdio.h>
#include "cocos2d.h"
using namespace cocos2d;
using namespace std;
USING_NS_CC;

class SaveData{
private:
    SaveData();
    virtual bool init();
    static SaveData * data;
public:
    static SaveData * getInstance();
    static void destroyInstance();
    
    void setIsFisrtPlayGame(bool isFirstPlayGame);
    bool getIsFisrtPlayGame();
    
    void setIsPlayBgMusic(bool value);
    bool getIsPlayBgMusic();
    
    void setIsPlayEffect(bool value);
    bool getIsPlayEffect();
    
    void setBestScore(int value);
    int getBestScore();
};


#endif /* defined(__YellowPlane__SaveData__) */
