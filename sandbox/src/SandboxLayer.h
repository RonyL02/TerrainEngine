#pragma once
#include "TerrainEngine.h"

class SandboxLayer : public TerrainEngine::Layer
{
public:
    SandboxLayer();
    ~SandboxLayer();

    void Init() override;
    void Update() override;
    void Close() override;

private:
    TerrainEngine::Drawable a;
};
