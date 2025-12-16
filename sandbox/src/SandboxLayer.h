#pragma once
#include "TerrainEngine.h"

using namespace TerrainEngine;

class MovableObject : public Entity {
public:
    using Entity::Entity;
    float speed = 4;

    void Update() override {
        if (Input::IsKeyDown(KeyCodes::KEY_P)) {
            transform.position += glm::vec3{speed, 1, 1} * Time::DeltaTime();
        }

        if (Input::IsKeyDown(KeyCodes::KEY_L)) {
            transform.position -= glm::vec3{speed, 1, 1} * Time::DeltaTime();
        }
    }
};

class SandboxLayer : public Layer {
public:
    SandboxLayer();

    ~SandboxLayer() override;

    void OnUpdate() override;

    void OnRender() override;

private:
    VoxelChunkManager voxelChunkManager;
};
