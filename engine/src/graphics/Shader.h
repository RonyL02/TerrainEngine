#pragma once
#include <GL/gl3w.h>
#include <string>
#include <glm/glm.hpp>
#include <memory>
namespace TerrainEngine
{
    class Shader
    {
    public:
        virtual ~Shader() = default;

        virtual void Bind() = 0;
        virtual void Unbind() = 0;

        virtual void SetBool(const GLchar *name, GLboolean value) = 0;
        virtual void SetInt(const GLchar *name, GLuint value) = 0;
        virtual void SetFloat(const GLchar *name, GLfloat value) = 0;

        virtual void SetVec2f(const GLchar *name, glm::vec2 value) = 0;
        virtual void SetVec3f(const GLchar *name, glm::vec3 value) = 0;
        virtual void SetVec4f(const GLchar *name, glm::vec4 value) = 0;

        virtual void SetMat3f(const GLchar *name, glm::mat3 value) = 0;
        virtual void SetMat4f(const GLchar *name, glm::mat4 value) = 0;

        static std::shared_ptr<Shader> Create(const std::string &vertexPath, const std::string &fragmentPath);
    };
}
