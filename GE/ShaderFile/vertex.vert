#version 330 core

layout (location=0) in vec3 aPos;
layout (location=1) in vec3 aColor;
layout (location=2) in vec2 aTexCoords;

out vec3 outColor;
out vec4 outPos;
out vec2 TexCoords;

uniform float g_H_Offset;

void main(){
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    outPos = gl_Position;
    TexCoords = aTexCoords;
    outColor = aColor;
}