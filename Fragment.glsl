#version 330 core

out vec4 pixColor;

uniform int iterationCount;
uniform float divergeThreshold;

in vec2 complexPos;

vec3 getColor(in float value){
    vec3 red = vec3(0.5, 0, 0);
    vec3 blue = vec3(0, 0, 0.5);
    return value * red + (1 - value) * blue;
}

vec2 square(in vec2 c){
    return vec2(c.x * c.x - c.y * c.y, 2 * c.x * c.y);
}

void main(){

    vec2 z;
    float stepsNeeded = 0;
    while (stepsNeeded < iterationCount && length(z) < divergeThreshold){
        z = square(z) + complexPos;
        ++stepsNeeded;
    }

    float value = stepsNeeded / iterationCount;
    pixColor = vec4(getColor(value), 1);
}

