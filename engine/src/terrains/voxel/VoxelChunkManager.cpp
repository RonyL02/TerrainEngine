#include "VoxelChunkManager.h"

#include <utility>

#include "core/Application.h"

namespace TerrainEngine {
    VoxelChunkManager::VoxelChunkManager(VoxelChunkManagerConfig config)
        : config(std::move(config)) {
    }

    VoxelChunkManager::~VoxelChunkManager() {
    }

    void VoxelChunkManager::LoadChunks(const glm::vec3 &cameraPosition) {
        const int chunkOffset = static_cast<int>(config.chunkSize);
        const float loadedChunksRadius = config.renderDistance + 2.0f * static_cast<float>(chunkOffset);

        loadedChunks.clear();

        const int renderDistanceRange = static_cast<int>(loadedChunksRadius / 2);

        for (int x = -renderDistanceRange; x < renderDistanceRange; x++) {
            for (int y = -renderDistanceRange; y < renderDistanceRange; y++) {
                for (int z = -renderDistanceRange; z < renderDistanceRange; z++) {
                    glm::ivec3 chunkPos = glm::ivec3(x, y, z) * chunkOffset;
                    glm::vec3 chunkCenter = glm::vec3(chunkPos) + (static_cast<float>(chunkOffset) / 2.0f);

                    if (const float distanceToCamera = glm::length(chunkCenter - cameraPosition); distanceToCamera <= loadedChunksRadius) {
                        loadedChunks.emplace_back(config.chunkSize, chunkPos);
                    }
                }
            }
        }
    }

    void VoxelChunkManager::Render() const {
        for (const auto &entity: visibleChunkEntities) {
            Application::Get().GetRenderer().Draw(entity);
        }
    }

    void VoxelChunkManager::UpdateChunkEntities() {
        visibleChunkEntities.clear();

        for (auto &chunk: loadedChunks) {
            visibleChunkEntities.push_back(Entity(
                    {
                        .position = chunk.GetPosition(),
                        .rotation = {0, 0, 0},
                        .scale = {1, 1, 1}
                    },
                    chunk.CreateMesh(loadedChunks),
                    config.material)
            );
        }
    }
}
