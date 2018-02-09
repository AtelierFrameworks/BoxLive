//
//  A_Particle.hpp
//  boxlive
//
//  Created by AtelierFrameworks on 2018/01/06.
//
//
#pragma once
#ifndef A_Particle_hpp
#define A_Particle_hpp

#include "ofMain.h"
#include "Particle.h"

#endif /* A_Particle_hpp */

class A_Particle
{
    public:
    void setup();
    void update(int _numHands, ofVec2f _handPos[4]);
    void draw();
    void keyPressed(int key);



    int numHands;
    vector<Particle> Particles;
    
    ofVec2f MousePos[2];
    ofVec2f pos;
    ofVec2f center;
    ofVec2f handPos[4];
    ofVec4f limit;
    int mode;
    int timeCount = 0;
};
