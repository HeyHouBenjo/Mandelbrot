#version 330 core
out vec4 pixColor;

uniform int iterationCount;

in vec2 complexPos;

vec3 hsvToRgb(in float h, in float s, in float v){
    float c = v * s;
    float x = c * (1 - abs(mod(h / 60, 2) - 1));
    float m = v - c;
    vec3 rgbT;
    if (0 <= h && h < 60)
        rgbT = vec3(c, x, 0);
    if (60 <= h && h < 120)
        rgbT = vec3(x, c, 0);
    if (120 <= h && h < 180)
        rgbT = vec3(0, c, x);
    if (180 <= h && h < 240)
        rgbT = vec3(0, x, c);
    if (240 <= h && h < 300)
        rgbT = vec3(x, 0, c);
    if (300 <= h && h < 360)
        rgbT = vec3(c, 0, x);
    vec3 rgb = rgbT + m;
    return rgb;
}

vec3 getColor(in float modifier){
    float hue = modifier * 360;
    float sat = 1;
    float value = modifier == 0 ? 0 : 1;

    return hsvToRgb(hue, sat, value);
}

vec2 square(in vec2 c){
    return vec2(c.x * c.x - c.y * c.y, 2 * c.x * c.y);
}

vec2 m(in vec2 c){
    return square(c) + complexPos;
}

int mandelbrot(in vec2 c){
    vec2 z = vec2(0, 0);
    int steps = 0;
    while (steps < iterationCount && length(z) <= 2){
        z = m(z);
        ++steps;
    }
    if (steps == iterationCount)
        return 0;
    return steps;
}

void main(){

    int m = mandelbrot(complexPos);

    float modifier = sqrt(float(m) / iterationCount);
    pixColor = vec4(getColor(modifier), 1);
}

