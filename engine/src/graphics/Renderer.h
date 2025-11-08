#pragma once
#include <memory>
namespace TerrainEngine
{

    class Renderer
    {
    public:
        Renderer() = default;
        virtual ~Renderer() = default;

        virtual void Init() = 0;
        static std::unique_ptr<Renderer> Create();
    };

}