#include "Texture.h"
#include "api/opengl/OpenGLTexture.h"
#include "core/Application.h"
namespace TerrainEngine
{
    std::shared_ptr<Texture> Texture::Create(const std::string &path)
    {
        return std::make_shared<OpenGLTexture>(path);
    }
}
