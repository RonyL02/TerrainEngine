#pragma once

namespace TerrainEngine {
  class Application {
  public:
    Application();
    virtual ~Application();

    void Run();

  protected:
    virtual void OnInit() {}
    virtual void OnUpdate(float deltaTime) {}
    virtual void OnRender() {}
    virtual void OnShutdown() {}

  private:
    bool m_Running;
    void Render();
  };
}