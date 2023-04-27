#include <cstdlib>
#include <algorithm>
#include <iostream>

#include "raylib.h"
#include "raymath.h"
#include "config.h"
#include "Player.h"
#include "Dirt.h"

//Schwipp Schwapp

/*
 * TO-DO List:
 * Create new classes for:
 * Memories (cpp  and h)
 * Boulder (cpp and h)
 * Sprite (for texture loading, updating etc.)
 * Screen (for window creation etc)
 * Controller (cpp and h; for movement, collision...)
 *
 * To work on a copy void name(int & x) {} <-- durch das & wird das original bearbeitet
 */

int main() {
    // Raylib initialization
    // Project name, screen size, fullscreen mode etc. can be specified in the config.h.in file
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitWindow(Game::ScreenWidth, Game::ScreenHeight, Game::PROJECT_NAME);
    SetTargetFPS(200);

#ifdef GAME_START_FULLSCREEN
    ToggleFullscreen();
#endif

    // Your own initialization code here
    // ...
    // ...
    RenderTexture2D canvas = LoadRenderTexture(Game::ScreenWidth, Game::ScreenHeight);
    float renderScale{}; //those two are relevant to drawing and code-cleanliness
    Rectangle renderRec{};

    //create the player
    Game::Player player = *new Game::Player(0, 0);

    //create all the dirt

    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        if (IsKeyDown(KEY_LEFT_ALT) && IsKeyPressed(KEY_ENTER)) { //Fullscreen logic.
            if (IsWindowFullscreen()) {
                ToggleFullscreen();
                SetWindowSize(Game::ScreenWidth, Game::ScreenHeight);
            } else {
                SetWindowSize(GetMonitorWidth(GetCurrentMonitor()), GetMonitorHeight(GetCurrentMonitor()));
                ToggleFullscreen();
            }
        }

        BeginDrawing();
        // You can draw on the screen between BeginDrawing() and EndDrawing()
        // For the letterbox we draw on canvas instad
        BeginTextureMode(canvas);
        { //Within this block is where we draw our app to the canvas.
            ClearBackground(WHITE);
            DrawText(TextFormat("Current FPS: %i", GetFPS()), 10, 10, 30, BLACK);
            DrawText(TextFormat("Paws Of Memories"), 480, 10, 30, BLACK);

            if (IsKeyDown(KEY_W)) {
                DrawTextureRec(player.player_back, player.frameRec_back, player.pos_pl, WHITE);
            }
            if (IsKeyDown(KEY_S)) {
                DrawTextureRec(player.player_front, player.frameRec_front, player.pos_pl, WHITE);
            }
            if (IsKeyDown(KEY_D)) {
                DrawTextureRec(player.player_right, player.frameRec_right, player.pos_pl, WHITE);
            }
            if (IsKeyDown(KEY_A)) {
                DrawTextureRec(player.player_left, player.frameRec_left, player.pos_pl, WHITE);
            }
        }
        EndTextureMode();
        //The following lines put the canvas in the middle of the window and have the negative as black
        ClearBackground(BLACK);
        renderScale = std::min(GetScreenHeight() /
                               (float) canvas.texture.height, //Calculates how big or small the canvas has to be rendered.
                               GetScreenWidth() / (float) canvas.texture.width);
        renderRec.width = canvas.texture.width * renderScale;
        renderRec.height = canvas.texture.height * renderScale;
        renderRec.x = (GetScreenWidth() - renderRec.width) / 2.0f;
        renderRec.y = (GetScreenHeight() - renderRec.height) / 2.0f;
        DrawTexturePro(canvas.texture, Rectangle{0, 0, (float) canvas.texture.width, (float) -canvas.texture.height},
                       renderRec,
                       {}, 0, WHITE);

        EndDrawing();

        //player inputs

        //check for collision
        Rectangle collPlayerRectangle;
        if(player.lives>0) {
            player.move();

            collPlayerRectangle = {player.pos_pl.x, player.pos_pl.y, (float) player.getTexture().width, (float) player.getTexture().height};
            /*if(CheckCollisionPointRec(dirt.getPos(), collPlayerRectangle)) {
                dirt.destroyed = true;
                //entity needs to be deleted
            }*/
        }

    } // Main game loop end

    // De-initialization here
    // ...
    // ...
    UnloadTexture(player.getTexture());

    // Close window and OpenGL context
    CloseWindow();

    return EXIT_SUCCESS;
}