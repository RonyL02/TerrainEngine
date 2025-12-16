#include "Renderer.h"
#include "api/opengl/OpenGLRenderer.h"
namespace TerrainEngine
{
    std::unique_ptr<Renderer> Renderer::Create()
    {
        return std::make_unique<OpenGLRenderer>();
    }

    void Renderer::Draw(const Entity &entity) const {
        entity.material->shader->Bind();
        entity.material->shader->SetMat4f("view", this->view);
        entity.material->shader->SetMat4f("model", entity.transform.GetMatrix());
        entity.material->shader->SetMat4f("projection", this->projection);
        if (entity.material->texture)
            entity.material->texture->Bind();

        entity.mesh->Draw();
    }

    void Renderer::StartDraw(const Camera &camera)
    {
        this->view = camera.GetViewMatrix();
        this->projection = camera.GetProjectionMatrix();
    }
}
