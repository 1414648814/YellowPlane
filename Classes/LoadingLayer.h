//
//  LoadingLayer.h
//  YellowPlane
//
//  Created by George on 15/8/16.
//
//

#ifndef __YellowPlane__LoadingLayer__
#define __YellowPlane__LoadingLayer__

#include <stdio.h>
#include "cocos2d.h"
#include "GameData.h"
#include "SaveData.h"
#include "MenuScene.h"
#include "ImgLoader.h"
using namespace cocos2d;

class LoadingLayer : public Layer{

private:
    Sprite * bg;
    
public:
    virtual bool init();
    void handleData();
    void removeLoadingBg(Node * pNode);
    CREATE_FUNC(LoadingLayer);

};

#endif /* defined(__YellowPlane__LoadingLayer__) */
