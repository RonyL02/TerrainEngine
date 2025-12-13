#pragma once
#include "Voxel.h"
#include "graphics/Mesh.h"
#include "scene/entity/Entity.h"
namespace TerrainEngine
{
    class VoxelChunk : public Entity
    {

    public:
         VoxelChunk(size_t size, glm::vec3 pos, std::shared_ptr<Material> material)
            : Entity()
        {
            this->voxelMap = std::vector<int>(size * size * size);
            this->chunkSize = size;
            this->material = material;
            this->transform.position = pos;
            InitVoxelMap();
            this->mesh = GenerateMesh();
        }
        ~VoxelChunk() = default;

        void InitVoxelMap()
        {
            for (size_t x = 0; x < chunkSize; x++)
            {
                for (size_t y = 0; y < chunkSize; y++)
                {
                    for (size_t z = 0; z < chunkSize; z++)
                    {
                        this->voxelMap[x * chunkSize * chunkSize + y * chunkSize + z] = 1; // TODO: set value from perlin noise
                    }
                }
            }
        }

        std::shared_ptr<Mesh> GenerateMesh()
        {
            std::vector<Vertex> vertices;
            std::vector<unsigned int> indices;
            unsigned int currentVertexIndex = 0;
            for (size_t x = 0; x < chunkSize; x++)
            {
                for (size_t y = 0; y < chunkSize; y++)
                {
                    for (size_t z = 0; z < chunkSize; z++)
                    {
                        for (size_t faceIndex = 0; faceIndex < 6; faceIndex++)
                        {
                            vertices.push_back({glm::vec3{x, y, z} + Voxel::FACES[faceIndex][0], glm::vec4(x, y, z, 1), glm::vec3(1), {0, 0}});
                            vertices.push_back({glm::vec3{x, y, z} + Voxel::FACES[faceIndex][1], glm::vec4(x, y, z, 1), glm::vec3(1), {1, 0}});
                            vertices.push_back({glm::vec3{x, y, z} + Voxel::FACES[faceIndex][2], glm::vec4(x, y, z, 1), glm::vec3(1), {1, 1}});
                            vertices.push_back({glm::vec3{x, y, z} + Voxel::FACES[faceIndex][3], glm::vec4(x, y, z, 1), glm::vec3(1), {0, 1}});

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
        std::vector<int> voxelMap;
    };
}
