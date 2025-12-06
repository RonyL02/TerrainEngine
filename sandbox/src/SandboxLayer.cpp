#include "SandboxLayer.h"

using namespace TerrainEngine;

SandboxLayer::SandboxLayer() : TerrainEngine::Layer()
{
    TE_INFO("start sandox");

    auto material = Material::Create(
        Texture::Create("res/textures/dabadi.png"));
    auto cubeMesh = Mesh::CreateCube();

    Chunk chunk = Chunk();

    auto chunkMesh = chunk.GenerateMesh();

    auto chunkEntity = new Entity(
        Transform{
            .position = {0, 0, 0},
            .rotation = {0, 0, 0},
            .scale = {1, 1, 1}},
        chunkMesh,
        material);

    scene.AddObject(chunkEntity);

    // auto cube = new Entity(
    //     Transform{
    //         .position = {0, 0, 0},
    //         .rotation = {0, 0, 0},
    //         .scale = {1, 1, 1}},
    //     cubeMesh,
    //     material);

    // auto cube2 = new MovableObject(
    //     Transform{
    //         .position = {0, 0, 3},
    //         .rotation = {0, 0, 0},
    //         .scale = {1, 1, 1}},
    //     cubeMesh,
    //     material);

    // auto cube3 = new Entity(
    //     Transform{
    //         .position = {0, 0, -3},
    //         .rotation = {0, 0, 0},
    //         .scale = {1, 1, 1}},
    //     Mesh::CreateCube(), material);

    // this->scene.AddObject(cube);
    // this->scene.AddObject(cube2);
    // this->scene.AddObject(cube3);
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
