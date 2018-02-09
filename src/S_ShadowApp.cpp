//
//  S_Shadow.cpp
//  boxlive
//
//  Created by AtelierFrameworks on 2018/01/10.
//
//

#include "S_ShadowApp.hpp"

//--------------------------------------------------------------
void S_ShadowApp::setup(){
    
    ofBackground(0);

    fingerMovie.load("movie.mp4");
    fingerMovie.play();
    
}

//--------------------------------------------------------------
void S_ShadowApp::update(){
    
    fingerMovie.update();
}

//--------------------------------------------------------------
void S_ShadowApp::draw(ofImage* _kirinuki){
    
    // ofSetColor(255, 255, 255);
    fingerMovie.draw(0, 0, ofGetWidth(), ofGetHeight());
    // ofSetColor(0, 0, 0);
    _kirinuki->draw(0, 0, ofGetWidth(), ofGetHeight());
    
}
