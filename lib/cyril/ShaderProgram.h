//
// Created by Darren Mothersele on 04/05/2016.
//

#ifndef CFW_SHADERPROGRAM_H
#define CFW_SHADERPROGRAM_H


#include <GL/glew.h>
#include <iostream>
#include <glm/vec3.hpp>
#include "Shader.h"
#include "cyrilMain.h"

class ShaderProgram {
    GLuint shaderProgram;
    GLint lightPosLocation;
    GLint mvpLocation;
    GLint modelMatrixLocation;

public:
    ShaderProgram();
    int link();

    void addShader(Shader shader);
    void printLog()
    {
        GLchar infoLog[512];
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << infoLog << std::endl;
    }

    void use();

    GLuint getShader() { return shaderProgram; }

    void setLightPosition(glm::vec3 position);
    void setViewProjectionMatrix(Matrix matrix);
    void setModelMatrix(Matrix matrix);

};


#endif //CFW_SHADERPROGRAM_H
