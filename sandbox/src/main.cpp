#include <TerrainEngine.h>
#include "SandboxLayer.h"

int main() {
    Application &application =
            Application::Create({
                .windowProps = {
                    .title = "nice",
                    .width = 700,
                    .height = 400
                }
            });
    application.SetLayer(std::make_unique<SandboxLayer>());
    application.Run();
}
