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
    cubeMaterial->Shader = std::make_shared<TerrainEngine::Shader>("engine/res/shaders/vertex.glsl", "engine/res/shaders/fragment.glsl");
    cubeMaterial->Color = glm::vec4(1.0f, 0.5f, 0.3f, 1.0f);
    cubeMaterial->Diffuse = std::make_shared<TerrainEngine::Texture>("engine/res/textures/dabadi.png");

    TerrainEngine::Drawable cube = TerrainEngine::Drawable{
        .Mesh = cubeMesh,
        .Material = cubeMaterial,
        .Position = {0, 0, -3},
        .Rotation = {1, 1, 1},
        .Scale = {1, 1, 1}};

    TerrainEngine::Drawable cube2 = TerrainEngine::Drawable{
        .Mesh = cubeMesh,
        .Material = cubeMaterial,
        .Position = {2, 0, -3},
        .Rotation = {1, 1, 1},
        .Scale = {1, 1, 1}};

    this->scene.AddObject(cube);
    this->scene.AddObject(cube2);

}

void SandboxLayer::Update()
{
}

void SandboxLayer::Close()
{
}
