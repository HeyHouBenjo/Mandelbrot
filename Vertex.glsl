#version 330 core
layout (location = 0) in vec2 pos;

uniform vec2 origin;
uniform vec2 size;

out vec2 complexPos;

void main(){
    vec2 offset = (pos + 1) / 2 * size;
    offset.y *= -1;
    complexPos = origin + offset;
    gl_Position = vec4(pos.xy, 0.0, 1.);
}