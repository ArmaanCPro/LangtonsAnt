#include "main.h"

#include "raylib.h"

int main()
{
    const int scrWidth = 800;
    const int scrHeight = 450;

    InitWindow(scrWidth, scrHeight, "Langton's Ant");

    int framesCounter = 0;
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        framesCounter++;

        if (IsKeyPressed(KEY_ESCAPE))
        {
            break;
        }

        ClearBackground(WHITE);

        BeginDrawing();

        DrawRectangle(0, 0, scrWidth - 10, scrHeight - 7, RED);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
