#pragma once
#include <TerrainEngine/Camera.h>
#include <TerrainEngine/CameraController.h>
#include <TerrainEngine/Renderer.h>
#include <TerrainEngine/Scene.h>

namespace Sandbox {
  class WorldScene : public TerrainEngine::Scene {
  public:
    void OnAttach() override {
      m_CameraController.GetCamera().SetPosition({0.0f, 2.0f, 5.0f});
      m_CameraController.SetMouseControlEnabled(true);
    }

    void OnUpdate(float dt) override {
      m_CameraController.Update(dt);
    }

    void OnRender() override {
      TerrainEngine::Renderer::Begin3D(m_CameraController.GetCamera());
      DrawCube({0.0f, 0.0f, 0.0f}, 4.0f, 4.0f, 4.0f, RED);
      TerrainEngine::Renderer::End3D();
    }

  private:
    TerrainEngine::CameraController m_CameraController;
  };
}