#include "raylib.h"
#include <iostream>
#define PLAYER_SIZE 40
int main(void)
{   //vars
    int width = 900;
    int hieght = 650;
    Rectangle player = {850, 600, PLAYER_SIZE, PLAYER_SIZE};
    //create window (size(x,y),window name)
    InitWindow(width, hieght, "raylib [core] example - basic window");
    SetTargetFPS(60);
    //Main loop 
    //without this the the winow would open and close instantly
    while (!WindowShouldClose())
    {
        BeginDrawing();
            //backround colour
            ClearBackground(LIGHTGRAY);
            if(IsKeyDown(KEY_A)) player.x -= 4.0f;
            if(IsKeyDown(KEY_D)) player.x += 4.0f;
            std::cout << "player" << player.x << std::endl;
            DrawRectangleRec(player,ORANGE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}