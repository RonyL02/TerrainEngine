#pragma once
#include <vector>
#include <glm/glm.hpp>
#include <memory>
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
        virtual ~Mesh() = default;
        virtual void Draw() = 0;

        static std::shared_ptr<Mesh> Create(const std::vector<Vertex> &vertices, const std::vector<unsigned int> &indices);
        static std::shared_ptr<Mesh> CreateCube();

    private:
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
    };

}