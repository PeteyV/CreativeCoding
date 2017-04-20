#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGlutWindow.h"

int main( )
{
    ofAppGlutWindow window;
    
	ofSetupOpenGL(1900, 1800, OF_WINDOW);
	ofRunApp(new ofApp());
}