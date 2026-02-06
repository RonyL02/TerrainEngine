#include "VoxelChunkManager.h"

#include <utility>

#include "core/Application.h"
#define GLM_ENABLE_EXPERIMENTAL
#include <algorithm>

#include "glm/gtx/string_cast.hpp"

namespace TerrainEngine {
    VoxelChunkManager::VoxelChunkManager(VoxelChunkManagerConfig config)
        : config(std::move(config)) {
    }

    VoxelChunkManager::~VoxelChunkManager() {
    }

    void VoxelChunkManager::LoadChunks(const glm::vec3 &cameraPosition) {
        const int chunkOffset = static_cast<int>(config.chunkSize);
        const int loadedChunksRadius = config.renderDistance;
        const auto position = glm::ivec3(cameraPosition) / chunkOffset;
        loadedChunks.clear();

        for (int x = position.x - loadedChunksRadius; x < loadedChunksRadius + position.x; x++) {
            for (int y = position.y - loadedChunksRadius; y < loadedChunksRadius + position.y; y++) {
                for (int z = position.z - loadedChunksRadius; z < loadedChunksRadius + position.z; z++) {
                    glm::ivec3 chunkPos = glm::ivec3(x, y, z) * chunkOffset;
                    loadedChunks.emplace_back(config.chunkSize, chunkPos);
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

    void VoxelChunkManager::Update(const glm::vec3 &cameraPosition) {
        const auto currentChunkPos = glm::ivec3(cameraPosition) / static_cast<int>(config.chunkSize);
        if (currentChunkPos == lastChunkPos) {
            return;
        }
        lastChunkPos = currentChunkPos;
        std::vector<glm::ivec3> newChunkPositions;
        const int loadedChunksRadius = config.renderDistance;
        for (int x = currentChunkPos.x - loadedChunksRadius; x < loadedChunksRadius + currentChunkPos.x; x++) {
            for (int y = currentChunkPos.y - loadedChunksRadius; y < loadedChunksRadius + currentChunkPos.y; y++) {
                for (int z = currentChunkPos.z - loadedChunksRadius; z < loadedChunksRadius + currentChunkPos.z; z++) {
                    glm::ivec3 chunkPos = glm::ivec3(x, y, z) * static_cast<int>(config.chunkSize);
                    newChunkPositions.push_back(chunkPos);
                }
            }
        }

        std::erase_if(loadedChunks, [&newChunkPositions, this](const VoxelChunk &chunk) {
            const glm::ivec3 chunkGridPos = glm::ivec3(chunk.GetPosition()) / static_cast<int>(config.chunkSize);
            return std::ranges::find(newChunkPositions, chunkGridPos * static_cast<int>(config.chunkSize)) ==
                   newChunkPositions.end();
        });

        for (const auto &pos: newChunkPositions) {
            const bool alreadyLoaded = std::ranges::any_of(loadedChunks, [&pos](const VoxelChunk &chunk) {
                return glm::ivec3(chunk.GetPosition()) == pos;
            });
            if (!alreadyLoaded) {
                loadedChunks.emplace_back(config.chunkSize, pos);
            }
        }

        UpdateChunkEntities();
    }
}
