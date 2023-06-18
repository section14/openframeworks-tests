#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    ofBackground(100, 100, 100);
    ofSetFrameRate(60);

    camera.setNearClip(0.1);
    camera.setFarClip(6200);
    camera.setPosition(ofVec3f(300, 100, 600));
    camAngle = 0;
    camX = 200;
    camY = 150;
    camZ = 900;
    lightX = 0.0;
    lightY = 0.0;
    lightZ = 0.0;

    pointLight.setPointLight();
    pointLight.setPosition(0, 100, 50);

    lightShader.load("shaders/lightShader");
    Xpass.load("shaders/Xpass");
    Ypass.load("shaders/Ypass");
    blendPass.load("shaders/blendPass");

    flatFbo.allocate(1024,768,GL_RGBA,16);
    glowFbo.allocate(1024,768,GL_RGBA,16);
    blurFbo01.allocate(1024,768,GL_RGBA,16);
    blurFbo02.allocate(1024,768,GL_RGBA,16);
    blendFbo.allocate(1024,768,GL_RGBA,16);

    flatFbo.begin();
    ofClear(0,0,0,0);
    flatFbo.end();

    glowFbo.begin();
    ofClear(0,0,0,0);
    glowFbo.end();

    blurFbo01.begin();
    ofClear(0,0,0,0);
    blurFbo01.end();

    blurFbo02.begin();
    ofClear(0,0,0,0);
    blurFbo02.end();

    blendFbo.begin();
    ofClear(0,0,0,0);
    blendFbo.end();

    boxAngle01 = 45.0;
    boxAngle02 = 75.0;
    boxAngle03 = 10.0;

    box1X = 0.0;
    box1Z = 0.0;
    boxSpin = 0.0;
}

//--------------------------------------------------------------
void testApp::update()
{
    /*camAngle += 0.01f;

    if (camAngle >= 360)
    {
        camAngle = 0;
    }

    camX = 300 * sin(camAngle);
    camZ = 300 * cos(camAngle);
*/

    camera.lookAt(ofVec3f(0, 0, 0));
    camera.setPosition(ofVec3f(camX, camY, camZ));

    /*lightX += 0.25f;

    if (lightX >= 200)
    {
        lightX = -200;
    }

    lightY += 0.25f;

    if (lightY >= 200)
    {
        lightY = -200;
    }

    lightZ += 0.25f;

    if (lightZ >= 200)
    {
        lightZ = -200;
    }

    pointLight.setPosition(lightX, lightY, lightZ);*/
}

//--------------------------------------------------------------
void testApp::draw()
{
    boxAngle01 += 0.55;

    if (boxAngle01 > 360.0)
    {
        boxAngle01 = 0.0;
    }

    boxAngle02 += 1.125;

    if (boxAngle02 > 360.0)
    {
        boxAngle02 = 0.0;
    }

    boxAngle03 += 0.49;

    if (boxAngle03 > 360.0)
    {
        boxAngle03 = 0.0;
    }

    boxSpin += 0.005f;

    if (boxSpin >= 360)
    {
        boxSpin = 0;
    }

    box1X = 600 * sin(boxSpin);
    box1Z = 600 * cos(boxSpin);

    //render flat scene
    flatFbo.begin();
    camera.begin();
    pointLight.enable();

        lightLocation = pointLight.getPosition();
        lightAttenuation = ofVec3f(pointLight.getAttenuationConstant(), pointLight.getAttenuationLinear(), pointLight.getAttenuationQuadratic());
        cameraLocation = camera.getPosition();

        ofPushMatrix();
        ofTranslate(box1X,-60,box1Z);
        //ofRotate(boxAngle03, 0.5, 1.0, 0.3);
        box1.drawFlat(lightLocation, lightAttenuation, cameraLocation);
        ofPopMatrix();


        ofPushMatrix();
        ofTranslate(60, 50);
        //ofRotate(boxAngle02, 1.0, 1.0, 0.0);
        box2.drawFlat(lightLocation, lightAttenuation, cameraLocation);
        ofPopMatrix();


        ofPushMatrix();
        ofTranslate(-70,70);
        //ofRotate(boxAngle03, 0.2, 0.0, 1.0);
        box3.drawFlat(lightLocation, lightAttenuation, cameraLocation);
        ofPopMatrix();

    pointLight.disable();
    camera.end();
    flatFbo.end();

    //render glow objects into FBO
    glowFbo.begin();
        camera.begin();
        pointLight.enable();

        lightLocation = pointLight.getPosition();
        cameraLocation = camera.getPosition();

        ofPushMatrix();
        ofTranslate(60, 50);
        ofRotate(boxAngle02, 1.0, 1.0, 0.0);
        box2.drawFlat(lightLocation, lightAttenuation, cameraLocation);
        ofPopMatrix();
        pointLight.disable();
        camera.end();
    glowFbo.end();

    //perform gaussian blur on glow objects
    blurFbo01.begin();
    Xpass.begin();
    Xpass.setUniformTexture("img", glowFbo.getTextureReference(0), 0);
    glowFbo.draw(0,0);
    Xpass.end();
    blurFbo01.end();

    blurFbo02.begin();
    Ypass.begin();
    Ypass.setUniformTexture("img", blurFbo01.getTextureReference(0), 0);
    blurFbo01.draw(0,0);
    Ypass.end();
    blurFbo02.end();

    blendFbo.begin();
    blendPass.begin();
    blendPass.setUniformTexture("glowRender", blurFbo02.getTextureReference(0), 0);
    blendPass.setUniformTexture("flatRender", flatFbo.getTextureReference(0), 1);
    blurFbo02.draw(0,0);
    blendPass.end();
    blendFbo.end();

    //flatFbo.draw(0,0);
    //glowFbo.draw(0,0);
    //blurFbo02.draw(0,0);

    blendFbo.draw(0,0);

    flatFbo.begin();
    ofClear(0,0,0,0);
    flatFbo.end();

    glowFbo.begin();
    ofClear(0,0,0,0);
    glowFbo.end();

    blurFbo01.begin();
    ofClear(0,0,0,0);
    blurFbo01.end();

    blurFbo02.begin();
    ofClear(0,0,0,0);
    blurFbo02.end();

    blendFbo.begin();
    ofClear(0,0,0,0);
    blendFbo.end();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
