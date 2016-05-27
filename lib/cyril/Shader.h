//
// Created by Darren Mothersele on 04/05/2016.
//

#ifndef CFW_SHADER_H
#define CFW_SHADER_H


#include <GL/glew.h>

class Shader {
    GLuint shader;

public:
    Shader(GLenum type, const char* path);
    ~Shader();

    GLuint getShader();

    void printLog()
    {
        GLchar infoLog[512];
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << infoLog << std::endl;
    }

};


#endif //CFW_SHADER_H
