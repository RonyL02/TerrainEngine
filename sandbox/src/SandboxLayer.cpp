#include "SandboxLayer.h"
#include "spdlog/spdlog.h"
#include <glm/ext.hpp>
SandboxLayer::SandboxLayer() : TerrainEngine::Layer()
{
}

SandboxLayer::~SandboxLayer()
{
}

void SandboxLayer::Init()
{
    spdlog::info("start sandox");

    std::vector<TerrainEngine::Vertex> cubeVertices = {
        // Front face
        {{-0.5f, -0.5f, 0.5f}, {0, 0, 1}, {0, 0, 1}, {0, 0}},
        {{0.5f, -0.5f, 0.5f}, {0, 0, 1}, {0, 0, 1}, {1, 0}},
        {{0.5f, 0.5f, 0.5f}, {0, 0, 1}, {0, 0, 1}, {1, 1}},
        {{-0.5f, 0.5f, 0.5f}, {0, 0, 1}, {0, 0, 1}, {0, 1}},

        // Back face
        {{0.5f, -0.5f, -0.5f}, {0, 0, 1}, {0, 0, -1}, {0, 0}},
        {{-0.5f, -0.5f, -0.5f}, {0, 0, 1}, {0, 0, -1}, {1, 0}},
        {{-0.5f, 0.5f, -0.5f}, {0, 0, 1}, {0, 0, -1}, {1, 1}},
        {{0.5f, 0.5f, -0.5f}, {0, 0, 1}, {0, 0, -1}, {0, 1}},

        // Left face
        {{-0.5f, -0.5f, -0.5f}, {0, 0, 1}, {-1, 0, 0}, {0, 0}},
        {{-0.5f, -0.5f, 0.5f}, {0, 0, 1}, {-1, 0, 0}, {1, 0}},
        {{-0.5f, 0.5f, 0.5f}, {0, 0, 1}, {-1, 0, 0}, {1, 1}},
        {{-0.5f, 0.5f, -0.5f}, {0, 0, 1}, {-1, 0, 0}, {0, 1}},

        // Right face
        {{0.5f, -0.5f, 0.5f}, {0, 0, 1}, {1, 0, 0}, {0, 0}},
        {{0.5f, -0.5f, -0.5f}, {0, 0, 1}, {1, 0, 0}, {1, 0}},
        {{0.5f, 0.5f, -0.5f}, {0, 0, 1}, {1, 0, 0}, {1, 1}},
        {{0.5f, 0.5f, 0.5f}, {0, 0, 1}, {1, 0, 0}, {0, 1}},

        // Top face
        {{-0.5f, 0.5f, 0.5f}, {0, 0, 1}, {0, 1, 0}, {0, 0}},
        {{0.5f, 0.5f, 0.5f}, {0, 0, 1}, {0, 1, 0}, {1, 0}},
        {{0.5f, 0.5f, -0.5f}, {0, 0, 1}, {0, 1, 0}, {1, 1}},
        {{-0.5f, 0.5f, -0.5f}, {0, 0, 1}, {0, 1, 0}, {0, 1}},

        // Bottom face
        {{-0.5f, -0.5f, -0.5f}, {0, 0, 1}, {0, -1, 0}, {0, 0}},
        {{0.5f, -0.5f, -0.5f}, {0, 0, 1}, {0, -1, 0}, {1, 0}},
        {{0.5f, -0.5f, 0.5f}, {0, 0, 1}, {0, -1, 0}, {1, 1}},
        {{-0.5f, -0.5f, 0.5f}, {0, 0, 1}, {0, -1, 0}, {0, 1}}};

    std::vector<unsigned int> cubeIndices = {
        0, 1, 2, 2, 3, 0,       // front
        4, 5, 6, 6, 7, 4,       // back
        8, 9, 10, 10, 11, 8,    // left
        12, 13, 14, 14, 15, 12, // right
        16, 17, 18, 18, 19, 16, // top
        20, 21, 22, 22, 23, 20  // bottom
    };

    auto cubeMesh = std::make_shared<TerrainEngine::Mesh>(cubeVertices, cubeIndices);
    auto cubeMaterial = std::make_shared<TerrainEngine::Material>();
    cubeMaterial->Shader = std::make_shared<TerrainEngine::Shader>("engine/res/shaders/vertex.glsl", "engine/res/shaders/fragment.glsl");
    cubeMaterial->Color = glm::vec4(1.0f, 0.5f, 0.3f, 1.0f);
    cubeMaterial->Diffuse = std::make_shared<TerrainEngine::Texture>("engine/res/textures/dabadi.png");

    TerrainEngine::Drawable cube;
    cube.Mesh = cubeMesh;
    cube.Material = cubeMaterial;
    cube.Transform = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -3));

    // this->a = cube;
    this->scene.AddObject(cube);
}

void SandboxLayer::Update()
{
}

void SandboxLayer::Close()
{
}
