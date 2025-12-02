#include "Shader.h"
#include "api/opengl/OpenGLShader.h"
#include "core/Application.h"

namespace TerrainEngine
{
    std::shared_ptr<Shader> Shader::Create(const std::string &vertexPath, const std::string &fragmentPath)
    {
        return std::make_shared<OpenGLShader>(vertexPath, fragmentPath);
    }
}