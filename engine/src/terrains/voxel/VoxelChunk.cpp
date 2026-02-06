#include "VoxelChunk.h"
#include "graphics/Mesh.h"
#include "Voxel.h"
#include "core/Log.h"

namespace TerrainEngine {
    VoxelChunk::VoxelChunk(const size_t size, const glm::ivec3 position) : voxelMap(size * size * size),
                                                                          position(position), size(size) {
        for (size_t x = 0; x < size; x++) {
            for (size_t y = 0; y < size; y++) {
                for (size_t z = 0; z < size; z++) {
                    const size_t index = x + y * size + z * size * size;
                    voxelMap[index] = 1;
                }
            }
        }
    }

    std::shared_ptr<Mesh> VoxelChunk::CreateMesh(const std::vector<VoxelChunk> &neighboringChunks) const {
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        unsigned int currentVertexIndex = 0;

        for (size_t x = 0; x < size; x++) {
            for (size_t y = 0; y < size; y++) {
                for (size_t z = 0; z < size; z++) {
                    for (size_t faceIndex = 0; faceIndex < 6; faceIndex++) {
                        if (GetVoxelType(glm::ivec3(x, y, z)) == 0) {
                            continue;
                        }

                        const glm::ivec3 neighborCoord = glm::ivec3(x, y, z) + Voxel::FACE_NORMALS[faceIndex];

                        if (const int neighborType = GetVoxelType(neighborCoord); neighborType != -1) {
                            if (neighborType != 0) {
                                continue;
                            }
                        } else {
                            glm::ivec3 neighboringChunkPosition =
                                   glm::ivec3(
                                       position + glm::ivec3(Voxel::FACE_NORMALS[faceIndex]) * static_cast<int>(size));

                            auto it = std::ranges::find_if(neighboringChunks,
                                                           [&neighboringChunkPosition](const VoxelChunk &chunk) {
                                                               return glm::ivec3(chunk.GetPosition()) == neighboringChunkPosition;
                                                           });
                            if (it != neighboringChunks.end()) {
                                glm::ivec3 wrappedCoord;
                                wrappedCoord.x = neighborCoord.x < 0
                                                     ? static_cast<int>(size) - 1
                                                     : neighborCoord.x >= static_cast<int>(size)
                                                           ? 0
                                                           : neighborCoord.x;
                                wrappedCoord.y = neighborCoord.y < 0
                                                     ? static_cast<int>(size) - 1
                                                     : neighborCoord.y >= static_cast<int>(size)
                                                           ? 0
                                                           : neighborCoord.y;
                                wrappedCoord.z = neighborCoord.z < 0
                                                     ? static_cast<int>(size) - 1
                                                     : neighborCoord.z >= static_cast<int>(size)
                                                           ? 0
                                                           : neighborCoord.z;

                                if (it->GetVoxelType(wrappedCoord) != 0) {
                                    continue;
                                }
                            }
                        }

                        vertices.push_back({
                            glm::ivec3{x, y, z} + Voxel::FACES[faceIndex][0], glm::vec4(x, y, z, 1),
                            glm::vec3(1), {0, 0}
                        });
                        vertices.push_back({
                            glm::ivec3{x, y, z} + Voxel::FACES[faceIndex][1], glm::vec4(x, y, z, 1),
                            glm::vec3(1), {1, 0}
                        });
                        vertices.push_back({
                            glm::ivec3{x, y, z} + Voxel::FACES[faceIndex][2], glm::vec4(x, y, z, 1),
                            glm::vec3(1), {1, 1}
                        });
                        vertices.push_back({
                            glm::ivec3{x, y, z} + Voxel::FACES[faceIndex][3], glm::vec4(x, y, z, 1),
                            glm::vec3(1), {0, 1}
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

    int VoxelChunk::GetVoxelType(const glm::ivec3 coord) const {
        if (coord.x < 0 || coord.x >= size || coord.y < 0 || coord.y >= size || coord.z < 0 || coord.z >=
            size) {
            return -1;
        }
        return voxelMap[coord.x + coord.y * size + coord.z * size * size];
    }
}
