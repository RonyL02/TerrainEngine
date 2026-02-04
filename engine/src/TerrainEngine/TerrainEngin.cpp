#include "TerrainEngine/TerrainEngine.h"

#include "Func.h"

#include "raylib.h"
#include "rcamera.h"

#define MAX_COLUMNS 20
void TerrainEngine::StartApplication() {
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight,
             "raylib [core] example - 3d camera first person");

  Camera camera = {.position = {10.0f, 10.0f, 10.0f},
                   .target = {0.0f, 0.0f, 0.0f},
                   .up = {0.0f, 1.0f, 0.0f},
                   .fovy = 45.0f,
                   .projection = CAMERA_PERSPECTIVE};

  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    if (IsKeyPressed(KEY_C)) {
      DisableCursor();
    } else if (IsKeyPressed(KEY_V)) {
      EnableCursor();
    }

    UpdateCamera(&camera, CAMERA_FREE);

    BeginDrawing();

    ClearBackground(RAYWHITE);

    BeginMode3D(camera);

    DrawCube({5, 5, 5}, 2.0f, 2.0f, 2.0f, RED);

    EndMode3D();

    EndDrawing();
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  CloseWindow();
}
