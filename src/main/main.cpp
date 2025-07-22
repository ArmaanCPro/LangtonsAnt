#include "ant.h"

#include <raylib.h>

int main()
{
    Board brd;
    const auto brdSettings = brd.GetBoardSettings();
    const int scrWidth = brdSettings.CellSize * brdSettings.Columns;
    const int scrHeight = brdSettings.CellSize * brdSettings.Rows;

    Ant ant(25, 25);

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

        ant.Update(brd);

        ClearBackground(PURPLE);

        BeginDrawing();

        for (uint32_t i = 0; i < 50; i++)
        {
            for (uint32_t j = 0; j < 50; j++)
            {
                auto cellValue = brd.GetCell(i, j);
                Color c;

                switch (cellValue)
                {
                case CellValue::White:
                    c = WHITE;
                    break;
                case CellValue::Black:
                    c = BLACK;
                    break;
               }

                const uint32_t startX = i * brdSettings.CellSize;
                const uint32_t startY = j * brdSettings.CellSize;
                const uint32_t endX = startX + brdSettings.CellSize;
                const uint32_t endY = startY + brdSettings.CellSize;
                DrawRectangle(startX, startY, endX, endY, c);
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
