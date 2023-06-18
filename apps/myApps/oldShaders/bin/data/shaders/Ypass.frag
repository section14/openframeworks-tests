// fragment shader

#version 150

in vec2 texCoordVar;

out vec4 outputColor;
uniform sampler2DRect img;

void main()
{
    vec4 color;
    float blurAmnt = 20.0;

    color += 1.0 * texture(img, texCoordVar + vec2(0.0, blurAmnt * -4.0));
    color += 2.0 * texture(img, texCoordVar + vec2(0.0, blurAmnt * -3.0));
    color += 3.0 * texture(img, texCoordVar + vec2(0.0, blurAmnt * -2.0));
    color += 4.0 * texture(img, texCoordVar + vec2(0.0, blurAmnt * -1.0));

    color += 5.0 * texture(img, texCoordVar + vec2(0, blurAmnt));

    color += 4.0 * texture(img, texCoordVar + vec2(0.0, blurAmnt * 1.0));
    color += 3.0 * texture(img, texCoordVar + vec2(0.0, blurAmnt * 2.0));
    color += 2.0 * texture(img, texCoordVar + vec2(0.0, blurAmnt * 3.0));
    color += 1.0 * texture(img, texCoordVar + vec2(0.0, blurAmnt * 4.0));

    color /= 20.0;

    outputColor = color;
}
