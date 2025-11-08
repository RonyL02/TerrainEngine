#include "OpenGLRenderer.h"
#include <GL/gl3w.h>
#include <spdlog/spdlog.h>
void TerrainEngine::OpenGLRenderer::Init()
{
    if (gl3wInit())
    {
        spdlog::error("failed to init gl3w");
        return;
    }

    spdlog::info("successfully initialized gl3w");
    spdlog::info("opengl version {}", reinterpret_cast<const char *>(glGetString(GL_VERSION)));
}