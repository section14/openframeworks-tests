#include "ofApp.h"
#include "ofAppRunner.h"
#include "ofColor.h"
#include "ofGraphics.h"
#include "ofGraphicsConstants.h"
#include "ofLight.h"
#include "ofLog.h"
#include "ofUtils.h"

//--------------------------------------------------------------
void ofApp::setup(){
	float width = ofGetWidth() * .12;	
	//float height = ofGetWidth() * .12;	

	material.setShininess(20.0);
	material.setSpecularColor(ofColor(0,255,0,255));
	material.setDiffuseColor(ofColor(0,255,0,255));
	material.setAmbientColor(ofColor(0,200,0,255));
	//box.set(width * 2.25);
	box.setWidth(width * 2.25);
	box.setHeight(width * 1.25);
	box.setMode(OF_PRIMITIVE_TRIANGLES);

	ofColor boxColor = ofColor(238,50,255,255);
	ofColor cubeColor = ofColor(131,218,255,255);

	box.setSideColor(box.SIDE_TOP, boxColor);
	box.setSideColor(box.SIDE_BOTTOM, boxColor);
	box.setSideColor(box.SIDE_FRONT, boxColor);
	box.setSideColor(box.SIDE_BACK, boxColor);
	box.setSideColor(box.SIDE_LEFT, boxColor);
	box.setSideColor(box.SIDE_RIGHT, boxColor);

	//my cube
	float size = width * 1.25;
	cube = Cube(size, size, size, cubeColor);

	//lighting
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
	//pointLight.setPosition((ofGetWidth()*.5)+ cos(ofGetElapsedTimef()*.5)*(ofGetWidth()*.3), 
						//ofGetHeight()/2.0, 500);
	//pointLight.setPosition(ofGetWidth()*1.25, ofGetHeight()*2.0, 500);
	cube.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

	//float spinX = sin(ofGetElapsedTimef() * .35f);
	//float spinY = cos(ofGetElapsedTimef() * .075f);
	//float spinZ = sin(ofGetElapsedTimef() * .85f);

	float spinX = sin(ofGetElapsedTimef() * .55f);
	float spinY = cos(ofGetElapsedTimef() * .25f);

	//ofLog(OF_LOG_NOTICE, "log thing" + ofToString(spinY * 180));

	camera.setGlobalPosition({ 0,0,camera.getImagePlaneDistance(ofGetCurrentViewport()) });
	camera.begin();

	ofEnableLighting();
	pointLight.enable();

	//box
	box.rotateDeg(spinX, 1.0, 0.0, 0.0);
	box.rotateDeg(spinY, 0, 1.0, 0.0);
	//box.rotateDeg(spinZ, 0, 0.0, 0.5);

	ofPushMatrix();
	//material.begin();
	//ofFill();

	//ofRotateXDeg(spinX * 180);
	//ofRotateYDeg(spinY * 180);

	box.draw();

	ofTranslate(40,100,-100);
	cube.draw();
	//material.end();
	ofPopMatrix();

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
