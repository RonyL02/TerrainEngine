#pragma once
#include <glm/glm.hpp>
#include <memory>
#include "Mesh.h"
#include "Material.h"

namespace TerrainEngine
{
    struct Drawable
    {
        glm::mat4 Transform;
        std::shared_ptr<Mesh> Mesh;
        std::shared_ptr<Material> Material;
    };
}