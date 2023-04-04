#include <cstdlib>
#include <algorithm>
#include <iostream>

#include "raylib.h"
#include "raymath.h"
#include "config.h"

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
    Texture2D myTexture = LoadTexture("assets/graphics/testimage.png");
    RenderTexture2D canvas = LoadRenderTexture(Game::ScreenWidth, Game::ScreenHeight);
    float renderScale{}; //those two are relevant to drawing and code-cleanliness
    Rectangle renderRec{};

    int dudeX = 10;
    int dudeY = 100;

    Vector2 dudePos{10, 100};
    Vector2 dudeVel{};
    float maxSpeed = 2;

    // Main game loop
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

        dudeVel = Vector2Scale(dudeVel, 0.95);

        if (IsKeyDown(KEY_LEFT_SHIFT)) {
            maxSpeed = 6;
        } else {
            maxSpeed = 2;
        }

        if (IsKeyDown(KEY_D)) {
            dudeVel.x += maxSpeed;
        }

        if (IsKeyDown(KEY_A)) {
            dudeVel.x -= maxSpeed;
        }

        if (IsKeyDown(KEY_W)) {
            dudeVel.y -= maxSpeed;
        }

        if (IsKeyDown(KEY_S)) {
            dudeVel.y += maxSpeed;
        }

        if (Vector2Length(dudeVel) > maxSpeed)
            dudeVel = Vector2Scale(Vector2Normalize(dudeVel), maxSpeed);

        dudePos = Vector2Add(dudePos, dudeVel);

        BeginDrawing();
        // You can draw on the screen between BeginDrawing() and EndDrawing()
        // For the letterbox we draw on canvas instad
        BeginTextureMode(canvas);
        { //Within this block is where we draw our app to the canvas.
            ClearBackground(BLUE);
            DrawText(TextFormat("Current FPS: %i",GetFPS()), 10, 10, 30, BLACK);
            DrawTexture(myTexture, dudePos.x, dudePos.y, BLUE);
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
    } // Main game loop end

    // De-initialization here
    // ...
    // ...
    UnloadTexture(myTexture);

    // Close window and OpenGL context
    CloseWindow();

    return EXIT_SUCCESS;
}
