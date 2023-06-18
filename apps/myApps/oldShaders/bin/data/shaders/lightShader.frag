// fragment shader

#version 150

uniform mat4 modelViewMatrix;
uniform vec3 lightLocation;
uniform vec3 lightColor;

in vec2 texCoordVar;
in vec3 vertNormal;
in vec4 vertPosition;
in vec4 vertColor;

out vec4 outputColor;

void main()
{
    //vec3 lightLocation = vec3(100,100,100);

    //calculate normal in world coordinates
    mat3 normalMatrix = transpose(inverse(mat3(modelViewMatrix)));
    vec3 vertexNormal = normalize(normalMatrix * vertNormal);

    //calculate the location of this pixel in world coordinates
    vec3 fragPosition = vec3(modelViewMatrix * vertPosition);

    //calculate the vector from this pixels surface to the light source
    vec3 surfaceToLight = normalize(lightLocation - fragPosition);

    //calculate the cosine of the angle of incidence (brightness)
    float brightness = max(0.0, dot(vertexNormal, surfaceToLight));

    //calculate final color of the pixel
    outputColor = vec4(brightness * vertColor.rgb, 1.0);
}
