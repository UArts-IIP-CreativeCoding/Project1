#pragma once

#include "ofMain.h"
#define MOVER 100


class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    void drawMover();
    void drawPop();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    float x,y;
    float theta;
    int dir;
    int acc;
    int d,r;
    float d2,r2;
    float h,w,i2;
    float tail, stay1, stay2;
    float arrayMover[200];
    
    int xpos[MOVER];
    int ypos[MOVER];
    int value = 255;
    int colors [5];
    float cval;
    int i,cstate;
};
