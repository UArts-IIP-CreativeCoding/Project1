#include "testApp.h"
//on-off
bool click;

//color variables
float r;
float g;
float b;
float m;
float o;
float p;

//--------------------------------------------------------------
void testApp::setup(){
    ofEnableSmoothing();
    ofSetFrameRate(60);
    //ofBackground(0);
    
    click = false;
    
    //initialize array
    for (int i = 0; i < CIRCLE; i++) {
        xpos[i] = 0;
        ypos[i] = 0;
    }
}

//--------------------------------------------------------------
void testApp::update(){
    //color stuff
    r = .045;
    m = ofNoise(r) * ofGetWidth()/7.5;
    g = .035;
    o = ofNoise(g) * ofGetWidth()/7.5;
    b = .025;
    p = ofNoise(b) * ofGetWidth()/7.5;
    
    if (mouseX < ofGetWidth()/3) {
        m = 180;
    }
    if ((mouseX > ofGetWidth()/3) && (mouseX < 2*ofGetWidth()/3)) {
        o = 180;
    }
    if (mouseX > 2*ofGetWidth()/3) {
        p = 180;
    }
    
    //array stuff
    for (int i = 0; i < CIRCLE; i++) {
        xpos[i] = xpos [i+1];
        ypos[i] = ypos [i+1];
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    //Un-Clicked State // Straight Gridlines
    if (click == false) {
        ofBackground(0);
        
        ofSetColor(255);
        ofFill();
        
        for(int i = 0; i < ofGetHeight(); i += 20){
            ofLine(0, i, ofGetWidth(), i);
        }
        for(int i = 0; i < ofGetWidth(); i += 20){
            ofLine(i, 0, i, ofGetHeight());
        }
        
        //trail array
        for (int i = 0; i < CIRCLE; i++) {
            ofSetColor(255-i*5);
            ofFill();
            ofCircle(xpos[i], ypos[i], i);
        }
    }
    
    //Clicked //
    if (click == true) {
        ofBackground(m, o, p);
        
        ofSetColor(255);
        ofFill();
        
        //Horizontal Lines
        for (int y = ofGetHeight()*-1; y < mouseY; y += ofGetWidth()/50) {
            //stroke(255);
            ofLine(0, y, mouseX, mouseY- ofGetHeight()/2+y);
            ofLine(mouseX, mouseY-ofGetHeight()/2+y, ofGetWidth(), y);
        }
        for (int y = mouseY; y < ofGetHeight()*2; y += ofGetWidth()/50) {
            //ofStroke(255);
            ofLine(0, y, mouseX, mouseY- ofGetHeight()/2+y);
            ofLine(mouseX, mouseY- ofGetHeight()/2+y, ofGetWidth(), y);
        }
        
        //Vertical Lines
        for (int x = ofGetHeight()*-1; x < mouseX; x += ofGetWidth()/50) {
            ofLine(x, 0, mouseX-ofGetWidth()/2+x, mouseY);
            ofLine(mouseX-ofGetWidth()/2+x, mouseY, x, ofGetHeight());
        }
        for (int x = mouseX; x < ofGetHeight()*2; x += ofGetWidth()/50) {
            ofLine(x, 0, mouseX-ofGetWidth()/2+x, mouseY);
            ofLine(mouseX-ofGetWidth()/2+x, mouseY, x, ofGetHeight());
        }
        
        //trail array
        for(int i = 0; i < CIRCLE; i++) {
            ofSetColor(m+i*4, o-i, p+i*2);
            ofFill();
            ofCircle(xpos[i], ypos[i], i-30);
        }
    }
    
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    xpos[CIRCLE-1] = x;
    ypos[CIRCLE-1] = y;
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    xpos[CIRCLE-1] = x;
    ypos[CIRCLE-1] = y;
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    click = true;
    xpos[CIRCLE-1] = x;
    ypos[CIRCLE-1] = y;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    click = false;
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}