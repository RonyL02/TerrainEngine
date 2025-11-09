#include "Time.h"
namespace TerrainEngine
{

    float Time::lastTime = 0.0f;
    float Time::deltaTime = 0.0f;

    float Time::DeltaTime()
    {
        return Time::deltaTime;
    }

    void Time::UpdateDeltaTime(float time)
    {
        Time::deltaTime = time - Time::lastTime;
        Time::lastTime = time;
    }
}