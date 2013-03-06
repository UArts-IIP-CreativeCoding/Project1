#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void relocateCircle(int w, int h);
        void nothing();
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
	int circlew;
    int circleh;
    int circlex;
    int circley;
    int click;
    //int continuousdraw = 0;
};
