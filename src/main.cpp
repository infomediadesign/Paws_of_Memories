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
 * Screen (for window creation etc)
 * Controller (cpp and h; for movement, collision...)
 *
 * Konstu --> Tiled
 *
 * To work on a copy void name(int & x) {} <-- durch das & wird das original bearbeitet
 */

void fillVectors(int map[], std::vector<Game::Dirt> &dirtList, std::vector<Game::Memory> &memoryList, std::vector<Game::Boulder> &boulderList);

int main() {
    bool generated;
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
    int map[(Game::ScreenHeight/24) * (Game::ScreenWidth/24)] =
            {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
             6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 4, 2, 2, 2, 2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 2, 2, 2, 2, 2, 2, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 2, 2, 2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6};
    //create the player
    Game::Player *player = new Game::Player();
    player->setPos(24, 54);
    player->target_x = player->getPos().x;
    player->target_y = player->getPos().y;

    Texture2D wall1 = LoadTexture("assets/graphics/Template/Wall_and_Door/Cracked_Wall_1.png");
    Texture2D wall2 = LoadTexture("assets/graphics/Template/Wall_and_Door/wall_2.png");
    Texture2D wall3 = LoadTexture("assets/graphics/Template/Wall_and_Door/wall_3.png");
    Rectangle frameRec_Wall = {0.0f, 0.0f, (float) wall1.width, (float) wall1.height};
    Rectangle wallSize;
    //TEXTURE FOR DIRT TO TEST LEVEL CREATION

    Texture2D dirtT = LoadTexture("assets/graphics/Template/Tiles/Tiles.png");
    Rectangle frameRec_dirtT = {0.0f, 0.0f, (float) dirtT.width, (float) dirtT.height};
    Rectangle dirtTSize;
    std::vector<Game::Dirt> dirtList;
    int currentDirt = 0;
    //TEXTURE FOR MEMORIES TO TEST LEVEL CREATION

    Texture2D memories = LoadTexture("assets/graphics/Animation/Sheets/Objects/Polaroid-Sheet.png");
    Rectangle frameRec_Memories = {0.0f, 0.0f, (float) memories.width / 7, (float) memories.height};
    Rectangle memoriesSize;
    std::vector<Game::Memory> memoryList;
    int currentMemory = 0;

    //Test for boulders
    Texture2D boulder = LoadTexture("assets/graphics/Animation/Sheets/Objects/Boulder-Sheet.png");
    Rectangle frameRec_Boulder = {0.0f, 0.0f, (float) boulder.width / 5, (float) boulder.height};
    Rectangle boulderSize;
    std::vector<Game::Boulder> boulderList;
    int currentBoulder = 0;

    //TEXTURE FOR BACKGROUND TO TEST LEVEL CREATION
    Texture2D background = LoadTexture(
            "assets/graphics/Animation/Sheets/Background/Background Animation - mit Color Palette.png");
    Rectangle backgroundFrame = {0.0f, 0.0f, (float) background.width / 11, (float) background.height};
    int collected = 0;

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

        BeginDrawing();
        // You can draw on the screen between BeginDrawing() and EndDrawing()
        // For the letterbox we draw on canvas instad
        BeginTextureMode(canvas);
        { //Within this block is where we draw our app to the canvas.
            ClearBackground(WHITE);
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
        DrawTexturePro(background, backgroundFrame,
                       renderRec,
                       {}, 0, WHITE);
        // Textur wird nicht auf canvas gezeichnet!!!!!!!!
        //All diese berechnungen mit renderscale sind nicht nötig, wenn ihr auf canvas zeichnet -Oli
        wallSize.height = frameRec_Wall.height * renderScale;
        wallSize.width = frameRec_Wall.width * renderScale;
        dirtTSize.height = frameRec_dirtT.height * renderScale;
        dirtTSize.width = frameRec_dirtT.width * renderScale;
        memoriesSize.height = frameRec_Memories.height * renderScale;
        memoriesSize.width = frameRec_Memories.width * renderScale;
        boulderSize.height = frameRec_Boulder.height * renderScale;
        boulderSize.width = frameRec_Boulder.width * renderScale;

        // ------------------------------------------------------------------
        for (int i = 0; i < sizeof(map)/sizeof(int); i++) { //geht den Array durch
            int xPos = (i%20)*24; // gibt einen Wert von 0-19 * 24
            int yPos = (i/20)*24+6; // geht alle 20 Tiles in eine neue Zeile
            Vector2 coordinates = {(float)xPos, (float)yPos}; //erstellt Vektor
            coordinates.x *= -1 * renderScale;
            coordinates.y *= -1 * renderScale; //für Größe, kann man inroeieren
            if (map[i] == 0) {
                //Draw Nothing
            } else if (map[i] == 1) {
                //Draw Player
            } else if (map[i] == 2) {
                //Draw Dirt
                if(currentDirt<157) {
                    dirtList.push_back(Game::Dirt(-coordinates.x, -coordinates.y)); // Objekt zu Vektor hinzfügen, textur geben
                    dirtList[currentDirt].setTexture(dirtT);
                    currentDirt++;
                }
            } else if (map[i] == 3) {
                //Draw Boulder
                if(currentBoulder<1) {
                    boulderList.push_back(Game::Boulder(-coordinates.x, -coordinates.y));
                    boulderList[currentMemory].setTexture(boulder);
                    currentBoulder++;
                }
            } else if (map[i] == 4) {
                if(currentMemory<4) {
                    memoryList.push_back(Game::Memory(-coordinates.x, -coordinates.y));
                    memoryList[currentMemory].setTexture(memories);
                    currentMemory++;
                }
            } else if (map[i] == 5) {
                //Draw Enemy
            } else if (map[i] == 6) {
                //Draw Wall
                DrawTexturePro(wall1, frameRec_Wall, wallSize, coordinates, 0, WHITE); //da keine Klasse nur zeichnen
                /*int w = rand()%(3-1+1);randomizer
                if(w==1)DrawTexturePro(wall1, frameRec_Wall, *wallSize, coordinates, 0, WHITE);
                if(w==2)DrawTexturePro(wall2, frameRec_Wall, *wallSize, coordinates, 0, WHITE);
                if(w==3)DrawTexturePro(wall3, frameRec_Wall, *wallSize, coordinates, 0, WHITE);*/
            } else {}
        }
        // ------------------------------------------------------------------

        //TEST
        for(int i=0; i < dirtList.size(); i++) {
            Vector2 position = dirtList[i].getPos();
            position.x *= -1*renderScale;
            position.y *= -1*renderScale;
            DrawTexturePro(dirtList[i].getTexture(), frameRec_dirtT, dirtTSize, position, 0, WHITE);
        }
        for(int i=0; i < memoryList.size(); i++) {
            Vector2 position = memoryList[i].getPos();
            position.x *= -1*renderScale;
            position.y *= -1*renderScale;
            DrawTexturePro(memoryList[i].getTexture(), frameRec_Memories, memoriesSize, position, 0, WHITE);
        }
        for(int i=0; i < boulderList.size(); i++) {
            Vector2 position = boulderList[i].getPos();
            position.x *= -1*renderScale;
            position.y *= -1*renderScale;
            DrawTexturePro(boulderList[i].getTexture(), frameRec_Boulder, boulderSize, position, 0, WHITE);
        }
        DrawText(TextFormat("Current FPS: %i", GetFPS()), 10 * renderScale, 5 * renderScale, 15 * renderScale, WHITE);
        DrawText(TextFormat("Paws Of Memories"), 190 * renderScale, 5 * renderScale, 15 * renderScale, WHITE);
        DrawText(TextFormat("Collected: %i", collected), 390 * renderScale, 5 * renderScale, 15 * renderScale, WHITE);

        //player inputs
        //check for collision
        if (player->lives > 0) {
            player->updatePlayer();
            for(int i=0; i < memoryList.size(); i++) { //CHECKT FÜR COLLISION BEI MEMORYS, UND FÜHRT BENÖTIGTE METHODEN AUS
                Rectangle collMemoryRectangle;
                collMemoryRectangle = {memoryList[i].getPos().x, memoryList[i].getPos().y, 24, 24};
                if (CheckCollisionRecs(player->getCollRec(),collMemoryRectangle)) {
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
                if (CheckCollisionRecs(player->getCollRec(),collDirtRectangle)) {
                    if(dirtList[i].active) {
                        dirtList[i].setTexture({});
                        dirtList[i].active = false;
                    }
                }
            }

            //Code um Dirt zu deleten
            for (int i = 0; i < sizeof(map)/sizeof(int); i++) {
                int xPos = (i%20)*24;
                int yPos = (i/20)*24+6;
                Vector2 coordinates = {(float)xPos, (float)yPos};
                coordinates.x *= -1 * renderScale;
                coordinates.y *= -1 * renderScale;
                    if (map[i] == 2) {
                        if (player->getPos().x == coordinates.x && player->getPos().y == coordinates.y) {
                            map[i] = 0;
                        }
                    } else if (map[i] == 5) {
                        if (player->getPos().x == coordinates.x && player->getPos().y == coordinates.y) {
                            player->lives--;
                            player->setPos(player->previousPosition.x, player->previousPosition.y);
                            player->target_x = player->previousPosition.x;
                            player->target_y = player->previousPosition.y;
                        }
                    }
                }
            }
            boulderList[0].direction = FallLeft;
            boulderList[0].fall();
            //END TEST

        Rectangle playerSize;
        playerSize.height = player->frameRec_left.height * renderScale;
        playerSize.width = player->frameRec_left.width * renderScale;

        playerSize.x = player->getPos().x * renderScale;
        playerSize.y = player->getPos().y * renderScale;
        if (!player->twoKeysPressed && player->animation_up ||player->animation_down || player->animation_right || player->animation_left) {
            if (player->animation_up) {
                DrawTexturePro(player->player_back, player->frameRec_back, playerSize, {}, 0, WHITE);
            }
            if (player->animation_down) {
                DrawTexturePro(player->player_front, player->frameRec_front, playerSize, {}, 0, WHITE);
            }
            if (player->animation_right) {
                DrawTexturePro(player->player_right, player->frameRec_right, playerSize, {}, 0, WHITE);
            }
            if (player->animation_left) {
                DrawTexturePro(player->player_left, player->frameRec_left, playerSize, {}, 0, WHITE);
            }
        } else {
            if (player->r0l1 == 0 && !player->moving) {
                DrawTexturePro(player->player_idleRight_PawDown, player->frameRec_idleRight, playerSize, {}, 0,
                               WHITE);
            }
            if (player->r0l1 == 1 && !player->moving) {
                DrawTexturePro(player->player_idleLeft_PawDown, player->frameRec_idleLeft, playerSize, {}, 0,
                               WHITE);
            }
        }
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

void drawLevel(int *map[], Game::Player &player, std::vector<Game::Dirt> &dirtList, std::vector<Game::Memory> &memoryList, std::vector<Game::Boulder> &boulderList) { //Wall vector missing, no class yet

}


void fillVectors(int map[], std::vector<Game::Dirt> &dirtList, std::vector<Game::Memory> &memoryList, std::vector<Game::Boulder> &boulderList) {
    Texture2D wall1 = LoadTexture("assets/graphics/Template/Wall_and_Door/Cracked_Wall_1.png");
    int currentDirt = 0;
    Texture2D dirtT = LoadTexture("assets/graphics/Template/Tiles/Tiles.png");
    int currentMemory = 0;
    Texture2D memories = LoadTexture("assets/graphics/Animation/Sheets/Objects/Polaroid-Sheet.png");
    int currentBoulder = 0;
    Texture2D boulder = LoadTexture("assets/graphics/Animation/Sheets/Objects/Boulder-Sheet.png");
    for (int i = 0; i < sizeof(map)/sizeof(int); i++) {
        int xPos = (i%20)*24;
        int yPos = (i/20)*24+6;
        Vector2 coordinates = {(float)xPos, (float)yPos};
        coordinates.x *= -1;
        coordinates.y *= -1;
        if (map[i] == 0) {
            //Draw Nothing
        } else if (map[i] == 1) {
            //Draw Player
        } else if (map[i] == 2) {
            //Draw Dirt
            if(currentDirt<157) {
                dirtList.push_back(Game::Dirt(-coordinates.x, -coordinates.y));
                dirtList[currentDirt].setTexture(dirtT);
                currentDirt++;
            }
        } else if (map[i] == 3) {
            //Draw Boulder
            if(currentBoulder<1) {
                boulderList.push_back(Game::Boulder(-coordinates.x, -coordinates.y));
                boulderList[currentMemory].setTexture(boulder);
                currentBoulder++;
            }
        } else if (map[i] == 4) {
            if(currentMemory<4) {
                memoryList.push_back(Game::Memory(-coordinates.x, -coordinates.y));
                memoryList[currentMemory].setTexture(memories);
                currentMemory++;
            }
        } else if (map[i] == 5) {
            //Draw Enemy
        } else if (map[i] == 6) {
            //Draw Wall
            DrawTexture(wall1, coordinates.x, coordinates.y, WHITE);
            /*int w = rand()%(3-1+1);randomizer
            if(w==1)DrawTexturePro(wall1, frameRec_Wall, *wallSize, coordinates, 0, WHITE);
            if(w==2)DrawTexturePro(wall2, frameRec_Wall, *wallSize, coordinates, 0, WHITE);
            if(w==3)DrawTexturePro(wall3, frameRec_Wall, *wallSize, coordinates, 0, WHITE);*/
        } else {}
    }
}