#include "OpenGLRenderer.h"
#include <GL/gl3w.h>
#include "core/Application.h"
#include "core/Log.h"


namespace TerrainEngine
{

    OpenGLRenderer::OpenGLRenderer()
    {
        if (gl3wInit())
        {
            TE_ERROR("failed to init gl3w");
            return;
        }

        TE_INFO("successfully initialized gl3w");
        TE_INFO("opengl version {}", reinterpret_cast<const char *>(glGetString(GL_VERSION)));

        glEnable(GL_DEPTH_TEST);
        // glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
        glFrontFace(GL_CCW);
    }

    OpenGLRenderer::~OpenGLRenderer()
    {
        GLenum error = glGetError();
        if (error != GL_NO_ERROR)
        {
            TE_ERROR("OpenGL Error: {}", error);
        }
    }

    
    void OpenGLRenderer::UpdateViewPort(int width, int height)
    {
        glViewport(0, 0, width, height);
    }
}