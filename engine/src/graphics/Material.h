#pragma once
#include <glm/glm.hpp>
#include <memory>
#include "Shader.h"
#include "Texture.h"

namespace TerrainEngine
{
    struct Material
    {
        glm::vec4 Color = glm::vec4(1.0f);
        std::shared_ptr<Texture> Diffuse;
        std::shared_ptr<Shader> Shader;
    };
}