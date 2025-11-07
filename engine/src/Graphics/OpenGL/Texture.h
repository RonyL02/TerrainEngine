#pragma once

#include <GL/glew.h>
#include <string>

namespace TE
{
    class Texture
    {
    public:
        Texture(std::string filePath);
        ~Texture();

        void Bind();
        void Unbind();

    private:
        GLuint m_Id;
    };
}