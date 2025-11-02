#include "Mesh.h"

TE::Mesh::Mesh(float *vertices, int verticesSize, unsigned int *indices, int indicesSize)
    : m_Vertices(vertices),
      m_VerticesSize(verticesSize),
      m_Indices(indices),
      m_IndicesSize(indicesSize),
      m_Va(VertexArray()),
      m_Vb(VertexBuffer()),
      m_Ib(IndexBuffer())
{
    m_Va.Bind();
    m_Vb.Bind();
    m_Vb.SetData(m_Vertices, m_VerticesSize);
    m_Ib.Bind();
    m_Ib.SetData(m_Indices, m_IndicesSize);

    m_Va.SetAttribute(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
    m_Va.SetAttribute(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(3 * sizeof(float)));
    m_Va.SetAttribute(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(6 * sizeof(float)));

    m_Vb.Unbind();
    m_Va.Unbind();
}

TE::Mesh::~Mesh()
{
}

void TE::Mesh::Draw()
{
    m_Va.Bind();
    glDrawElements(GL_TRIANGLES, m_IndicesSize, GL_UNSIGNED_INT, 0);
    m_Va.Unbind();
}

void TE::Mesh::Bind()
{
    m_Va.Bind();
}

void TE::Mesh::Unbind()
{
    m_Va.Unbind();
}

int TE::Mesh::GetIndicesCount()
{
    return m_IndicesSize;
}
