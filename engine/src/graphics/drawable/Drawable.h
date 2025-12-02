#pragma once
#include <glm/glm.hpp>
#include <memory>
#include "graphics/Mesh.h"
#include "Material.h"
#include "Transform.h"

namespace TerrainEngine
{
    class Drawable
    {
    public:
        Transform transform;
        std::shared_ptr<Mesh> mesh;
        std::shared_ptr<Material> material;
    };
}