#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(30);// draw grey background
    ofSetColor(255);// set color drawing color to white
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);  // move initital drawing postion to the center of the screen
    //ofTranslate(mouseX, mouseY);
    int circle_resolution=2000; // amount of points circle is made of, more points - better quality, but could decrease perfomance
    int radius= r;
    int smoothing_amount=10;
    
    ofPolyline circle_sin;
    //ofPolyline circle_cos;
    ofPolyline circle_un_cos;
    
    
    int wave_height=radius*0.1;
    int anim_shape=16;
    float sine_pct = d; // setting in percantage how big is the part
    
    float speed_increment=ofGetElapsedTimef() * s;
    
    int line_w= w;
    int radius_cos=radius+line_w-1; // let's make it little less then line width, so circles will overlap each other
    int radius_un_cos=radius+(line_w-1)*2;
    for(int i=0; i<circle_resolution; i++)
    {
        
        float angle=TWO_PI/circle_resolution*i;
        float raidus_addon=wave_height*sin((angle+speed_increment)*anim_shape);
        
        float x=cos(angle+speed_increment)*radius;
        float y=sin(angle+speed_increment)*radius;
        
        // drawing sine wave only on a part of the circle
        if(i<sine_pct*circle_resolution)
        {
            x=cos(angle+speed_increment)*(radius+raidus_addon);
            y=sin(angle+speed_increment)*(radius+raidus_addon);
        }
        circle_sin.addVertex(ofPoint(x,y));
        
        
        raidus_addon=wave_height*cos((angle+speed_increment)*anim_shape);
        x=cos(angle+speed_increment)*(radius_cos);
        y=sin(angle+speed_increment)*(radius_cos);
        
        if(i<sine_pct*circle_resolution)
        {
            x=cos(angle+speed_increment)*(radius_cos+raidus_addon);
            y=sin(angle+speed_increment)*(radius_cos+raidus_addon);
        }
        
        //circle_cos.addVertex(ofPoint(x,y));
        
        
        //increment a wave angle to flip the wave
        raidus_addon=wave_height*cos((angle+TWO_PI/3+speed_increment)*anim_shape);
        x=cos(angle+speed_increment)*(radius_un_cos);
        y=sin(angle+speed_increment)*(radius_un_cos);
        
        if(i<sine_pct*circle_resolution)
        {
            x=cos(angle+speed_increment)*(radius_un_cos+raidus_addon);
            y=sin(angle+speed_increment)*(radius_un_cos+raidus_addon);
        }
        
        circle_un_cos.addVertex(ofPoint(x,y));
        
        
    }
    
    ofSetLineWidth(line_w);
    ofSetColor(clr);
    circle_sin.close(); // to connect first and last point of our shape we need to use ÔcloseÕ function
    circle_sin= circle_sin.getSmoothed(smoothing_amount);
    circle_sin.draw();
    
    ofSetColor(clr1);
    //circle_cos.close();
    //circle_cos= circle_cos.getSmoothed(smoothing_amount);
    //circle_cos.draw();
    
    ofSetColor(clr2);
    circle_un_cos.close();
    circle_un_cos= circle_un_cos.getSmoothed(smoothing_amount);
    circle_un_cos.draw();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    ofLog() << "key pressed: " << (char)key;
    
    if(key == '1') {
        clr =ofColor::orangeRed;
        clr1 =ofColor::cadetBlue;
        clr2 =ofColor::antiqueWhite;
    }
    else if(key == '2') {
        clr =ofColor::yellow;
        clr1 =ofColor::black;
        clr2 =ofColor::blue;
           }
    else if(key == '3') {
        clr =ofColor::darkRed;
        clr1 =ofColor::indianRed;
        clr2 =ofColor::paleVioletRed;
            }
    else if(key == '4') {
        clr =ofColor::lawnGreen;
        clr1 =ofColor::limeGreen;
        clr2 =ofColor::seaGreen;
            }
    else if(key == '5') {
        clr =ofColor::darkCyan;
        clr1 =ofColor::peru;
        clr2 =ofColor::dimGrey;
    }
    else if(key == 'a') {
        d += .05;
    }
    else if(key == 'z') {
        d -= .05;
    }
    else if(key == 's') {
        r += 25;
    }
    else if(key == 'x') {
        r -= 25;
    }
    else if(key == 'd') {
        w += 1;
    }
    else if(key == 'c') {
        w -= 1;
    }
    else if(key == 'f') {
        s += .05;
    }
    else if(key == 'v') {
        s -= .05;
    }
    else if(key == 'r') {
        d =0.5;
        r = 200;
        w = 7;
        s = 1;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    w = x * .5;

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
