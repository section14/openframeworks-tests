// vertex shader

#version 150

uniform mat4 modelViewProjectionMatrix;
uniform sampler2DRect noiseTexture;
in vec4 position;
in vec4 color;
in vec3 normal;
in vec2 texcoord;

out vec4 vertPosition;
out vec4 vertColor;
out vec3 vertNormal;
out vec2 texCoordVar;

void main()
{
    texCoordVar = texcoord;
    vertPosition = position;
    vertColor = color;
    vertNormal = normal;

    vec4 modPosition = modelViewProjectionMatrix * position;

    float noiseOffset = texture(noiseTexture,texcoord).r;

    gl_Position = modPosition + (noiseOffset * 10);
}
