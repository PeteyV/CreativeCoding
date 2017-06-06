#pragma once
#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxOpenCv.h"
#include "ofxKinect.h"
#include "KinectCursor.h"

// -------------------------------------------------

class ofApp : public ofBaseApp {
    
public:
    
    
    void setup();
    void update();
    void draw();
    
    void drawPointCloud();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void resized(int w, int h);
    public: int count;
    KinectCursor cursor;
    
    ofxBox2d                               box2d;   // the box2d world
    vector   <shared_ptr<ofxBox2dCircle> > circles; // default box2d circles
    vector   <shared_ptr<ofxBox2dPolygon> >   triangles;   // box2d poly for triangles
    
    ofxKinect kinect;
    
#ifdef USE_TWO_KINECTS
    ofxKinect kinect2;
#endif
    
    ofxCvColorImage colorImg;
    
    ofxCvGrayscaleImage grayImage; // grayscale depth image
    ofxCvGrayscaleImage grayThreshNear; // the near thresholded image
    ofxCvGrayscaleImage grayThreshFar; // the far thresholded image
    
    ofxCvContourFinder contourFinder;
    
    bool bThreshWithOpenCV;
    bool bDrawPointCloud;
    
    int nearThreshold;
    int farThreshold;
    
    int angle;
    
    // used for viewing the point cloud
    ofEasyCam easyCam;
    
};
