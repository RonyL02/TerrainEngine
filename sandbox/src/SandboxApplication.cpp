#include "SandboxApplication.h"
#include <TerrainEngine/Renderer.h>
#include <TerrainEngine/TerrainEngine.h>
#include <print>

using namespace TerrainEngine;

Sandbox::SandboxApplication::SandboxApplication() : Application() {
  std::println("constructor called");
}

Sandbox::SandboxApplication::~SandboxApplication() {
  std::println("dtor called");
}

void Sandbox::SandboxApplication::OnInit() {
  std::println("oninit called");
  Renderer::SetCamera({
      .position = {1, 1, 1},
      .target = {0, 0, 0},
      .up = {0, 1, 0},
      .fov = 45,
  });
}

void Sandbox::SandboxApplication::OnUpdate(float deltaTime) {
  //   std::println("onupdate called");
}

void Sandbox::SandboxApplication::OnRender() {
  Renderer::SetClearColor({100, 100, 100});
  Renderer::DrawCubeShape({0, 0, 1}, 4, {255, 0, 0});
}

void Sandbox::SandboxApplication::OnShutdown() {
  std::println("onshutdown called");
}

void TerrainEngine::StartApplication() {
  std::println("entry point");
  auto app = Sandbox::SandboxApplication();
  app.Run();
}
