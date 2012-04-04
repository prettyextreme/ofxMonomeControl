#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"

//========================================================================
int main( ){

    //ofAppGlutWindow window;
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofSetupOpenGL(830,830, OF_WINDOW);			// <-------- setup the GL context
	 
	// this kicks off the running of my app
	ofRunApp(new testApp);
	
}
