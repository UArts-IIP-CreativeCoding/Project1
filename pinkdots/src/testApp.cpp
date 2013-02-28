#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetFrameRate(30);
    ofSetCircleResolution(50);
    ofBackground(175, 175, 175);
    
    float dude = 0;
    float ult = 0;
    float dudeSomething= 1;
    float dudeHeight = 1;
    
    
    
}

//--------------------------------------------------------------
void testApp::update(){

    
    int a = 1; a < 100; a++;
    float dudeOffset= a* .01;
    pos. y = sin( 50+ dudeOffset) * ofGetHeight()/2.0 + ofGetHeight()/2.0;
    pos. x = (a * 5 + 50);
    
}

//--------------------------------------------------------------
void testApp::draw(){
    

    
    
    
    for ( int a = 1; a < 100; a++) // if a is less than 40
    {
        float dudeOffset = a* .01;
    
    
    float y = cos(0 + dudeOffset) *  ofGetHeight ()/2.0 + ofGetHeight ()/2.0;
    //
    float x = a * 5 + 250;// // first # effects space between and last effects loc
    //ofFill(255, 0, 100);
    ofEllipse(x, y, 30, 30);
        
        
    ofSetColor(255, 0, 100);
    ofCircle (50, 50, 15);
    

    }}

//--------------------------------------------------------------
    void testApp::keyPressed(int key){
        
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

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

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