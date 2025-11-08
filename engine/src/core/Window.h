#pragma once
#include <memory>
#include <string>

namespace TerrainEngine
{

  struct WindowProps
  {
    std::string title;
    int width;
    int height;
  };

  class Window
  {
  public:
    Window(WindowProps windowProps) : windowProps(windowProps) {}
    virtual ~Window() = default;

    virtual void Init() = 0;
    virtual void Close() = 0;
    virtual bool ShouldClose() = 0;
    virtual void PollEvents() = 0;
    virtual void SwapBuffers() = 0;

    static std::unique_ptr<Window> Create(WindowProps windowProps);

    WindowProps GetWindowProps() const
    {
      return this->windowProps;
    }

  protected:
    WindowProps windowProps;
  };
}
