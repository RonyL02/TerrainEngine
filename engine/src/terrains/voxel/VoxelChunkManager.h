#pragma once
#include <vector>
#include "VoxelChunk.h"
#include <glm/glm.hpp>
#include "graphics/Texture.h"
#include "scene/entity/Entity.h"

namespace TerrainEngine {
    struct VoxelChunkManagerConfig {
        size_t chunkSize = 16;
        float renderDistance = 100.0f;
        glm::ivec3 worldDimensions = {2, 2, 2};
        std::shared_ptr<Material> material;
    };

    class VoxelChunkManager {
    public:
        VoxelChunkManager(VoxelChunkManagerConfig config);

        ~VoxelChunkManager();

        void LoadChunks(const glm::vec3 &cameraPosition);

        void UpdateChunkEntities();

        void Render() const;
    private:
        std::vector<VoxelChunk> loadedChunks;
        std::vector<Entity> visibleChunkEntities;
        VoxelChunkManagerConfig config;
    };
}
