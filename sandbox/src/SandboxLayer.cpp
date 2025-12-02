#include "SandboxLayer.h"

using namespace TerrainEngine;

SandboxLayer::SandboxLayer() : TerrainEngine::Layer()
{
}

SandboxLayer::~SandboxLayer()
{
}

void SandboxLayer::Init()
{
    TE_INFO("start sandox");

    auto material = Material::Create(
        Texture::Create("res/textures/dabadi.png"));

    Drawable cube = {
        .transform = {
            .position = {0, 0, 0},
            .rotation = {0, 0, 0},
            .scale = {1, 1, 1}},
        .mesh = Mesh::CreateCube(),
        .material = material};

    Drawable cube2 = {
        .transform = {
            .position = {0, 0, 3},
            .rotation = {0, 0, 0},
            .scale = {1, 1, 1}},
        .mesh = Mesh::CreateCube(),
        .material = material};

    Drawable cube3 = Drawable{
        .transform = Transform{
            .position = {0, 0, -3},
            .rotation = {0, 0, 0},
            .scale = {5, 5, 5}},
        .mesh = Mesh::CreateCube(),
        .material = material};

    this->scene.AddObject(cube);
    this->scene.AddObject(cube2);
    this->scene.AddObject(cube3);
}

void SandboxLayer::Update()
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
        Application::Get().Exit();
    }

    scene.cameraController.Move();
    scene.cameraController.UpdateDirection();
}

void SandboxLayer::Close()
{
}
