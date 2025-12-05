#include "OpenGLTexture.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include "core/Log.h"

namespace TerrainEngine
{

    OpenGLTexture::OpenGLTexture(const std::string &filePath)
    {
        glGenTextures(1, &this->id);
        this->Bind();

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        int width, height, nrChannels;
        stbi_set_flip_vertically_on_load(true);
        unsigned char *data = stbi_load(filePath.c_str(), &width, &height, &nrChannels, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            TE_ERROR("TEXTURE::Failed to load texture: {}", filePath);
        }
        stbi_image_free(data);
        this->Unbind();
        TE_INFO("texture initialized");
    }

    OpenGLTexture::~OpenGLTexture()
    {
        TE_INFO("destroy texture");
        
        glDeleteTextures(1, &this->id);
    }

    void OpenGLTexture::Bind()
    {
        glBindTexture(GL_TEXTURE_2D, this->id);
    }

    void OpenGLTexture::Unbind()
    {
        glBindTexture(GL_TEXTURE_2D, 0);
    }
}
