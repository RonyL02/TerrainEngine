#pragma once
#include <memory>
#include "graphics/Shader.h"
#include "graphics/Texture.h"

namespace TerrainEngine
{
    class Material
    {
    public:
        std::shared_ptr<Shader> shader;
        std::shared_ptr<Texture> texture;

        Material(std::shared_ptr<Texture> texture,
                 std::shared_ptr<Shader> shader = nullptr)
        {
            if (!shader)
            {
                this->shader = Shader::Create("res/shaders/vertex.glsl", "res/shaders/fragment.glsl");
            }
            else
            {
                this->shader = shader;
            }

            this->texture = texture;
        }

        void Bind()
        {
            shader->Bind();
            texture->Bind();
        }

        static std::shared_ptr<Material> Create(
            std::shared_ptr<Texture> texture,
            std::shared_ptr<Shader> shader = nullptr)
        {
            return std::make_shared<Material>(texture, shader);
        }
    };
}