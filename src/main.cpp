#include "raylib.h"
#include <iostream>
#include "CellCollection.hpp"


int main(void) {
    const float screenSize = 800.0f;
    InitWindow((int) screenSize, (int) screenSize, "Conway's Game of Life");
    ClearWindowState(FLAG_WINDOW_RESIZABLE);
    SetTargetFPS(60);

    CellCollection cellCollection;
    bool play = false;
    int count = 0;
    // Main loop
    while (!WindowShouldClose()) {
        // Input
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            Vector2 mousePos = GetMousePosition();
            cellCollection.setCellAlive(mousePos.x, mousePos.y);
        } else if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
            Vector2 mousePos = GetMousePosition();
            cellCollection.setCellDead(mousePos.x, mousePos.y);
        } else if (IsKeyPressed(KEY_N)) {
            cellCollection.computeNextCycle();
        } else if (IsKeyPressed(KEY_P)) {
            play = !play;
        } else if (IsKeyPressed(KEY_C)) {
            cellCollection.clearCells();
        }

        // Draw
        BeginDrawing();

            ClearBackground(BLACK);
            cellCollection.drawCells();

        EndDrawing();

        if (play) { 
            ++count;
            count %= 5;
            if (count == 0)
                cellCollection.computeNextCycle();
        }
    }
    CloseWindow();

    return 0;
}
