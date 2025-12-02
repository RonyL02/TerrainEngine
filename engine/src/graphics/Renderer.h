#pragma once
#include <memory>
#include "drawable/Drawable.h"
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
        void StartDraw(const Camera &camera);
        void Draw(Drawable &drawable);
        virtual void Shutdown() = 0;
        static std::unique_ptr<Renderer> Create();

    private:
        glm::mat4 view;
        glm::mat4 projection;
    };

}