//
// Created by Darren Mothersele on 04/05/2016.
//

#ifndef CFW_CYRILMAIN_H
#define CFW_CYRILMAIN_H

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vector>

#include "Shader.h"

using namespace std;

typedef glm::vec4 Color;
typedef glm::vec4 Quaternion;
typedef glm::vec3 Point;
typedef glm::vec3 Vector;
typedef glm::mat4 Matrix;
typedef GLfloat Float;

typedef struct Vertex
{
    Point position;
    Point normal;
    Color color;
} Vertex;

#endif //CFW_CYRILMAIN_H
