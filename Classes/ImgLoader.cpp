//
//  ImgLoader.cpp
//  YellowPlane
//
//  Created by George on 15/6/1.
//
//
/*
 进行数据的加载
 
 
 */
#include "ImgLoader.h"

ImgLoader * ImgLoader::loader = NULL;
ImgLoader::ImgLoader(){
    
    
}

ImgLoader * ImgLoader::getInstance()
{
    if (loader==NULL) {
        loader = new ImgLoader();
        if (!loader->init()) {
            delete loader;
            loader = NULL;
        }
        
    }
    return loader;
}

void ImgLoader::destroyInstance()
{
    

}

Sprite * ImgLoader::LoadImg(string filename)
{
    Sprite *  item = Sprite::create(filename);
    return item;
}


Sprite * ImgLoader::getSpriteFramesByName(string filename)
{
    Sprite * item = Sprite::createWithSpriteFrameName(filename);
    return item;
}

SpriteFrame * ImgLoader::getSpriteFrameByName(string filename,Rect rect)
{
    SpriteFrame * frame = SpriteFrame::create(filename, rect);
    return frame;
}

void ImgLoader::addBackgroundFrameCache(){
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/Background/BackGround.plist", "res/Background/background.png");

}

void ImgLoader::removeBackgroundFrameCache(){
    SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("res/Background/BackGround.plist");

}

void ImgLoader::addGUIFrameCache(){
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/GUI/GUI.plist","res/GUI/GUI.png");

}

void ImgLoader::removeGUIFrameCache(){
    SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("res/GUI/GUI.plist");
    
}

void ImgLoader::addObstacleFrameCache(){
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/Obstacles/Obstacle.plist","res/Obstacles/Obstacle.png");

}

void ImgLoader::removeObstacleFrameCache(){
    SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("res/Obstacles/Obstacle.plist");

}

void ImgLoader::addPowerFrameCache(){
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/PowerUps/PowerUp.plist", "res/PowerUps/PowerUp.png");

}

void ImgLoader::removePowerFrameCache(){
    SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("res/PowerUps/PowerUp.plist");
    
}

void ImgLoader::addYelleowplaneFrameCache(){
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/YelloPlane.plist", "res/YelloPlane.png");

}

void ImgLoader::removeYellowplaneFrameCache(){
    SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("res/YelloPlane.plist");

}

void ImgLoader::removeUnusedFrameCache(){
    SpriteFrameCache::getInstance()->removeUnusedSpriteFrames();
    
}

void ImgLoader::removeUnusedTexture(){
    Director::getInstance()->getTextureCache()->removeUnusedTextures();

}

bool ImgLoader::init()
{
    return true;
}

