#include "SandboxLayer.h"

using namespace TerrainEngine;

SandboxLayer::SandboxLayer() : TerrainEngine::Layer()
{
    TE_INFO("start sandox");

    auto material = Material::Create(
        Texture::Create("res/textures/dabadi.png"));

    voxelWorld.InitLimitedWorld(2, 10,material);
}

SandboxLayer::~SandboxLayer()
{
    TE_INFO("closing sandbox layer");
}

void SandboxLayer::OnUpdate()
{
    if (Input::IsKeyPressed(KeyCodes::KEY_C))
    {
        Application::Get().GetWindow().DisableCursor(true);
    }
    if (Input::IsKeyPressed(KeyCodes::KEY_V))
    {
        Application::Get().GetWindow().DisableCursor(false);
    }
    if (Input::IsKeyPressed(KeyCodes::KEY_ESCAPE))
    {
        TE_INFO("Escape pressed - closing application");
        Application::Get().Exit();
    }

    scene.cameraController.Move();
    scene.cameraController.UpdateDirection();
}

void SandboxLayer::OnRender()
{
    voxelWorld.Render();
}
