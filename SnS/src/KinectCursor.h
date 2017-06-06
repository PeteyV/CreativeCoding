//
//  KinectCursor.hpp
//  ShapeChop
//
//  Created by Peter Valesares on 6/0/17.
//
//


#ifndef CURSOR_H
#define CURSOR_H

#include "ofMain.h"

class KinectCursor {
    
private:
    ofPoint center;
    ofPoint satellite[4];
    float centerRadius;
    float satelliteRadius;
    float angle;
    float speed; // Smooth effect
    float distance;
    
public:
    KinectCursor();
    void draw(bool, bool);
    void set(int, int);
    
    ofPoint cursor;
    bool done;
};

#endif