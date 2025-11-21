#include "Renderer.h"
#include "api/opengl/OpenGLRenderer.h"
namespace TerrainEngine
{
    std::unique_ptr<Renderer> Renderer::Create()
    {
        return std::make_unique<OpenGLRenderer>();
    }
} 
