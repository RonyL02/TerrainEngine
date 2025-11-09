#pragma once
#include "../../Renderer.h"
#include "../../Drawable.h"
#include "../../camera/Camera.h"
namespace TerrainEngine
{

    class OpenGLRenderer : public Renderer
    {
    public:
        OpenGLRenderer() {};
        ~OpenGLRenderer() = default;

        void Init() override;
        void Shutdown() override;
        void Draw(Drawable &drawable) override;
        void StartDraw(const Camera &camera) override;
        void UpdateViewPort(int width, int height) override;

    private:
        glm::mat4 view;
        glm::mat4 projection;
    };

}