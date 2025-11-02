#include "Model.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <spdlog/spdlog.h>
TE::Model::~Model()
{
    spdlog::info("destroy model");
}

void TE::Model::Update()
{
}

void TE::Model::Render()
{
    m_Material.Bind();
    m_Mesh.Draw();
    m_Material.Unbind();
}

glm::mat4 TE::Model::GetModelMatrix()
{
    glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    model = glm::translate(model, m_Position);
    model = glm::rotate(model, glm::radians(m_Rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(m_Rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(m_Rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, m_Scale);
    return model;
}

TE::Material &TE::Model::GetMaterial()
{
    return m_Material;
}

TE::Mesh &TE::Model::GetMesh()
{
    return m_Mesh;
}

void TE::Model::Init()
{
}
