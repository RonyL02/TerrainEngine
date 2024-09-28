#pragma once
#include "../Graphics/OpenGL/Utils.h"

namespace TE
{
    class Mesh
    {
    public:
        Mesh(float *vertices, int verticesSize, unsigned int *indices, int indicesSize);
        ~Mesh();

        void Draw();

    private:
        float *m_Vertices;
        int m_VerticesSize;
        unsigned int *m_Indices;
        int m_IndicesSize;

        VertexArray m_Va;
        VertexBuffer m_Vb;
        IndexBuffer m_Ib;
    };
}