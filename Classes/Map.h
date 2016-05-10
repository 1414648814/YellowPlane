//
//  Map.h
//  YellowPlane
//
//  Created by George on 15/6/3.
//
//

#ifndef __YellowPlane__Map__
#define __YellowPlane__Map__

#include <stdio.h>
#include "cocos-ext.h"
#include "chipmunk.h"
#include "GroundItem.h"
#include "ImgLoader.h"
#include "GameData.h"
#include "GroundItemGroup.h"

#include <time.h>
#define random(x) (rand()%x)
using namespace cocos2d;
USING_NS_CC;

class MAP : public Sprite
{
public:
    static MAP* create(int index);
    MAP(int index);
    ~MAP();
    virtual bool init();
    
    static float getSandHeight(){return 72;};
    float getMapWidth();
    float getVisibleWidth();
    void loadImg(int index);
private:
    ForeGroundItem foreitem;
    MiddleGroundItem miditem;
    BackGroundItem backitem;

    float sandy;
    float visibleWidth;
};

#endif /* defined(__YellowPlane__Map__) */
