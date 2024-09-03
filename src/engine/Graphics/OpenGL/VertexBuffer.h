#pragma once
#include <GL/glew.h>

namespace TE
{
    class VertexBuffer
    {
    public:
        VertexBuffer();
        ~VertexBuffer();

        void Bind();
        void Unbind();
        void SetData(const float *vertices, int length);

    private:
        GLuint m_Id;
    };
}