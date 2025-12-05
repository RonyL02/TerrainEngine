#pragma once
#include <glm/glm.hpp>
#include <memory>
#include "graphics/Mesh.h"
#include "Material.h"
#include "Transform.h"
#include "core/Log.h"

namespace TerrainEngine
{
    class Entity
    {
    public:
        Entity() = default;
        Entity(Transform transform,
               std::shared_ptr<Mesh> mesh,
               std::shared_ptr<Material> material)
            : transform(transform), mesh(mesh), material(material) {}
        virtual ~Entity() = default;
        Transform transform;
        std::shared_ptr<Mesh> mesh;
        std::shared_ptr<Material> material;

        virtual void Update() {}
    };
}