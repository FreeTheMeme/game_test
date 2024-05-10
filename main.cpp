#include "raylib.h"
#include <iostream>
#include <string>
#include "raylib.h"

#include "rlgl.h"
#include "raymath.h"

#define PLAYER_SIZE 48
int main(void)
{   //vars
    int width = 1024;
    int height = 1024;
    Rectangle player = {(width/2)-24, (height/2)-24, PLAYER_SIZE, PLAYER_SIZE};
    float playerSpeed = 2.0f;
    //create window (size(x,y),window name)
    InitWindow(width, height, "raylib [core] example - basic window");
    SetTargetFPS(60);
    //Main loop 
    //without this the the window would open and close instantly
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
            DrawFPS(16,16);
            DrawText("pos: ",10,20,20,GREEN);
            //grid
            
            
            // Draw the 3d grid, rotated 90 degrees and centered around 0,0 
            // just so we have something in the XY plane
            rlPushMatrix();
            rlTranslatef(0, 64*16, 0);
            rlRotatef(90, 1, 0, 0);
            DrawGrid(128, 64);
            rlPopMatrix();
            DrawRectangleRec(player,ORANGE);


            
        EndDrawing();
    }

    CloseWindow();

    return 0;
}