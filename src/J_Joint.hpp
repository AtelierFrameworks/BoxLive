//
//  J_Joint.hpp
//  boxlive
//
//  Created by AtelierFrameworks on 2018/01/06.
//
//
#pragma once
#ifndef J_Joint_hpp
#define J_Joint_hpp

#include "ofMain.h"
#include "ofxOpenNI.h"

#endif /* J_Joint_hpp */

class J_Joint
{
public:
    float scale, offsetX, offsetY;
    void setup();
    void update();
    void draw(ofVec2f _headpos, ofVec2f _lefthandpos, ofVec2f _righthandpos, ofVec2f _leftfootpos, ofVec2f _rightfootpos,ofVec2f _lefttelbowpos,ofVec2f _rightterebowpos, ofVec2f _leftkneepos, ofVec2f _rightkneepos, ofVec2f _head2pos, ofVec2f _lefthand2pos, ofVec2f _leftfoot2pos, ofVec2f _righthand2pos, ofVec2f _rightfoot2pos);


    ofImage mimage,mStar,mStar1,mStar2,mStar3,mStar4,mStar5;
    float mSpeed1X,mSpeed1Y,mSpeed2X,mSpeed2Y,mSpeed3X,mSpeed3Y,mSpeed4X,mSpeed4Y;
    ofSoundPlayer mSound;
    bool mIsInitialized = false;
};
