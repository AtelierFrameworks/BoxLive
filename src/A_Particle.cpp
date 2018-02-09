//
//  A_Particle.cpp
//  boxlive
//
//  Created by AtelierFrameworks on 2018/01/06.
//
//

#include "A_Particle.hpp"



#define PARTICLE_MAX_NUM 300


//--------------------------------------------------------------
void A_Particle::setup(){
    ofSetVerticalSync(true);
    
    mode = 0;
        
    handPos[0]=ofVec2f(0,0);
    handPos[1]=ofVec2f(0,ofGetHeight());
    handPos[2]=ofVec2f(ofGetWidth(),0);
    handPos[3]=ofVec2f(ofGetWidth(),ofGetHeight());
}

//--------------------------------------------------------------
void A_Particle::update(int _numHands, ofVec2f _handPos[]){
    
    for(int i=0;i<_numHands;i++){
        
        _handPos[i].x=_handPos[i].x/640*ofGetWidth();
        _handPos[i].y=_handPos[i].y/480*ofGetHeight();
        
        for (int i = 0; i < Particles.size(); i++) {
            Particles[i].update(mode);
        }
        
        MousePos[0] = MousePos[1];
        //MousePos[1] = ofVec2f(ofGetMouseX(), ofGetMouseY());
        MousePos[1]=ofVec2f(_handPos[i].x,_handPos[i].y);
        
        //êiçsï˚å¸âEå¸Ç´
        if (MousePos[0].x < MousePos[1].x) {
            limit.w = 0;
            limit.x = 2;
        }
        else {
            limit.w = -2;
            limit.x = 0;
        }
        //êiçsï˚å¸â∫å¸Ç´
        if (MousePos[0].y < MousePos[1].y) {
            limit.y = 0;
            limit.z = 2;
        }
        else {
            limit.y = -2;
            limit.z = 0;
        }
        
        timeCount++;
        if (timeCount > 60*0.1) {
            Particle myParticle;
            if(mode==1){
                limit.w=center.x;
                limit.x=center.y;
            }
            myParticle.setup(_handPos[i], limit,mode);
            
            Particles.push_back(myParticle);
            timeCount = 0;
        }
        
        if (Particles.size() > PARTICLE_MAX_NUM) {
            Particles.erase(Particles.begin());
        }
    }
    /*
     if (ofGetFrameRate() < 40 && Particles.size()>0) {
     Particles.erase(Particles.begin());
     }
     */
    if(mode==0){
        for(int i=0;i<_numHands;i++){
            for(int j=i+1;j<_numHands;j++){
                if(abs(_handPos[i].x-_handPos[j].x)<70&&abs(_handPos[i].y-_handPos[j].y)<70){
                    mode = 1;
                    Particles.clear();
                    center=ofVec2f(ofGetWidth()/2,100);
//                    center= ofVec2f(ofGetWidth()-(_handPos[i].x+_handPos[j].x)/2 ,(_handPos[i].y+_handPos[j].y)/2);
//                    if(center.x<70)center.x=70;
//                    else if(center.x>ofGetWidth()-250)center.x=ofGetWidth()-250;
                    /* for (int i = 0; i < Particles.size(); i++) {
                     Particles[i].setMode(mode,center);
                     }*/
                }
            }
        }
    }
    
}

//--------------------------------------------------------------
void A_Particle::draw(){
    
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    //Background.draw(0, 0, ofGetWidth(), ofGetHeight());
    //ofDrawBitmapString(ofToString(ofGetFrameRate()) + "fps", 20, 20);
    
    
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    //ofCircle(ofGetWidth() / 2, ofGetHeight() / 2, 5);
    for (int i = 0; i < Particles.size(); i++) {
        Particles[i].draw(mode);
    }
    /*
    for(int i=0;i<numHands;i++){
        ofDrawCircle(handPos[i].x , handPos[i].y, 10);
    }
    */
    //kinect.drawDepth(0, 0, ofGetWidth(), ofGetHeight());   //  depth image (in color)
    
}


//--------------------------------------------------------------
void A_Particle::keyPressed(int key){
    /*if (key == 'a') {
     mode = 1;
     for (int i = 0; i < Particles.size(); i++) {
     Particles[i].setMode(mode);
     }
     }*/
    if (key == 'c') {
        Particles.clear();
    }
    
}
