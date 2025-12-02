#pragma once
#include <glm/ext/matrix_transform.hpp>

namespace TerrainEngine
{
    class Transform
    {
    public:
        glm::vec3 position{0};
        glm::vec3 rotation{0};
        glm::vec3 scale{1};

        glm::mat4 GetMatrix() const
        {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, position);
            model = glm::rotate(model, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
            model = glm::rotate(model, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
            model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
            model = glm::scale(model, scale);
            return model;
        }
    };

}