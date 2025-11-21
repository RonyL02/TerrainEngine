#pragma once
#include <glm/glm.hpp>
#include <memory>
#include "Mesh.h"
#include "Material.h"

namespace TerrainEngine
{
    struct Drawable
    {
        glm::vec3 Position;
        glm::vec3 Rotation;
        glm::vec3 Scale;
        std::shared_ptr<Mesh> Mesh;
        std::shared_ptr<Material> Material;

        glm::mat4 GetModelMatrix();
    };
}