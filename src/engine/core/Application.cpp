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
#include "../Entities/Model.h"
#include "../Graphics/Renderer/Renderer.h"
#include "Time.h"

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

    Shader shader = Shader("res/shaders/vertex.glsl", "res/shaders/fragment.glsl");
    Texture texture = Texture("res/textures/dabadi.png");
    Material material = Material(shader, texture);

    float vertices[] = {
        -0.5f, -0.5f, 0, 0, 0, 0, 0, 0,
        0.5f, -0.5f, 0, 0, 0, 0, 1, 0,
        0, 0.5f, 0, 0, 0, 0, 1, 1};
    int numOfVertices = sizeof(vertices) / sizeof(float);

    unsigned int indices[] = {
        0, 1, 2};

    int numOfIndices = sizeof(indices) / sizeof(unsigned int);

    Mesh mesh = Mesh(vertices, numOfVertices, indices, numOfIndices);

    Model model = Model({0, 0, 0}, {0, 0, 0}, {1, 1, 1}, mesh, material);

    Model model2 = Model({2, 0, 0}, {0, 0, 0}, {1, 1, 1}, mesh, material);

    Model model3 = Model({1, 1, 0}, {0, 0, 0}, {1, 1, 1}, mesh, material);

    spdlog::info("APPLICATION::App is running...");

    Ref<Camera> camera = MakeRef<Camera>(glm::vec3{0, 0, 3}, glm::vec3{0, 0, -1});

    Renderer::SetCamera(camera);

    m_Window->DisableCursor(true);

    while (!m_Window->ShouldClose())
    {
        Time::UpdateDeltaTime();
        if (Input::IsKeyDown(KeyCode::KEY_ESCAPE))
        {
            m_Window->SetShouldClose();
        }

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        const float cameraSpeed = 1.75f * Time::DeltaTime();
        if (Input::IsKeyDown(KeyCode::KEY_W))
            camera->Move(-cameraSpeed * glm::vec3(0,0,1));
        if (Input::IsKeyDown(KeyCode::KEY_S))
            camera->Move(cameraSpeed * glm::vec3(0,0,1));
        if (Input::IsKeyDown(KeyCode::KEY_A))
            camera->Move(-cameraSpeed * glm::vec3(1,0,0));
        if (Input::IsKeyDown(KeyCode::KEY_D))
            camera->Move(cameraSpeed * glm::vec3(1,0,0));
        if (Input::IsKeyDown(KeyCode::KEY_SPACE))
            camera->Move(cameraSpeed * glm::vec3(0,1,0));
        if (Input::IsKeyDown(KeyCode::KEY_LEFT_SHIFT))
            camera->Move(-cameraSpeed * glm::vec3(0,1,0));

        Renderer::StartDraw();

        Renderer::Draw(model);
        Renderer::Draw(model2);
        Renderer::Draw(model3);

        Input::SetMouseOffset(0, 0);
        m_Window->Update();
    }

    spdlog::info("APPLICATION::Exiting run loop");

    m_Window->Destroy();
}
