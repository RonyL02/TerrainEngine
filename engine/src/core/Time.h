#pragma once
namespace TerrainEngine
{
    class Time
    {
    public:
        static float DeltaTime();
        static void UpdateDeltaTime(float time);

    private:
        static float lastTime;
        static float deltaTime;
    };
}