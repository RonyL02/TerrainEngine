#include "VoxelWorld.h"
#include "core/Application.h"
namespace TerrainEngine
{
    VoxelWorld::~VoxelWorld()
    {
    }

    void VoxelWorld::UpdateRenderedChunks(glm::vec3 pos)
    {
        // load chunks from memory/file
        // search by render radius
    }
    void VoxelWorld::InitLimitedWorld(size_t worldSize, size_t chunkSize, std::shared_ptr<Material> material)
    {
        for (size_t x = 0; x < worldSize; x++)
        {
            for (size_t y = 0; y < worldSize; y++)
            {
                for (size_t z = 0; z < worldSize; z++)
                {
                    renderedChunks.push_back(VoxelChunk(chunkSize, (float)chunkSize * glm::vec3(x, y, z), material));
                }
            }
        }
    }
    void VoxelWorld::Render()
    {
        for (auto &chunk : renderedChunks)
        {
            Application::Get().GetRenderer().Draw(chunk);
        }
    }
}