//
//  MenuScene.h
//  YellowPlane
//
//  Created by George on 15/6/1.
//
//

#ifndef __YellowPlane__MenuScene__
#define __YellowPlane__MenuScene__

#include <stdio.h>
#include "cocos2d.h"
#include "WelcomeScene.h"
#include "PlayScene.h"
#include "ImgLoader.h"
#include "Audio.h"
#include "GameData.h"
USING_NS_CC;
using namespace cocos2d;

class MenuScene : public Layer{
public:
    static Scene * createScene();
    virtual bool init();
    CREATE_FUNC(MenuScene);
private:
    void homePlayCallBack(Ref * pSender);

};

#endif /* defined(__YellowPlane__MenuScene__) */
