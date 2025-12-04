#pragma once
#include "scene/Scene.h"

namespace TerrainEngine
{
    class Layer
    {
    public:
        Layer() = default;
        virtual ~Layer() = default;
        virtual void Init() = 0;
        virtual void Update() = 0;
        void Render();
        void UpdateScene();
        virtual void Close() = 0;

    protected:
        Scene scene;
    };

}
