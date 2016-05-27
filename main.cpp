#include <cyril.h>
#include <iomanip>
#include <glm/gtc/matrix_transform.hpp>


class TestApp {

    Mesh cube;
    Camera camera;
    vector<Vector> cubePositions;

public:
    void init();
    void draw(ShaderProgram &shader);

    void keyPressed(int key, int mods);
    void keyReleased(int key, int mods);
    void mouseScroll(double xOffset, double yOffset);
    void mouseMove(double xPos, double yPos, GLenum drag);

};

CYRIL_MAIN(TestApp, 800, 600)



void TestApp::init() {

    std::cout << "TestApp initializing" << std::endl;

    Color white = {1, 1, 1, 1.f};
    Color red = {1, 0, 0, 1.f};
    Color green = {0, 1, 0, 1.f};
    Color blue = {0, 0, 1, 1.f};
    Color yellow = {1, 1, 0, 1.f};
    Color pink = {1, 0, 1, 1.f};

    cube.addQuad(0.5f, 0.5f, {0, 0, 1}, white);
    cube.addQuad(0.5f, 0.5f, {0, 0, -1}, red);
    cube.addQuad(0.5f, 0.5f, {0, 1, 0}, green);
    cube.addQuad(0.5f, 0.5f, {0, -1, 0}, blue);
    cube.addQuad(0.5f, 0.5f, {1, 0, 0}, yellow);
    cube.addQuad(0.5f, 0.5f, {-1, 0, 0}, pink);

    cube.bind();

    cubePositions.push_back({0, 0, 0});
    for (int i = 0; i < 10; i++)
    {
        Float x = -2.f + (rand() / (float)RAND_MAX) * 4.f;
        Float y = -2.f + (rand() / (float)RAND_MAX) * 4.f;
        Float z = -2.f + (rand() / (float)RAND_MAX) * 4.f;
        cubePositions.push_back({x, y, z});
    }

}

void TestApp::keyPressed(int key, int mods)
{
    GLfloat speed = 0.05f;

    switch (key)
    {
        case GLFW_KEY_A:
            camera.move({-speed, 0, 0});
            break;

        case GLFW_KEY_D:
            camera.move({speed, 0, 0});
            break;

        case GLFW_KEY_W:
            camera.move({0, speed, 0});
            break;

        case GLFW_KEY_S:
            camera.move({0, -speed, 0});
            break;

        case GLFW_KEY_Q:
            camera.rotate(-speed, {0, 1, 0});
            break;

        case GLFW_KEY_E:
            camera.rotate(speed, {0, 1, 0});
            break;

        case GLFW_KEY_R:
            camera.reset();
            break;

        default:
            break;
    }
}

void TestApp::keyReleased(int key, int mods) {

}

void TestApp::draw(ShaderProgram &shader)
{
    camera.update();

    shader.setViewProjectionMatrix(camera.getViewProjectionMatrix());
    shader.setLightPosition(camera.getPosition());

    for (auto i : cubePositions)
    {
        Matrix model;
        shader.setModelMatrix(glm::translate(model, i));
        cube.draw();
    }
}

void TestApp::mouseScroll(double xOffset, double yOffset)
{
    GLfloat speed = 0.05f;
    camera.move({0, 0, speed * (float)yOffset});
    camera.move({speed * (float)xOffset, 0, 0});
}

void TestApp::mouseMove(double xPos, double yPos, GLenum drag)
{
    if (drag == GLFW_PRESS)
        camera.mouseDrag(xPos, yPos);
    else
        camera.mouseMove(xPos, yPos);
}

