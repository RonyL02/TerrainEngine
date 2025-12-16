#include "VoxelChunk.h"
#include "graphics/Mesh.h"
#include "Voxel.h"

namespace TerrainEngine {
    VoxelChunk::VoxelChunk(const size_t size, const glm::vec3 position) : voxelMap(size * size * size),
                                                                          position(position) {
        for (size_t x = 0; x < size; x++) {
            for (size_t y = 0; y < size; y++) {
                for (size_t z = 0; z < size; z++) {
                    const size_t index = x + y * size + z * size * size;
                    voxelMap[index] = 1;
                }
            }
        }
    }

    std::shared_ptr<Mesh> VoxelChunk::CreateMesh() const {
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        unsigned int currentVertexIndex = 0;

        const auto chunkSize = static_cast<size_t>(cbrt(voxelMap.size()));

        for (size_t x = 0; x < chunkSize; x++) {
            for (size_t y = 0; y < chunkSize; y++) {
                for (size_t z = 0; z < chunkSize; z++) {
                    for (const auto & faceIndex : Voxel::FACES) {
                        if (voxelMap[x + y * chunkSize + z * chunkSize * chunkSize] == 0) {
                            continue;
                        }

                        vertices.push_back({
                            glm::vec3{x, y, z} + faceIndex[0], glm::vec4(x, y, z, 1), glm::vec3(1), {0, 0}
                        });
                        vertices.push_back({
                            glm::vec3{x, y, z} + faceIndex[1], glm::vec4(x, y, z, 1), glm::vec3(1), {1, 0}
                        });
                        vertices.push_back({
                            glm::vec3{x, y, z} + faceIndex[2], glm::vec4(x, y, z, 1), glm::vec3(1), {1, 1}
                        });
                        vertices.push_back({
                            glm::vec3{x, y, z} + faceIndex[3], glm::vec4(x, y, z, 1), glm::vec3(1), {0, 1}
                        });

                        indices.push_back(currentVertexIndex);
                        indices.push_back(currentVertexIndex + 1);
                        indices.push_back(currentVertexIndex + 2);
                        indices.push_back(currentVertexIndex);
                        indices.push_back(currentVertexIndex + 2);
                        indices.push_back(currentVertexIndex + 3);

                        currentVertexIndex += 4;
                    }
                }
            }
        }
        return Mesh::Create(vertices, indices);
    }
}
