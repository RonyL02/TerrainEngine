#include "Time.h"
#include "Window/Window.h"

float TE::Time::m_LastTime = 0.0f;
float TE::Time::m_DeltaTime = 0.0f;

float TE::Time::DeltaTime()
{
    return m_DeltaTime;
}

double TE::Time::CurrentTime()
{
    return Window::GetInstance()->GetTime();
}

void TE::Time::UpdateDeltaTime()
{
    float currentTime = (float)CurrentTime();
    m_DeltaTime = currentTime - m_LastTime;
    m_LastTime = currentTime;
}
