#include "testApp.h"


   float r= ofRandom(250); 
   float g = ofRandom(250); 
   float b = ofRandom(250); 
   float rs = 1.5; // don't randomize
   float rpx1 = ofRandom(1024);
   float rpy1 = ofRandom(768);
   float rpx2 = ofRandom(1024);
   float rpy2 = ofRandom(768);
   float rpx3 = ofRandom(1024);
   float rpy3 = ofRandom(768); 

//--------------------------------------------------------------

void ofTriangles(){
    
    ofEnableAlphaBlending();
    ofNoFill();
    ofSetColor(r,g,b);
    ofSetLineWidth(rs);
    ofTriangle(rpx1, rpy1, rpx2, rpy2, rpx3, rpy3);
    ofDisableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetWindowTitle("Controling Triangle Chaos");
    ofSetWindowShape(1024,768);
    ofSetFrameRate(2);
    ofEnableSmoothing();
    
}

//--------------------------------------------------------------
void testApp::update(){
    ofTriangles();
    if(rs <1){
        rs = 2;
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofTriangles();    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if (key == 'e'){
        rs++;
    }
    if (key == 'E'){
        rs--;
}
    if (key == 'q' || key == 'Q') {
        r=ofRandom(250);
        g=ofRandom(250);
        b=ofRandom(250);
    }
    if (key == 'w') {
        rpx2++;
        rpy2++;
        rpx3++;
        rpy3++;
    }
        if (key == 'W') {
        rpx1--;
        rpy1--;
        rpx2--;
        rpy2--;
        rpx3--;
        rpy3--;
        }
    if (key == 'r') {
        ofBackground(r); // figure out how to get this to reset the whole thing
    }

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    rpx1 = mouseX;
    rpy1 = mouseY;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------






