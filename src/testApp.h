#pragma once

#ifndef _OF_TRIANGLES
#define _OF_TRIANGLES

#include "ofMain.h"

class ofTriangles{
    
public: 
    

    void update();
    void draw();
    
    float r;
    float g;
    float b;
    float rs;
    float rpx1;
    float rpy1;
    float rpx2;
    float rpy2;
    float rpx3;
    float rpy3;
    
    ofTriangles();
    
};

#endif



class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed  (int key);
		void keyReleased(int key);
		void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
    
		
};



