#include "raylib.h"

int main(void)
{
    //create window (size(x,y),window name)
    InitWindow(800, 450, "raylib [core] example - basic window");

    //Main loop 
    //without this the the winow would open and close instantly
    while (!WindowShouldClose())
    {
        BeginDrawing();
            //backround colour
            ClearBackground(RAYWHITE);
            //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}