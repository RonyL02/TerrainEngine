#pragma once
#include <memory>
#include "scene/entity/Entity.h"
#include "camera/Camera.h"
namespace TerrainEngine
{

    class Renderer
    {
    public:
        Renderer() = default;
        virtual ~Renderer() = default;
        virtual void UpdateViewPort(int width, int height) = 0;
        void StartDraw(const Camera &camera);
        void Draw(Entity &entity);
        static std::unique_ptr<Renderer> Create();

    private:
        glm::mat4 view;
        glm::mat4 projection;
    };

}