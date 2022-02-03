#version 330 core
out vec4 pixColor;

uniform int iterationCount;

in vec2 complexPos;

vec2 mul(in vec2 a, in vec2 b) {
    return vec2(a.x * b.x - a.y * b.y, a.y * b.x + a.x * b.y);
}

vec3 getColor(in float value){
    vec3 red = vec3(0.5, 0, 0);
    vec3 blue = vec3(0, 0, 0.5);
    return value * red + (1 - value) * blue;
}

void main(){

    vec2 z;
    float stepsNeeded = 0;
    while (stepsNeeded < iterationCount && length(z) < 2){
        z = mul(z, z) + complexPos;
        ++stepsNeeded;
    }

    float value = stepsNeeded / iterationCount;
    pixColor = vec4(getColor(value), 1);
}

