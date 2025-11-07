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
#include "../Entities/Mesh.h"

TE::Application::Application(int width, int height, const char *title)
{
    m_Window = Window::InitializeWindow(width, height, title);
}

void TE::Application::Run()
{
    glEnable(GL_DEPTH_TEST);
    // glEnable(GL_CULL_FACE);
    // glCullFace(GL_BACK);
    // glFrontFace(GL_CCW);
    Material material = Material(new Shader("engine/res/shaders/vertex.glsl", "engine/res/shaders/fragment.glsl"),
                                 new Texture("engine/res/textures/dabadi.png")

    );

    float vertices[] = {
        -0.5f, -0.5f, 0, 1, 1, 1, 0, 0,
        0.5f, -0.5f, 0, 1, 1, 1, 1, 0,
        0, 0.5f, 0, 1, 1, 1, 1, 1};
    int numOfVertices = sizeof(vertices) / sizeof(float);

    unsigned int indices[] = {
        2, 1, 0};

    int numOfIndices = sizeof(indices) / sizeof(unsigned int);

    Mesh mesh = Mesh(vertices, numOfVertices, indices, numOfIndices);

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

        // for (unsigned int i = 0; i < 10; i++)
        {
            // calculate the model matrix for each object and pass it to shader before drawing

            mesh.Draw();
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
