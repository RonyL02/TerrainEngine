#pragma once
#include "../Graphics/OpenGL/Utils.h"
#include <optional>
#include "../utils.h"
namespace TE
{
    class Material
    {
    public:
        Material();
        Material(Shader* shader, Texture* texture);
        ~Material();

        void Bind();
        void Unbind();

        Shader* GetShader();

    private:
        std::optional<Texture*> m_Texture;
        Shader* m_Shader;
    };
}