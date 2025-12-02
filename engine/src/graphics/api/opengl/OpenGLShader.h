#pragma once
#include <GL/gl3w.h>
#include <string>
#include <glm/glm.hpp>
#include "graphics/Shader.h"

namespace TerrainEngine
{
    class OpenGLShader : public Shader
    {
    public:
        OpenGLShader(std::string vertexShaderPath, std::string fragmentShaderPath);
        ~OpenGLShader();

        void Bind() override;
        void Unbind() override;

        void SetBool(const GLchar *name, GLboolean value) override;
        void SetInt(const GLchar *name, GLuint value) override;
        void SetFloat(const GLchar *name, GLfloat value) override;

        void SetVec2f(const GLchar *name, glm::vec2 value) override;
        void SetVec3f(const GLchar *name, glm::vec3 value) override;
        void SetVec4f(const GLchar *name, glm::vec4 value) override;

        void SetMat3f(const GLchar *name, glm::mat3 value) override;
        void SetMat4f(const GLchar *name, glm::mat4 value) override;

    private:
        GLuint id;

        std::string LoadShaderSource(std::string filePath);
        GLuint LoadShader(std::string filePath, GLenum type);
        GLuint LinkProgram(GLuint vertexShader, GLuint fragmentShader);
    };
}
