#pragma once
#include <GL/gl3w.h>
#include <string>
#include <memory>
namespace TerrainEngine
{
    class Texture
    {
    public:
        virtual ~Texture() = default;

        virtual void Bind() = 0;
        virtual void Unbind() = 0;

        static std::shared_ptr<Texture> Create(const std::string &path);
    };

}
