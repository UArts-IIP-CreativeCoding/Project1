#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    ofBackground(255);
    ofEnableSmoothing();
    
}


//--------------------------------------------------------------
void testApp::update(){

    if(yfallstate == 0){
        yfall+=40;
        ellipsefill = 0;
        splatterstate = 1;
        dropletstate = 1;
    }
    
    if (yfallstate == 3 || yfallstate == 1){
        yfall = 0;
        ellipsefill = 255;
    }
    
    if (yfall >= 768){
        yfallstate = 3;
    }
    
    if(dropletstate == 1){
        droplet = 768;
        
    }
    if (dropletstate == 2) {
        droplet-=13;
        dropletfill = 0;
    }
    if (dropletstate == 3) {
        droplet+=3;
        dropletfill = 0;
    }
    
    if (dropletstate == 4) {
        droplet+=20;
        dropletfill = 0;
    }
    
    if(splatterstate == 1){
        splatterfill = 255;
        splatterheight = 768;
    }
    
    if(splatterstate == 2){
        splatterfill = 0;
        splatterheight-=10;
    }
    if(splatterstate == 3){
        splatterheight+=13;
    }
    
    if (dropletstate == 1 && yfallstate == 3){
        dropletstate = 2;
    }
    if (dropletstate == 2 && droplet <= 500){
        dropletstate = 3;
    }
    
    if (dropletstate == 3 && droplet >= 510){
        dropletstate = 4;
    }
    
    
    
    if(splatterstate == 3 && splatterheight >=768){
        splatterstate = 1;
    }
    if(splatterheight == 768 && yfallstate == 3){
        splatterstate = 2;
    }
    if(splatterheight == 568 && yfallstate == 3){
        splatterstate = 3;
    }
    if(splatterstate == 3 && splatterheight >= 762){
        splatterstate = 1;
        yfallstate = 1;
    }
    
    if (yfallstate == 1 && droplet >= 760){
        dropletstate = 1;
        dropletfill = 255;
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(ellipsefill);
    ofFill();
    ofCircle(xgrab, yfall, 20, 20);
    ofSetColor(splatterfill);
    ofFill();
    ofBeginShape();
    ofVertex(xgrab - 200, 768);
    ofBezierVertex(xgrab - 70, 768, xgrab - 10, 768 + (splatterheight/9), xgrab, splatterheight);
    ofBezierVertex(xgrab + 10, 768 + (splatterheight/9), xgrab + 70, 768 + (splatterheight/9), xgrab + 200, 768);
    ofEndShape();
    ofSetColor(dropletfill);
    ofFill();

    ofCircle(xgrab, droplet, 10, 10);
    ofCircle(xgrab + ofRandom(50), droplet + ofRandom(50), 5, 5);
    ofCircle(xgrab + ofRandom(50), droplet + ofRandom(50), 5, 5);
    ofCircle(xgrab + ofRandom(50), droplet + ofRandom(50), 5, 5);
    ofCircle(xgrab, droplet, 10, 10);
    ofCircle(xgrab - ofRandom(50), droplet + ofRandom(50), 5, 5);
    ofCircle(xgrab - ofRandom(50), droplet + ofRandom(50), 5, 5);
    ofCircle(xgrab - ofRandom(50), droplet + ofRandom(50), 5, 5);

}

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

    xgrab = mouseX;
    yfallstate = 0;
    
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