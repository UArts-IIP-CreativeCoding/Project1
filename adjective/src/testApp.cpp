#include "testApp.h"

/*
 Intro to Interactive Programming Ð Creative Coding
 project 1 - adjective - magnetic
 bk
 bklevence@uarts.edu
 ========
 input:
 
 mouseover  - rub center to excite
 space - color
 UP/DWN - speed
 */


//--------------------------------------------------------------
void testApp::setup(){
    ofSetBackgroundAuto(false);
    ofSetWindowShape(1024, 768);
    ofSetFrameRate(60); //set framerate
    ofBackground(255); //set background initially
    ofSetCircleResolution(50); //circ res
    dir = 0; //set state 0, not moving
    x = (ofGetWidth()/2); //set x at 1/2 width
    y = (ofGetHeight()/2); //set y at 1/2 height
    stay1 = .75*ofGetWidth(); //set constraint out
    stay2 = ofGetWidth()/2; //set constraint in
    d = 15; //diameter of movers
    r = d/2; //r of movers
    d2 = 100; //init diameter of center
    r2 = d2/2; //r of center
    tail = 5; // variable for tail "speed"
    theta = 90; //theta used in forloop
    for(int i = 0; i < MOVER; i++){
        xpos[i] = 0;
        ypos[i]= 0;
    }
    cval =125;
    cstate = 0;
    //colors[5]= 0x6F00FF, 0xFF004F, 0x00FF7F, 0xFFFF00, 0x2F4F4F;
    //cant get alpha with hex colors in oF looked high and low for an answer


}

//--------------------------------------------------------------
void testApp::update(){
    
    if(dir == 1){ //direction out
        x = x + ofRandom(tail);
        y = y + ofRandom(tail);
        
    }
    else //direction in
        if(dir == 2){
            x= x - ofRandom(tail);
            y= y - ofRandom(tail);
        }
    if(x > stay1) { //hold at constrain .75 w/h
        dir = 0; //stay
    }
    if(x < stay2) { //hold at constrain center
        dir = 0; //stay
    }
    
    if (abs(mouseX - x) < r2 && abs(mouseY - y) < r2 && x <= ofGetWidth()/2) {
        dir = 1; //home
    }
    if  (abs(mouseX - (ofGetWidth()/2)) < r2 && (mouseY - (ofGetHeight()/2)) < r2 && x >= (.75*ofGetWidth())) {
        dir = 2; //go home your drunk
    }
    
    for(int n = 0; n < MOVER; n++){ //setting up tail
        arrayMover[n] = int(ofRandom(0,10));
        cout << arrayMover[n] << endl;
    
    }
    for(int i = 0; i< MOVER; i ++){
        xpos[i] = xpos [i+1];
        ypos[i] = ypos [i+1];
    }

    xpos[MOVER-1] = x;
    ypos[MOVER-1] = y;
    

    if  (dir == 0) { //transparent area of influence circles
        d2 = ofRandom(25, 50); //if not moving bounce d small
    }
    else    {
        d2 = ofRandom(60, 75); //if moving
    }
}


//--------------------------------------------------------------
void testApp::draw(){
    ofEnableAlphaBlending(); //documentation helped me figure out transparencif (dir ==0)
    ofSetColor(25, 75); //set transparent background
    ofSetRectMode(OF_RECTMODE_CENTER); //rect mode
    ofRect(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()*2, ofGetHeight()*2); //draw rect

    if (dir == 0){
        ofEnableAlphaBlending(); //documentation helped me figure out transparency
        ofSetColor(255, 100); //set transparent background
        ofSetRectMode(OF_RECTMODE_CENTER); //rect mode
        ofRect(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()*2, ofGetHeight()*2); //draw rect
    }
    //area of influence or center circle
    if (dir ==1 || dir ==2){
        ofSetColor(5, 25);
    }
    else if (dir == 0){
        ofSetColor(125, 3);
    }
    ofCircle(ofGetWidth()/2, ofGetHeight()/2, d2*.75);
    ofSetColor(5, 5);
    ofCircle(ofGetWidth()/2, ofGetHeight()/2, d2); //draw center circle w/ variable diameter
    ofDisableAlphaBlending();
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    for (float i2 = 0; i2 < 360; i2 += 6){ //forloop used to rotate movers
        ofPushMatrix();
            ofScale(.33, .33); 
            ofRotate(theta + i2);
            drawMover(); //call function mover
        ofPopMatrix();
        
    }
    }


//--------------------------------------------------------------
void testApp::drawMover(){
    for(int i = 0; i < MOVER; i ++){

        ofEnableAlphaBlending();
        if(cstate==0){
            ofSetColor(125+i, i);//brightness
        }
        if (cstate == 1) {
            ofSetHexColor(0x6F00FF-i);
        }
        
        ofCircle(xpos[i], ypos[i], d);
        ofDisableAlphaBlending();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    
    
    if(key==OF_KEY_UP) //increase speed
    {
        tail++;
    }
    if(key==OF_KEY_DOWN) //decrease speed
    {
        tail--;
    }
    if(key==32 && cstate==0 && dir==0) //color
    {
        cstate = 1;
    }
    else if(key==32 && cstate==1 && dir==0) //grayscale
    {
        cstate = 0;
    }
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