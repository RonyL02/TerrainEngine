#pragma once
#include "../../Renderer.h"

namespace TerrainEngine
{

    class OpenGLRenderer : public Renderer
    {
    public:
        OpenGLRenderer() {};
        ~OpenGLRenderer() = default;

        void Init() override;
    };

}