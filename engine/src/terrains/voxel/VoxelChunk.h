#pragma once
#include <vector>
#include <glm/glm.hpp>
#include "graphics/Mesh.h"

namespace TerrainEngine {
    class VoxelChunk {
    public:
        VoxelChunk(size_t size, glm::vec3 position);

        ~VoxelChunk() = default;

        std::shared_ptr<Mesh> CreateMesh() const;

        glm::vec3 GetPosition() const { return position; }

    private:
        std::vector<int> voxelMap;
        glm::vec3 position;
    };
}
