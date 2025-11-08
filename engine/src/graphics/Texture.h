#pragma once
#include <GL/gl3w.h>
#include <string>
namespace TerrainEngine
{
    class Texture
    {
    public:
        Texture(std::string filePath);
        ~Texture();

        void Bind();
        void Unbind();

    private:
        GLuint id;
    };

}
