#include "GLFWWindow.h"
#include "GLFWCallback.h"
#include <GLFW/glfw3.h>
#include <utility>
#include <core/Log.h>

namespace TerrainEngine {
    GLFWWindow::GLFWWindow(WindowProps props) : Window(std::move(props)), handle(nullptr) {
        if (!glfwInit()) {
            TE_ERROR("failed to init glfw");
            return;
        }

        auto [title, width, height] = this->windowProps;
        this->handle =
                glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

        if (!this->handle) {
            TE_ERROR("failed to init glfw window");
            return;
        }

        glfwSetErrorCallback(GLFWCallback::ErrorCallback);
        glfwSetKeyCallback(this->handle, GLFWCallback::Key);
        glfwSetMouseButtonCallback(this->handle, GLFWCallback::MouseButton);
        glfwSetCursorPosCallback(this->handle, GLFWCallback::MousePosition);
        glfwSetFramebufferSizeCallback(this->handle, GLFWCallback::FramebufferSize);
        glfwMakeContextCurrent(this->handle);
        glfwSwapInterval(1);
        TE_INFO("successfully created glfw window");
    }

    GLFWWindow::~GLFWWindow() {
        if (this->handle) {
            glfwDestroyWindow(this->handle);
            this->handle = nullptr;
            TerminateGLFW();
        }
    }

    void GLFWWindow::PollEvents() { glfwPollEvents(); }

    void GLFWWindow::SwapBuffers() { glfwSwapBuffers(this->handle); }

    bool GLFWWindow::ShouldClose() { return glfwWindowShouldClose(this->handle); }

    float GLFWWindow::GetTime() {
        return glfwGetTime();
    }

    void GLFWWindow::DisableCursor(const bool disable) {
        glfwSetInputMode(this->handle, GLFW_CURSOR, disable ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
    }

    void GLFWWindow::TerminateGLFW() {
        TE_INFO("terminating glfw");
        glfwTerminate();
    }
}
