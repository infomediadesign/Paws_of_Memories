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
#include "Memories.h"

#include <nlohmann/json.hpp>
#include <fstream>

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

    //Texture2D map[(Game::ScreenHeight / 24) - 1][(Game::ScreenWidth / 24)] = {};

    //create tileMap
    int tiles[(Game::ScreenHeight / 24) - 1][(Game::ScreenWidth / 24)] =
            {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
             6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 4, 2, 2, 2, 2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 2, 2, 2, 2, 2, 2, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
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
    Game::Player *player = new Game::Player();
    player->setPos(24, 54);
    player->target_x = player->getPos().x;
    player->target_y = player->getPos().y;

    Texture2D wall1 = LoadTexture("assets/graphics/Template/Wall_and_Door/Cracked_Wall_1.png");
    Texture2D wall2 = LoadTexture("assets/graphics/Template/Wall_and_Door/wall_2.png");
    Texture2D wall3 = LoadTexture("assets/graphics/Template/Wall_and_Door/wall_3.png");
    Rectangle frameRec_Wall = {0.0f, 0.0f, (float) wall1.width, (float) wall1.height};
    Rectangle *wallSize = new Rectangle;
    //TEXTURE FOR DIRT TO TEST LEVEL CREATION

    Texture2D dirtT = LoadTexture("assets/graphics/Template/Tiles/Tiles.png");
    Rectangle frameRec_dirtT = {0.0f, 0.0f, (float) dirtT.width, (float) dirtT.height};
    Rectangle *dirtTSize = new Rectangle;
    std::vector<Game::Dirt> dirtList;
    int currentDirt = 0;
    //TEXTURE FOR MEMORIES TO TEST LEVEL CREATION

    Texture2D memories = LoadTexture("assets/graphics/Animation/Sheets/Objects/Polaroid-Sheet.png");
    Rectangle frameRec_Memories = {0.0f, 0.0f, (float) memories.width / 7, (float) memories.height};
    Rectangle *memoriesSize = new Rectangle;
    std::vector<Game::Memory> memoryList;
    int currentMemory = 0;

    /*
     * Test:
     *
     */

    //TEXTURE FOR WALLS TO TEST LEVEL CREATION

    //TEXTURE FOR BACKGROUND TO TEST LEVEL CREATION
    Texture2D background = LoadTexture(
            "assets/graphics/Animation/Sheets/Background/Background Animation - mit Color Palette.png");
    Rectangle backgroundFrame = {0.0f, 0.0f, (float) background.width / 11, (float) background.height};
    int collected = 0;

    //Game::Boulder boulder = *new Game::Boulder(1, 1); //Added the boulder to the main file

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

        Rectangle *tileSize = new Rectangle();
        tileSize->height = 24;
        tileSize->width = 24;


        //player inputs
        //check for collision
        if (player->lives > 0) {
            player->move();
            player->setRectangle(player->getPos().x, player->getPos().y, 24,24);
            for(int i=0; i < memoryList.size(); i++) { //CHECKT FÜR COLLISION BEI MEMORYS, UND FÜHRT BENÖTIGTE METHODEN AUS
                Rectangle collMemoryRectangle;
                collMemoryRectangle = {memoryList[i].getPos().x, memoryList[i].getPos().y, 24, 24};
                if (CheckCollisionRecs(player->getRectangle(),collMemoryRectangle)) {
                    if(memoryList[i].active) {
                        memoryList[i].setTexture({});
                        collected++;
                        memoryList[i].active = false;
                    }
                }
            }
            for(int i=0; i < dirtList.size(); i++) { //CHECKT FÜR COLLISION BEI MEMORYS, UND FÜHRT BENÖTIGTE METHODEN AUS
                Rectangle collDirtRectangle;
                collDirtRectangle = {dirtList[i].getPos().x, dirtList[i].getPos().y, 24, 24};
                if (CheckCollisionRecs(player->getRectangle(),collDirtRectangle)) {
                    if(dirtList[i].active) {
                        dirtList[i].setTexture({});
                        dirtList[i].active = false;
                    }
                }
            }

            //Code um Dirt zu deleten
            for (int i = 0; i < (Game::ScreenHeight / 24); i++) {
                for (int z = 0; z < (Game::ScreenWidth / 24); z++) {
                    Vector2 coordinates;
                    coordinates.x = z * 24;
                    coordinates.y = i * 24 + 30;
                    if (tiles[i][z] == 2) {
                        if (player->getPos().x == coordinates.x && player->getPos().y == coordinates.y) {
                            tiles[i][z] = 0;
                        }
                    } else if (tiles[i][z] == 5) {
                        if (player->getPos().x == coordinates.x && player->getPos().y == coordinates.y) {
                            player->lives--;
                            player->setPos(player->previousPosition.x, player->previousPosition.y);
                            player->target_x = player->previousPosition.x;
                            player->target_y = player->previousPosition.y;
                        }
                    }
                }
            }
        }

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

            wallSize->height = frameRec_Wall.height * renderScale;
            wallSize->width = frameRec_Wall.width * renderScale;
            dirtTSize->height = frameRec_dirtT.height * renderScale;
            dirtTSize->width = frameRec_dirtT.width * renderScale;
            memoriesSize->height = frameRec_Memories.height * renderScale;
            memoriesSize->width = frameRec_Memories.width * renderScale;

            renderRec.width = canvas.texture.width * renderScale;
            renderRec.height = canvas.texture.height * renderScale;
            renderRec.x = (GetScreenWidth() - renderRec.width) / 2.0f;
            renderRec.y = (GetScreenHeight() - renderRec.height) / 2.0f;


            DrawTexturePro(background, backgroundFrame,
                           renderRec,
                           {}, 0, WHITE);
            DrawText(TextFormat("Current FPS: %i", GetFPS()), 10 * renderScale, 5 * renderScale, 15 * renderScale, WHITE);
            DrawText(TextFormat("Paws Of Memories"), 190 * renderScale, 5 * renderScale, 15 * renderScale, WHITE);
            DrawText(TextFormat("Collected: %i", collected), 390 * renderScale, 5 * renderScale, 15 * renderScale, WHITE);

            //Draw the level layout with the array, going row for  row top to bottom
            for (int i = 0; i < (Game::ScreenHeight / 24)-1; i++) {
                for (int z = 0; z < (Game::ScreenWidth / 24); z++) {
                    Vector2 coordinates = {float(z * 24), float(i * 24 + 30)};
                    coordinates.x *= -1 * renderScale;
                    coordinates.y *= -1 * renderScale;
                    if (tiles[i][z] == 0) {
                        //Draw Nothing
                    } else if (tiles[i][z] == 1) {
                        //Draw Player
                    } else if (tiles[i][z] == 2) {
                        //Draw Dirt
                        if(currentDirt<138) {
                            dirtList.push_back(Game::Dirt(-coordinates.x, -coordinates.y));
                            dirtList[currentDirt].setTexture(dirtT);
                            currentDirt++;
                        }
                    } else if (tiles[i][z] == 3) {
                        //Draw Boulder
                    } else if (tiles[i][z] == 4) {
                        if(currentMemory<4) {
                            memoryList.push_back(Game::Memory(-coordinates.x, -coordinates.y));
                            memoryList[currentMemory].setTexture(memories);
                            currentMemory++;
                        }
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

            //TEST
            for(int i=0; i < dirtList.size(); i++) {
                Vector2 position = dirtList[i].getPos();
                position.x *= -1*renderScale;
                position.y *= -1*renderScale;
                DrawTexturePro(dirtList[i].getTexture(), frameRec_dirtT, *dirtTSize, position, 0, WHITE);
            }
            for(int i=0; i < memoryList.size(); i++) {
                Vector2 position = memoryList[i].getPos();
                position.x *= -1*renderScale;
                position.y *= -1*renderScale;
                DrawTexturePro(memoryList[i].getTexture(), frameRec_Memories, *memoriesSize, position, 0, WHITE);
            }
            //END TEST

            Rectangle *playerSize = new Rectangle;
            playerSize->height = player->frameRec_left.height * renderScale;
            playerSize->width = player->frameRec_left.width * renderScale;
            Vector2 playerVector;
            playerVector.x = player->getPos().x * -1 * renderScale;
            playerVector.y = player->getPos().y * -1 * renderScale;
            if (!player->twoKeysPressed && player->animation_up ||player->animation_down || player->animation_right || player->animation_left) {
                if (player->animation_up) {
                    DrawTexturePro(player->player_back, player->frameRec_back, *playerSize, playerVector, 0, WHITE);
                }
                if (player->animation_down) {
                    DrawTexturePro(player->player_front, player->frameRec_front, *playerSize, playerVector, 0, WHITE);
                }
                if (player->animation_right) {
                    DrawTexturePro(player->player_right, player->frameRec_right, *playerSize, playerVector, 0, WHITE);
                }
                if (player->animation_left) {
                    DrawTexturePro(player->player_left, player->frameRec_left, *playerSize, playerVector, 0, WHITE);
                }
            } else {
                if (player->r0l1 == 0 && !player->moving) {
                    DrawTexturePro(player->player_idleRight, player->frameRec_idleRight, *playerSize, playerVector, 0,
                                   WHITE);
                }
                if (player->r0l1 == 1 && !player->moving) {
                    DrawTexturePro(player->player_idleLeft, player->frameRec_idleLeft, *playerSize, playerVector, 0,
                                   WHITE);
                }
            }
        }
        /*go through the vector and draw them.
        memoryList.
        for(int i=0; i<memoryList.size();i++) {

        }*/
        EndDrawing();
    } // Main game loop end

    // De-initialization here
    // ...
    // ...
    UnloadTexture(player->getTexture());

    // Close window and OpenGL context
    CloseWindow();

    return EXIT_SUCCESS;
}