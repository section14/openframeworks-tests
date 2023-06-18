#pragma once

#include "ofMain.h"
#include "baseCube.h"

class testApp : public ofBaseApp{

	public:

    ofCamera camera;
    ofLight pointLight;
    float camAngle;
    float camX;
    float camY;
    float camZ;
    float lightX;
    float lightY;
    float lightZ;

    ofVec3f lightLocation;
    ofVec3f lightAttenuation;
    ofVec3f cameraLocation;

    ofShader lightShader;
    ofShader Xpass;
    ofShader Ypass;
    ofShader blendPass;

    ofFbo flatFbo;
    ofFbo glowFbo;
    ofFbo blurFbo01;
    ofFbo blurFbo02;
    ofFbo blendFbo;

    //baseCube box1 = baseCube(0.6,0.0,0.8);
    //baseCube box2 = baseCube(0.9,0.2,0.0);
    //baseCube box3 = baseCube(0.2,0.0,1.0);

    baseCube box1 = baseCube(1.0,0.0,0.0);
    baseCube box2 = baseCube(0.0,1.0,0.0);
    baseCube box3 = baseCube(0.0,0.0,1.0);

    float boxAngle01;
    float boxAngle02;
    float boxAngle03;

    float box1Z;
    float box1X;
    float boxSpin;

    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

};
