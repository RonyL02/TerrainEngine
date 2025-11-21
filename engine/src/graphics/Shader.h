#pragma once
#include <GL/gl3w.h>
#include <string>
#include <glm/glm.hpp>

namespace TerrainEngine
{
    class Shader
    {
    public:
        Shader(std::string vertexShaderPath, std::string fragmentShaderPath);
        ~Shader();

        void Bind();
        void Unbind();

        void SetBool(const GLchar *name, GLboolean value);
        void SetInt(const GLchar *name, GLuint value);
        void SetFloat(const GLchar *name, GLfloat value);

        void SetVec2f(const GLchar *name, glm::vec2 value);
        void SetVec3f(const GLchar *name, glm::vec3 value);
        void SetVec4f(const GLchar *name, glm::vec4 value);

        void SetMat3f(const GLchar *name, glm::mat3 value);
        void SetMat4f(const GLchar *name, glm::mat4 value);

    private:
        GLuint id;

        std::string LoadShaderSource(std::string filePath);
        GLuint LoadShader(std::string filePath, GLenum type);
        GLuint LinkProgram(GLuint vertexShader, GLuint fragmentShader);
    };
}
