#include "raylib.h"
#include <iostream>
#define PLAYER_SIZE 40
int main(void)
{   //vars
    int width = 900;
    int height = 650;
    Rectangle player = {850, 600, PLAYER_SIZE, PLAYER_SIZE};
    float playerSpeed = 2.0f;
    //create window (size(x,y),window name)
    InitWindow(width, height, "raylib [core] example - basic window");
    SetTargetFPS(60);
    //Main loop 
    //without this the the winow would open and close instantly
    while (!WindowShouldClose())
    {
        BeginDrawing();
            //background colour
            ClearBackground(LIGHTGRAY);
            //Key input
            if(IsKeyDown(KEY_W)) player.y-= playerSpeed;
            if(IsKeyDown(KEY_S)) player.y += playerSpeed;
            if(IsKeyDown(KEY_A)) player.x -= playerSpeed;
            if(IsKeyDown(KEY_D)) player.x += playerSpeed;
            //Draws
            std::cout << "player" << player.x << std::endl;
            DrawRectangleRec(player,ORANGE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}