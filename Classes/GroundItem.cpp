//
//  BackGroundItem.cpp
//  YellowPlane
//
//  Created by George on 15/5/31.
//
//
/*
 创建出地面上的物体
 
 */
#include "GroundItem.h"

Sprite* ForeGroundItem::create(ForeGroundItemType type)
{
    Sprite *item;
    switch (type) {
        case Fore_Chest:
            item = ImgLoader::getInstance()->getSpriteFramesByName("deepocean_foreground_chest1.png");
            break;
        case Fore_Plant1:
            item = ImgLoader::getInstance()->getSpriteFramesByName("deepocean_foreground_plant1.png");
            break;
        case Fore_Plant2:
            item = ImgLoader::getInstance()->getSpriteFramesByName("deepocean_foreground_plant2.png");
            break;
        case Fore_Plant3:
            item = ImgLoader::getInstance()->getSpriteFramesByName("deepocean_foreground_plant3.png");
            break;
        case Fore_Snail:
            item = ImgLoader::getInstance()->getSpriteFramesByName("deepocean_foreground_snail1.png");
            break;
        case Fore_Startfish:
            item = ImgLoader::getInstance()->getSpriteFramesByName("deepocean_foreground_starfish1.png");
            break;
        case Fore_Stone1:
            item = ImgLoader::getInstance()->getSpriteFramesByName("deepocean_foreground_stone1.png");
            break;
        case Fore_Stone2:
            item = ImgLoader::getInstance()->getSpriteFramesByName("deepocean_foreground_stone2.png");
            break;
        case Fore_Stone3:
            item = ImgLoader::getInstance()->getSpriteFramesByName("deepocean_foreground_stone3.png");
            break;
        case Fore_Stone4:
            item = ImgLoader::getInstance()->getSpriteFramesByName("deepocean_foreground_stone4.png");
            break;
        case Fore_Stone5:
            item = ImgLoader::getInstance()->getSpriteFramesByName("deepocean_foreground_stone5.png");
            break;
        case Fore_Stone6:
            item = ImgLoader::getInstance()->getSpriteFramesByName("deepocean_foreground_stone6.png");
            break;
    }
    return item;
}

Sprite* ForeGroundItem::RandomCreateForeItem()
{
    //srand((int)time(0));
    //int type = random(11);
    int type = CCRANDOM_0_1()*11;
    ForeGroundItemType foretype = (ForeGroundItemType)type;
    Sprite * sprite = create(foretype);
    return sprite;
}

Sprite* MiddleGroundItem::create(MiddleGroundItemType type)
{
    Sprite * sprite;
    switch (type) {
        case Mid_Plant1:
            sprite = ImgLoader::getInstance()->getSpriteFramesByName("deepocean_middleground_plant1.png");
            break;
        case Mid_Plant2:
            sprite = ImgLoader::getInstance()->getSpriteFramesByName("deepocean_middleground_plant2.png");
            break;
        case Mid_Plant3:
            sprite = ImgLoader::getInstance()->getSpriteFramesByName("deepocean_middleground_plant3.png");
            break;
        case Mid_Plant4:
            sprite = ImgLoader::getInstance()->getSpriteFramesByName("deepocean_middleground_plant4.png");
            break;
        case Mid_Plant5:
            sprite = ImgLoader::getInstance()->getSpriteFramesByName("deepocean_middleground_plant5.png");
            break;
        case Mid_Plant6:
            sprite = ImgLoader::getInstance()->getSpriteFramesByName("deepocean_middleground_plant6.png");
            break;
    }
    return sprite;
    
}


Sprite* MiddleGroundItem::RandomCreateMidItem()
{
    //srand((int)time(0));
    //int type = random(5);
    int type = CCRANDOM_0_1()*5;
    MiddleGroundItemType midtype = (MiddleGroundItemType)type;
    Sprite * sprite = create(midtype);
    return sprite;
}

Sprite* BackGroundItem::create(BackGroundItemType type)
{
    Sprite * frame;
    switch (type) {
        case Back_Rock1:
            frame = ImgLoader::getInstance()->getSpriteFramesByName("deepocean_background_rock1.png");
            break;
        case Back_Rock2:
            frame = ImgLoader::getInstance()->getSpriteFramesByName("deepocean_background_rock2.png");
            break;
        case Back_Wreck:
            frame = ImgLoader::getInstance()->getSpriteFramesByName("deepocean_background_wreck1.png");
            break;
    }
    return frame;
}


Sprite* BackGroundItem::RandomCreateBackItem()
{
    //srand((int)time(0));
    //int type = random(2);
    int type = CCRANDOM_0_1()*2;
    BackGroundItemType backtype = (BackGroundItemType)type;
    Sprite * sprite = create(backtype);
    return sprite;
}

