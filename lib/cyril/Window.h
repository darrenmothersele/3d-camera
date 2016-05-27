//
// Created by Darren Mothersele on 04/05/2016.
//

#ifndef CFW_WINDOW_H
#define CFW_WINDOW_H

#include "cyrilMain.h"

using namespace std;

template <typename APP>
class Window {
    GLFWwindow* window;
    int screenWidth, screenHeight;
    Color backgroundColor;

    static void keyCallback(GLFWwindow* window, int key, int scanCode, int action, int mods)
    {
        void* ptr = glfwGetWindowUserPointer(window);
        APP* a = static_cast<APP *>(ptr);

        if (action == GLFW_PRESS || action == GLFW_REPEAT)
            a->keyPressed(key, mods);
        if (action == GLFW_RELEASE)
            a->keyReleased(key, mods);

    }

    static void scrollCallback(GLFWwindow* window, double xOffset, double yOffset)
    {
        void* ptr = glfwGetWindowUserPointer(window);
        APP* a = static_cast<APP *>(ptr);

        a->mouseScroll(xOffset, yOffset);
    }

    static void mouseCallback(GLFWwindow* window, double xPos, double yPos)
    {
        void* ptr = glfwGetWindowUserPointer(window);
        APP* a = static_cast<APP *>(ptr);

        a->mouseMove(xPos, yPos, glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT));
    }



public:
    Window(APP &a, const int width, const int height)
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

        window = glfwCreateWindow(width, height, "Cyril", nullptr, nullptr);
        if (!window)
        {
            throw "Failed to open window";
        }
        glfwMakeContextCurrent(window);

        glewExperimental = GL_TRUE;
        if (glewInit() != GLEW_OK)
        {
            throw "Failed to initialize GLEW";
        }

        glfwSetWindowUserPointer(window, &a);
        glfwSetKeyCallback(window, keyCallback);
        glfwSetScrollCallback(window, scrollCallback);
        glfwSetCursorPosCallback(window, mouseCallback);

        glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
        glViewport(0, 0, screenWidth, screenHeight);

        glEnable(GL_DEPTH_TEST);
    }

    int shouldClose()
    {
        return glfwWindowShouldClose(window);
    }

    void setClearColor(Color c)
    {
        backgroundColor = c;
    }

    void update()
    {
        glfwSwapBuffers(window);
    }

    void clear()
    {
        glClearColor(backgroundColor.x, backgroundColor.y, backgroundColor.z, backgroundColor.w);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
};


#endif //CFW_WINDOW_H
