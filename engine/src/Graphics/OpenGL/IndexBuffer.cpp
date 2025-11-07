#include "IndexBuffer.h"

TE::IndexBuffer::IndexBuffer()
{
    glGenBuffers(1, &m_Id);
}

TE::IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &m_Id);
}

void TE::IndexBuffer::Bind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Id);
}

void TE::IndexBuffer::Unbind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void TE::IndexBuffer::SetData(const GLuint *indices, int length)
{
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * length, indices, GL_STATIC_DRAW);
}
