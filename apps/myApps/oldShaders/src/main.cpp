
#include "ofMain.h"
#include "ofUtils.h"
#include "testApp.h"
#include "ofGLProgrammableRenderer.h"

//========================================================================
int main( ){
	//ofSetWorkingDirectoryToDefault();
	ofRestoreWorkingDirectoryToDefault();
	//ofSetCurrentRenderer(ofGLProgrammableRenderer::TYPE);
    ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new testApp());

}


/*
#include "ofMain.h"
#include "testApp.h"

//========================================================================
int main( ){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new testApp());

}
*/
