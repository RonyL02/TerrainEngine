#pragma once
#include <GL/glew.h>
#include <string>

namespace TE
{
    class Shader
    {
    public:
        Shader(std::string vertexShaderPath, std::string fragmentShaderPath);
        ~Shader();

        void Bind();
        void Unbind();

    private:
        GLuint m_Id;

        std::string LoadShaderSource(std::string filePath);
        GLuint LoadShader(std::string filePath, GLenum type);
        GLuint LinkProgram(GLuint vertexShader, GLuint fragmentShader);

        void SetBool(const GLchar *name, GLboolean value);
        void SetInt(const GLchar *name, GLuint value);
        void SetFloat(const GLchar *name, GLfloat value);
    };
}