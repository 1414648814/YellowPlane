//
//  ImgLoader.h
//  YellowPlane
//
//  Created by George on 15/6/1.
//
//

#ifndef __YellowPlane__ImgLoader__
#define __YellowPlane__ImgLoader__

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
using namespace cocos2d;
using namespace std;
USING_NS_CC;

typedef struct{
    char name[255];
    int width;
    int height;
    cocos2d::Point start;
    cocos2d::Point end;
}Img;
class ImgLoader{
public:
    static ImgLoader * getInstance();
    
    static void destroyInstance();
    
    Sprite* LoadImg(string filename);

    Sprite * getSpriteFramesByName(string filename);
    
    SpriteFrame * getSpriteFrameByName(string filename,cocos2d::Rect rect);
    
    void addBackgroundFrameCache();
    void removeBackgroundFrameCache();
    
    void addGUIFrameCache();
    void removeGUIFrameCache();
    
    void addObstacleFrameCache();
    void removeObstacleFrameCache();
    
    void addPowerFrameCache();
    void removePowerFrameCache();
    
    void addYelleowplaneFrameCache();
    void removeYellowplaneFrameCache();
    
    void removeUnusedFrameCache();
    void removeUnusedTexture();
    
protected:
    ImgLoader();
    
    virtual bool init();
    
    static ImgLoader * loader;
    
};

#endif /* defined(__YellowPlane__ImgLoader__) */
