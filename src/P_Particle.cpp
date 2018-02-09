//
//  P_Particle.cpp
//  boxlive
//
//  Created by AtelierFrameworks on 2018/01/06.
//
//

#include "P_Particle.hpp"

//--------------------------------------------------------------
void P_Particle::setup() {
    ofSetFrameRate(60);
    ofBackground(0, 0, 0);
   if(!mIsInitialized){
        for (int i = 0; i < 24; i++) {
            char char1[100];
            sprintf(char1, "P_%dparticle.png", i + 1);
            
            Particle[i].load(char1);
        }
      mIsInitialized = true;
    }
    
    for (int j = 0; j < 24; j++) {
        G_index[j] = j;
    }
    pos.clear();
    vel.clear();
}

//--------------------------------------------------------------
void P_Particle::update(ofPoint _handpos) {

    _handpos.set(ofGetWidth()-(_handpos.x / 640 * ofGetWidth()), _handpos.y / 480 * ofGetHeight());
    pos.push_back(_handpos);
    ofVec2f v;
    v.set(ofRandom(-5, 5), ofRandom(-5, 5));
    vel.push_back(v);
    
    for (int i = 0;i < pos.size(); i++) {
        pos[i] += vel[i];
    }
}

//--------------------------------------------------------------
void P_Particle::draw() {
    int i, j = 0;

    for (i = 0;i < pos.size(); i++) {
        ofPushMatrix();
        ofTranslate(pos[i]);
        
        if (j > 23) {
            j = 0;
        }
        
        G_count = G_index[j];
        ofSetColor(G_color,G_color,G_color);
        Particle[G_count].draw(0, 0, 50, 50);
        if(G_color <= 255 && G_color > 0){
            //G_color -= 0.1;
        }else{
            pos.clear();
            vel.clear();
            G_color = 255;
        }
        ofPopMatrix();
        j++;
    }
    
    
}
