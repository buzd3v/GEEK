#version 330 core
out vec4 FragColor;
in vec3 outColor;
in vec4 outPos;
in vec2 TexCoords;

uniform sampler2D outTexture; 

void main()
{
   FragColor = texture(outTexture, TexCoords);
}