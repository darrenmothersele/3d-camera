#version 330 core
in vec3 vColor;
in vec3 vFragPos;
in vec3 vNormal;

uniform vec3 lightPosition;

out vec4 color;

void main()
{
    if (gl_FrontFacing)
    {
        vec3 lightColor = vec3(1, 1, 1);

        float ambientStrength = 0.1f;
        vec3 ambient = ambientStrength * lightColor;

        vec3 norm = normalize(vNormal);
        vec3 lightDir = normalize(lightPosition - vFragPos);
        float diff = max(dot(norm, lightDir), 0.0);
        vec3 diffuse = diff * lightColor;

        vec3 result = (diffuse + ambient) * vColor;
        color = vec4(result, 1.0f);
    }
    else
    {
        color = vec4(0.1, 0.1, 0.1, 1);
    }
}
