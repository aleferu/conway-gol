#include "raylib.h"
#include <iostream>


int main(void) {
    const float screenSize = 800.0f;
    InitWindow((int) screenSize, (int) screenSize, "Conway's Game of Life");
    ClearWindowState(FLAG_WINDOW_RESIZABLE);
    SetTargetFPS(60);

    // Main loop
    while (!WindowShouldClose()) {
        // Input

        // Draw
        BeginDrawing();

            ClearBackground(BLACK);

        EndDrawing();
    }
    CloseWindow();

    return 0;
}
