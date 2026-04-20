#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

static void errorCallback(int error, const char* description) {
    std::cerr << "GLFW Error [" << error << "]: " << description << std::endl;
}

int main() {
    glfwSetErrorCallback(errorCallback);
    
    if (!glfwInit()) {
        std::cout << "GLFW init failed!" << std::endl;
        return -1;
    }

    std::cout << "GLFW initialized successfully" << std::endl;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    std::cout << "Creating window..." << std::endl;
    GLFWwindow* window = glfwCreateWindow(800, 600, "My 3D Game", NULL, NULL);
    if (!window) {
        std::cout << "Window creation failed!" << std::endl;
        glfwTerminate();
        return -1;
    }
    
    std::cout << "Window created successfully" << std::endl;

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "GLAD init failed!" << std::endl;
        return -1;
    }

    std::cout << "OpenGL: " << glGetString(GL_VERSION) << std::endl;

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}