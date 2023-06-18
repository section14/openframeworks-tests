#ifndef _BASECUBE
#define _BASECUBE

#include "ofMain.h"

class baseCube {

public:

    //ofBoxPrimitive cube;
    ofSpherePrimitive cube;
    ofShader cubeShader;
    ofImage stripes;
    ofImage noise;

    float cubeRed;
    float cubeGreen;
    float cubeBlue;

    ofVec3f lightLocation;
    ofVec3f lightAttenuation;
    ofVec3f cameraLocation;

    baseCube(float _cubeRed, float _cubeGreen, float _cubeBlue);
    void drawFlat(ofVec3f _lightLocation, ofVec3f _lightAttenuation, ofVec3f _cameraLocation);
    void update();

private:

};

#endif
