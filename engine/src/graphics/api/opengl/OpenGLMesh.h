#pragma once
#include <vector>
#include <memory>
#include <glm/glm.hpp>
#include "graphics/Mesh.h"

namespace TerrainEngine
{
    class OpenGLMesh : public Mesh
    {
    public:
        OpenGLMesh(const std::vector<Vertex> &vertices, const std::vector<unsigned int> &indices);
        ~OpenGLMesh();

        void Draw() override;

    private:
        unsigned int vao = 0, vbo = 0, ebo = 0;
        unsigned int indexCount = 0;
    };

}