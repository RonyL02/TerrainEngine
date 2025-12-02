#include "OpenGLShader.h"
#include <fstream>
#include "core/Log.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace TerrainEngine
{

    OpenGLShader::OpenGLShader(std::string vertexShaderPath, std::string fragmentShaderPath)
    {
        GLuint vertexShaderId = 0;
        GLuint fragmentShaderId = 0;

        vertexShaderId = this->LoadShader(vertexShaderPath, GL_VERTEX_SHADER);
        fragmentShaderId = this->LoadShader(fragmentShaderPath, GL_FRAGMENT_SHADER);

        this->LinkProgram(vertexShaderId, fragmentShaderId);
        TE_INFO("shader initialized");
    }

    OpenGLShader::~OpenGLShader()
    {
        TE_INFO("destroy shader");
        this->Unbind();
        glDeleteProgram(id);
    }

    void OpenGLShader::Bind()
    {
        glUseProgram(id);
    }

    void OpenGLShader::Unbind()
    {
        glUseProgram(0);
    }

    std::string OpenGLShader::LoadShaderSource(std::string filePath)
    {
        std::ifstream file = std::ifstream(filePath);

        if (!file.is_open())
        {
            TE_ERROR("SHADER::Failed to read file {}", filePath);
            return "";
        }

        std::string line;
        std::string source;
        while (getline(file, line))
        {
            source += line + "\n";
        }

        file.close();

        GLint major_version, minor_version;
        glGetIntegerv(GL_MAJOR_VERSION, &major_version);
        glGetIntegerv(GL_MINOR_VERSION, &minor_version);

        std::string version =
            std::to_string(major_version) +
            std::to_string(minor_version) +
            "0";

        source.replace(source.find("#version"), 12, ("#version " + version));

        return source;
    }

    GLuint OpenGLShader::LoadShader(std::string filePath, GLenum type)
    {
        GLuint shaderId = glCreateShader(type);
        std::string strSource = this->LoadShaderSource(filePath);
        const GLchar *source = strSource.c_str();

        glShaderSource(shaderId, 1, &source, NULL);
        glCompileShader(shaderId);

        char infoLog[512];
        int success;

        glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);

        if (!success)
        {
            glGetShaderInfoLog(shaderId, 512, NULL, infoLog);
            TE_ERROR("SHADER::Failed to compile {}: {}", filePath, infoLog);
        }

        return shaderId;
    }

    GLuint OpenGLShader::LinkProgram(GLuint vertexShader, GLuint fragmentShader)
    {
        this->id = glCreateProgram();

        glAttachShader(this->id, vertexShader);

        glAttachShader(this->id, fragmentShader);

        glLinkProgram(this->id);

        char infoLog[512];
        int success;

        glGetProgramiv(this->id, GL_LINK_STATUS, &success);

        if (!success)
        {
            glGetProgramInfoLog(this->id, 512, NULL, infoLog);

            if (!success)
            {
                glGetShaderInfoLog(this->id, 512, NULL, infoLog);
                TE_ERROR("SHADER::Failed to link program: {}", infoLog);
            }
        }

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        return this->id;
    }

    void OpenGLShader::SetBool(const GLchar *name, GLboolean value)
    {
        glUniform1i(glGetUniformLocation(this->id, name), (int)value);
    }

    void OpenGLShader::SetInt(const GLchar *name, GLuint value)
    {
        glUniform1i(glGetUniformLocation(this->id, name), value);
    }

    void OpenGLShader::SetFloat(const GLchar *name, GLfloat value)
    {
        glUniform1f(glGetUniformLocation(this->id, name), value);
    }

    void OpenGLShader::SetVec2f(const GLchar *name, glm::vec2 value)
    {
        glUniform2fv(glGetUniformLocation(this->id, name), 1, glm::value_ptr(value));
    }

    void OpenGLShader::SetVec3f(const GLchar *name, glm::vec3 value)
    {
        glUniform3fv(glGetUniformLocation(this->id, name), 1, glm::value_ptr(value));
    }

    void OpenGLShader::SetVec4f(const GLchar *name, glm::vec4 value)
    {
        glUniform4fv(glGetUniformLocation(this->id, name), 1, glm::value_ptr(value));
    }

    void OpenGLShader::SetMat3f(const GLchar *name, glm::mat3 value)
    {
        glUniformMatrix3fv(glGetUniformLocation(this->id, name), 1, GL_FALSE, glm::value_ptr(value));
    }

    void OpenGLShader::SetMat4f(const GLchar *name, glm::mat4 value)
    {
        glUniformMatrix4fv(glGetUniformLocation(this->id, name), 1, GL_FALSE, glm::value_ptr(value));
    }
}