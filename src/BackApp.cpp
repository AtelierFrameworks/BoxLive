//
//  BackApp.cpp
//  2_boxlive
//
//  Created by AtelierFrameworks on 2018/01/17.
//
//

#include "BackApp.hpp"

void BackApp::setup(){
    A_Background.load("A_background.png");
//    J_Background.load("J_Haikei.png");
}

void BackApp::update(){
   
    switch (mVariety) {
        case CONST::P:
           
            break;
        case CONST::A:
          
            break;
//        case CONST::J:
//          
//            break;
        case CONST::S:
            mS_ShadowSs.update(mputs);
            break;
      
        default:
            break;
    }

}

void BackApp::draw(){
    switch (mVariety) {
        case CONST::P:
            mP_Avaters.draw(mKirinuki);
            break;
        case CONST::A:
            A_Background.draw(0,0, ofGetWidth(), ofGetHeight());
            break;
        case CONST::J:
            J_Background.draw(0,0, ofGetWidth(), ofGetHeight());
            break;
        case CONST::S:
            mS_ShadowSs.draw();
            break;
        case CONST::F:
            ofSetColor(0);
            ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
            ofSetColor(255);
            break;
        default:
            break;
    }

}

void BackApp::setVariety(CONST::VARIETY variety){
    mVariety = variety;
    switch (mVariety) {
        case CONST::S:
            mS_ShadowSs.setup();
            break;
            
        default:
            break;
    }
}
void BackApp::setKirinuki(ofImage* kirinuki){
     mKirinuki = kirinuki;
}
void BackApp::setPut(int put[640*480]){
    for (int k = 0; k < 640*480; k+=5) {
        mputs[k] = put[k];
    }
}
