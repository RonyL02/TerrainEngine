#pragma once
#include "graphics/camera/CameraController.h"
#include "graphics/drawable/Drawable.h"
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

        CameraController cameraController;

    private:
        std::vector<Drawable> objects;
    };
}
