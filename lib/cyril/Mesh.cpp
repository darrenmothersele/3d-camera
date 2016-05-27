//
// Created by Darren Mothersele on 04/05/2016.
//

#include "Mesh.h"
#include <glm/gtx/norm.hpp>

void Mesh::draw()
{
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, (GLsizei)indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void Mesh::bind() {
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &indices[0], GL_STATIC_DRAW);

    // Vertex positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
    // Vertex normals
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
    // Vertex colours
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, color));

    glBindVertexArray(0);
}

void Mesh::addTriangle(Vertex v1, Vertex v2, Vertex v3) {
    unsigned int offset = (unsigned int)vertices.size();
    vertices.push_back(v1);
    indices.push_back(offset++);
    vertices.push_back(v2);
    indices.push_back(offset++);
    vertices.push_back(v3);
    indices.push_back(offset);
}

void Mesh::addQuad(Point p1, Point p2, Point p3, Point p4, Vector n, Color c)
{
    unsigned int offset = (unsigned int)vertices.size();

    vertices.push_back({p1, n, c});
    vertices.push_back({p2, n, c});
    vertices.push_back({p3, n, c});
    vertices.push_back({p4, n, c});

    indices.push_back(offset + 0);
    indices.push_back(offset + 1);
    indices.push_back(offset + 2);
    indices.push_back(offset + 0);
    indices.push_back(offset + 2);
    indices.push_back(offset + 3);
}

void Mesh::addTriangle(Point p1, Point p2, Point p3, Vector n, Color c)
{
    unsigned int offset = (unsigned int)vertices.size();

    vertices.push_back({p1, n, c});
    vertices.push_back({p2, n, c});
    vertices.push_back({p3, n, c});

    indices.push_back(offset + 0);
    indices.push_back(offset + 1);
    indices.push_back(offset + 2);
}

void Mesh::addQuad(float size, float distance, Vector n, Color c)
{
    unsigned int offset = (unsigned int)vertices.size();

    Vector vX = glm::cross(n, {1.f, 0.f, 0.f});
    if (glm::length2(vX) <= 0)
    {
        vX = glm::cross(n, {0.f, 1.f, 0.f});
    }
    vX = glm::normalize(vX);
    Vector vY = glm::cross(n, vX);

    Point p0 = (-size * vX) - (size * vY) + (distance * n);
    Point p1 = (-size * vX) + (size * vY) + (distance * n);
    Point p2 = (size * vX) + (size * vY) + (distance * n);
    Point p3 = (size * vX) - (size * vY) + (distance * n);

    vertices.push_back({p0, n, c});
    vertices.push_back({p1, n, c});
    vertices.push_back({p2, n, c});
    vertices.push_back({p3, n, c});

    indices.push_back(offset + 2);
    indices.push_back(offset + 1);
    indices.push_back(offset + 0);
    indices.push_back(offset + 3);
    indices.push_back(offset + 2);
    indices.push_back(offset + 0);
}











