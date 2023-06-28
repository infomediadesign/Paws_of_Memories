//
// Created by konst on 01.05.2023.
//

#include <iostream>
#include "raylib.h"
#include "LevelData.h"
#include "GameScreen.h"

Game::GameScreen::GameScreen() {
    LoadTextures();
    generateMap();
}

void Game::GameScreen::LoadTextures() {
    dirtT = LoadTexture("assets/graphics/Template/Tiles/Tileset.png");dirtT;
    frameRec_dirtT = {0.0f, 0.0f, (float) dirtT.width/4, (float) dirtT.height/4};
    memories = LoadTexture("assets/graphics/Animation/Sheets/Objects/Polaroid-Sheet.png");
    frameRec_Memories = {0.0f, 0.0f, (float) memories.width / 7, (float) memories.height};
    boulder = LoadTexture("assets/graphics/Animation/Sheets/Objects/Boulder/OLDBoulder-Sheet.png");
    frameRec_Boulder = {0.0f, 0.0f, (float) boulder.width / 5, (float) boulder.height};
    crackedWall = LoadTexture("assets/graphics/Template/Wall_and_Door/Cracked_Wall_1.png");
    wall2 = LoadTexture("assets/graphics/Template/Wall_and_Door/wall_2.png");
    wall3 = LoadTexture("assets/graphics/Template/Wall_and_Door/wall_3.png");
    frameRec_Wall = {0.0f, 0.0f, (float) 24, 24};
}

void Game::GameScreen::InitPlayer(int valueX, int valueY) {
    Vector2 playerStartPosition;
    //playerStartPosition.x = array place;
    //playerStartPosition.y = array place;
    //for now:
    playerStartPosition.x = valueX;
    playerStartPosition.y = valueY;
    player.target_x = playerStartPosition.x;
    player.target_y = playerStartPosition.y;
    player.setPos(playerStartPosition.x, playerStartPosition.y);
    player.active = true;
}

void Game::GameScreen::generateMap() {
    // import Level Data, in this case an array, from LevelData.h. Use the functions from the class (not working yet)
    // It should create the current level
    int layout[((Game::ScreenHeight / 24) - 1)*((Game::ScreenWidth / 24))] =
            {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
             6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2, 6,
             6, 2, 2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 4, 2, 2, 2, 2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 2, 2, 2, 3, 2, 2, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 2, 2, 2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6};

    for (int i = 0; i < sizeof(layout)/sizeof(int); i++) { //geht den Array durch
        int xPos = (i%20)*24; // gibt einen Wert von 0-19 * 24
        int yPos = (i/20)*24+30; // geht alle 20 Tiles in eine neue Zeile
        Vector2 coordinates = {(float)xPos, (float)yPos}; //erstellt Vektor
        if (layout[i] == 0) {
            //Draw Nothing
        } else if (layout[i] == 1) { // Generate Player
            InitPlayer(coordinates.x,coordinates.y);
        } else if (layout[i] == 2) { //Generate Dirt
            dirtList.emplace_back(coordinates.x, coordinates.y); // Objekt zu Vektor hinzfügen, textur geben
            dirtList.back().setTexture(dirtT);
        } else if (layout[i] == 3) { //Generate Boulder
            boulderList.emplace_back(coordinates.x, coordinates.y, 1);
            boulderList.back().setTexture(boulder);
        } else if (layout[i] == 4) { //Generate Memory
            memoryList.emplace_back(coordinates.x, coordinates.y);
            memoryList.back().setTexture(memories);
        } else if (layout[i] == 5) { //generate Enemy

        } else if (layout[i] == 6) { //Generate Wall
            wallList.emplace_back(coordinates.x,coordinates.y);
            int randTexture = std::rand() % 2;
            switch (randTexture) {
                case 0:
                    wallList.back().setTexture(crackedWall);
                    break;
                case 1:
                    wallList.back().setTexture(wall2);
                    break;
                case 2:
                    wallList.back().setTexture(wall3);
                    break;
            }
        } else {}
    }
}

void Game::GameScreen::playerInteractions() {
    if (player.lives > 0) {
        player.updatePlayer();
        for (auto & i : memoryList) { //CHECKT FÜR COLLISION BEI MEMORYS, UND FÜHRT BENÖTIGTE METHODEN AUS
            if (CheckCollisionRecs(player.getCollRec(), i.getCollRec())) {
                if (i.active) {
                    i.setTexture({});
                    collected++;
                    i.active = false;
                }
            }
        }
        for (auto & i : dirtList) { //CHECKT FÜR COLLISION BEI DIRT, UND FÜHRT BENÖTIGTE METHODEN AUS
            if (CheckCollisionRecs(player.getCollRec(), i.getCollRec())) {
                if (i.active) {
                    i.setTexture({});
                    i.active = false;
                }
            }
        }
        // Interaction for adjacent spaces
        if(IsKeyDown(KEY_LEFT_CONTROL) || IsKeyDown(KEY_RIGHT_CONTROL))
        {
            player.setAdjRec(player.getPos().x, player.getPos().y, 24, 24);
            if(!player.moving) {
                player.updatePlayer();
                for (auto & i : memoryList) { //CHECKT FÜR COLLISION BEI MEMORYS, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(player.getAdjRec(), i.getCollRec())) {
                        if (i.active) {
                            i.setTexture({});
                            collected++;
                            i.active = false;
                        }
                    }
                }
                for (auto & i : dirtList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(player.getAdjRec(), i.getCollRec())) {
                        if (i.active) {
                            i.setTexture({});
                            i.active = false;
                        }
                    }
                }
            }
        } else {
            for(auto & i : boulderList) {
                if(player.getAdjRec().x == i.getCollRec().x && player.getAdjRec().y == i.getCollRec().y) {
                    player.canMove = false;
                } else {
                    for(auto & z : wallList) {
                        if(player.getAdjRec().x == z.getCollRec().x && player.getAdjRec().y == z.getCollRec().y) {
                            player.canMove = false;
                        } else {
                            player.canMove = true;
                        }
                    }
                }
            }
            if(player.getAdjRec().x == wallList[1].getCollRec().x && player.getAdjRec().y == wallList[1].getCollRec().y) {
                player.canMove = false;
            }
                if(player.canMove) {
                player.move();
            }
        }
    } //players lives are 0
}

void Game::GameScreen::boulderFall() {
    for(auto & i : boulderList) { //BOULDERS
        i.updateBoulder();
        switch (i.direction) {
            case FallDown:
                for (auto & z : dirtList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.getAdjRec(), z.getCollRec())) {
                        if (!z.active) {
                            i.fall();
                        }
                    }
                }
                for (auto & z : wallList) { //CHECKT FÜR COLLISION BEI Walls, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.adjRectangle, z.getCollRec())) {
                        if (!z.active) {
                            i.fall();
                        }
                    }
                }
                for (auto & z : memoryList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.adjRectangle, z.getCollRec())) {
                        if (!z.active) {
                            i.fall();
                        }
                    }
                }
                break;
            case FallUp:
                for (auto & z : dirtList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.adjRectangle, z.getCollRec())) {
                        if (!z.active) {
                            i.fall();
                        }
                    }
                }
                for (auto & z : wallList) { //CHECKT FÜR COLLISION BEI Walls, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.getAdjRec(), z.getCollRec())) {
                        if (!z.active) {
                            i.fall();
                        }
                    }
                }
                for (auto & z : memoryList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.getAdjRec(), z.getCollRec())) {
                        if (!z.active) {
                            i.fall();
                        }
                    }
                }
                break;
            case FallLeft:
                for (auto & z : dirtList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.getAdjRec(), z.getCollRec())) {
                        if (!z.active) {
                            i.fall();
                        }
                    }
                }
                for (auto & z : wallList) { //CHECKT FÜR COLLISION BEI Walls, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.getAdjRec(), z.getCollRec())) {
                        if (!z.active) {
                            i.fall();
                        }
                    }
                }
                for (auto & z : memoryList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.getAdjRec(), z.getCollRec())) {
                        if (!z.active) {
                            i.fall();
                        }
                    }
                }
                break;
            case FallRight:
                for (auto & z : dirtList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.getAdjRec(), z.getCollRec())) {
                        if (!z.active) {
                            i.fall();
                        }
                    }
                }
                for (auto & z : wallList) { //CHECKT FÜR COLLISION BEI Walls, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.getAdjRec(), z.getCollRec())) {
                        if (!z.active) {
                            i.fall();
                        }
                    }
                }
                for (auto & z : memoryList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.getAdjRec(), z.getCollRec())) {
                        if (!z.active) {
                            i.fall();
                        }
                    }
                }
                break;
        }
    }
}

void Game::GameScreen::ProcessInput() {
    // player Input here, just what the button presses do, not the interactions
}

void Game::GameScreen::Update() {
    // Game code here. Interactions etc.
    playerInteractions();
    boulderFall();
    if(IsKeyPressed(KEY_ESCAPE)) {
        UnloadTexture(dirtT);
        UnloadTexture(boulder);
        UnloadTexture(memories);
        UnloadTexture(crackedWall);
        UnloadTexture(wall2);
        UnloadTexture(wall3);
        exit(0);
    }
}

void Game::GameScreen::Draw() {
    DrawTexturePro(background, backgroundFrame,
                   Rectangle{0, 0, backgroundFrame.width, backgroundFrame.height},
                   {}, 0, WHITE);

    Rectangle playerSize;
    playerSize.height = player.frameRec_left.height;
    playerSize.width = player.frameRec_left.width;
    playerSize.x = player.getPos().x;
    playerSize.y = player.getPos().y;

    if (!player.twoKeysPressed && player.animation_up ||player.animation_down || player.animation_right || player.animation_left) {
        if (player.animation_up) {
            DrawTexturePro(player.player_back, player.frameRec_back, playerSize, {}, 0, WHITE);
        }
        if (player.animation_down) {
            DrawTexturePro(player.player_front, player.frameRec_front, playerSize, {}, 0, WHITE);
        }
        if (player.animation_right) {
            DrawTexturePro(player.player_right, player.frameRec_right, playerSize, {}, 0, WHITE);
        }
        if (player.animation_left) {
            DrawTexturePro(player.player_left, player.frameRec_left, playerSize, {}, 0, WHITE);
        }
    } else {
        if (player.r0l1 == 0 && !player.moving) {
            DrawTexturePro(player.player_idleRight_PawDown, player.frameRec_idleRight, playerSize, {}, 0,
                           WHITE);
        }
        if (player.r0l1 == 1 && !player.moving) {
            DrawTexturePro(player.player_idleLeft_PawDown, player.frameRec_idleLeft, playerSize, {}, 0,
                           WHITE);
        }
    }

    for(auto & i : dirtList) { //DIRT
        Vector2 position = i.getPos();
        position.x *= -1/2;
        position.y *= -1/2;
        Rectangle dirtTSize {i.getPos().x, i.getPos().y, 24, 24};
        DrawTexturePro(i.getTexture(), frameRec_dirtT, dirtTSize, position, 0, WHITE);
    }
    for(auto & i : memoryList) { //MEMORIES
        Vector2 position = i.getPos();
        position.x *= -1/2;
        position.y *= -1/2;
        Rectangle memoriesSize {i.getPos().x, i.getPos().y, 24, 24};
        DrawTexturePro(i.getTexture(), frameRec_Memories, memoriesSize, position, 0, WHITE);
    }
    for(auto & i : boulderList) { //BOULDERS
        Vector2 position = i.getPos();
        position.x *= -1/2;
        position.y *= -1/2;
        Rectangle boulderSize {i.getPos().x, i.getPos().y, 24, 24};
        DrawTexturePro(i.getTexture(), frameRec_Boulder, boulderSize, position, 0, WHITE);
    }
    for(auto & i : wallList) { //WALLS
        Vector2 position = i.getPos();
        position.x *= -1/2;
        position.y *= -1/2;
        Rectangle wallSize {i.getPos().x, i.getPos().y, 24, 24};
        DrawTexturePro(i.getTexture(), frameRec_Wall, wallSize, position, 0, WHITE);
    }

    DrawText(TextFormat("Current FPS: %i", GetFPS()), 10, 5, 15, WHITE);
    DrawText(TextFormat("Paws Of Memories"), 190, 5, 15, WHITE);
    DrawText(TextFormat("Collected: %i", collected), 390, 5, 15, WHITE);
}

Game::GameScreen::~GameScreen() {
    //unload all textures?
    //delete all objects?
    UnloadTexture(player.getTexture());
}
