#ifndef _CUBE
#define _CUBE

#include "of3dPrimitives.h"
#include "ofMain.h"
#include "ofVboMesh.h"

class Cube
{
    public:

    float w;
    float h;
    float d;

    float x;
    float y;
    float z;

    void update();
    void draw();

	Cube();
    Cube(float, float, float, ofColor);
    void setLocation(float, float, float);

    ofVboMesh mesh;
    ofVbo myVbo;
	of3dPrimitive cubePrimitive;
	~Cube();
};

#endif
