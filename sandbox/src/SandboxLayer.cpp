#include "SandboxLayer.h"
#include "spdlog/spdlog.h"
#include <glm/ext.hpp>
SandboxLayer::SandboxLayer() : TerrainEngine::Layer()
{
}

SandboxLayer::~SandboxLayer()
{
}

void SandboxLayer::Init()
{
    spdlog::info("start sandox");

    auto cubeMesh = std::make_shared<TerrainEngine::Mesh>(TerrainEngine::Mesh::Cube());
    auto cubeMaterial = std::make_shared<TerrainEngine::Material>();
    cubeMaterial->Shader = std::make_shared<TerrainEngine::Shader>(RESOURCE_PATH + "/shaders/vertex.glsl", RESOURCE_PATH + "/shaders/fragment.glsl");
    cubeMaterial->Color = glm::vec4(1.0f, 0.5f, 0.3f, 1.0f);
    cubeMaterial->Diffuse = std::make_shared<TerrainEngine::Texture>(RESOURCE_PATH + "/textures/dabadi.png");

    TerrainEngine::Drawable cube = TerrainEngine::Drawable{
        .Mesh = cubeMesh,
        .Material = cubeMaterial,
        .Position = {0, 0, 3},
        .Rotation = {1, 1, 1},
        .Scale = {1, 1, 1}};

    TerrainEngine::Drawable cube2 = TerrainEngine::Drawable{
        .Mesh = cubeMesh,
        .Material = cubeMaterial,
        .Position = {0, 0, -3},
        .Rotation = {1, 1, 1},
        .Scale = {5, 5, 5}};

    this->scene.AddObject(cube);
    this->scene.AddObject(cube2);
}

void SandboxLayer::Update()
{
    if (TerrainEngine::Input::IsKeyPressed(TerrainEngine::KeyCodes::KEY_C))
    {
        TerrainEngine::Application::Get().GetWindow().DisableCursor(true);
    }
    if (TerrainEngine::Input::IsKeyPressed(TerrainEngine::KeyCodes::KEY_V))
    {
        TerrainEngine::Application::Get().GetWindow().DisableCursor(false);
    }
    if (TerrainEngine::Input::IsKeyPressed(TerrainEngine::KeyCodes::KEY_ESCAPE))
    {
        TerrainEngine::Application::Get().Exit();
    }

    scene.cameraController.Move();
    scene.cameraController.UpdateDirection();
}

void SandboxLayer::Close()
{
}
