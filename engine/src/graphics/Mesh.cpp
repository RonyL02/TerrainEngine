#include "Mesh.h"
#include <GL/gl3w.h>
namespace TerrainEngine
{
    Mesh::Mesh(const std::vector<Vertex> &vertices, const std::vector<unsigned int> &indices)
    {
        this->indexCount = (unsigned int)indices.size();

        glGenVertexArrays(1, &this->vao);
        glGenBuffers(1, &this->vbo);
        glGenBuffers(1, &this->ebo);

        glBindVertexArray(this->vao);

        // Vertex buffer
        glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

        // Index buffer
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

        // Vertex layout
        glEnableVertexAttribArray(0); // position
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, Position));

        glEnableVertexAttribArray(1); // color
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, Color));

        glEnableVertexAttribArray(2); // normal
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, Normal));

        glEnableVertexAttribArray(3); // texcoord
        glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, TexCoord));

        glBindVertexArray(0);
    }

    Mesh Mesh::Cube()
    {
        std::vector<TerrainEngine::Vertex> cubeVertices = {
            // Front face
            {{-0.5f, -0.5f, 0.5f}, {0, 0, 1}, {0, 0, 1}, {0, 0}},
            {{0.5f, -0.5f, 0.5f}, {0, 0, 1}, {0, 0, 1}, {1, 0}},
            {{0.5f, 0.5f, 0.5f}, {0, 0, 1}, {0, 0, 1}, {1, 1}},
            {{-0.5f, 0.5f, 0.5f}, {0, 0, 1}, {0, 0, 1}, {0, 1}},

            // Back face
            {{0.5f, -0.5f, -0.5f}, {0, 0, 1}, {0, 0, -1}, {0, 0}},
            {{-0.5f, -0.5f, -0.5f}, {0, 0, 1}, {0, 0, -1}, {1, 0}},
            {{-0.5f, 0.5f, -0.5f}, {0, 0, 1}, {0, 0, -1}, {1, 1}},
            {{0.5f, 0.5f, -0.5f}, {0, 0, 1}, {0, 0, -1}, {0, 1}},

            // Left face
            {{-0.5f, -0.5f, -0.5f}, {0, 0, 1}, {-1, 0, 0}, {0, 0}},
            {{-0.5f, -0.5f, 0.5f}, {0, 0, 1}, {-1, 0, 0}, {1, 0}},
            {{-0.5f, 0.5f, 0.5f}, {0, 0, 1}, {-1, 0, 0}, {1, 1}},
            {{-0.5f, 0.5f, -0.5f}, {0, 0, 1}, {-1, 0, 0}, {0, 1}},

            // Right face
            {{0.5f, -0.5f, 0.5f}, {0, 0, 1}, {1, 0, 0}, {0, 0}},
            {{0.5f, -0.5f, -0.5f}, {0, 0, 1}, {1, 0, 0}, {1, 0}},
            {{0.5f, 0.5f, -0.5f}, {0, 0, 1}, {1, 0, 0}, {1, 1}},
            {{0.5f, 0.5f, 0.5f}, {0, 0, 1}, {1, 0, 0}, {0, 1}},

            // Top face
            {{-0.5f, 0.5f, 0.5f}, {0, 0, 1}, {0, 1, 0}, {0, 0}},
            {{0.5f, 0.5f, 0.5f}, {0, 0, 1}, {0, 1, 0}, {1, 0}},
            {{0.5f, 0.5f, -0.5f}, {0, 0, 1}, {0, 1, 0}, {1, 1}},
            {{-0.5f, 0.5f, -0.5f}, {0, 0, 1}, {0, 1, 0}, {0, 1}},

            // Bottom face
            {{-0.5f, -0.5f, -0.5f}, {0, 0, 1}, {0, -1, 0}, {0, 0}},
            {{0.5f, -0.5f, -0.5f}, {0, 0, 1}, {0, -1, 0}, {1, 0}},
            {{0.5f, -0.5f, 0.5f}, {0, 0, 1}, {0, -1, 0}, {1, 1}},
            {{-0.5f, -0.5f, 0.5f}, {0, 0, 1}, {0, -1, 0}, {0, 1}}};

        std::vector<unsigned int> cubeIndices = {
            0, 1, 2, 2, 3, 0,       // front
            4, 5, 6, 6, 7, 4,       // back
            8, 9, 10, 10, 11, 8,    // left
            12, 13, 14, 14, 15, 12, // right
            16, 17, 18, 18, 19, 16, // top
            20, 21, 22, 22, 23, 20  // bottom
        };

        return Mesh(cubeVertices, cubeIndices);
    }
}
