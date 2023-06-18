#pragma once

#include "of3dPrimitives.h"
#include "ofMain.h"
#include "ofShader.h"

class Box {
	public: 
	Box();
	void setup(float w, float h, float r, float g, float b);
	void update();
	void draw(ofVec3f lightLocation, ofVec3f lightAttenuation, ofVec3f cameraLocation);
	void rotateDeg(float deg, float x, float y, float z);

	private:
	ofBoxPrimitive box;
	ofShader shader;

	typedef struct Color {
		float r;
		float b;
		float g;
	} Color;

	Color color;
};
