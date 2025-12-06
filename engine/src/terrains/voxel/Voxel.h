#pragma once
#include <glm/glm.hpp>

namespace TerrainEngine
{
    namespace Voxel
    {
        const glm::vec3 POSITIONS[8] = {
            {0, 0, 0},
            {1, 0, 0},
            {1, 1, 0},
            {0, 1, 0},
            {0, 0, 1},
            {1, 0, 1},
            {1, 1, 1},
            {0, 1, 1},
        };

        const glm::vec3 FACES[6][4] = {
            {POSITIONS[0], POSITIONS[1], POSITIONS[2], POSITIONS[3]}, // front
            {POSITIONS[5], POSITIONS[4], POSITIONS[7], POSITIONS[6]}, // back
            {POSITIONS[4], POSITIONS[0], POSITIONS[3], POSITIONS[7]}, // left
            {POSITIONS[1], POSITIONS[5], POSITIONS[6], POSITIONS[2]}, // right
            {POSITIONS[3], POSITIONS[2], POSITIONS[6], POSITIONS[7]}, // top
            {POSITIONS[4], POSITIONS[5], POSITIONS[1], POSITIONS[0]}  // bottom
        };
    }
}