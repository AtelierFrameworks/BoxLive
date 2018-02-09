#pragma once
#include "ofMain.h"
class S_shadow
{
public:
    void setup(int _pos[480][640],ofVec3f color);
    int update();
    void draw();
    
    float alpha=255;
    int pos[480][640];
    ofVec3f color;
    int sepa;
};
