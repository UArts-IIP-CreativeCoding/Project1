#include "testApp.h"
// brenden moore - uarts 2013, theme 'stress'
// added help coding from Kenneth Guglielmino & Je Seok Koo

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetFrameRate(60); // Set Frame Rate as 60
    ofBackground(169, 239, 185);  // Set backgorund color
  
    int circley = ofGetHeight() / 2.0;
    int circlex = ofGetWidth() / 2.0;

}

//--------------------------------------------------------------
void testApp::update(){ // where logic or if statements go
    
   // cout<<click;

    if(click==1){ // if click is 1 operate under the if condition
        if(circlew >99){
        // making random location
        ofBackground(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
        circlex = ofRandom(ofGetWidth());
        circley = ofRandom(ofGetHeight());
        }
}
    
    else{ // if click is not 1 operate under the else condition
        windowResized(ofGetWidth()/2, ofGetHeight()/2);
        ofBackground(169, 239, 185);  // Set backgorund color
        circlex = ofGetWidth()/2;
        circley = ofGetHeight()/2;
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){ // graphics
    // set circle's size,location & color    
    if(click==1){
        circlew++;
        circleh++;
        if(circlew >99){
            circlew = 100;
            ofFill();
            ofSetColor(218, 29, 29);
        }
        if(circleh >99){
            circleh = 100;
            ofFill();
            ofSetColor(218, 29, 29);
        }
    }
    
    else{
        circlew = 30;
        circleh = 30;
        ofNoFill();
        ofSetColor(255);
    }
        
    ofCircle(circlex, circley, circlew, circleh);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    windowResized(circlex,circley);  // testing windowResized function when any key is pressed.

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
     if(button == 0) click = 1;  // set click as 1 if mouse pressed
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    if(button == 0) click = 0;  // set click as 0 if mouse released
}

void testApp::nothing(){ // test void function
    
}

//--------------------------------------------------------------
void testApp::relocateCircle(int w, int h){ // custom function changing circle's size
    circlex = w/2;  // making circlex half
    circley = h/2;  // making circlex half

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}