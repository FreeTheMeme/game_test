#include "raylib.h"
#include <iostream>
#include <string>
#include "raylib.h"

#include "rlgl.h"
#include "raymath.h"

#define PLAYER_SIZE 48

int main(void)
{   //vars
    const int screenWidth = 1024;
    const int screenHeight = 1024;
    const Vector2 blockSize ={64,64};

    Rectangle player = {(screenWidth/2), (screenHeight/2), PLAYER_SIZE, PLAYER_SIZE};
    float playerSpeed = 2.0f;
    //create window (size(x,y),window name)
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    //Camera
    Camera2D camera = { 0 };
    camera.zoom = 1.0f;
    camera.target=  (Vector2){player.x,player.y};
    camera.offset = (Vector2){ 512, 512 };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    SetTargetFPS(60);

    //Main loop 
    //without this the the window would open and close instantly
    while (!WindowShouldClose())
    {
        BeginDrawing();
            //background colour
            ClearBackground(LIGHTGRAY);
            //Key input
            if(IsKeyDown(KEY_LEFT_SHIFT)) playerSpeed *= 2 ;
            if(IsKeyDown(KEY_W)) player.y-= playerSpeed;
            if(IsKeyDown(KEY_S)) player.y += playerSpeed;
            if(IsKeyDown(KEY_A)) player.x -= playerSpeed;
            if(IsKeyDown(KEY_D)) player.x += playerSpeed;
            camera.target = (Vector2){ player.x + 20, player.y + 20 };

        

        // Camera zoom controls
        camera.zoom += ((float)GetMouseWheelMove()*0.05f);

        if (camera.zoom > 3.0f) camera.zoom = 3.0f;
        else if (camera.zoom < 0.1f) camera.zoom = 0.1f;

        // Camera reset (zoom and rotation)
        if (IsKeyPressed(KEY_R))
        {
            camera.zoom = 1.0f;
            camera.rotation = 0.0f;
        }
            //Draws
            BeginMode2D(camera);
            DrawRectangleRec(player,ORANGE);
                //Grid
                //Draw the 3d grid, rotated 90 degrees and centered around 0,0 
                //just so we have something in the XY plane
                rlPushMatrix();
                    rlTranslatef(0, 64*16, 0);
                    rlRotatef(90, 1, 0, 0);
                    DrawGrid(128, 64);
                rlPopMatrix();
                DrawRectangle(512,512,blockSize.x,blockSize.y,GRAY);

            EndMode2D();
            std::cout << "player x" << player.x << std::endl;
            DrawFPS(16,16);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}