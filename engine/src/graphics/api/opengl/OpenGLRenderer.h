#pragma once
#include "graphics/Renderer.h"
#include "graphics/drawable/Drawable.h"
#include "graphics/camera/Camera.h"
namespace TerrainEngine
{

    class OpenGLRenderer : public Renderer
    {
    public:
        OpenGLRenderer() {};
        ~OpenGLRenderer() = default;

        void Init() override;
        void Shutdown() override;
        void UpdateViewPort(int width, int height) override;
    };

}