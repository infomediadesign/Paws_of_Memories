#include <cstdlib>
#include <algorithm>
#include <iostream>

#include "raylib.h"
#include "raymath.h"
#include "config.h"
#include "Player.h"
#include "Dirt.h"

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
    Game::Dirt dirt;
    dirt.setPos(600, 300);

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
        Texture2D dirtT = LoadTexture("assets/graphics/cat.png");
        BeginTextureMode(canvas);
        { //Within this block is where we draw our app to the canvas.
            ClearBackground(WHITE);
            DrawText(TextFormat("Current FPS: %i",GetFPS()), 10, 10, 30, BLACK);
            DrawText(TextFormat("Paws Of Memories"), GetScreenWidth()/2, GetScreenHeight()-500, 30, BLACK);
            DrawTexture(player.getTexture(), player.getPos().x, player.getPos().y, WHITE);
            DrawTexture(dirt.getTexture(), dirt.getPos().x, dirt.getPos().y, WHITE);
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
            collPlayerRectangle = {player.pos.x, player.pos.y, (float) player.getTexture().width, (float) player.getTexture().height};
            if(CheckCollisionPointRec(dirt.getPos(), collPlayerRectangle)) {
                dirt.destroyed = true;
                UnloadTexture(dirt.getTexture());
                dirt.setTexture(LoadTexture("assets/graphics/BWcat.png"));
                //entity needs to be deleted
            }
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