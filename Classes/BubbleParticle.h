//
//  BubbleParticle.h
//  YellowPlane
//
//  Created by George on 15/7/1.
//
//

#ifndef __YellowPlane__BubbleParticle__
#define __YellowPlane__BubbleParticle__

#include <stdio.h>
#include "chipmunk.h"
#include "cocos-ext.h"
using namespace cocos2d;
using namespace std;

class BubbleParticle : public extension::PhysicsSprite{

private:
    BubbleParticle(cpSpace *space);
    ~BubbleParticle();
public:
    void initBody();
    float speed;
};
#endif /* defined(__YellowPlane__BubbleParticle__) */
