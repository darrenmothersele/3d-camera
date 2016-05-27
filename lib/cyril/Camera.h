//
// Created by Darren Mothersele on 04/05/2016.
//

#ifndef CFW_CAMERA_H
#define CFW_CAMERA_H

#include "cyrilMain.h"

class Camera {
    Point position;
    Vector front;
    Vector up;

    Float yaw = -90.f;
    Float pitch = 0.f;
    Float lastX = 0;
    Float lastY = 0;
    Float fov = 45.0f;
    bool keys[1024];

    Float deltaTime = 0.f;
    Float lastFrame = 0.f;

    Matrix projection;
public:
    Camera()
    {
        reset();
    }

    void rotate(float angel, Vector direction);
    void move(Vector direction);

    void reset();

    Point getPosition() { return position; }
    Matrix getViewProjectionMatrix();

    void update()
    {
        Float currentFrame = (float)glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
    }

    void mouseDrag(double d, double d1);
    void mouseMove(double d, double d1);
};


#endif //CFW_CAMERA_H
