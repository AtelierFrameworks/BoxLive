//
//  J_Joint.cpp
//  boxlive
//
//  Created by AtelierFrameworks on 2018/01/06.
//
//

#include "J_Joint.hpp"

//--------------------------------------------------------------
void J_Joint::setup(){
    if (!mIsInitialized) {
        mimage.load("J_Haikei.png");
        mStar.load("J_HandShine.png");
        mStar1.load("J_Shine1.png");
        mStar2.load("J_Shine2.png");
        mStar3.load("J_Shine3.png");
        mStar4.load("J_ShiningStar.png");
        mSound.load("J_Sound.mp3");
        mSound.setLoop(false);
        mIsInitialized = true;
    }
 
   // ofBackground(0, 0, 0);

    mSpeed1X = ofGetWidth()-590;
    mSpeed1Y = ofGetHeight()-500;
    mSpeed2X = ofGetWidth()-550;
    mSpeed2Y = ofGetHeight()-500;
    mSpeed3X = ofGetWidth()-100;
    mSpeed3Y = ofGetHeight()-550;
    mSpeed4X = ofGetWidth()-550;
    mSpeed4Y = ofGetHeight()-550;
}

//--------------------------------------------------------------
void J_Joint::update(){
    mSpeed1X ++;
    mSpeed1Y ++;
    mSpeed2X ++;
    mSpeed2Y ++;
    mSpeed3X --;
    mSpeed3Y ++;
    mSpeed4X --;
    mSpeed4Y ++;
}

//--------------------------------------------------------------
void J_Joint::draw(ofVec2f _headpos, ofVec2f _lefthandpos, ofVec2f _righthandpos, ofVec2f _leftfootpos, ofVec2f _rightfootpos,ofVec2f _leftelbowpos,ofVec2f _rightelbowpos, ofVec2f _leftkneepos, ofVec2f _rightkneepos,ofVec2f _head2pos, ofVec2f _lefthand2pos, ofVec2f _leftfoot2pos, ofVec2f _righthand2pos, ofVec2f _rightfoot2pos){
    
    ofSetColor(0, 0, 0);

    float w = ofGetWindowWidth(), h = ofGetWindowHeight();
    scale = MIN(w / 640, h / 480);
    offsetX = (w - 640 * scale) / 2;
    offsetY = (h - 480 * scale) / 2;
    ofTranslate(offsetX, offsetY);
    ofScale(scale, scale);
    ofSetColor(255, 255, 255);
    
    if(_headpos.x != -999 && _lefthandpos.x != -999){
        ofDrawLine(_headpos,_leftelbowpos);
    }
    if(_leftfootpos.x != -999 && _lefthandpos.x != -999){
        ofDrawLine(_leftelbowpos,_lefthandpos);
    }
    if(_rightfootpos.x != -999 && _lefthandpos.x != -999){
        ofDrawLine(_lefthandpos,_leftkneepos);
    }
    if(_rightfootpos.x != -999 && _righthandpos.x != -999){
        ofDrawLine(_leftkneepos,_leftfootpos);
    }
    if(_headpos.x != -999 && _righthandpos.x != -999){
        ofDrawLine(_leftfootpos,_rightfootpos);
    }
    if(_headpos.x != -999 && _righthandpos.x != -999){
        ofDrawLine(_rightfootpos,_rightkneepos);
    }
    if(_headpos.x != -999 && _righthandpos.x != -999){
        ofDrawLine(_rightkneepos,_righthandpos);
    }
    if(_headpos.x != -999 && _righthandpos.x != -999){
        ofDrawLine(_righthandpos,_rightelbowpos);
    }
    if(_headpos.x != -999 && _righthandpos.x != -999){
        ofDrawLine(_rightelbowpos,_headpos);
    }
    if(_head2pos.x != -999){
        mStar.draw(_head2pos.x-50,_head2pos.y-50,100,100);;
    }
    if(_lefthand2pos.x != -999){
        mStar.draw(_lefthand2pos.x-50,_lefthand2pos.y-50,100,100);;
    }
    if(_leftfoot2pos.x != -999){
        mStar.draw(_leftfoot2pos.x-50,_leftfoot2pos.y-50,100,100);;
    }
    if(_righthand2pos.x != -999){
        mStar.draw(_righthand2pos.x-50,_righthand2pos.y-50,100,100);;
    }
    if(_rightfoot2pos.x != -999){
        mStar.draw(_rightfoot2pos.x-50,_rightfoot2pos.y-50,100,100);;
    }
    if(_lefthand2pos.y<=30 && _righthand2pos.y<=30){
        mStar1.draw(mSpeed1X, mSpeed1Y, 100, 100);
        mStar2.draw(mSpeed2X, mSpeed2Y, 100, 100);
        mStar3.draw(mSpeed3X, mSpeed3Y, 100, 100);
        mStar4.draw(mSpeed4X, mSpeed4Y, 100, 100);
        //mSound.play();
    }else if(_lefthand2pos.y>=30 && _righthand2pos.y>=30){
        mSpeed1X = ofGetWidth()-590;
        mSpeed1Y = ofGetHeight()-500;
        mSpeed2X = ofGetWidth()-550;
        mSpeed2Y = ofGetHeight()-500;
        mSpeed3X = ofGetWidth()-100;
        mSpeed3Y = ofGetHeight()-550;
        mSpeed4X = ofGetWidth()-550;
        mSpeed4Y = ofGetHeight()-550;
    }else{
        //mSound.stop();
    }

}

//--------------------------------------------------------------

//--------------------------------------------------------------
