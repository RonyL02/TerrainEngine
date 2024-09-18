#include "Application.h"
#include <spdlog/spdlog.h>
#include "../Graphics/OpenGL/Utils.h"
#include <GLFW/glfw3.h>
#include "Window/Window.h"
#include "Input.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../Entities/Camera.h"
#include "../Entities/Material.h"

TE::Application::Application(int width, int height, const char *title)
{
    m_Window = Window::InitializeWindow(width, height, title);
}

void TE::Application::Run()
{
    glEnable(GL_DEPTH_TEST);

    Material material = Material(new Shader("res/shaders/vertex.glsl", "res/shaders/fragment.glsl"),
                                 new Texture("res/textures/dabadi.png")

    );
    float vertices[] = {
        -0.5f, -0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
        0.5f, -0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
        0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
        -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.0f, 0.0f,

        -0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
        -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.0f, 0.0f,

        -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

        0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
        0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
        0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        -0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.0f, 1.0f,

        -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
        0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.0f, 1.0f};
    // world space positions of our cubes
    glm::vec3 cubePositions[] = {
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(2.0f, 5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3(2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f, 3.0f, -7.5f),
        glm::vec3(1.3f, -2.0f, -2.5f),
        glm::vec3(1.5f, 2.0f, -2.5f),
        glm::vec3(1.5f, 0.2f, -1.5f),
        glm::vec3(-1.3f, 1.0f, -1.5f)};

    unsigned int indices[] = {
        // note that we start from 0!
        0, 1, 3, // first Triangle
        1, 2, 3  // second Triangle
    };

    VertexArray va = VertexArray();
    VertexBuffer vb = VertexBuffer();
    // IndexBuffer ib = IndexBuffer();

    va.Bind();

    vb.Bind();
    vb.SetData(vertices, sizeof(vertices) / sizeof(float));

    // ib.Bind();
    // ib.SetData(indices, sizeof(indices) / sizeof(unsigned int));

    va.SetAttribute(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
    va.SetAttribute(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(3 * sizeof(float)));
    va.SetAttribute(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(6 * sizeof(float)));

    vb.Unbind();
    va.Unbind();

    spdlog::info("APPLICATION::App is running...");

    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

    Camera camera = Camera({0, 0, 3}, {0, 0, -1});

    glm::mat4 projection = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(45.0f), (float)m_Window->GetWidth() / (float)m_Window->GetHeight(), 0.1f, 100.0f);
    m_Window->DisableCursor(true);
    while (!m_Window->ShouldClose())
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        float ms = 7.f * deltaTime;

        if (Input::GetMouseOffset().first != 0 || Input::GetMouseOffset().second != 0)
        {
            camera.UpdateDirection(Input::GetMouseOffset().first * ms,
                                   Input::GetMouseOffset().second * ms);
        }

        if (Input::IsKeyDown(KeyCode::KEY_ESCAPE))
        {
            m_Window->SetShouldClose();
        }

        material.Bind();
        material.GetShader()->SetMat4f("projection", projection);
        glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        model = glm::translate(model, {0, 0, 0});
        float angle = 0;
        model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
        material.GetShader()->SetMat4f("model", model);

        const float cameraSpeed = 1.75f * deltaTime;
        if (Input::IsKeyDown(KeyCode::KEY_W))
            camera.Move(cameraSpeed * camera.GetFront());
        if (Input::IsKeyDown(KeyCode::KEY_S))
            camera.Move(-cameraSpeed * camera.GetFront());
        if (Input::IsKeyDown(KeyCode::KEY_A))
            camera.Move(-cameraSpeed * camera.GetRight());
        if (Input::IsKeyDown(KeyCode::KEY_D))
            camera.Move(cameraSpeed * camera.GetRight());
        if (Input::IsKeyDown(KeyCode::KEY_SPACE))
            camera.Move(cameraSpeed * camera.GetUp());
        if (Input::IsKeyDown(KeyCode::KEY_LEFT_SHIFT))
            camera.Move(-cameraSpeed * camera.GetUp());
        // retrieve the matrix uniform locations

        material.GetShader()->SetMat4f("view", camera.GetViewMatrix());

        // pass them to the shaders (3 different ways)
        // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.

        va.Bind();

        // for (unsigned int i = 0; i < 10; i++)
        {
            // calculate the model matrix for each object and pass it to shader before drawing

            glDrawArrays(GL_TRIANGLES, 0, 36);
        }

        material.Unbind();
        // glDrawArrays(GL_TRIANGLES, 0, 3);
        // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        Input::SetMouseOffset(0, 0);
        m_Window->Update();
    }

    spdlog::info("APPLICATION::Exiting run loop");

    m_Window->Destroy();
}
