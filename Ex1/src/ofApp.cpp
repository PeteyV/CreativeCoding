#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofFill();
    
    //Hair
    ofSetColor(177, 209, 239);
    straightSegmentPolyline.addVertex(140, 360);
    straightSegmentPolyline.addVertex(130, 370);
    straightSegmentPolyline.addVertex(120, 350);
    straightSegmentPolyline.addVertex(90, 360);
    straightSegmentPolyline.addVertex(100, 340);
    straightSegmentPolyline.addVertex(90, 320);
    straightSegmentPolyline.addVertex(70, 320);
    straightSegmentPolyline.addVertex(50, 310);
    straightSegmentPolyline.addVertex(90, 290);
    straightSegmentPolyline.addVertex(60, 270);
    straightSegmentPolyline.addVertex(20, 250);
    straightSegmentPolyline.addVertex(60, 240);
    straightSegmentPolyline.addVertex(80, 230);
    straightSegmentPolyline.addVertex(50, 210);
    straightSegmentPolyline.addVertex(40, 190);
    straightSegmentPolyline.addVertex(10, 170);
    straightSegmentPolyline.addVertex(90, 170);
    straightSegmentPolyline.addVertex(60, 120);
    straightSegmentPolyline.addVertex(50, 80);
    straightSegmentPolyline.addVertex(130, 130);
    straightSegmentPolyline.addVertex(160, 80);
    straightSegmentPolyline.addVertex(160, 50);
    straightSegmentPolyline.addVertex(180, 90);
    straightSegmentPolyline.addVertex(190, 140);
    straightSegmentPolyline.addVertex(260, 100);
    straightSegmentPolyline.addVertex(250, 180);
    straightSegmentPolyline.addVertex(280, 190);
    straightSegmentPolyline.addVertex(310, 190);
    straightSegmentPolyline.addVertex(270, 230);
    straightSegmentPolyline.addVertex(310, 250);
    straightSegmentPolyline.addVertex(270, 270);
    straightSegmentPolyline.addVertex(280, 300);
    straightSegmentPolyline.addVertex(290, 310);
    straightSegmentPolyline.addVertex(260, 320);
    straightSegmentPolyline.addVertex(260, 340);
    straightSegmentPolyline.addVertex(240, 340);
    closedShapePolyline.close();
    
    //Ears
    ofSetColor(221, 196, 171);
    straightSegmentPolyline.addVertex(120, 330);
    straightSegmentPolyline.addVertex(100, 320);
    straightSegmentPolyline.addVertex(100, 300);
    straightSegmentPolyline.addVertex(120, 280);
    closedShapePolyline.close();
    
    straightSegmentPolyline.addVertex(250, 260);
    straightSegmentPolyline.addVertex(260, 260);
    straightSegmentPolyline.addVertex(260, 290);
    straightSegmentPolyline.addVertex(230, 300);
    closedShapePolyline.close();
    
    //Neck
    ofSetColor(217, 176, 139);
    straightSegmentPolyline.addVertex(170, 370);
    straightSegmentPolyline.addVertex(160, 390);
    straightSegmentPolyline.addVertex(180, 400);
    straightSegmentPolyline.addVertex(200, 400);
    straightSegmentPolyline.addVertex(210, 390);
    straightSegmentPolyline.addVertex(210, 370);
    closedShapePolyline.close();
    
    //Clothing
    ofSetColor(232, 228, 225);
    straightSegmentPolyline.addVertex(160, 390);
    straightSegmentPolyline.addVertex(180, 400);
    straightSegmentPolyline.addVertex(200, 400);
    straightSegmentPolyline.addVertex(210, 390);
    straightSegmentPolyline.addVertex(270, 420);
    straightSegmentPolyline.addVertex(300, 560);
    straightSegmentPolyline.addVertex(80, 560);
    straightSegmentPolyline.addVertex(100, 430);
    closedShapePolyline.close();
    
    ofSetColor(175, 203, 205);
    straightSegmentPolyline.addVertex(160, 390);
    straightSegmentPolyline.addVertex(180, 400);
    straightSegmentPolyline.addVertex(200, 400);
    straightSegmentPolyline.addVertex(210, 390);
    straightSegmentPolyline.addVertex(220, 560);
    straightSegmentPolyline.addVertex(150, 560);
    closedShapePolyline.close();
    
    ofSetColor(255, 255, 255);
    straightSegmentPolyline.addVertex(160, 390);
    straightSegmentPolyline.addVertex(170, 450);
    straightSegmentPolyline.addVertex(170, 560);
    straightSegmentPolyline.addVertex(120, 560);
    straightSegmentPolyline.addVertex(110, 550);
    straightSegmentPolyline.addVertex(150, 510);
    straightSegmentPolyline.addVertex(120, 490);
    closedShapePolyline.close();
    
    straightSegmentPolyline.addVertex(210, 390);
    straightSegmentPolyline.addVertex(260, 490);
    straightSegmentPolyline.addVertex(230, 520);
    straightSegmentPolyline.addVertex(260, 550);
    straightSegmentPolyline.addVertex(250, 560);
    straightSegmentPolyline.addVertex(210, 560);
    straightSegmentPolyline.addVertex(210, 440);
    closedShapePolyline.close();
    
    //Face
    ofSetColor(232, 196, 161);
    straightSegmentPolyline.addVertex(190, 380);
    straightSegmentPolyline.addVertex(140, 370);
    straightSegmentPolyline.addVertex(110, 310);
    straightSegmentPolyline.addVertex(90, 210);
    straightSegmentPolyline.addVertex(110, 170);
    straightSegmentPolyline.addVertex(150, 150);
    straightSegmentPolyline.addVertex(190, 150);
    straightSegmentPolyline.addVertex(230, 190);
    straightSegmentPolyline.addVertex(250, 260);
    straightSegmentPolyline.addVertex(240, 330);
    straightSegmentPolyline.addVertex(220, 370);
    closedShapePolyline.close();
    
    //Eyes
    ofSetColor(255, 255, 255);
    straightSegmentPolyline.addVertex(110, 250);
    straightSegmentPolyline.addVertex(110, 260);
    straightSegmentPolyline.addVertex(120, 270);
    straightSegmentPolyline.addVertex(150, 270);
    straightSegmentPolyline.addVertex(160, 260);
    straightSegmentPolyline.addVertex(160, 230);
    straightSegmentPolyline.addVertex(130, 235);
    closedShapePolyline.close();
    
    straightSegmentPolyline.addVertex(170, 230);
    straightSegmentPolyline.addVertex(180, 250);
    straightSegmentPolyline.addVertex(200, 260);
    straightSegmentPolyline.addVertex(230, 250);
    straightSegmentPolyline.addVertex(230, 230);
    straightSegmentPolyline.addVertex(230, 230);
    straightSegmentPolyline.addVertex(200, 225);
    closedShapePolyline.close();
    
    ofDrawLine(160,230,155,220);
    ofDrawLine(110,250,110,240);
    ofDrawLine(170,230,175,220);
    ofDrawLine(230,230,225,220);
    
    //Eyebrow(s)
    ofSetColor(177, 209, 239);
    straightSegmentPolyline.addVertex(100, 210);
    straightSegmentPolyline.addVertex(110, 200);
    straightSegmentPolyline.addVertex(140, 200);
    straightSegmentPolyline.addVertex(190, 180);
    straightSegmentPolyline.addVertex(210, 180);
    straightSegmentPolyline.addVertex(210, 190);
    straightSegmentPolyline.addVertex(170, 200);
    straightSegmentPolyline.addVertex(140, 210);
    closedShapePolyline.close();
    

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofSetLineWidth(2.0);  // Line widths apply to polylines
    
    straightSegmentPolyline.draw();
    closedShapePolyline.draw();
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
