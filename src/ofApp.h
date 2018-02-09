#pragma once

#include "ofMain.h"
#include "P_Particle.hpp"
#include "A_Particle.hpp"
#include "S_ShadowApp.hpp"
//#include "S_ShadowS.hpp"
#include "J_Joint.hpp"
#include "F_Avoid.hpp"
#include "ofxOpenNI.h"
#include "BackApp.hpp"
#include "CONST.h"
#include "Kinect.hpp"
//#include "ofxOpenCv.h"

class ofApp : public ofBaseApp{
public:
    ofxOpenNI kinect;
    ofImage kirinuki,scenery;
    ofImage* kirinukiP;
    int VARIETY_NUM = 3;
    CONST::VARIETY mVariety;
    //BackApp
    shared_ptr<BackApp> mBackApp;
    shared_ptr<Kinect> kinectApp;

private:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    P_Particle mP_Perticles;
    A_Particle mA_Perticles;
    S_ShadowApp mS_ShadowApps;
//    S_ShadowS mS_ShadowS;
    J_Joint mJ_Joints;
    F_Avoid mF_Avoids;
    
    
    //Timer
    double timer;
    int countp,counta,countj,counts,counf;
    
    // P_Particle + A_Particle
    ofPoint P_handpos;
    int numHands;
    ofVec2f handPos[4];

    //J_Joint
    ofVec2f gotAcount(Joint bone);
    ofVec2f headpos, lefthandpos, righthandpos, leftfootpos, rightfootpos,leftelbowpos,rightelbowpos, leftkneepos, rightkneepos,head2pos, lefthand2pos, leftfoot2pos, righthand2pos, rightfoot2pos;
    
    //Arduino
    ofSerial serial;
    
    //S_Shadow
    int putS[640*480];
};

