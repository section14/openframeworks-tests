#version 150

uniform mat4 modelViewMatrix;
uniform vec3 lightLocation;
uniform vec3 lightColor;
uniform float constantAttenuation;
uniform float linearAttenuation;
uniform float quadraticAttenuation;
uniform vec3 cameraLocation;
uniform vec3 colorInput;
//uniform sampler2DRect stripesTexture;

//in vec2 texCoordVar;
in vec3 vertNormal;
in vec4 vertPosition;
in vec4 vertColor; //may not be needed

out vec4 outputColor;

void main()
{
    float windowWidth = 1024.0;
    float windowHeight = 768.0;
    
	float r = gl_FragCoord.x / windowWidth;
	float g = gl_FragCoord.y / windowHeight;
	float b = 1.0;
	float a = 1.0;

	vec4 color = vec4(r,g,b,a);

    vec4 inputColor = vec4(colorInput.rgb, 1.0);
    //vec4 stripes = texture(stripesTexture, texCoordVar);
    //vec4 colorMix = mix(color, stripes, 0.1);
	//vec4 colorMix = mix(inputColor, color, 0.9);
	vec4 colorMix = inputColor;

    //////////////////////////////////////////////////
    ///// LIGHTING  /////////////////////////////////
    /////////////////////////////////////////////////

    //calculate normal in world coordinates
    mat3 normalMatrix = transpose(inverse(mat3(modelViewMatrix)));
    vec3 vertexNormal = normalize(normalMatrix * vertNormal);

    //calculate the location of this pixel in world coordinates
    vec3 fragPosition = vec3(modelViewMatrix * vertPosition);

    //calculate the vector from this pixels surface to the light source
    vec3 surfaceToLight = normalize(lightLocation - fragPosition) * (normalize(cameraLocation));

    //////////////////////////////
    //ambient component //////////
    //////////////////////////////
    vec3 ambientCoefficient = lightColor * 0.25;
    vec3 ambient = ambientCoefficient * lightColor * colorMix.rgb;

    /////////////////////////////
    //diffuse component /////////
    ////////////////////////////
    //calculate the cosine of the angle of incidence (brightness)
    float diffuseCoefficient = max(0.0, dot(vertexNormal, surfaceToLight));
    vec3 diffuse = diffuseCoefficient * lightColor * colorMix.rgb;

    ////////////////////////////
    //specular component ///////
    ////////////////////////////
    float materialShine = 0.8; //make a uniform?
    vec3 specularColor = vec3(0.5,0.5,0.5); //make a uniform

    vec3 incidenceVector = -surfaceToLight; //points from light to surface
    vec3 reflectionVector = reflect(incidenceVector, vertexNormal); //??
    vec3 surfaceToCamera = normalize(cameraLocation - fragPosition);
    float cosAngle = max(0.0, dot(surfaceToCamera, reflectionVector));
    float specularCoefficient = 0.0;

    //make sure we aren't reflecting the back of a surface
    if (diffuseCoefficient > 0.0)
    {
       specularCoefficient = pow(cosAngle, materialShine);
    }

    vec3 specular = specularCoefficient * specularColor * colorMix.rgb; //get creative

    ///////////////////////////
    //attenuation /////////////
    ///////////////////////////
    float distanceToLight = length(normalize(lightLocation) - fragPosition);

	//first num (ie. 2.0) makes stuff brighter the higher you go
    float attenuation = 4.0 / ((1 + 0.00095 * distanceToLight) * 
		(1 + 0.000005 * distanceToLight * distanceToLight));
    //
    // above with uniforms is:
    //float attenuation = constatntAttenuation / ((1 + linearAttenuation * distanceToLight) * (1 + quadraticAttenuation * distanceToLight * distanceToLight));

    //calculate final linear color of the pixel
    vec3 linearColor = attenuation * (diffuse + ambient + specular);

    //gamma corrected output
    vec3 gamma = vec3(2.0/2.2);
    outputColor = vec4(pow(linearColor, gamma), 1.0);

	//outputColor = vec4(r, g, b, a);
}

/*
out vec4 outputColor;

void main()
{
    // gl_FragCoord contains the window relative coordinate for the fragment.
    // we use gl_FragCoord.x position to control the red color value.
    // we use gl_FragCoord.y position to control the green color value.
    // please note that all r, g, b, a values are between 0 and 1.
    
    float windowWidth = 1024.0;
    float windowHeight = 768.0;
    
	float r = gl_FragCoord.x / windowWidth;
	float g = gl_FragCoord.y / windowHeight;
	float b = 1.0;
	float a = 1.0;
	outputColor = vec4(r, g, b, a);
}
*/
