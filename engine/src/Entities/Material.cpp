#include "Material.h"
#include <spdlog/spdlog.h>
#include <utility>
TE::Material::Material()
    : m_Shader(new Shader("res/shaders/vertex.glsl", "res/shaders/fragment.glsl"))
{
}

TE::Material::Material(Shader *shader, Texture *texture)
    : m_Shader(shader), m_Texture(texture)
{
}

TE::Material::~Material()
{
    delete m_Shader;
    delete m_Texture.value();
    spdlog::info("destroy material");
}

void TE::Material::Bind()
{
    if (m_Texture.has_value())
    {
        m_Texture.value()->Bind();
    }

    m_Shader->Bind();
}

void TE::Material::Unbind()
{
    m_Shader->Unbind();

    if (m_Texture.has_value())
    {
        m_Texture.value()->Bind();
    }
}

TE::Shader* TE::Material::GetShader()
{
    return m_Shader;
}
