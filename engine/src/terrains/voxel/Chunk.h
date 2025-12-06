#pragma once
#include "Voxel.h"
#include "graphics/Mesh.h"
namespace TerrainEngine
{
    class Chunk
    {

    public:
        static constexpr size_t CHUNK_SIZE = 5;

        Chunk() = default;
        ~Chunk() = default;

        void InitVoxelMap()
        {
            for (size_t x = 0; x < CHUNK_SIZE; x++)
            {
                for (size_t y = 0; y < CHUNK_SIZE; y++)
                {
                    for (size_t z = 0; z < CHUNK_SIZE; z++)
                    {
                        this->voxelMap[x * CHUNK_SIZE * CHUNK_SIZE + y * CHUNK_SIZE + z] = 1; // TODO: set value from perlin noise
                    }
                }
            }
        }

        std::shared_ptr<Mesh> GenerateMesh()
        {
            std::vector<Vertex> vertices;
            std::vector<unsigned int> indices;
            unsigned int currentVertexIndex = 0;
            for (size_t x = 0; x < CHUNK_SIZE; x++)
            {
                for (size_t y = 0; y < CHUNK_SIZE; y++)
                {
                    for (size_t z = 0; z < CHUNK_SIZE; z++)
                    {
                        for (size_t faceIndex = 0; faceIndex < 6; faceIndex++)
                        {
                            vertices.push_back({glm::vec3{x, y, z} + Voxel::FACES[faceIndex][0], glm::vec4(1), glm::vec3(1), {0, 0}});
                            vertices.push_back({glm::vec3{x, y, z} + Voxel::FACES[faceIndex][1], glm::vec4(1), glm::vec3(1), {1, 0}});
                            vertices.push_back({glm::vec3{x, y, z} + Voxel::FACES[faceIndex][2], glm::vec4(1), glm::vec3(1), {1, 1}});
                            vertices.push_back({glm::vec3{x, y, z} + Voxel::FACES[faceIndex][3], glm::vec4(1), glm::vec3(1), {0, 1}});

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

    private:
        int chunkSize;
        int voxelMap[CHUNK_SIZE * CHUNK_SIZE * CHUNK_SIZE];
    };
}
