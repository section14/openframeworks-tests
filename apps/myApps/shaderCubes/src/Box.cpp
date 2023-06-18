#include "Box.h"

Box::Box() {
	
}

void Box::setup(float w, float h, float r, float g, float b) {
	color.r = r;
	color.g = g;
	color.b = b;

	box.setWidth(w);
	box.setHeight(h);

	shader.load("vert.glsl", "frag.glsl");
}

void Box::update() {

}

void Box::draw(ofVec3f lightLocation, ofVec3f lightAttenuation, ofVec3f cameraLocation) {
    shader.begin();
    shader.setUniform3f("colorInput", color.r, color.g, color.b);
    shader.setUniform3f("lightLocation", lightLocation.x, lightLocation.y, lightLocation.z);

	//ofVec3f used here
    shader.setUniform1f("constantAttenuation", lightAttenuation.x);
    shader.setUniform1f("linearAttenuation", lightAttenuation.y);
    shader.setUniform1f("quadraticAttenuation", lightAttenuation.z);

    shader.setUniform3f("cameraLocation", cameraLocation.x, cameraLocation.y, cameraLocation.z);
    shader.setUniform3f("lightColor", 1.0, 0.8, 1.0);
    //shader.setUniformTexture("stripesTexture", stripes.getTextureReference(), 0);
    //shader.setUniformTexture("noiseTexture", noise.getTextureReference(), 0);
    box.draw();
    shader.end();
}


void Box::rotateDeg(float deg, float x, float y, float z) {
	box.rotateDeg(deg,x,y,z);
}
