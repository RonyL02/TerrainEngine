#pragma once
#include "../Graphics/OpenGL/Utils.h"
#include <optional>
#include "../Utils.h"
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

        Shader *GetShader();

    private:
        Box<Texture> m_Texture;
        Box<Shader> m_Shader;
    };
}