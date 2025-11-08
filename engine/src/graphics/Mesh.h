#pragma once
#include <vector>
#include <memory>
#include <glm/glm.hpp>

namespace TerrainEngine
{

    struct Vertex
    {
        glm::vec3 Position;
        glm::vec3 Color;
        glm::vec3 Normal;
        glm::vec2 TexCoord;
    };

    class Mesh
    {
    public:
        Mesh(const std::vector<Vertex> &vertices, const std::vector<unsigned int> &indices);
        ~Mesh() = default;

        unsigned int GetVAO() const { return this->vao; }
        unsigned int GetIndexCount() const { return this->indexCount; }

    private:
        unsigned int vao = 0, vbo = 0, ebo = 0;
        unsigned int indexCount = 0;
    };

}