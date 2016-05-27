//
// Created by Darren Mothersele on 04/05/2016.
//

#include <glm/gtc/type_ptr.hpp>
#include "ShaderProgram.h"

ShaderProgram::ShaderProgram() {
    shaderProgram = glCreateProgram();
}

int ShaderProgram::link() {
    glLinkProgram(shaderProgram);
    GLint success;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (success)
    {
        mvpLocation = glGetUniformLocation(shaderProgram, "vp");
        lightPosLocation = glGetUniformLocation(shaderProgram, "lightPosition");
        modelMatrixLocation = glGetUniformLocation(shaderProgram, "model");
    }
    return success;
}

void ShaderProgram::addShader(Shader shader) {
    glAttachShader(shaderProgram, shader.getShader());
}

void ShaderProgram::use() {
    glUseProgram(shaderProgram);
}

void ShaderProgram::setLightPosition(glm::vec3 position)
{
    glUniform3f(lightPosLocation, position.x, position.y, position.z);
}

void ShaderProgram::setViewProjectionMatrix(Matrix matrix)
{
    glUniformMatrix4fv(mvpLocation, 1, GL_FALSE, glm::value_ptr(matrix));
}

void ShaderProgram::setModelMatrix(Matrix matrix)
{
    glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, glm::value_ptr(matrix));
}














