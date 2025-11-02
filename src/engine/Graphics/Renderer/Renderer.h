#pragma once
#include "../../Entities/Mesh.h"
#include "../../Entities/Model.h"
#include "../../Entities/Camera.h"
#include "../../Utils.h"

namespace TE
{
    class Renderer
    {
    public:
        static void Draw(Model &model);
        static void SetCamera(Ref<Camera> c);
        static void StartDraw();

    private:
        static void DrawCall(Mesh& mesh);
        static Ref<Camera> Camera;
    };
}
