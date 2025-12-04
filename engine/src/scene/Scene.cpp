#include "Scene.h"
#include "core/Application.h"
#include "core/Log.h"

namespace TerrainEngine
{
    Scene::Scene()
        : cameraController((float)Application::Get().GetWindow().GetWindowProps().width / (float)Application::Get().GetWindow().GetWindowProps().width), entities({})
    {
    }

    Scene::~Scene()
    {
        TE_INFO("scene destroyed, clearing {} entities", entities.size());
        entities.clear();
    }

    void Scene::Update()
    {
        for (auto &entity : this->entities)
        {
            entity->Update();
        }
    }

    void Scene::Render()
    {
        Application::Get().GetRenderer().StartDraw(this->cameraController.GetCamera());

        for (auto &entity : this->entities)
        {
            Application::Get().GetRenderer().Draw(*entity);
        }
    }

    void Scene::AddObject(Entity *entity)
    {
        this->entities.push_back(std::shared_ptr<Entity>(entity));
    }
}
