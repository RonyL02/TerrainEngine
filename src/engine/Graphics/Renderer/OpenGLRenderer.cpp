#include "./Renderer.h"
#include "Renderer.h"

Ref<TE::Camera> TE::Renderer::Camera;

void TE::Renderer::SetCamera(Ref<TE::Camera> camera)
{
    Camera = camera;
}

void TE::Renderer::StartDraw()
{
    Camera->UpdateDirection();
}

void TE::Renderer::DrawCall(Mesh &mesh)
{
    glDrawElements(GL_TRIANGLES, mesh.GetIndicesCount(), GL_UNSIGNED_INT, 0);
}

void TE::Renderer::Draw(Model &model)
{

    model.GetMaterial().Bind();

    Shader &shader = model.GetMaterial().GetShader();
    shader.SetMat4f("projection", Camera->GetProjectionMatrix());
    shader.SetMat4f("view", Camera->GetViewMatrix());
    shader.SetMat4f("model", model.GetModelMatrix());

    model.GetMesh().Bind();

    DrawCall(model.GetMesh());

    model.GetMesh().Unbind();

    model.GetMaterial().Unbind();
}