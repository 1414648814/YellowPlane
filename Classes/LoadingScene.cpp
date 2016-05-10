//
//  LoadingScene.cpp
//  YellowPlane
//
//  Created by George on 15/5/31.
//
//

#include "LoadingScene.h"

bool LoadingScene::init(){
    if (!Scene::init()) {
        return false;
    }
    
    LoadingLayer * layer = LoadingLayer::create();
    this->addChild(layer);

    return true;

}