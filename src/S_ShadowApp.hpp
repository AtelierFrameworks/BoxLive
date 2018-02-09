//
//  S_ShadowApp.hpp
//  boxlive
//
//  Created by AtelierFrameworks on 2018/01/10.
//
//

#ifndef S_ShadowApp_hpp
#define S_ShadowApp_hpp

#include "ofMain.h"

#endif /* S_ShadowApp_hpp */

class S_ShadowApp
{
private:
    ofVideoPlayer fingerMovie;
    
public:
    void setup();
    void update();
    void draw(ofImage* _kirinuki);


    bool mIsInitialized = false;
    ofVec2f pos;
    ofVec3f color;
    int sepa;
    int spli;
    int counter;
};

    
