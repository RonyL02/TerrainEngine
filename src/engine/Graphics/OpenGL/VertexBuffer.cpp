#include "VertexBuffer.h"

TE::VertexBuffer::VertexBuffer()
{
    glGenBuffers(1, &m_Id);
}

TE::VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &m_Id);
}

void TE::VertexBuffer::Bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, m_Id);
}

void TE::VertexBuffer::Unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void TE::VertexBuffer::SetData(const float *vertices, int length)
{
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * length, vertices, GL_STATIC_DRAW);
}
