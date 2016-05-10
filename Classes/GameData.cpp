//
//  GameData.cpp
//  YellowPlane
//
//  Created by George on 15/5/31.
//
//
/*
 游戏的数据的处理
 
 
 */
#include "GameData.h"


GameData * GameData::data = NULL;
GameData::GameData(){
    
}

GameData::~GameData(){
    
}

bool GameData::init(){
    return true;
}

GameData * GameData::getInstance()
{
    if (data==NULL) {
        data = new GameData();
        if (!data->init()) {
            delete data;
            data = NULL;
        }
    }
    return data;
}

void GameData::destroyInstance()
{
    
}

void GameData::GameInit(){
    m_IsFirstPlayGame = false;
    IsStartPlaying = false;
    m_IsPlayBgMusic = false;
    m_IsPlayEffect = false;
    m_BestScore = 0;
    sandHeight = 101;
}

bool GameData::getStartPlaying(){
    return IsStartPlaying;
}

void GameData::setStartPlaying(bool newStartPlaying){
    IsStartPlaying = newStartPlaying;
}

bool GameData::getIsFirstPlayGame(){
    return m_IsFirstPlayGame;
    
}

void GameData::setIsFirstPlayGame(bool value){
    m_IsFirstPlayGame = value;
    
}

bool GameData::getIsPlayBgMusic(){
    return m_IsPlayBgMusic;
    
}

void GameData::setIsPlayBgMusic(bool value){
    m_IsPlayBgMusic = value;
    
}

bool GameData::getIsPlayEffect(){
    return m_IsPlayEffect;
    
}

void GameData::setIsPlayEffect(bool value){
    m_IsPlayEffect = value;
    
}

void GameData::setBestScore(int value){
    m_BestScore = value;
    
}

int GameData::getsetBestScore(){
    return m_BestScore;
    
}

void GameData::setScale(float valuex,float valuey){
    scalex = valuex;
    scaley = valuey;
}

float GameData::getScaleX(){
    return scalex;
    
}

float GameData::getScaleY(){
    return scaley;
    
}

GameStatus GameData::getGameStatus()
{
    return gamestatus;
}

void GameData::setGameStatus(GameStatus status){
    gamestatus = status;
}

float GameData::getSandHeight(){
    return sandHeight;
}

void GameData::setSandHeight(float newSandHeight){
    sandHeight = newSandHeight;

}


