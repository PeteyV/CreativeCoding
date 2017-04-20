#include "ofApp.h"

int Line::MinLength = 4;
int Line::MaxLength = 100;

void ofApp::setup()
{
    mouseEmitter.velSpread = ofVec3f(25.0,25.0);
    mouseEmitter.life = 100;
    mouseEmitter.lifeSpread = 5.0;
    mouseEmitter.numPars = 10;
    mouseEmitter.color = ofColor(0,0,0);
    mouseEmitter.colorSpread = ofColor(20,20,0);
    mouseEmitter.size = 32;
    
    vectorField.allocate(128, 128, 3);
    
// instantiate and position the gui //
    gui = new ofxDatGui( ofxDatGuiAnchor::BOTTOM_LEFT );

// add some color pickers to color our lines //
    ofxDatGuiFolder* f1 = gui->addFolder("Line Color", ofColor::fromHex(0x2FA1D6));
    f1->addColorPicker("LINE 1", ofColor::fromHex(0x20201f));
    f1->addColorPicker("LINE 2", ofColor::fromHex(0x80b0b0));
    f1->addColorPicker("LINE 3", ofColor::fromHex(0x4f4b4d));
    f1->addColorPicker("LINE 4", ofColor::fromHex(0xe5e2d9));
    f1->expand();
    gui->addBreak();
    
// and some sliders to adjust how they're drawn //
    ofxDatGuiFolder* f2 = gui->addFolder("Line Control", ofColor::fromHex(0xFFD00B));
    s1 = f2->addSlider("DRAW SPEED", 0, 120, 5);
    s2 = f2->addSlider("LINE WEIGHT", 1, 60, 2);
    //s3 = f2->addSlider("LINE LENGTH", 4, 200, 4);
    f2->expand();
    gui->addBreak();
    
// and a few others widgits for good measure :) //
    gui->addButton("CLEAR");
    gui->addToggle("PAUSE DRAWING", false);
    
// register a few callbacks to listen for our gui events //
    gui->onButtonEvent(this, &ofApp::onButtonEvent);
    gui->onToggleEvent(this, &ofApp::onToggleEvent);
    gui->onSliderEvent(this, &ofApp::onSliderEvent);
    gui->onTextInputEvent(this, &ofApp::onTextInputEvent);
    gui->onColorPickerEvent(this, &ofApp::onColorPickerEvent);
    
// capture the default slider values into variables //
    drawSpeed = s1->getValue();
    lineWeight = s2->getValue();
    Line::MaxLength = 4;
    gui->setOpacity(gui->getSlider("datgui opacity")->getScale());
    drawingPaused = gui->getToggle("pause drawing")->getChecked();
    
// finally add some generative lines to draw //
    lines.push_back(Line(ofGetWidth()*.05, ofGetHeight()/2, gui->getColorPicker("line 1")->getColor()));
    lines.push_back(Line(ofGetWidth()*.02, ofGetHeight()/2, gui->getColorPicker("line 2")->getColor()));
    lines.push_back(Line(ofGetWidth()*.95, ofGetHeight()/2, gui->getColorPicker("line 3")->getColor()));
    lines.push_back(Line(ofGetWidth()*.92, ofGetHeight()/2, gui->getColorPicker("line 4")->getColor()));
    
// let's launch the app fullscreen //
    isFullscreen = false;
    ofSetFullscreen(isFullscreen);
    
// and tile the background with a pattern //
    bkgd.load("bkgd-pattern.png");
}

void ofApp::onSliderEvent(ofxDatGuiSliderEvent e)
{
//  every event has a pointer to the object (target) that dispatched the event
    if (e.target->getLabel() == "DRAW SPEED"){
        drawSpeed = e.value;
// you can also compare the target pointer against a local variable
    }   else if (e.target == s2){
        lineWeight = e.value;
// slider event objects also carry the current scale & value of the slider
    }   else if (e.target == s3){
        Line::MaxLength = e.value;
    }   else if (e.target->getLabel() == "DATGUI OPACITY"){
// however you can always read these values directly off of the slider itself
        gui->setOpacity(e.target->getScale());
    }
}

void ofApp::onButtonEvent(ofxDatGuiButtonEvent e)
{
    if (e.target->is("clear")) reset();
}

void ofApp::onToggleEvent(ofxDatGuiToggleEvent e)
{
    if (e.target->is("pause drawing")) {
        drawingPaused = e.checked;
    }
}

void ofApp::onTextInputEvent(ofxDatGuiTextInputEvent e)
{
    cout << "onTextInputEvent: " << e.target->getLabel() << " " << e.target->getText() << endl;
}

void ofApp::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
{
    if (e.target->getLabel() == "LINE 1"){
        lines[0].color = e.target->getColor();
    }   else if (e.target->getLabel() == "LINE 2"){
        lines[1].color = e.target->getColor();
    }   else if (e.target->getLabel() == "LINE 3"){
        lines[2].color = e.target->getColor();
    }   else if (e.target->getLabel() == "LINE 4"){
        lines[3].color = e.target->getColor();
    }
}

void ofApp::update()
{
    if (drawingPaused) return;
    for(int i=0; i<lines.size(); i++){
        lines[i].tick();
        lines[i].head->x += (lines[i].dx) * drawSpeed;
        lines[i].head->y += (lines[i].dy) * drawSpeed;
    }
    
    for(int y = 0; y < vectorField.getHeight(); y++)
        for(int x=0; x< vectorField.getWidth(); x++){
            int index = vectorField.getPixelIndex(x, y);
            float angle = ofNoise(x/(float)vectorField.getWidth()*4.0, y/(float)vectorField.getHeight()*4.0,ofGetElapsedTimef()*0.05)*TWO_PI*2.0;
            ofVec2f dir(cos(angle), sin(angle));
            dir.normalize().scale(ofNoise(x/(float)vectorField.getWidth()*4.0, y/(float)vectorField.getHeight()*4.0,ofGetElapsedTimef()*0.05+10.0));
            vectorField.setColor(x, y, ofColor_<float>(dir.x,dir.y, 0));
        }
    
    particleSystem.gravitateTo(ofPoint(ofGetWidth()/2,ofGetHeight()/2), gravAcc, 1, 10.0, false);
    particleSystem.rotateAround(ofPoint(ofGetWidth()/2,ofGetHeight()/2), rotAcc, 10.0, false);
    particleSystem.applyVectorField(vectorField.getData(), vectorField.getWidth(), vectorField.getHeight(), vectorField.getNumChannels(), ofGetWindowRect(), fieldMult);
    if(ofGetMousePressed(2)){
        particleSystem.gravitateTo(ofPoint(mouseX,mouseY), gravAcc, 1, 10.0, false);
    }
    
    float dt = (ofGetLastFrameTime() * 60);
    
    particleSystem.update(dt, drag);
    
    particleSystem.addParticles(leftEmitter);
    particleSystem.addParticles(rightEmitter);
    particleSystem.addParticles(topEmitter);
    particleSystem.addParticles(botEmitter);
    
    ofVec2f mouseVel(mouseX-pmouseX,mouseY - pmouseY);
    mouseVel *= 2.0;
    if(ofGetMousePressed(0)){
        mouseEmitter.setPosition(ofVec3f(pmouseX,pmouseY),ofVec3f(mouseX,mouseY));
        mouseEmitter.posSpread = ofVec3f(10.0,10.0,0.0);
        mouseEmitter.setVelocity(pmouseVel, mouseVel);
        particleSystem.addParticles(mouseEmitter);
    }
    pmouseX = mouseX;
    pmouseY = mouseY;
    pmouseVel = mouseVel;
}

void ofApp::draw()
{
    
// pattern the background //
    for(int i = 0; i < ofGetHeight(); i += 400) for(int j = 0; j < ofGetWidth(); j += 400) bkgd.draw(j, i, 400, 400);
// draw some lines //
    ofPushStyle();
        ofSetLineWidth(lineWeight);
        for (int i=0; i<lines.size(); i++){
            ofSetColor(lines[i].color);
            lines[i].draw();
        }
    ofPopStyle();
    
    if(ofGetKeyPressed('v')){
        ofMesh fieldMesh;
        fieldMesh.disableIndices();
        fieldMesh.setMode(OF_PRIMITIVE_LINES);
        for(int y = 0; y < vectorField.getHeight(); y++) {
            for(int x=0; x< vectorField.getWidth(); x++) {
                ofColor_<float> c = vectorField.getColor(x, y);
                ofVec3f pos(x,y);
                ofVec3f dir(c.r, c.g);
                fieldMesh.addVertex(pos);
                fieldMesh.addColor(c);
                fieldMesh.addVertex(pos + dir);
                fieldMesh.addColor(c);
            }
        }
        
        ofSetLineWidth(1.0);
        ofSetColor(80, 80, 80);
        ofPushMatrix();
        ofScale(ofGetWidth()/(float)vectorField.getWidth(), ofGetHeight()/(float)vectorField.getHeight());
        fieldMesh.draw();
        ofPopMatrix();
    }
    
    ofNoFill();
    ofSetCircleResolution(180);
    ofSetColor(255, 0, 0, 50);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, gravAcc);
    ofSetColor(0, 0, 255, 50);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, rotAcc);
    
    ofSetLineWidth(2.0);
    if (displayMode == 1) {
        particleSystem.draw(pTex);
    }
    else if(displayMode == 2) {
        particleSystem.draw(p1Tex, p2Tex);
    }
    else {
        particleSystem.draw();
    }
    
    float dt = (ofGetLastFrameTime() * 60);
    ofSetColor(255, 255, 255);
    ofDrawBitmapString(ofToString(particleSystem.getNumParticles()) + "\n" + ofToString(ofGetFrameRate()) +
                       "\n(G/g) gravitation: " + ofToString(gravAcc) +
                       "\n(R/r) rotational acceleration: " + ofToString(rotAcc) +
                       "\n(F/f) vector field multiplier: " + ofToString(fieldMult) +
                       "\n(D/d) drag constant: " + ofToString(drag) +
                       "\n(v) show vector field" +
                       "\n(1-3) particle display modes" +
                       "\ntimestep: " + ofToString(dt) , 20,20);
    
}

void ofApp::reset()
{
    for(int i=0; i<lines.size(); i++) lines[i].reset();
}

void ofApp::keyPressed(int key)
{
    if (key == 'f') {
        isFullscreen =!isFullscreen;
        ofSetFullscreen(isFullscreen);
        if (!isFullscreen) {
            ofSetWindowShape(1920, 1080);
            ofSetWindowPosition((ofGetScreenWidth()/2)-(1920/2), 0);
        }
    }

}



