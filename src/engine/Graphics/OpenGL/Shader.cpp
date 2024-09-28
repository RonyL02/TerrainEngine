#include "Shader.h"
#include <fstream>
#include <spdlog/spdlog.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Defines.h"

TE::Shader::Shader(std::string vertexShaderPath, std::string fragmentShaderPath)
{
    GLuint vertexShaderId = 0;
    GLuint fragmentShaderId = 0;

    vertexShaderId = LoadShader(vertexShaderPath, GL_VERTEX_SHADER);
    fragmentShaderId = LoadShader(fragmentShaderPath, GL_FRAGMENT_SHADER);

    LinkProgram(vertexShaderId, fragmentShaderId);
    spdlog::info("shader initialized");
}

TE::Shader::~Shader()
{
    spdlog::info("destroy shader");
    Unbind();
    glDeleteProgram(m_Id);
}

void TE::Shader::Bind()
{
    glUseProgram(m_Id);
}

void TE::Shader::Unbind()
{
    glUseProgram(0);
}

std::string TE::Shader::LoadShaderSource(std::string filePath)
{
    std::ifstream file = std::ifstream(filePath);

    if (!file.is_open())
    {
        spdlog::error("SHADER::Failed to read file {}", filePath);
        return "";
    }

    std::string line;
    std::string source;
    while (getline(file, line))
    {
        source += line + "\n";
    }

    file.close();

    std::string version =
        std::to_string(TE_OPENGL_VERSION_MAJOR) +
        std::to_string(TE_OPENGL_VERSION_MINOR) +
        "0";

    source.replace(source.find("#version"), 12, ("#version " + version));

    return source;
}

GLuint TE::Shader::LoadShader(std::string filePath, GLenum type)
{
    GLuint shaderId = glCreateShader(type);
    std::string strSource = LoadShaderSource(filePath);
    const GLchar *source = strSource.c_str();

    glShaderSource(shaderId, 1, &source, NULL);
    glCompileShader(shaderId);

    char infoLog[512];
    int success;

    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(shaderId, 512, NULL, infoLog);
        spdlog::error("SHADER::Failed to compile {}: {}", filePath, infoLog);
    }

    return shaderId;
}

GLuint TE::Shader::LinkProgram(GLuint vertexShader, GLuint fragmentShader)
{
    m_Id = glCreateProgram();

    glAttachShader(m_Id, vertexShader);

    glAttachShader(m_Id, fragmentShader);

    glLinkProgram(m_Id);

    char infoLog[512];
    int success;

    glGetProgramiv(m_Id, GL_LINK_STATUS, &success);

    if (!success)
    {
        glGetProgramInfoLog(m_Id, 512, NULL, infoLog);

        if (!success)
        {
            glGetShaderInfoLog(m_Id, 512, NULL, infoLog);
            spdlog::error("SHADER::Failed to link program: {}", infoLog);
        }
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return m_Id;
}

void TE::Shader::SetBool(const GLchar *name, GLboolean value)
{
    glUniform1i(glGetUniformLocation(m_Id, name), (int)value);
}

void TE::Shader::SetInt(const GLchar *name, GLuint value)
{
    glUniform1i(glGetUniformLocation(m_Id, name), value);
}

void TE::Shader::SetFloat(const GLchar *name, GLfloat value)
{
    glUniform1f(glGetUniformLocation(m_Id, name), value);
}

void TE::Shader::SetVec2f(const GLchar *name, glm::vec2 value)
{
    glUniform2fv(glGetUniformLocation(m_Id, name), 1, glm::value_ptr(value));
}

void TE::Shader::SetVec3f(const GLchar *name, glm::vec3 value)
{
    glUniform3fv(glGetUniformLocation(m_Id, name), 1, glm::value_ptr(value));
}

void TE::Shader::SetVec4f(const GLchar *name, glm::vec4 value)
{
    glUniform4fv(glGetUniformLocation(m_Id, name), 1, glm::value_ptr(value));
}

void TE::Shader::SetMat3f(const GLchar *name, glm::mat3 value)
{
    glUniformMatrix3fv(glGetUniformLocation(m_Id, name), 1, GL_FALSE, glm::value_ptr(value));
}

void TE::Shader::SetMat4f(const GLchar *name, glm::mat4 value)
{
    glUniformMatrix4fv(glGetUniformLocation(m_Id, name), 1, GL_FALSE, glm::value_ptr(value));
}
