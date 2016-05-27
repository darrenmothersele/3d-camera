#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec4 color;

uniform mat4 model;
uniform mat4 vp;

out vec3 vColor;
out vec3 vNormal;
out vec3 vFragPos;

void main()
{
    gl_Position = vp * model * vec4(position, 1.0);
    vColor = color.rgb;
    vNormal =  (model * vec4(normal, 1)).xyz;
    vFragPos = (model * vec4(position, 1)).xyz;
}
