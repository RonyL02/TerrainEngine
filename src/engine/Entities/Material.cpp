#include "Material.h"
#include <spdlog/spdlog.h>
#include <utility>

TE::Material::Material(Shader &shader, Texture &texture)
    : m_Shader(shader), m_Texture(texture)
{
}

TE::Material::~Material()
{
    spdlog::info("destroy material");
}

void TE::Material::Bind()
{
    m_Texture.Bind();
    m_Shader.Bind();
}

void TE::Material::Unbind()
{
    m_Shader.Unbind();
    m_Texture.Unbind();
}

TE::Shader &TE::Material::GetShader()
{
    return m_Shader;
}