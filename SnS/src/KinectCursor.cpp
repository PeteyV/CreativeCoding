//
//  KinectCursor.cpp
//  ShapeChop
//
//  Created by Peter Valesares on 6/0/17.
//
//

#include "KinectCursor.h"

KinectCursor::KinectCursor() {
    
    // Main circle
    centerRadius = 12;
    angle = 0;
    distance = 8;
    center.x = 0;
    center.y = 0;
    
    // First satellite (upper-left)
    satelliteRadius = 8;
    satellite[0].x = -centerRadius - distance;
    satellite[0].y = -centerRadius - distance;
    
    // Second satellite (upper-right)
    satellite[1].x = +centerRadius + distance;
    satellite[1].y = -centerRadius - distance;
    
    // Third satellite (lower-left)
    satellite[2].x = -centerRadius - distance;
    satellite[2].y = +centerRadius + distance;
    
    // Fourth satellite (lower-right)
    satellite[3].x = +centerRadius + distance;
    satellite[3].y = +centerRadius + distance;
}

void KinectCursor::draw(bool rotate, bool animate) {
    
    ofPushMatrix();
    ofTranslate(cursor.x, cursor.y, 0);
    
    if(rotate) {
        ofRotateZ(angle);
    }
    
    if(animate) {
        if(distance > 2) {
            distance-= 0.1;
        } else {
            done = true;
        }
    } else {
        done = false;
        if(distance < 10) {
            distance+= 0.1;
        }
    }
    
    // Updating circles coordinates
    satellite[0].x = -centerRadius - distance;
    satellite[0].y = -centerRadius - distance;
    
    satellite[1].x = +centerRadius + distance;
    satellite[1].y = -centerRadius - distance;
    
    satellite[2].x = -centerRadius - distance;
    satellite[2].y = +centerRadius + distance;
    
    satellite[3].x = +centerRadius + distance;
    satellite[3].y = +centerRadius + distance;
    
    
    // Drawing circles
    ofSetColor(255,0,0,127);
    ofNoFill();
    ofCircle(center.x, center.y, centerRadius);
    ofFill();
    ofCircle(center.x, center.y, centerRadius/2);
    for(int i = 0; i < 4; i++) {
        ofCircle(satellite[i].x, satellite[i].y, satelliteRadius);
        //ofLine(satellite[i].x, satellite[i].y, center.x, center.y);
    }
    
    if(rotate) {
        angle+=2;
        if (angle == 360) {
            angle = 0;
        }
    }
    ofSetColor(255,255,255,255);
    ofPopMatrix();
}

void KinectCursor::set(int x, int y) {
    
    this->cursor.x = x;
    this->cursor.y = y;
}