#include "Scene.h"
#include "Application.h"
namespace TerrainEngine
{
    Scene::Scene()
        // : cameraController(1280.0f / 720.0f), objects({})
    
        : cameraController((float)Application::Get().GetWindow().GetWindowProps().width / (float)Application::Get().GetWindow().GetWindowProps().width), objects({})
    {
    }

    void Scene::Update()
    {
    }

    void Scene::Render()
    {
        Application::Get().GetRenderer().StartDraw(this->cameraController.GetCamera());

        for (auto &object : this->objects)
        {
            Application::Get().GetRenderer().Draw(object);
        }
    }

    void Scene::AddObject(const Drawable &object)
    {
        this->objects.push_back(object);
    }
}
