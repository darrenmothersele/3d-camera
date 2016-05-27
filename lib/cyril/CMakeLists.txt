
find_package(GLEW REQUIRED)

find_package(GLM REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
include_directories(${GLFW_INCLUDE_DIRS})


add_library(Cyril Window.h Shader.cpp Shader.h Mesh.cpp Mesh.h ShaderProgram.cpp ShaderProgram.h Camera.cpp Camera.h CyrilRuntime.h cyril.h)
target_link_libraries(Cyril ${GLFW_STATIC_LIBRARIES} "-framework OpenGL" ${GLEW_LIBRARY})
