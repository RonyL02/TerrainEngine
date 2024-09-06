#include "Application.h"
#include <spdlog/spdlog.h>
#include "../Graphics/OpenGL/Utils.h"
#include <GLFW/glfw3.h>
#include "Window/Window.h"
#include "Input.h"

TE::Application::Application(int width, int height, const char *title)
{
    m_Window = Window::InitializeWindow(width, height, title);
}

void TE::Application::Run()
{
    Shader shader = Shader("res/shaders/vertex.glsl", "res/shaders/fragment.glsl");
    float vertices[] = {
    // positions          // colors           // texture coords
     0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
};

    unsigned int indices[] = {
        // note that we start from 0!
        0, 1, 3, // first Triangle
        1, 2, 3  // second Triangle
    };

    VertexArray va = VertexArray();
    VertexBuffer vb = VertexBuffer();
    IndexBuffer ib = IndexBuffer();

    va.Bind();

    vb.Bind();
    vb.SetData(vertices, sizeof(vertices) / sizeof(float));

    ib.Bind();
    ib.SetData(indices, sizeof(indices) / sizeof(unsigned int));

    va.SetAttribute(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
    va.SetAttribute(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(3 * sizeof(float)));
    va.SetAttribute(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(6 * sizeof(float)));

    vb.Unbind();
    va.Unbind();

    Texture texture = Texture("res/textures/awesomeface.png");


    spdlog::info("APPLICATION::App is running...");
    while (!m_Window->ShouldClose())
    {
        if (Input::IsKeyDown(KeyCode::KEY_ESCAPE))
        {
            m_Window->SetShouldClose();
        }

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        texture.Bind();
        shader.Bind();
        va.Bind();
        // glDrawArrays(GL_TRIANGLES, 0, 3);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        m_Window->Update();
    }

    spdlog::info("APPLICATION::Exiting run loop");
}
