#include "S_shadow.h"

void S_shadow::setup(int _pos[480][640],ofVec3f _color){
    ofBackground(0,0,0);
    for(int m=0;m<480;m+=5){
        for(int n=0;n<640;n+=5){
    pos[m][n]=_pos[m][n];
        }
    }
    color=_color;
}
int S_shadow::update(){
    alpha-=15;
    
    return alpha;
    
}
void S_shadow::draw(){
    
    ofSetColor(color.x,color.y,color.z,alpha);
  
    for(int m=0;m<480;m+=5){
        for(int n=0;n<640;n+=5){
            if( pos[m][n]==1){
                ofDrawCircle(n*ofGetWidth()/640, m*ofGetHeight()/480, 5);
            }
        }
    }
}
