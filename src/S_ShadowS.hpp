//
//  S_ShadowS.hpp
//  2_boxlive
//
//  Created by AtelierFrameworks on 2018/01/17.
//
//

#pragma once
#ifndef S_ShadowS_hpp
#define S_ShadowS_hpp

#include "ofMain.h"
#include "S_shadow.h"
#include "ofxOpenNI.h"

#endif /* S_ShadowS_hpp */

class S_ShadowS
{
private:
ofxOpenNI kinect;
ofImage kirinuki,scenery;
public:
void setup();
void update(int _put[640*480]);
void draw();

void keyPressed(int key);
void keyReleased(int key);
void mouseMoved(int x, int y );
void mouseDragged(int x, int y, int button);
void mousePressed(int x, int y, int button);
void mouseReleased(int x, int y, int button);
void mouseEntered(int x, int y);
void mouseExited(int x, int y);
void windowResized(int w, int h);
void dragEvent(ofDragInfo dragInfo);
void gotMessage(ofMessage msg);

//int put[640*480];
int pos[480][640];
vector<S_shadow> shadow;
ofVec3f color;
int sepa;
int spli;
int counter;

};
