//
//  LoadingScene.h
//  YellowPlane
//
//  Created by George on 15/5/31.
//
//

#ifndef __YellowPlane__LoadingScene__
#define __YellowPlane__LoadingScene__

#include <stdio.h>
#include "cocos2d.h"
#include "LoadingLayer.h"
using namespace cocos2d;

class LoadingScene : public Scene
{
public:
    virtual bool init();
    CREATE_FUNC(LoadingScene);
private:
    
};


#endif /* defined(__YellowPlane__LoadingScene__) */
