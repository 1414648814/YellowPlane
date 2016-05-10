//
//  BackGroundItem.h
//  YellowPlane
//
//  Created by George on 15/5/31.
//
//
//store the backgrounditem 
#ifndef __YellowPlane__BackGroundItem__
#define __YellowPlane__BackGroundItem__

#include <stdio.h>
#include "cocos2d.h"
#include "ImgLoader.h"
#include<time.h>

#define random(x) (rand()%x)
using namespace cocos2d;
using namespace std;

USING_NS_CC;
//foreitem
enum ForeGroundItemType
{
    Fore_Chest = 0,
    Fore_Plant1 = 1,
    Fore_Plant2 = 2,
    Fore_Plant3 = 3,
    Fore_Snail = 4,
    Fore_Startfish =5,
    Fore_Stone1 = 6,
    Fore_Stone2 = 7,
    Fore_Stone3 = 8,
    Fore_Stone4 = 9,
    Fore_Stone5 = 10,
    Fore_Stone6 = 11
};

class ForeGroundItem : public Sprite{
public:
    static Sprite* create(ForeGroundItemType type);
    Sprite* RandomCreateForeItem();
    CREATE_FUNC(ForeGroundItem);
};

//middleitem
enum MiddleGroundItemType
{
    Mid_Plant1 = 0,
    Mid_Plant2 = 1,
    Mid_Plant3 = 2,
    Mid_Plant4 = 3,
    Mid_Plant5 = 4,
    Mid_Plant6 = 5,
};

class MiddleGroundItem : public Sprite{
public:
    static Sprite* create(MiddleGroundItemType type);
    Sprite* RandomCreateMidItem();
    CREATE_FUNC(MiddleGroundItem);
};

//backgrounditem
enum BackGroundItemType{
    Back_Rock1 = 0,
    Back_Rock2 = 1,
    Back_Wreck = 2
};

class BackGroundItem : public Sprite{
public:
    static Sprite* create(BackGroundItemType type);
    Sprite* RandomCreateBackItem();
    CREATE_FUNC(BackGroundItem);
};



#endif /* defined(__YellowPlane__BackGroundItem__) */
