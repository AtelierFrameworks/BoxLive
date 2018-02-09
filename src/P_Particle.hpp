//
//  P_Particle.hpp
//  boxlive
//
//  Created by AtelierFrameworks on 2018/01/06.
//
//
#pragma once
#ifndef P_Particle_hpp
#define P_Particle_hpp
#include "ofMain.h"

#endif /* P_Particle_hpp */

class P_Particle
{
    public:
        void setup();
        void update(ofPoint _handpos);
        void draw();
    
    
    vector<ofVec2f> pos;
    vector<ofVec2f> vel;
    
    int G_count;
    int G_index[48];
    float G_color = 255;
    
    ofImage Particle[100];
    bool mIsInitialized = false;
//    ofImage P_1particle;
//    ofImage P_2particle;
//    ofImage P_3particle;
//    ofImage P_4particle;
//    ofImage P_5particle;
//    ofImage P_6particle;
//    ofImage P_7particle;
//    ofImage P_8particle;
//    ofImage P_9particle;
//    ofImage P_10particle;
//    ofImage P_11particle;
//    ofImage P_12particle;
//    ofImage P_13particle;
//    ofImage P_14particle;
//    ofImage P_15particle;
//    ofImage P_16particle;
//    ofImage P_17particle;
//    ofImage P_18particle;
//    ofImage P_19particle;
//    ofImage P_20particle;
//    ofImage P_21particle;
//    ofImage P_22particle;
//    ofImage P_23particle;
//    ofImage P_24particle;
    
};
