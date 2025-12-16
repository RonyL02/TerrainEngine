#include "SandboxLayer.h"

using namespace TerrainEngine;

SandboxLayer::SandboxLayer() : Layer(),
                               voxelChunkManager(VoxelChunkManagerConfig{
                                   .chunkSize = 16,
                                   .renderDistance = 100.0f,
                                   .worldDimensions = {2, 2, 2},
                                   .material = Material::Create(Texture::Create("res/textures/dabadi.png"))
                               }) {
    TE_INFO("start sandbox");
    voxelChunkManager.LoadChunks(scene.cameraController.GetCamera().GetPosition());
    voxelChunkManager.UpdateChunkEntities();
}

SandboxLayer::~SandboxLayer() {
    TE_INFO("closing sandbox layer");
}

void SandboxLayer::OnUpdate() {
    if (Input::IsKeyPressed(KeyCodes::KEY_C)) {
        Application::Get().GetWindow().DisableCursor(true);
    }
    if (Input::IsKeyPressed(KeyCodes::KEY_V)) {
        Application::Get().GetWindow().DisableCursor(false);
    }
    if (Input::IsKeyPressed(KeyCodes::KEY_ESCAPE)) {
        TE_INFO("Escape pressed - closing application");
        Application::Get().Exit();
    }

    scene.cameraController.Move();
    scene.cameraController.UpdateDirection();
}

void SandboxLayer::OnRender() {
    voxelChunkManager.Render();
}
