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
        0.5f, 0.5f, 0.0f,   // top right
        0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f, // bottom left
        -0.5f, 0.5f, 0.0f   // top left
    };
    unsigned int indices[] = {
        // note that we start from 0!
        0, 1, 3, // first Triangle
        1, 2, 3  // second Triangle
    };

    unsigned int VBO, VAO, EBO;
    VertexArray va = VertexArray();
    VertexBuffer vb = VertexBuffer();
    IndexBuffer ib = IndexBuffer();

    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    va.Bind();

    vb.Bind();
    vb.SetData(vertices, sizeof(vertices) / sizeof(float));

    ib.Bind();
    ib.SetData(indices, sizeof(indices) / sizeof(unsigned int));

    va.SetAttribute(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind

    // glBindBuffer(GL_ARRAY_BUFFER, 0);
    vb.Unbind();

    // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    va.Unbind();

    spdlog::info("APPLICATION::App is running...");
    while (!m_Window->ShouldClose())
    {
        if (Input::IsKeyDown(KeyCode::KEY_ESCAPE))
        {
            m_Window->SetShouldClose();
        }

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.Bind();
        va.Bind();
        // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        // glDrawArrays(GL_TRIANGLES, 0, 6);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        m_Window->Update();
    }
    // glDeleteBuffers(1, &VBO);

    GLenum error = glGetError();
    if (error != GL_NO_ERROR)
    {
        spdlog::error("OpenGL Error: {}", error);
    }

    spdlog::info("APPLICATION::Exiting run loop");
}
