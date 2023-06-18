// fragment shader

#version 150

in vec2 texCoordVar;

out vec4 outputColor;
uniform sampler2DRect flatRender;
uniform sampler2DRect glowRender;

void main()
{
    vec4 flatColor = texture(flatRender, texCoordVar);
    vec4 glowColor = texture(glowRender, texCoordVar);
    vec4 alphaColor = flatColor * flatColor.a + glowColor * (1 - flatColor.a);

    float grayChannel = 0.3086 * alphaColor.r + 0.6094 * alphaColor.g + 0.0820 * alphaColor.b;

    vec4 mixColor = vec4(flatColor.r + glowColor.r, flatColor.g + glowColor.g, flatColor.b + glowColor.b, flatColor.a + glowColor.a);

    outputColor = alphaColor;
}
