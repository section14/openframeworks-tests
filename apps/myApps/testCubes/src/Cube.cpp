#include "Cube.h"

Cube::Cube() {}

Cube::Cube(float w, float h, float d, ofColor color)
{
    GLfloat vdata[8][3] = {
        {-w, -h, -d}, {-w, h, -d},
        {w, h, -d}, {w, -h, -d},
        {-w, -h, d}, {w, -h, d},
        {-w, h, d}, {w, h, d}
    };

    GLint indices[6][4] = {
        {3, 2, 1, 0},
        {3, 5, 4, 0},
        {3, 5, 7, 2},
        {0, 4, 6, 1},
        {1, 2, 7, 6},
        {5, 4, 6, 7}
    };

    for (int i=0; i<8; ++i)
    {
        mesh.addVertex(ofVec3f( vdata[i][0], vdata[i][1], vdata[i][2] ));
        mesh.addColor(color);

        for (int i=0; i<6; ++i)
        {
            mesh.addIndex(indices[i][0]);
            mesh.addIndex(indices[i][1]);
            mesh.addIndex(indices[i][2]);
            mesh.addIndex(indices[i][3]);
        }
    }

	cubePrimitive.getMesh().append(mesh);
    myVbo.setMesh(cubePrimitive.getMesh(), GL_STATIC_DRAW);
}

void Cube::draw()
{
    myVbo.drawElements(GL_QUADS, 24);
	//cubePrimitive.draw();
}

void Cube::update()
{
}

void Cube::setLocation(float _x, float _y, float _z)
{
    x = _x;
    y = _y;
    z = _z;
}

Cube::~Cube(){}
