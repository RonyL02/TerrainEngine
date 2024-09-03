#pragma once
#include <GL/glew.h>

namespace TE
{
    class IndexBuffer
    {
    public:
        IndexBuffer();
        ~IndexBuffer();

        void Bind();
        void Unbind();
        void SetData(const GLuint *indices, int length);

    private:
        GLuint m_Id;
    };
}