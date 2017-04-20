#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofColor clr=ofColor::fromHex(0x379392);
        ofColor clr1=ofColor::fromHex(0x2E4952);
        ofColor clr2=ofColor::fromHex(0x0BC9C7);
    
        float d =0.5;
        int r = 200;
        int w = 7;
        float s = 1;
		
};
