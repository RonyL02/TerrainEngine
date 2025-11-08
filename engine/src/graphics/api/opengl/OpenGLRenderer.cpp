#include "OpenGLRenderer.h"
#include <GL/gl3w.h>
#include <spdlog/spdlog.h>
#include "../../../core/Application.h"
void TerrainEngine::OpenGLRenderer::Init()
{
    if (gl3wInit())
    {
        spdlog::error("failed to init gl3w");
        return;
    }

    spdlog::info("successfully initialized gl3w");
    spdlog::info("opengl version {}", reinterpret_cast<const char *>(glGetString(GL_VERSION)));

    glViewport(0, 0, Application::Get().GetWindow().GetWindowProps().width, Application::Get().GetWindow().GetWindowProps().height);
}

void TerrainEngine::OpenGLRenderer::Shutdown()
{
    GLenum error = glGetError();
    if (error != GL_NO_ERROR)
    {
        spdlog::error("OpenGL Error: {}", error);
    }
}
