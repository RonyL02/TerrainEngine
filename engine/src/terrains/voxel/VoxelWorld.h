#pragma once
#include <vector>
#include "VoxelChunk.h"
namespace TerrainEngine
{
    class VoxelWorld
    {
    public:
        VoxelWorld() = default;
        ~VoxelWorld();

        inline std::vector<VoxelChunk> GetRenderedChunks() { return this->renderedChunks; }
        void UpdateRenderedChunks(glm::vec3 pos);

        void InitLimitedWorld(size_t worldSize, size_t chunkSize, std::shared_ptr<Material> material);
        void Render();

    private:
        std::vector<VoxelChunk> renderedChunks;
        std::vector<VoxelChunk> cachedChunks;
    };
}
