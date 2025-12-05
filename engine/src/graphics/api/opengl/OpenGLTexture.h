#pragma once
#include <GL/gl3w.h>
#include <string>
#include "graphics/Texture.h"
namespace TerrainEngine
{
    class OpenGLTexture : public Texture
    {
    public:
        OpenGLTexture(const std::string &filePath);
        ~OpenGLTexture();

        void Bind() override;
        void Unbind() override;

    private:
        GLuint id;
    };

}
