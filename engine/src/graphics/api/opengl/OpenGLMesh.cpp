#include "OpenGLMesh.h"
#include <GL/gl3w.h>
namespace TerrainEngine
{
    OpenGLMesh::OpenGLMesh(const std::vector<Vertex> &vertices, const std::vector<unsigned int> &indices)
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
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, Color));

        glEnableVertexAttribArray(2); // normal
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, Normal));

        glEnableVertexAttribArray(3); // texcoord
        glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, TexCoord));

        glBindVertexArray(0);
    }

    OpenGLMesh::~OpenGLMesh()
    {
        glDeleteBuffers(1, &this->ebo);
        glDeleteBuffers(1, &this->vbo);
        glDeleteVertexArrays(1, &this->vao);
    }

    void OpenGLMesh::Draw()
    {
        glBindVertexArray(this->vao);
        glDrawElements(GL_TRIANGLES, this->indexCount, GL_UNSIGNED_INT, nullptr);
    }
}
