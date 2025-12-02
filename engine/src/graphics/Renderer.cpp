#include "Renderer.h"
#include "api/opengl/OpenGLRenderer.h"
namespace TerrainEngine
{
    std::unique_ptr<Renderer> Renderer::Create()
    {
        return std::make_unique<OpenGLRenderer>();
    }

    void Renderer::Draw(Drawable &drawable)
    {
        drawable.material->shader->Bind();
        drawable.material->shader->SetMat4f("view", this->view);
        drawable.material->shader->SetMat4f("model", drawable.transform.GetMatrix());
        drawable.material->shader->SetMat4f("projection", this->projection);
        if (drawable.material->texture)
            drawable.material->texture->Bind();

        drawable.mesh->Draw();
    }

    void Renderer::StartDraw(const Camera &camera)
    {
        this->view = camera.GetViewMatrix();
        this->projection = camera.GetProjectionMatrix();
    }
}
