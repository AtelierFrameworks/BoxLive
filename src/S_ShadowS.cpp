//
//  S_ShadowS.cpp
//  2_boxlive
//
//  Created by AtelierFrameworks on 2018/01/17.
//
//

#include "S_ShadowS.hpp"
//--------------------------------------------------------------
void S_ShadowS::setup(){
    ofBackground(0,0,0);
    
    
    color.x = ofRandom(15, 230);
    color.y = ofRandom(15, 230);
    color.z = ofRandom(15, 230);
 
    
    
//    spli = ofRandom(0, 6);
//    
//    switch (spli) {
//        case 0:
//            color.x = 212;
//            color.y = 255;
//            color.z = 5;
//            break;
//        case 1:
//            color.x = 16;
//            color.y = 252;
//            color.z = 167;
//            break;
//        case 2:
//            color.x = 237;
//            color.y = 219;
//            color.z = 255;
//            break;
//        case 3:
//            color.x = 255;
//            color.y = 219;
//            color.z = 255;
//            break;
//        case 4:
//            color.x = 196;
//            color.y = 3;
//            color.z = 223;
//            break;
//        case 5:
//            color.x = 20;
//            color.y = 181;
//            color.z = 255;
//            break;
//        case 6:
//            color.x = 255;
//            color.y = 212;
//            color.z = 20;
//            break;
//    }
//    
//    
}

//--------------------------------------------------------------
void S_ShadowS::update(int _put[640*480]){
    
//    for (int l = 0; l < 640*480; l++) {
//        //  set visible or invisible
//        if (_kirinukiData[l*4+3]==0){
//            put[l]=1;
//        }
//        else put[l]=0;
//        
//    }
    
    for(int m=0;m<480;m+=5){
        for(int n=0;n<640;n+=5){
            pos[m][n]=_put[640*m+n];
        }
    }
    
    
    sepa = (int)ofRandom(0, 5);
    switch(sepa){
        case 0:
            color.x+=4;
            break;
        case 1:
            color.y+=4;
            break;
        case 2:
            color.z+=4;
            break;
        case 3:
            color.x-=4;
            break;
        case 4:
            color.y-=4;
            break;
        case 5:
            color.z-=4;
            break;
    }

    
//    sepa = ofRandom(0, 8);
//    
//    switch (sepa) {
//        case 0:
//            color.x += 3;
//            color.y += 3;
//            color.z += 3;
//            break;
//        case 1:
//            color.x += 3;
//            color.y += 3;
//            color.z -= 3;
//            break;
//        case 2:
//            color.x += 3;
//            color.y -= 3;
//            color.z += 3;
//            break;
//        case 3:
//            color.x += 3;
//            color.y -= 3;
//            color.z -= 3;
//            break;
//        case 4:
//            color.x -= 3;
//            color.y += 3;
//            color.z += 3;
//            break;
//        case 5:
//            color.x -= 3;
//            color.y += 3;
//            color.z -= 3;
//            break;
//        case 6:
//            color.x -= 3;
//            color.y -= 3;
//            color.z += 3;
//            break;
//        case 7:
//            color.x -= 3;
//            color.y -= 3;
//            color.z -= 3;
//            break;
//    }
    if (color.x < 10 && color.y < 10 && color.z < 10) {
        color.x = 10;
        color.y = 10;
        color.z = 10;
    }
    else  if (color.x > 245 && color.y >245 && color.z > 245) {
        color.x = 245;
        color.y = 245;
        color.z = 245;
    }
    
//    else if (color.x > 240 && (color.y < 50 || color.z < 50))
//    {
//        color.x = 240;
//        color.y = 50;
//        color.z = 50;
//    }
    
    ofSetColor(color.x, color.y, color.z);
    
    for(int i = 0; i < shadow.size(); i++) {
        counter=shadow[i].update();
        if (counter <= 0)shadow.erase(shadow.begin());
    }
    
    
    S_shadow myshadow;
    myshadow.setup(pos,color);
    shadow.push_back(myshadow);
    
}

//--------------------------------------------------------------
void S_ShadowS::draw(){
    //  ofSetColor(0, 0, 0);
    //kirinuki.draw(640, 0, 640, 480);
    
    for(int i = 0; i <shadow.size(); i++) {
        shadow[i].draw();
    }
}
