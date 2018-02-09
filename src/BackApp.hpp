//
//  BackApp.hpp
//  2_boxlive
//
//  Created by AtelierFrameworks on 2018/01/17.
//
//
#pragma once
#ifndef BackApp_hpp
#define BackApp_hpp

#include "ofMain.h"
#include "CONST.h"
#include "P_Avater.hpp"
#include "S_ShadowS.hpp"
#endif /* BackApp_hpp */
class BackApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void setVariety(CONST::VARIETY variety);
    void setKirinuki(ofImage* kirinuki);
    void setPut(int put[640*480]);
    
    CONST::VARIETY mVariety;
    ofImage* mKirinuki;
    
    int mputs[640*480];
    
    P_Avater mP_Avaters;
    S_ShadowS mS_ShadowSs;
    ofImage A_Background;
    ofImage J_Background;
};
