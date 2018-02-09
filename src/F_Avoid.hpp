//
//  F_Font.hpp
//  boxlive
//
//  Created by AtelierFrameworks on 2018/01/06.
//
//


#pragma once
#ifndef F_Avoid_hpp
#define F_Avoid_hpp

#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxOpenNI.h"
#include "ofxOpenCv.h"
#define MAX_BLOBS 4
#include "F_triangleShape.h"

#endif /* F_Avoid_hpp */
class F_Avoid
{
public:
    //  kinect + OpenCv
    float minDist, maxDist;
    ofxCvGrayscaleImage invertImage;
    ofxCvGrayscaleImage shadowImage;
    ofxCvContourFinder finder;
    int numShadows;
    ofPolyline shadowLines[MAX_BLOBS];
    ofPtr<ofxBox2dPolygon> shadows[MAX_BLOBS];
    
public:
    void setup();
    void update(unsigned short *_depthData);
    void draw();
    

    ofxBox2d box2d;

// a vector of all the texture images
    vector <ofImage> textures;

    static const int mCount = 24;

    ofxBox2dCircle mCircles[mCount];

    int circleColor = (int)ofRandom(1, 10);
    int rectColor = (int)ofRandom(1, 10);


    vector <ofPtr<ofxBox2dRect> > mRects;
    vector <ofColor> rectColors;

// a vector of all the texture shapes
    vector <shared_ptr<F_triangleShape> > mTriangles;

//  display mode
    float scale, offsetX, offsetY;
    bool mIsInitialized = false;
    
};
