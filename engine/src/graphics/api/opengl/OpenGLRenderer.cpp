#include "OpenGLRenderer.h"
#include <GL/gl3w.h>
#include <spdlog/spdlog.h>
#include "../../../core/Application.h"

namespace TerrainEngine
{

    void OpenGLRenderer::Init()
    {
        if (gl3wInit())
        {
            spdlog::error("failed to init gl3w");
            return;
        }

        spdlog::info("successfully initialized gl3w");
        spdlog::info("opengl version {}", reinterpret_cast<const char *>(glGetString(GL_VERSION)));

        this->UpdateViewPort(Application::Get().GetWindow().GetWindowProps().width, Application::Get().GetWindow().GetWindowProps().height);
    }

    void OpenGLRenderer::Shutdown()
    {
        GLenum error = glGetError();
        if (error != GL_NO_ERROR)
        {
            spdlog::error("OpenGL Error: {}", error);
        }
    }

    void OpenGLRenderer::Draw(Drawable &drawable)
    {
        drawable.Material->Shader->Bind();
        drawable.Material->Shader->SetMat4f("view", this->view);
        drawable.Material->Shader->SetMat4f("model", drawable.GetModelMatrix());
        drawable.Material->Shader->SetMat4f("projection", this->projection);
        if (drawable.Material->Diffuse)
            drawable.Material->Diffuse->Bind();

        glBindVertexArray(drawable.Mesh->GetVAO());
        glDrawElements(GL_TRIANGLES, drawable.Mesh->GetIndexCount(), GL_UNSIGNED_INT, nullptr);
    }

    void OpenGLRenderer::StartDraw(const Camera &camera)
    {
        this->view = camera.GetViewMatrix();
        this->projection = camera.GetProjectionMatrix();
    }
    void OpenGLRenderer::UpdateViewPort(int width, int height)
    {
        glViewport(0, 0, width, height);
    }
}