#include <cstdlib>
#include <algorithm>
#include <iostream>

#include "raylib.h"
#include "raymath.h"
#include "config.h"
#include "Player.h"
#include "Dirt.h"
#include "Boulder.h"

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

    //create tileMap
    int tiles[(Game::ScreenHeight / 48) - 1][(Game::ScreenWidth / 48)] =
            {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
             6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6};

    /*
     * Array rules:
     * 0 = Nothing
     * 1 = Player
     * 2 = Dirt
     * 3 = Boulder
     * 4 = Memory
     * 5 = Enemy
     * 6 = Wall
     * 7 = Exit
     */
    //TEST TEXTURE FOR DIRT TO TEST LEVEL CREATION
    Texture2D door = LoadTexture("assets/graphics/Animation/Sheets/Objects/Door/Door_Animation.png");
    Rectangle frameRec_door = {0.0f, 0.0f, (float) door.width / 3, (float) door.height};
    Rectangle doorSize = *new Rectangle;
    doorSize.height = frameRec_door.height * 2;
    doorSize.width = frameRec_door.width * 2;

    //create the player
    Game::Player player = *new Game::Player(48, 108);
    Game::Boulder boulder = *new Game::Boulder(1, 1); //Added the boulder to the main file

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


        Rectangle rectangle = *new Rectangle();
        rectangle.height = 48;
        rectangle.width = 48;
        BeginDrawing();
        // You can draw on the screen between BeginDrawing() and EndDrawing()
        // For the letterbox we draw on canvas instad
        BeginTextureMode(canvas);
        { //Within this block is where we draw our app to the canvas.
            ClearBackground(WHITE);
            DrawText(TextFormat("Current FPS: %i", GetFPS()), 10, 10, 30, BLACK);
            DrawText(TextFormat("Paws Of Memories"), 480, 10, 30, BLACK);

            //Draw the level layout with the array, going row for  row top to bottom
            for (int i = 0; i < (Game::ScreenHeight / 48); i++) {
                for (int z = 0; z < (Game::ScreenWidth / 48); z++) {
                    Vector2 coordinates;
                    coordinates.x = z * 48;
                    coordinates.y = i * 48 + 60;
                    if (tiles[i][z] == 0) {
                        //Draw Nothing
                    } else if (tiles[i][z] == 1) {
                        //Draw Player
                    } else if (tiles[i][z] == 2) {
                        //Draw Dirt
                        DrawRectangle(coordinates.x, coordinates.y, 48, 48, BROWN);
                        //DrawTexturePro(door, frameRec_door, doorSize, coordinates, 0, WHITE);
                    } else if (tiles[i][z] == 3) {
                        //Draw Boulder
                    } else if (tiles[i][z] == 4) {
                        //Draw Memory
                    } else if (tiles[i][z] == 5) {
                        //Draw Enemy
                    } else if (tiles[i][z] == 6) {
                        //Draw Door
                        rectangle.x = coordinates.x;
                        rectangle.y = coordinates.y;
                        DrawRectangleRec(rectangle, GRAY);
                        //DrawRectangle(coordinates.x, coordinates.y, 48, 48, GRAY);
                    }
                }
            }

            Rectangle playerSize = *new Rectangle;
            playerSize.height = player.frameRec_left.height * 2;
            playerSize.width = player.frameRec_left.width * 2;
            Vector2 playerVector;
            playerVector.x = player.getPos().x * -1;
            playerVector.y = player.getPos().y * -1;
            if (!player.twoKeysPressed && (IsKeyDown(KEY_W) || IsKeyDown(KEY_A) || IsKeyDown(KEY_S) || IsKeyDown(KEY_D))) {
                if (IsKeyDown(KEY_W) && !IsKeyDown(KEY_D) && !IsKeyDown(KEY_S) && !IsKeyDown(KEY_A)) {
                    DrawTexturePro(player.player_back, player.frameRec_back, playerSize, playerVector, 0, WHITE);
                }
                if (IsKeyDown(KEY_S) && !IsKeyDown(KEY_W) && !IsKeyDown(KEY_D) && !IsKeyDown(KEY_A)) {
                    DrawTexturePro(player.player_front, player.frameRec_front, playerSize, playerVector, 0, WHITE);
                }
                if (IsKeyDown(KEY_D) && !IsKeyDown(KEY_S) && !IsKeyDown(KEY_A) && !IsKeyDown(KEY_W)) {
                    DrawTexturePro(player.player_right, player.frameRec_right, playerSize, playerVector, 0, WHITE);
                }
                if (IsKeyDown(KEY_A) && !IsKeyDown(KEY_W) && !IsKeyDown(KEY_D) && !IsKeyDown(KEY_S)) {
                    DrawTexturePro(player.player_left, player.frameRec_left, playerSize, playerVector, 0, WHITE);
                }
            } else {

                if (player.r0l1 == 0) {
                    DrawTexturePro(player.player_idleRight, player.frameRec_idleRight, playerSize, playerVector, 0,
                                   WHITE);
                }
                if (player.r0l1 == 1) {
                    DrawTexturePro(player.player_idleLeft, player.frameRec_idleLeft, playerSize, playerVector, 0,
                                   WHITE);
                }
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
        Vector2 wall = {rectangle.x, rectangle.y};
        if (player.lives > 0) {
            player.move();

            collPlayerRectangle = {player.pos_pl.x, player.pos_pl.y, collPlayerRectangle.width,
                                   collPlayerRectangle.height};
            if (CheckCollisionPointRec(wall, collPlayerRectangle)) {

                DrawRectangleRec(rectangle, WHITE);
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