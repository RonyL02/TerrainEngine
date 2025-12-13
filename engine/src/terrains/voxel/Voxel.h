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
            {POSITIONS[0], POSITIONS[1], POSITIONS[2], POSITIONS[3]}, // front  (z-)
            {POSITIONS[5], POSITIONS[4], POSITIONS[7], POSITIONS[6]}, // back   (z+)
            {POSITIONS[4], POSITIONS[0], POSITIONS[3], POSITIONS[7]}, // left   (x-)
            {POSITIONS[1], POSITIONS[5], POSITIONS[6], POSITIONS[2]}, // right  (x+)
            {POSITIONS[3], POSITIONS[2], POSITIONS[6], POSITIONS[7]}, // top    (y+)
            {POSITIONS[4], POSITIONS[5], POSITIONS[1], POSITIONS[0]}  // bottom (y-)
        };

        // Direction offsets for checking neighbors (corresponds to FACES order)
        const glm::ivec3 FACE_NORMALS[6] = {
            {0, 0, -1}, // front
            {0, 0, 1},  // back
            {-1, 0, 0}, // left
            {1, 0, 0},  // right
            {0, 1, 0},  // top
            {0, -1, 0}  // bottom
        };
    }
}