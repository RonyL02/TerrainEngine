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
            this->OnRender();
            this->scene.Render();
        }
        
        virtual void OnUpdate() {}
        virtual void OnRender() {}


    protected:
        Scene scene;
    };

}
