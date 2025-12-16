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
        const size_t countX = config.worldDimensions.x;
        const size_t countY = config.worldDimensions.y;
        const size_t countZ = config.worldDimensions.z;

        const size_t chunkSize = config.chunkSize;

        loadedChunks.clear();

        for (size_t x = 0; x < countX; x++) {
            for (size_t y = 0; y < countY; y++) {
                for (size_t z = 0; z < countZ; z++) {
                    const glm::vec3 chunkPosition = static_cast<float>(chunkSize) * glm::vec3(x, y, z);
                    loadedChunks.emplace_back(chunkSize, chunkPosition);
                }
            }
        }
    }

    void VoxelChunkManager::Render() const {
        for (const auto& entity: visibleChunkEntities) {
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
