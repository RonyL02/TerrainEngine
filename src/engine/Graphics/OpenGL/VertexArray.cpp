#include "VertexArray.h"

TE::VertexArray::VertexArray()
{
    glGenVertexArrays(1, &m_Id);
}

TE::VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &m_Id);
}

void TE::VertexArray::Bind()
{
    glBindVertexArray(m_Id);
}

void TE::VertexArray::Unbind()
{
    glBindVertexArray(0);
}

void TE::VertexArray::SetAttribute(GLuint index,
                                   GLint size,
                                   GLenum type,
                                   GLboolean normalized,
                                   GLsizei stride,
                                   const void *pointer)
{
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
    glEnableVertexAttribArray(index);
}
