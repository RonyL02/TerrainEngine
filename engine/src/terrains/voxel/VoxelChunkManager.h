#pragma once
#include <vector>
#include "VoxelChunk.h"
#include <glm/glm.hpp>
#include "graphics/Texture.h"
#include "scene/entity/Entity.h"

namespace TerrainEngine {
    struct VoxelChunkManagerConfig {
        size_t chunkSize = 16;
        int renderDistance = 2;
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

        void Update(const glm::vec3 &cameraPosition) ;
    private:
        std::vector<VoxelChunk> loadedChunks;
        std::vector<Entity> visibleChunkEntities;
        VoxelChunkManagerConfig config;
        glm::ivec3 lastChunkPos = glm::ivec3(0, 0, 0);
    };
}
