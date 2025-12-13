#pragma once
#include "TerrainEngine.h"

using namespace TerrainEngine;

class MovableObject : public TerrainEngine::Entity
{
public:
    using Entity::Entity;
    float speed = 4;
    void Update() override
    {
        if (Input::IsKeyDown(KeyCodes::KEY_P))
        {
            transform.position += glm::vec3{speed, 1, 1} * Time::DeltaTime();
        }

        if (Input::IsKeyDown(KeyCodes::KEY_L))
        {
            transform.position -= glm::vec3{speed, 1, 1} * Time::DeltaTime();
        }
    }
};

class SandboxLayer : public TerrainEngine::Layer
{
public:
    SandboxLayer();
    ~SandboxLayer();
    void OnUpdate() override;
    void OnRender() override;

private:
    VoxelWorld voxelWorld;
};
