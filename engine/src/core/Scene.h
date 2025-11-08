#pragma once
#include "../graphics/camera/CameraController.h"
#include "../graphics/Drawable.h"
#include <vector>
namespace TerrainEngine
{
    class Scene
    {
    public:
        Scene();
        ~Scene() = default;
        void Update();
        void Render();
        void AddObject(const Drawable &object);

    private:
        CameraController cameraController;
        std::vector<Drawable> objects;
    };
}
