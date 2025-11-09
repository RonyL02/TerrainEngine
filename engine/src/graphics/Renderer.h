#pragma once
#include <memory>
#include "Drawable.h"
#include "camera/Camera.h"
namespace TerrainEngine
{

    class Renderer
    {
    public:
        Renderer() = default;
        virtual ~Renderer() = default;
        virtual void UpdateViewPort(int width, int height) = 0;
        virtual void Init() = 0;
        virtual void StartDraw(const Camera &camera) = 0;
        virtual void Shutdown() = 0;
        virtual void Draw(Drawable &drawable) = 0;
        static std::unique_ptr<Renderer> Create();
    };

}