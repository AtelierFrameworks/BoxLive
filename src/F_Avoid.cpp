//
//  F_Font.cpp
//  boxlive
//
//  Created by AtelierFrameworks on 2018/01/06.
//
//

#include "F_Avoid.hpp"

//--------------------------------------------------------------
void F_Avoid::setup() {
    //  sensing range of distance [mm]
    minDist = 500;
    maxDist = 2000;
    
    //ËÉåÊôØ
    ofSetBackgroundColor(0);
    ofSetLogLevel(OF_LOG_NOTICE);
    ofSetVerticalSync(true);
    ofDisableAntiAliasing();
    
    // find all the texture files and load them
    ofDirectory dir;
    ofDisableArbTex();
    int n = dir.listDir("textures");
    for (int i = 0; i < n; i++) {
        textures.push_back(ofImage(dir.getPath(i)));
    }
    
    // Box2d
    if(!mIsInitialized){
        box2d.init();
        box2d.setGravity(0, 0.98);
        box2d.createBounds();
        box2d.setFPS(60.0);
        box2d.registerGrabbing();
        mIsInitialized= true;
        
    }
    
    //  circle
    for(int cnt = 0; cnt < mCount; cnt++){
        
        mCircles[cnt].setPhysics(5.0,0.8,0);
        
        int x = ofRandom(0, ofGetWidth());
        int y = ofRandom(100, ofGetHeight() - 40);
        
        mCircles[cnt].setup(box2d.getWorld(),x, y, 20);
        
    }
    
    //  rect
    for(int cnt = 0; cnt < mCount; cnt++){
        ofPtr<ofxBox2dRect> r = ofPtr<ofxBox2dRect>(new ofxBox2dRect);
        
        float w = 40;
        float h = 40;
        
        float x = ofRandom(0, ofGetWidth() - 40);
        float y = ofRandom(100, ofGetHeight() - 40);
        r.get()->setPhysics(5, 1.2, 0.5);
        r.get()->setup(box2d.getWorld(), ofRectangle(x, y, w, h));
        mRects.push_back(r);
        rectColors.push_back(ofColor(ofRandom(255), ofRandom(255), ofRandom(255)));
        
    }
    
    //  triangle
    for(int i = 0; i < mCount; i++){
        int x = ofRandom(0, ofGetWidth());
        int y = ofRandom(100, ofGetHeight()-40);
        
        mTriangles.push_back(shared_ptr<F_triangleShape>(new F_triangleShape));
        mTriangles.back().get()->setTexture(&textures[(int)ofRandom(textures.size())]);
        mTriangles.back().get()->setup(box2d, x, y, 30);
    }

    
    //  allocate OpenCv images
    shadowImage.allocate(640, 480);
    invertImage.allocate(640, 480);
    
    //  shadow of a person
    for (int i = 0; i < MAX_BLOBS; i++){
        shadows[i] = ofPtr<ofxBox2dPolygon>(new ofxBox2dPolygon);
    }
}

//--------------------------------------------------------------
void F_Avoid::update(unsigned short *_depthData) {
    //  shadow (OpenNI/OpenCv)

    invertImage = shadowImage;
    invertImage.invert();
    
    unsigned char *shadowData = shadowImage.getPixels().getData();
    //unsigned short *shadowData = kinect.getDepthRawPixels().getData();//= shadowImage.getPixels().getData();
    
    for (int k = 0; k < 640 * 480; k++){
        shadowData[k] = (minDist < _depthData[k] && _depthData[k] < maxDist)? 255: 0;
    }
    
    shadowImage.flagImageChanged();     //  must call after pixel manipulation
    invertImage = shadowImage;
    invertImage.invert();
    
    //  find contours
    finder.findContours(shadowImage, 1000, 640*480/4, MAX_BLOBS, false);
    
    numShadows = finder.nBlobs;
    
    for (int j = 0; j < MAX_BLOBS; j++) {
        shadowLines[j].clear();
        shadows[j].get()->clear();
        
        if (j < numShadows) {
            //  make a contour
            for (int k = 0; k < finder.blobs[j].pts.size(); k++){
                shadowLines[j].addVertex(finder.blobs[j].pts[k]);
            }
            shadowLines[j].close();
            shadowLines[j].simplify();
            //  make a polygon
            shadows[j].get()->clear();
            shadows[j].get()->addVertexes(shadowLines[j]);
            shadows[j].get()->triangulatePoly(30);
            shadows[j].get()->setPhysics(1.0, 0.5, 0.1);
            shadows[j].get()->create(box2d.getWorld());
        }
    }
    
    box2d.update();
}

//--------------------------------------------------------------
void F_Avoid::draw() {
    //  display mode
    float w = ofGetWindowWidth(), h = ofGetWindowHeight();
    scale = MIN(w / 640, h / 480);
    offsetX = (w - 640 * scale) / 2;
    offsetY = (h - 480 * scale) / 2;
    ofTranslate(offsetX, offsetY);
    ofScale(scale, scale);
    
    //  draw shadow/background
    ofSetColor(0);
    invertImage.draw(0, 0, ofGetWidth(), ofGetHeight());
    
    //  draw contours
    ofSetLineWidth(3);
    ofSetColor(140, 140, 200);
    for (int j = 0; j < numShadows; j++){
        shadowLines[j].draw();
    }
    
    //  draw triangles
    for (int i = 0; i < mCount; i++) {
        mTriangles[i].get()->draw();
    }
    
    //  draw circles
    for(int cnt = 0; cnt < mCount; cnt++){
        if(cnt < circleColor){
            ofSetColor(255, 255, 66);
        }else if(cnt < circleColor * 2){
            ofSetColor(255, 170, 86);
        }else if(cnt < circleColor * 3){
            ofSetColor(255, 96, 96);
        }else if(cnt < circleColor * 4){
            ofSetColor(255, 122, 188);
        }else if(cnt < circleColor * 5){
            ofSetColor(255, 122, 255);
        }else{
            ofSetColor(255, 0, 127);
        }
        
        mCircles[cnt].draw();
    }
    
    //  draw rects
    for(int cnt = 0; cnt < mRects.size(); cnt++){
        if(cnt < rectColor){
            ofSetColor(255, 255, 66);
        }else if(cnt < rectColor * 2){
            ofSetColor(255, 170, 86);
        }else if(cnt < rectColor * 3){
            ofSetColor(255, 96, 96);
        }else if(cnt < rectColor * 4){
            ofSetColor(255, 122, 188);
        }else if(cnt < rectColor * 5){
            ofSetColor(255, 122, 255);
        }else{
            ofSetColor(255, 0, 127);
        }
        
        mRects[cnt].get()->draw();
    }
    
}
