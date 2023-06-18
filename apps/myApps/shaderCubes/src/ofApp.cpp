#include "ofApp.h"
#include "ofAppRunner.h"
#include "ofGraphics.h"
#include "ofLight.h"

//--------------------------------------------------------------
void ofApp::setup(){
	float width = ofGetScreenWidth() * .12;		

	box1.setup(width * 1.5, width * 1.5, .9f, .8f, 0);	
	box2.setup(width * 2.0, width * 0.75, 0, .8f, .5f);	

	ofSetSmoothLighting(true);
	pointLight.setDiffuseColor( ofFloatColor(.95, .95, .65) );
	pointLight.setSpecularColor( ofFloatColor(1.f, 1.f, 1.f));
	pointLight.setAmbientColor(ofFloatColor(0.20, 0.20, 0.20));
	pointLight.setAreaLight(50.0,50.0);
	pointLight.setPosition(ofGetWidth()*0.75, ofGetHeight()*0.75, 0);

	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update(){
	//camera.lookAt(ofVec3f(0, 0, 0));
}

//--------------------------------------------------------------
void ofApp::draw(){
	float spinX = sin(ofGetElapsedTimef() * .55f);
	float spinY = cos(ofGetElapsedTimef() * .25f);

	camera.setGlobalPosition({0, 0, camera.getImagePlaneDistance(ofGetCurrentViewport())});
	camera.begin();

	ofFill();
	//ofSetColor(8,255,206);

	ofEnableLighting();
	pointLight.enable();

	lightLocation = pointLight.getPosition();
    lightAttenuation = ofVec3f(pointLight.getAttenuationConstant(), 
							   pointLight.getAttenuationLinear(), 
							   pointLight.getAttenuationQuadratic());
    cameraLocation = camera.getPosition();


	//ofLog(OF_LOG_NOTICE, "log thing" + ofToString(spinY * 180));

	//box
	ofPushMatrix();
	box1.rotateDeg(spinX, 1.0, 0.0, 0.0);
	box1.rotateDeg(spinY, 0, 1.0, 0.0);
	box1.draw(lightLocation, lightAttenuation, cameraLocation);

	ofTranslate(0,150,0);

	box2.rotateDeg(spinY, 0, 0.8, 0.0);
	box2.rotateDeg(spinX, 0.5, 0, 0.0);
	box2.draw(lightLocation, lightAttenuation, cameraLocation);
	ofPopMatrix();

	pointLight.disable();
	camera.end();
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
