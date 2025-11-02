#pragma once
#include "../Graphics/OpenGL/Utils.h"
#include <optional>
#include "../Utils.h"
namespace TE
{
    class Material
    {
    public:
        Material(Shader &shader, Texture &texture);

        ~Material();

        void Bind();
        void Unbind();

        Shader &GetShader();

    private:
        Texture &m_Texture;
        Shader &m_Shader;
    };
}