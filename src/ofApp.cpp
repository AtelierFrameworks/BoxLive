#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetBackgroundColor(0);
    
    
    //  setup ofxOpenNI
    kinect.setup();
    kinect.setRegister(true);
    kinect.setMirror(true);
    kinect.addImageGenerator();     //  required for RGB image
    kinect.addDepthGenerator();     //  required for depth image
    kinect.addHandsGenerator();      //  required for hand tracking
    kinect.addAllHandFocusGestures();
    kinect.setMaxNumHands(4);       //  max num of skeleton to track
    kinect.addUserGenerator();
    kinect.setMaxNumUsers(100);
    
    //  start kinect
    kinect.start();
    //  align depth image to RGB image
    kinect.getDepthGenerator().GetAlternativeViewPointCap().SetViewPoint(kinect.getImageGenerator());
    //  kirinuki image (RGBA)
    
    kirinuki.allocate(640, 480, OF_IMAGE_COLOR_ALPHA);
    kirinukiP = &kirinuki;
    mBackApp -> setKirinuki(kirinukiP);
    // Arduino
    serial.setup("/dev/cu.usbmodem14341",9600);
    mVariety = CONST::P;
     mP_Perticles.setup();
    mBackApp -> setVariety(mVariety);

    
}

//--------------------------------------------------------------
void ofApp::update(){
    // Timer
    timer += 0.0167;
    //timer += 0.0333;
    
    //切り替え
    if(timer > 15){
        int index = ((int)mVariety)+1;
        if(index == 5){
            index = 0;
        }
        mVariety=(CONST::VARIETY)(index);
        mBackApp -> setVariety(mVariety);
        timer = 0;
        switch (mVariety) {
            case CONST::P:
                 mP_Perticles.setup();
                break;
            case CONST::A:
                mA_Perticles.setup();
                break;
            case CONST::J:
                mJ_Joints.setup();
                break;
            case CONST::S:
                mS_ShadowApps.setup();
                break;
            case CONST::F:
                mF_Avoids.setup();
                break;
            default:
                break;
        }
    }

    //kinect
    kinect.update();
    numHands=kinect.getNumTrackedHands();
    if (kinect.getNumTrackedHands() > 0) {
        for(int i=0;i<numHands;i++){
            ofxOpenNIHand hand = kinect.getTrackedHand(i);
            P_handpos = hand.getPosition();
            ofPoint  p= hand.getPosition();
            handPos[i]=p;
        }
        
        //  kirinuki (1000-2000mm)
        unsigned char *kirinukiData = kirinukiP->getPixels().getData();
        unsigned char *imageData = kinect.getImagePixels().getData();
        unsigned short *depthData = kinect.getDepthRawPixels().getData();
        for (int k = 0; k < 640*480; k+=5) {
            kirinukiData[k * 4 + 0] = imageData[k * 3 + 0];
            kirinukiData[k * 4 + 1] = imageData[k * 3 + 1];
            kirinukiData[k * 4 + 2] = imageData[k * 3 + 2];
            //  set visible or invisible
            if (800 <= depthData[k] && depthData[k] < 2800){
                kirinukiData[k * 4 + 3] = 0;  //  visible
                putS[k] = 1;
            }else{
                kirinukiData[k * 4 + 3] = 255;    //  invisible
                putS[k] = 0;
            }
        }
        
        mBackApp->setPut(putS);
        kirinukiP->update();
        shared_ptr<ofImage> kirinukiP(new ofImage);

 
        
        //update
        switch (mVariety) {
            case CONST::P:
                mP_Perticles.update(P_handpos);
                 serial.writeByte('2');
                break;
            case CONST::A:
                mA_Perticles.update(numHands, handPos);
                 serial.writeByte('2');
                break;
            case CONST::J:
                mJ_Joints.update();
                serial.writeByte('1');
                break;
            case CONST::S:
                mS_ShadowApps.update();
                 serial.writeByte('2');
                break;
            case CONST::F:
                mF_Avoids.update(depthData);
                serial.writeByte('2');
                break;
            default:
                break;
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //kinect.drawDepth(0, 0, ofGetWidth(), ofGetHeight());   //  depth image (in color)
    //kinect.drawImage(0, 0, 600, 500);
    
    ofDrawBitmapString(ofToString(ofGetFrameRate()) + "fps", 20, 20);
    
    switch (mVariety) {
        case CONST::P:
            mP_Perticles.draw();
            break;
        case CONST::A:
            mA_Perticles.draw();
            break;
        case CONST::J:
            if (kinect.getNumTrackedUsers() > 0) {
                ofxOpenNIUser user = kinect.getTrackedUser(0);
                ofSetLineWidth(5);
                ofSetColor(255,255,255);
                
                headpos = gotAcount(JOINT_HEAD);
                lefthandpos = gotAcount(JOINT_LEFT_HAND);
                righthandpos = gotAcount(JOINT_RIGHT_HAND);
                leftfootpos = gotAcount(JOINT_LEFT_FOOT);
                rightfootpos = gotAcount(JOINT_RIGHT_FOOT);
                leftelbowpos = gotAcount(JOINT_LEFT_ELBOW);
                rightelbowpos = gotAcount(JOINT_RIGHT_ELBOW);
                leftkneepos = gotAcount(JOINT_LEFT_KNEE);
                rightkneepos = gotAcount(JOINT_RIGHT_KNEE);
                
                head2pos = gotAcount(JOINT_HEAD);
                lefthand2pos = gotAcount(JOINT_LEFT_HAND);
                leftfoot2pos = gotAcount(JOINT_LEFT_FOOT);
                righthand2pos = gotAcount(JOINT_RIGHT_HAND);
                rightfoot2pos = gotAcount(JOINT_RIGHT_FOOT);
            }
            mJ_Joints.draw(headpos, lefthandpos, righthandpos, leftfootpos, rightfootpos,leftelbowpos, rightelbowpos, leftkneepos, rightkneepos,head2pos, lefthand2pos, leftfoot2pos, righthand2pos, rightfoot2pos);
            break;
        case CONST::S:
            mS_ShadowApps.draw(kirinukiP);
            break;
        case CONST::F:
            mF_Avoids.draw();
            break;
        default:break;
    }
    //xmin = 70 xmax = width - 250
   // ofDrawCircle(ofGetWidth()-250,ofGetHeight()/2,50);

}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}

//--------------------------------------------------------------
ofVec2f ofApp::gotAcount(Joint bone){
    ofxOpenNIUser user = kinect.getTrackedUser(0);
    ofxOpenNIJoint joint = user.getJoint(bone);
    ofVec2f position;
    if (joint.isFound()) {
        position.x = joint.getProjectivePosition().x;
        position.y = joint.getProjectivePosition().y;
    }else{
        //position.x = -999;
       //position.y = -999;
    }
    return position;
}
