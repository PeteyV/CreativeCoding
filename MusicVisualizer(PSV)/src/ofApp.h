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
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    //utils
    ofDirectory dir;
    vector<string> songlist;
    int pos;
    int songsize;
    
    float lerpAmount;
    
    int time; //time intedrvals for calculations
    int counter;
    ofIcoSpherePrimitive sphere1, sphere2, sphere3; //spheres
    ofSoundPlayer sound;
    ofTrueTypeFont verdana;
    string songData;
    
    bool pause,change;
    
    float * fftSmoothed; //pointer?
    int numSongs; //number of samples
    int sampleBand;
    float freq;
};
