#pragma once

namespace TerrainEngine
{
    class Layer
    {
    public:
        Layer() = default;
        virtual ~Layer() = default;
        virtual void Init() = 0;
        virtual void Update() = 0;
        virtual void Render() = 0;
        virtual void Close() = 0;
    };

}
