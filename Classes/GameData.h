//
//  GameData.h
//  YellowPlane
//
//  Created by George on 15/5/31.
//
//
//store the game data
#ifndef __YellowPlane__GameData__
#define __YellowPlane__GameData__

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
using namespace cocos2d;

typedef enum{
    SpriteYelloPlane = 0,
    SpriteCoin = 1,
    SpriteMine_chain_export =2,
    SpriteMine_chains = 3,
    SpriteLasers_export = 4,
    SpriteNaval_mine = 5,
    SpriteLaser1 = 6,
    SpriteLaser2 = 7,
    SpriteTorpedo_export = 8,
    SpriteTorpedo_fire1 = 9,
    SpriteTorpedo_fire2 = 10,
    
    SpriteRevive = 11,
    SpriteShield = 12,
    SpriteSonicWave = 13,
    SpriteSpeed = 14,
    
    SpriteSand = 15,
    SpriteUp = 16,
    
    SpriteShieldParticle = 17,
    SpriteSonicWaveParticle = 18,
    SpriteSpeedFrontParticle = 19,
}CollisionTag;


typedef enum{
    TAG_BackgroundLayer = 0,
    TAG_PlayLayer = 1,
    TAG_StatusLayer = 2,
}TAG_Layer;

typedef enum {
    Game_Ready,
    Game_Run,
    Game_Over,
    Game_Resume,
}GameStatus;


static bool m_IsFirstPlayGame;
static bool IsStartPlaying;
static bool m_IsPlayBgMusic;
static bool m_IsPlayEffect;
static int m_BestScore;
static GameStatus gamestatus;

static float scalex;
static float scaley;
static float sandHeight;


class GameData
{
private:
    GameData();
    ~GameData();

    virtual bool init();
    static GameData * data;
    
public:
    
    static GameData * getInstance();
    static void destroyInstance();

    void GameInit();
    bool getStartPlaying();
    void setStartPlaying(bool newStartPlaying);
    
    bool getIsPlayBgMusic();
    void setIsPlayBgMusic(bool value);
    
    bool getIsPlayEffect();
    void setIsPlayEffect(bool value);
    
    bool getIsFirstPlayGame();
    void setIsFirstPlayGame(bool value);
    
    void setBestScore(int value);
    int getsetBestScore();
    
    void setScale(float valuex,float valuey);
    float getScaleX();
    float getScaleY();
    
    GameStatus getGameStatus();
    void setGameStatus(GameStatus status);
    
    float getSandHeight();
    void setSandHeight(float newSandHeight);
};

#endif /* defined(__YellowPlane__GameData__) */
