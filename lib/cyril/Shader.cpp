//
// Created by Darren Mothersele on 04/05/2016.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include "Shader.h"

Shader::Shader(GLenum type, const char* path) {
    shader = glCreateShader(type);
    std::ifstream shaderFile;
    shaderFile.exceptions(std::ifstream::badbit);
    std::string shaderString;
    const GLchar* shaderCode;
    try
    {
        shaderFile.open(path);
        std::stringstream ss;
        ss << shaderFile.rdbuf();
        shaderFile.close();
        shaderString = ss.str();
        shaderCode = shaderString.c_str();
    }
    catch (std::ifstream::failure e)
    {
        std::cout << "Error reading shader file" << std::endl;
    }
    glShaderSource(shader, 1, &shaderCode, NULL);
    glCompileShader(shader);
    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        printLog();
        throw "shader failed to compile";
    }
}

Shader::~Shader() {
    glDeleteShader(shader);
}

GLuint Shader::getShader() {
    return shader;
}





