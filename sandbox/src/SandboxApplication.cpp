#include "SandboxApplication.h"
#include <TerrainEngine/TerrainEngine.h>
#include <print>
Sandbox::SandboxApplication::SandboxApplication() : Application() {
  std::println("constructor called");
}

Sandbox::SandboxApplication::~SandboxApplication() {
  std::println("dtor called");
}

void Sandbox::SandboxApplication::OnInit() { std::println("oninit called"); }

void Sandbox::SandboxApplication::OnUpdate(float deltaTime) {
  //   std::println("onupdate called");
}

void Sandbox::SandboxApplication::OnRender() {
  //   std::println("onrender called");
}

void Sandbox::SandboxApplication::OnShutdown() {
  std::println("onshutdown called");
}

void TerrainEngine::StartApplication() {
  std::println("entry point");
  auto app = Sandbox::SandboxApplication();
  app.Run();
}
