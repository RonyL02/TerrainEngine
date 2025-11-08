#pragma once
#include "TerrainEngine.h"

class SandboxLayer : public TerrainEngine::Layer
{
public:
    SandboxLayer();
    ~SandboxLayer();

    void Init() override;
    void Render() override;
    void Update() override;
    void Close() override;
};
