#include "ofMain.h"
#include "ofApp.h"
#include "Kinect.hpp"
//========================================================================
int main( ){
//	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

    ofGLFWWindowSettings settings;
    //単焦点
    settings.width = 1280;
    settings.height = 1024;
    settings.setPosition(ofVec2f(2560,0));
    settings.multiMonitorFullScreen = true;
    settings.decorated = false;
    shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
    
    settings.resizable = true;
    settings.shareContextWith = mainWindow;
    
    settings.height = 1000;
    settings.setPosition(ofVec2f(-1280,0));
    
//    settings.width=648;
//    settings.height=1000;
//    settings.setPosition(ofVec2f(0,0));
//    shared_ptr<ofAppBaseWindow> kinectWindow = ofCreateWindow(settings);
//    shared_ptr<Kinect> kinectApp(new Kinect);
//    
    
    shared_ptr<ofAppBaseWindow> backWindow = ofCreateWindow(settings);
    
    shared_ptr<ofApp> mainApp(new ofApp);
    shared_ptr<BackApp> backApp (new BackApp);
    mainApp -> mBackApp = backApp;
//    mainApp -> kinectApp = kinectApp;
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(mainWindow,mainApp);
    ofRunApp(backWindow,backApp);
//    ofRunApp(kinectWindow,kinectApp);
    ofRunMainLoop();

}
