#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <list>

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
 * Sprite (for texture loading, updating etc.)?
 * Screen (for window creation etc)
 * Controller (cpp and h; for movement, collision...)
 *
 * Nicole --> Player Movement anpassen (Pokémon like) No Animation needed, just the movement
 * Till & Konsti --> Sprites Klasse fertigstellen & Animationen bearbeiten
 * Konstu --> Tiled
 *
 * To work on a copy void name(int & x) {} <-- durch das & wird das original bearbeitet
 */

int main() {
    // Raylib initialization
    // Project name, screen size, fullscreen mode etc. can be specified in the config.h.in file
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitWindow(Game::ScreenWidth, Game::ScreenHeight, Game::PROJECT_NAME);
    SetTargetFPS(60);

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
             6, 2, 2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 4, 2, 2, 2, 2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 2, 2, 2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
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
    //create the player
    Game::Player* player = new Game::Player();
    player->setPos(48, 108);
    player->target_x=player->getPos().x;
    player->target_y=player->getPos().y;

    //TEXTURE FOR WALLS TO TEST LEVEL CREATION
    Texture2D wall1 = LoadTexture("assets/graphics/Template/Wall_and_Door/Cracked_Wall_1.png");
    Texture2D wall2 = LoadTexture("assets/graphics/Template/Wall_and_Door/wall_2.png");
    Texture2D wall3 = LoadTexture("assets/graphics/Template/Wall_and_Door/wall_3.png");
    Rectangle frameRec_Wall = {0.0f, 0.0f, (float) wall1.width, (float) wall1.height};
    Rectangle* wallSize = new Rectangle;
    wallSize->height = frameRec_Wall.height * 2;
    wallSize->width = frameRec_Wall.width * 2;
    //TEXTURE FOR DIRT TO TEST LEVEL CREATION

    Texture2D dirtT = LoadTexture("assets/graphics/Template/Tiles/Tiles.png");
    Rectangle frameRec_dirtT = {0.0f, 0.0f, (float) dirtT.width, (float) dirtT.height};
    Rectangle* dirtTSize = new Rectangle;
    dirtTSize->height = frameRec_dirtT.height * 2;
    dirtTSize->width = frameRec_dirtT.width * 2;
    //TEXTURE FOR MEMORIES TO TEST LEVEL CREATION

    Texture2D memories = LoadTexture("assets/graphics/Animation/Sheets/Objects/Polaroid-Sheet.png");
    Rectangle frameRec_Memories = {0.0f, 0.0f, (float) memories.width/7, (float) memories.height};
    Rectangle* memoriesSize = new Rectangle;
    memoriesSize->height = frameRec_Memories.height * 2;
    memoriesSize->width = frameRec_Memories.width * 2;

    //TEXTURE FOR BACKGROUND TO TEST LEVEL CREATION
    Texture2D background = LoadTexture("assets/graphics/Animation/Sheets/Background/Background Animation - mit Color Palette.png");
    int collected = 0;

    //Game::Boulder boulder = *new Game::Boulder(1, 1); //Added the boulder to the main file

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

        Rectangle* rectangle = new Rectangle();
        rectangle->height = 48;
        rectangle->width = 48;
        BeginDrawing();
        // You can draw on the screen between BeginDrawing() and EndDrawing()
        // For the letterbox we draw on canvas instad
        BeginTextureMode(canvas);
        { //Within this block is where we draw our app to the canvas.
            ClearBackground(WHITE);
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
        DrawTexturePro(background, Rectangle{0, 0, (float) background.width/11, (float) -background.height},
                       renderRec,
                       {}, 0, WHITE);
            DrawText(TextFormat("Current FPS: %i", GetFPS()), 10, 10, 30, WHITE);
            DrawText(TextFormat("Paws Of Memories"), 380, 10, 30, WHITE);
            DrawText(TextFormat("Collected: %i", collected), 740, 10, 30, WHITE);

            //Draw the level layout with the array, going row for  row top to bottom
            for (int i = 0; i < (Game::ScreenHeight / 48); i++) {
                for (int z = 0; z < (Game::ScreenWidth / 48); z++) {
                    Vector2 coordinates = {float (z * 48), float (i * 48 + 60)};
                    coordinates.x *= -1;
                    coordinates.y *= -1;
                    if (tiles[i][z] == 0) {
                        //Draw Nothing
                    } else if (tiles[i][z] == 1) {
                        //Draw Player
                    } else if (tiles[i][z] == 2) {
                        //Draw Dirt
                        DrawTexturePro(dirtT, frameRec_dirtT, *dirtTSize, coordinates, 0, WHITE);
                    } else if (tiles[i][z] == 3) {
                        //Draw Boulder
                    } else if (tiles[i][z] == 4) {
                        //Draw Memory -=- No animation implemented yet -=-
                        DrawTexturePro(memories, frameRec_Memories, *memoriesSize, coordinates, 0, WHITE);
                    } else if (tiles[i][z] == 5) {
                        //Draw Enemy
                    } else if (tiles[i][z] == 6) {
                        //Draw Wall
                        DrawTexturePro(wall1, frameRec_Wall, *wallSize, coordinates, 0, WHITE);
                        /*int w = rand()%(3-1+1);randomizer
                        if(w==1)DrawTexturePro(wall1, frameRec_Wall, *wallSize, coordinates, 0, WHITE);
                        if(w==2)DrawTexturePro(wall2, frameRec_Wall, *wallSize, coordinates, 0, WHITE);
                        if(w==3)DrawTexturePro(wall3, frameRec_Wall, *wallSize, coordinates, 0, WHITE);*/
                    } else {}
                }
            }

            Rectangle* playerSize = new Rectangle;
            playerSize->height = player->frameRec_left.height * 2;
            playerSize->width = player->frameRec_left.width * 2;
            Vector2 playerVector;
            playerVector.x = player->getPos().x * -1;
            playerVector.y = player->getPos().y * -1;
            if (!player->twoKeysPressed && (IsKeyDown(KEY_W) || IsKeyDown(KEY_A) || IsKeyDown(KEY_S) || IsKeyDown(KEY_D))) {
                if (IsKeyDown(KEY_W) && !IsKeyDown(KEY_D) && !IsKeyDown(KEY_S) && !IsKeyDown(KEY_A)) {
                    DrawTexturePro(player->player_back, player->frameRec_back, *playerSize, playerVector, 0, WHITE);
                }
                if (IsKeyDown(KEY_S) && !IsKeyDown(KEY_W) && !IsKeyDown(KEY_D) && !IsKeyDown(KEY_A)) {
                    DrawTexturePro(player->player_front, player->frameRec_front, *playerSize, playerVector, 0, WHITE);
                }
                if (IsKeyDown(KEY_D) && !IsKeyDown(KEY_S) && !IsKeyDown(KEY_A) && !IsKeyDown(KEY_W)) {
                    DrawTexturePro(player->player_right, player->frameRec_right, *playerSize, playerVector, 0, WHITE);
                }
                if (IsKeyDown(KEY_A) && !IsKeyDown(KEY_W) && !IsKeyDown(KEY_D) && !IsKeyDown(KEY_S)) {
                    DrawTexturePro(player->player_left, player->frameRec_left, *playerSize, playerVector, 0, WHITE);
                }
            } else {
                if (player->r0l1 == 0) {
                    DrawTexturePro(player->player_idleRight, player->frameRec_idleRight, *playerSize, playerVector, 0,
                                   WHITE);
                }
                if (player->r0l1 == 1) {
                    DrawTexturePro(player->player_idleLeft, player->frameRec_idleLeft, *playerSize, playerVector, 0,
                                   WHITE);
                }
            }
        }
        EndDrawing();

        //player inputs
        //check for collision
        Rectangle collPlayerRectangle;
        Vector2 wall = {rectangle->x, rectangle->y};
        if (player->lives > 0) {
            player->move();
            collPlayerRectangle = {player->pos.x, player->pos.y, collPlayerRectangle.width,
                                   collPlayerRectangle.height};
            if (CheckCollisionPointRec(wall, collPlayerRectangle)) {

                //DrawRectangleRec(rectangle, WHITE);
                //entity needs to be deleted
            }

            //Code um Dirt zu deleten
            for (int i = 0; i < (Game::ScreenHeight / 48); i++) {
                for (int z = 0; z < (Game::ScreenWidth / 48); z++) {
                    Vector2 coordinates;
                    coordinates.x = z * 48;
                    coordinates.y = i * 48 + 60;
                    if (tiles[i][z] == 2) {
                        if(player->getPos().x == coordinates.x && player->getPos().y == coordinates.y) {
                            tiles[i][z] = 0;
                        }
                    } else if (tiles[i][z] == 4) {
                        if(player->getPos().x == coordinates.x && player->getPos().y == coordinates.y) {
                            tiles[i][z] = 0;
                            collected++;
                        }
                    }
                }
            }
        }

    } // Main game loop end

    // De-initialization here
    // ...
    // ...
    UnloadTexture(player->getTexture());

    // Close window and OpenGL context
    CloseWindow();

    return EXIT_SUCCESS;
}