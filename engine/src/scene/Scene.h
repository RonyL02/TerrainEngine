#pragma once
#include "CameraController.h"
#include <vector>
#include <memory>
#include "scene/entity/Entity.h"

namespace TerrainEngine {
    class Scene {
    public:
        Scene();

        ~Scene();

        void Update();

        void Render();

        void AddObject(Entity *entity);

        CameraController cameraController;

    private:
        std::vector<std::shared_ptr<Entity> > entities;
    };
}
