#include "Layer.h"

namespace TerrainEngine
{
    void Layer::Render()
    {
        this->scene.Render();
    }
    void Layer::UpdateScene()
    {
        this->scene.Update();
    }
}
