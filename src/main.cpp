#include "raylib.h"
#include <iostream>
#include "CellCollection.hpp"


int main(void) {
    const float screenSize = 800.0f;
    InitWindow((int) screenSize, (int) screenSize, "Conway's Game of Life");
    ClearWindowState(FLAG_WINDOW_RESIZABLE);
    SetTargetFPS(60);

    CellCollection cellCollection;
    // Main loop
    while (!WindowShouldClose()) {
        // Input
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            Vector2 mousePos = GetMousePosition();
            cellCollection.setCellAlive(mousePos.x, mousePos.y);
        }

        // Draw
        BeginDrawing();

            ClearBackground(BLACK);
            cellCollection.drawCells();

        EndDrawing();
    }
    CloseWindow();

    return 0;
}
