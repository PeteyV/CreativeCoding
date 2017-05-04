#include "ofApp.h"
#include "ofxTweenzor.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofEnableDepthTest();
    
    Tweenzor::init();
    lerpAmount = 255.f;
    Tweenzor::add(&lerpAmount, 255.f, 0.f, 0.f, 10.f);
    Tweenzor::getTween(&lerpAmount)->setRepeat(-1, true);
    
    verdana.load("verdana.ttf",12,true,false);
    
    //song list
    pos = 0;
    dir.listDir("Music/");
    songsize = dir.size();
    if(dir.size())
    {
        songlist.resize(songsize);
    }
    for (int i =0; i < songsize; i++)
    {
        songlist[i] = dir.getName(i);
        cout << songlist[i] << endl;
    }
    songData = (dir.getPath(pos));
    sound.load(songData);
    sound.play();
    
    pause = true;
    change = false;
    
    time = int(ofGetElapsedTimef()); //ellapsed time
    
    sphere1.setRadius(ofGetWidth()/3.5); // radius of inner sphere
    sphere3.setRadius(ofGetWidth()/3);

    fftSmoothed = new float[200];
    for (int i = 0; i < 200; i++){
        fftSmoothed[i] = 0;
    }
    
    numSongs = 128; //number of samples
    
    sampleBand = 2;
    counter = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    Tweenzor::update(ofGetElapsedTimeMillis());
    
    if (change == true)
    {
        if(pos < 0)
        {
            pos = songsize - 1;
        }
        if (pos >= songsize)
        {
            pos = 0;
        }
        songData = (dir.getPath(pos));
        sound.stop();
        sound.unload();
        sound.load(songData);
        sound.play();
        change = false;
    }
    ofSoundUpdate();
    
    sphere2.setRadius(ofGetWidth()/2.5);
    
    time = ofGetElapsedTimef(); //update on time
    
    float * val = ofSoundGetSpectrum(numSongs);		// request 128 values from SoundSpectrum for fft
    for (int i = 0;i < numSongs; i++){
        
        // let the smoothed value sink to zero:
        fftSmoothed[i] *= 0.96f;
        
        // take the max, either the smoothed or the incoming:
        if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val[i];
        
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetWindowTitle("MusicVisualizer - Petey V");
    ofBackgroundGradient(100,0,OF_GRADIENT_CIRCULAR);
    
    
    // draw the fft results with setColor:
     ofSetColor(lerpAmount, lerpAmount*cos(time), lerpAmount*time);
    
    float width = (float)(ofGetWidth()) / numSongs;
    for (int i = 0;i < numSongs; i++){
        ofFill();
        ofDrawRectangle(i*width,ofGetHeight(),width,-(fftSmoothed[i] * 100));
    }
    freq = (fftSmoothed[0] + fftSmoothed[1] + fftSmoothed[2] + fftSmoothed [3] + fftSmoothed[4] + fftSmoothed[5])/20;
    
    counter++;
    if(counter >=1)
    {
        if((freq * ofGetWidth()/7) > ofGetWidth()/7)
        {
            sphere1.setRadius(ofGetWidth()/7);
        }
        else
        {
            sphere1.setRadius(freq * ofGetWidth()/7);
        }
        counter = 0;
    }
    
    
    vector<ofMeshFace> triangles = sphere3.getMesh().getUniqueFaces();
    vector<ofMeshFace> t1 = sphere3.getMesh().getUniqueFaces();
    vector<ofMeshFace> t2 = sphere1.getMesh().getUniqueFaces();
    
    float displacement = cos(time) * freq * 40;
    float d1 = sin(time) * fftSmoothed[0] * 20;
    
    for (size_t i = 0; i < triangles.size(); i++) {
        ofVec3f normal = triangles[i].getFaceNormal();
        for (int j = 0; j < 3; j++) {
            triangles[i].setVertex(j, triangles[i].getVertex(j) + normal * displacement);
        }
    }
    
    for (size_t i = 0; i < t1.size(); i++) {
        ofVec3f normal = t1[i].getFaceNormal();
        for (int j = 0; j < 3; j++) {
            t1[i].setVertex(j, t1[i].getVertex(j) + normal * displacement);
        }
    }
    for (size_t i = 0; i < t2.size(); i++) {
        if(i%2==1){
            ofVec3f normal = t2[i].getFaceNormal();
            for (int j = 0; j < 3; j++) {
                t2[i].setVertex(j, t2[i].getVertex(j) + normal * d1);
            }
        }
    }
    
    //create 3 spheres and set colors
    sphere1.getMesh().setFromTriangles(t2);
    ofSetColor(lerpAmount, lerpAmount*cos(time), lerpAmount*time);
    sphere1.draw();
    sphere1.setScale(2.5);
    
    sphere3.getMesh().setFromTriangles(triangles);
    sphere3.setPosition(ofGetWidth()/2,ofGetHeight()/2,0);
    sphere3.drawWireframe();
    ofSetColor(255,255,255,1);
    sphere3.drawFaces();
    
    ofSetColor(0);
    sphere1.drawWireframe();
    sphere2.getMesh().setFromTriangles(t1);
    sphere2.setPosition(ofGetWidth()/2,ofGetHeight()/2,0);
    sphere2.draw();
    
    ofSetColor(255);
    sphere2.setScale(.6);
    sphere2.drawVertices();
    ofSetColor(lerpAmount, lerpAmount*cos(time), lerpAmount*time);
    sphere2.rotate(-fftSmoothed[0]/1.5,-1.0,1.0,0.0);
    sphere1.setPosition(ofGetWidth()/2,ofGetHeight()/2,0);
    sphere1.rotate(fftSmoothed[1]/1.5, 1.0, -1.0, 0.0);
    sphere3.rotate(freq*1.5,-1.0,1.0,0.0);
    
    if(pause == true) //music is playing
    {
        ofNoFill();
        ofDrawTriangle(17,8,17,27,28,17);
        verdana.drawString(songData,32,23);
    }
    else
    {
        ofNoFill();
        ofDrawRectangle(13,10,5,15);
        ofDrawRectangle(23,10,5,15);
        verdana.drawString(songData,32,23);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 358)
    {
        pos++;
        change = true;
    }
    if (key == 356)
    {
        pos--;
        change = true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    //pause/play
    if (key == ' ')
    {
        sound.setPaused(pause);
        if (pause == true)
        { pause = false; }
        else{pause = true;}
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
