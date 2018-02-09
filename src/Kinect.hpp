//
//  Kinect.hpp
//  2_boxlive
//
//  Created by AtelierFrameworks on 2018/01/24.
//
//
#pragma once
#ifndef Kinect_hpp
#define Kinect_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxOpenNI.h"
#endif /* Kinect_hpp */
class Kinect : public ofBaseApp{
public:
    void setup();
    void draw();
     ofxOpenNI kinect;
};
