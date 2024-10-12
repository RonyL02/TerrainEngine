#include "Material.h"
#include <spdlog/spdlog.h>
#include <utility>

TE::Material::Material()
    : m_Shader(MakeBox<Shader>("res/shaders/vertex.glsl", "res/shaders/fragment.glsl")), m_Texture(nullptr)
{
}

TE::Material::Material(Shader* shader, Texture* texture)
    : m_Shader(shader), m_Texture(texture)
{
}

TE::Material::~Material()
{
    spdlog::info("destroy material");
}

void TE::Material::Bind()
{
    if (m_Texture.get())
    {
        m_Texture->Bind();
    }
    m_Shader->Bind();
}

void TE::Material::Unbind()
{
    m_Shader->Unbind();

    if (m_Texture.get())
    {
        m_Texture->Unbind();
    }
}

TE::Shader *TE::Material::GetShader()
{
    return m_Shader.get();
}