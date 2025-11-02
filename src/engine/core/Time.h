#pragma once
namespace TE
{
    class Time
    {
    public:
        static float DeltaTime();
        static double CurrentTime();
        static void UpdateDeltaTime();

    private:
        static float m_LastTime;
        static float m_DeltaTime;
    };
}