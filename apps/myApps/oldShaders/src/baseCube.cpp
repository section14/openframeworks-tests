#include "baseCube.h"

baseCube::baseCube(float _cubeRed, float _cubeGreen, float _cubeBlue)
{
    cubeRed = _cubeRed;
    cubeGreen = _cubeGreen;
    cubeBlue = _cubeBlue;

    //box
    //cube.set(50);
    //cube.setResolution(50.0);

    //sphere
    cube.set(50,25);

    cubeShader.load("shaders/cubeShader");
    stripes.loadImage("stripes.jpg");
    noise.loadImage("noise.jpg");

    cube.mapTexCoordsFromTexture(stripes.getTextureReference());
}

void baseCube::update()
{

}

void baseCube::drawFlat(ofVec3f _lightLocation, ofVec3f _lightAttenuation, ofVec3f _cameraLocation)
{
    lightLocation = _lightLocation;
    lightAttenuation = _lightAttenuation;
    cameraLocation = _cameraLocation;

    cubeShader.begin();
    cubeShader.setUniform3f("colorInput", cubeRed, cubeGreen, cubeBlue);
    cubeShader.setUniform3f("lightLocation", lightLocation.x, lightLocation.y, lightLocation.z);
    cubeShader.setUniform1f("constantAttenuation", lightAttenuation.x);//
    cubeShader.setUniform1f("linearAttenuation", lightAttenuation.y);/////// XYZ used for easy data encapsulation
    cubeShader.setUniform1f("quadraticAttenuation", lightAttenuation.z);//
    cubeShader.setUniform3f("cameraLocation", cameraLocation.x, cameraLocation.y, cameraLocation.z);
    cubeShader.setUniform3f("lightColor", 1.0, 0.8, 1.0);
    cubeShader.setUniformTexture("stripesTexture", stripes.getTextureReference(), 0);
    cubeShader.setUniformTexture("noiseTexture", noise.getTextureReference(), 0);
    cube.draw();
    cubeShader.end();
}
