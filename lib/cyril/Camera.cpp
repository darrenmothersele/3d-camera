//
// Created by Darren Mothersele on 04/05/2016.
//

#include "Camera.h"

#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>


void Camera::rotate(float angle, Vector direction)
{
    //view = glm::rotate(view, angle, direction);
//    position += (angle * direction);

//    glm::vec4 f = glm::rotate(Matrix(), angle, direction) * glm::vec4(position.x, position.y, position.z, 1);
//    position = {f.x, f.y, f.z};
    front += direction * angle;
}

void Camera::move(Vector direction)
{
    position += direction;
}


void Camera::reset()
{
    position = {0.0f, 0.0f, 3.0f};
    front = {0.0f, 0.0f, -1.0f};
    up = {0.0f, 1.0f, 0.0f};

    yaw = -90.f;
    pitch = 0.f;

    // TODO SCREEN WIDTH / SCREEN HEIGHT RATIO USED HERE
    projection = glm::perspective(fov, 8.f/6.f, 0.1f, 100.0f);
}

Matrix Camera::getViewProjectionMatrix() {
    Matrix view = glm::lookAt(position, position + front, up);
    return projection * view;
}

void Camera::mouseMove(double x, double y)
{
    lastX = (float)x;
    lastY = (float)y;
}

void Camera::mouseDrag(double x, double y)
{
    static bool firstMouse = true;
    if (firstMouse)
    {
        lastX = (float)x;
        lastY = (float)y;
        firstMouse = false;
    }

    Float xOffset = (float)x - lastX;
    Float yOffset = (float)y - lastY;
    lastX = (float)x;
    lastY = (float)y;

    Float sensitivity = 0.05f;
    xOffset *= sensitivity;
    yOffset *= sensitivity;

    yaw += xOffset;
    pitch += yOffset;

    if (pitch > 89.0f) pitch = 89.0f;
    if (pitch < -89.0f) pitch = -89.0f;

    front = glm::normalize(Vector(
            cos(glm::radians(yaw)) * cos(glm::radians(pitch)),
            sin(glm::radians(pitch)),
            sin(glm::radians(yaw)) * cos(glm::radians(pitch))
    ));
}












