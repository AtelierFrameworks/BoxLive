#pragma once

#include "ofMain.h"
class Particle
{
public:

	ofVec2f pos;
	ofVec2f vel;
	

	
    bool mIsInitialized=false;
	void setup(ofVec2f _pos,ofVec4f _limit,int _mode);
	void update(int _mode);
	void draw(int _mode);
	float getDegree(float x, float y);
	//void setMode(int _mode,ofVec2f center);

	//int angle;
	ofImage img;
	ofImage snow;


	ofVec2f center;
	ofVec2f gap;
	ofVec2f radious;
	float degree;
	float angle;
	float distance;
	float count;
	float radian;

	int mode;
	
};

