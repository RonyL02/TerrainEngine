#pragma once
#include <GL/glew.h>

namespace TE
{
    class VertexArray
    {
    public:
        VertexArray();
        ~VertexArray();

        void Bind();
        void Unbind();
        void SetAttribute(GLuint index,
                          GLint size,
                          GLenum type,
                          GLboolean normalized,
                          GLsizei stride,
                          const void *pointer);

    private:
        GLuint m_Id;
    };
}
