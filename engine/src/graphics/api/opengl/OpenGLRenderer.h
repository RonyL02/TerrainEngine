#pragma once
#include "graphics/Renderer.h"
namespace TerrainEngine
{

    class OpenGLRenderer : public Renderer
    {
    public:
        OpenGLRenderer();
        ~OpenGLRenderer() override;

        void UpdateViewPort(int width, int height) override;
    };

}