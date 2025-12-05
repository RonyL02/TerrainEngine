#pragma once
#include "scene/Scene.h"

namespace TerrainEngine
{
    class Layer
    {
    public:
        Layer() = default;
        virtual ~Layer() = default;
        
        void Update()
        {
            this->OnUpdate();
            this->scene.Update();
        }
        
        void Render()
        {
            this->scene.Render();
        }
        
        virtual void OnUpdate() {}

    protected:
        Scene scene;
    };

}
