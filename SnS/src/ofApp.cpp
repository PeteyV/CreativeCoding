#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    
    count = 0;
    
    ofSetVerticalSync(true);
    ofBackgroundHex(0x00000);
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    kinect.setRegistration(true);
    
    kinect.init();
    kinect.enableDepthNearValueWhite(true);
    kinect.open();
    
    if(kinect.isConnected()) {
        ofLogNotice() << "sensor-emitter dist: " << kinect.getSensorEmitterDistance() << "cm";
        ofLogNotice() << "sensor-camera dist:  " << kinect.getSensorCameraDistance() << "cm";
        ofLogNotice() << "zero plane pixel size: " << kinect.getZeroPlanePixelSize() << "mm";
        ofLogNotice() << "zero plane dist: " << kinect.getZeroPlaneDistance() << "mm";
    }
    
    colorImg.allocate(kinect.width, kinect.height);
    grayImage.allocate(kinect.width, kinect.height);
    grayThreshNear.allocate(kinect.width, kinect.height);
    grayThreshFar.allocate(kinect.width, kinect.height);
    
    nearThreshold = 230;
    farThreshold = 70;
    bThreshWithOpenCV = true;
    
    ofSetFrameRate(60);
    
    kinect.setCameraTiltAngle(angle);
    
    
    // start from the front
    bDrawPointCloud = false;
    
    box2d.init();
    box2d.setGravity(0, 5);
    box2d.createGround();
    box2d.setFPS(60.0);
    box2d.registerGrabbing();
}

//--------------------------------------------------------------
void ofApp::update() {
    kinect.update();
    // there is a new frame and we are connected
    if(kinect.isFrameNew()) {
        
        grayImage.setFromPixels(kinect.getDepthPixels());
        
        if(bThreshWithOpenCV) {
            grayThreshNear = grayImage;
            grayThreshFar = grayImage;
            grayThreshNear.threshold(nearThreshold, true);
            grayThreshFar.threshold(farThreshold);
            cvAnd(grayThreshNear.getCvImage(), grayThreshFar.getCvImage(), grayImage.getCvImage(), NULL);
        } else {
            
            // or we do it ourselves - show people how they can work with the pixels
            ofPixels & pix = grayImage.getPixels();
            int numPixels = pix.size();
            for(int i = 0; i < numPixels; i++) {
                if(pix[i] < nearThreshold && pix[i] > farThreshold) {
                    pix[i] = 255;
                } else {
                    pix[i] = 0;
                }
            }
        }
        
        // update the cv images
        grayImage.flagImageChanged();
        
        // find contours which are between the size of 20 pixels and 1/3 the w*h pixels.
        // also, find holes is set to true so we will get interior contours as well....
        contourFinder.findContours(grayImage, 10, (kinect.width*kinect.height)/2, 20, false);
    }
    
    box2d.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
    
    ofSetColor(219, 158, 0);
    kinect.drawDepth(0, 0, ofGetWidth(), ofGetHeight());
    contourFinder.draw(0, 0, ofGetWidth(), ofGetHeight());
    
    for(int i=0; i<circles.size(); i++) {
        ofFill();
        ofSetHexColor(0x21dadf);
        circles[i].get()->draw();
        
        if(circles.size() > 5){
            circles.clear();
        }
    }
    
    
    // draw the ground
    box2d.drawGround();
    
    string info = "";
    info += "Spawn n Slap\n";
    info += "Press [space] to spawn balls\n";
    info += "FPS: "+ofToString(ofGetFrameRate(), 1)+"\n";
    string info2 = "";
    info2 += "Balls Slapped: " + ofToString(count)+"\n";
    ofSetHexColor(0xfffff);
    ofDrawBitmapString(info, 30, 30);
    ofDrawBitmapString(info2, 800, 30);
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    switch (key) {
        case '`':
            bThreshWithOpenCV = !bThreshWithOpenCV;
            break;
            
        case'p':
            bDrawPointCloud = !bDrawPointCloud;
            break;
            
        case '>':
        case '.':
            farThreshold ++;
            if (farThreshold > 255) farThreshold = 255;
            break;
            
        case '<':
        case ',':
            farThreshold --;
            if (farThreshold < 0) farThreshold = 0;
            break;
            
        case '+':
        case '=':
            nearThreshold ++;
            if (nearThreshold > 255) nearThreshold = 255;
            break;
            
        case '-':
            nearThreshold --;
            if (nearThreshold < 0) nearThreshold = 0;
            break;
            
        case 'w':
            kinect.enableDepthNearValueWhite(!kinect.isDepthNearValueWhite());
            break;
            
        case OF_KEY_UP:
            angle++;
            if(angle>30) angle=30;
            kinect.setCameraTiltAngle(angle);
            break;
            
        case OF_KEY_DOWN:
            angle--;
            if(angle<-30) angle=-30;
            kinect.setCameraTiltAngle(angle);
            break;
    }

    if(key == ' ') {
        float r = ofRandom(4, 20);
        circles.push_back(shared_ptr<ofxBox2dCircle>(new ofxBox2dCircle));
        circles.back().get()->setPhysics(3.0, 0.53, 0.1);
        circles.back().get()->setup(box2d.getWorld(), mouseX, mouseY, r);
    }
    
    if(key == 'f') ofToggleFullscreen();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
    
}

//--------------------------------------------------------------
void ofApp::resized(int w, int h){
    
}
