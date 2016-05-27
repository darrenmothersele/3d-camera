//
// Created by Darren Mothersele on 05/05/2016.
//

#ifndef CFW_CYRILRUNTIME_H
#define CFW_CYRILRUNTIME_H

#include "cyrilMain.h"
#include "Window.h"
#include "ShaderProgram.h"


template <typename BaseApp>
class CyrilRuntime {
    BaseApp app;
public:

    void operator()(int width, int height)
    {
        if (!glfwInit())
            throw "Failed to initialize GLFW";


        Window<BaseApp> window(app, width, height);
        window.setClearColor({0, 0, 0, 1});

        ShaderProgram shader;
        {
            Shader vertexShader(GL_VERTEX_SHADER, "shaders/basic.vs");
            Shader fragmentShader(GL_FRAGMENT_SHADER, "shaders/basic.fs");
            shader.addShader(vertexShader);
            shader.addShader(fragmentShader);
            if (!shader.link())
            {
                shader.printLog();
                throw "Error linking Shader";
            }
        }
        app.init();

        while (!window.shouldClose())
        {
            window.clear();
            shader.use();
            app.draw(shader);

            window.update();
            glfwPollEvents();
        }

        glfwTerminate();
    }
};


#endif //CFW_CYRILRUNTIME_H
