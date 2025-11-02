#pragma once
#include <glm/glm.hpp>
#include "./Mesh.h"
#include "./Material.h"

namespace TE
{
    class Model
    {
    public:
        Model(
            glm::vec3 position,
            glm::vec3 rotation,
            glm::vec3 scale,
            Mesh &mesh,
            Material &material)
            : m_Position(position),
              m_Rotation(rotation),
              m_Scale(scale),
              m_Mesh(mesh),
              m_Material(material)
        {
            Init();
        }

        ~Model();

        void Update();
        void Render();
        glm::mat4 GetModelMatrix();

        Material &GetMaterial();
        Mesh &GetMesh();

    private:
        void Init();

        glm::vec3 m_Position;
        glm::vec3 m_Rotation;
        glm::vec3 m_Scale;
        Mesh &m_Mesh;
        Material &m_Material;
    };
}