//
// Created by konst on 01.05.2023.
//

#include <iostream>
#include "raylib.h"
#include "LevelData.h"
#include "GameScreen.h"

Game::GameScreen::GameScreen() {
    LoadTextures();
    readLevelData();
    generateMap();
}

void Game::GameScreen::LoadTextures() {
    dirtT = LoadTexture("assets/graphics/Template/Tiles/Tileset.png");
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

void Game::GameScreen::readLevelData() {
    for (int i = 0; i < ((Game::ScreenHeight / 24) - 1)*((Game::ScreenWidth / 24)); i++) {
        levelLayout = levelData.returnLevelLayout();
    }
}

void Game::GameScreen::generateMap() {
    // import Level Data, in this case an array, from LevelData.h. Use the functions from the class (not working yet)
    // It should create the current level

    clearLevel();
    int layout[((Game::ScreenHeight / 24) - 1)*((Game::ScreenWidth / 24))];
    levelData.createLevel("assets/maps/TestLevel.tmj");
    for (int i = 0; i < sizeof(layout)/sizeof(int); i++) {
        layout[i] = levelLayout[i];
    }

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
            int rand = std::rand() % 3;
            boulderList.emplace_back(coordinates.x, coordinates.y, rand);
            boulderList.back().setTexture(boulder);
        } else if (layout[i] == 4) { //Generate Memory
            memoryList.emplace_back(coordinates.x, coordinates.y);
            memoryList.back().setTexture(memories);
        } else if (layout[i] == 5) { //generate Enemy
            // Not existent yet
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
                    i.collected = true;
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
                            i.collected = true;
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
        }
        canPlayerMove();
        if(player.canMove) {
            player.move();
        }
    } //players lives are 0
}

void Game::GameScreen::canPlayerMove() {
    for(auto &i : boulderList) {
        if (CheckCollisionRecs(player.getAdjRec(), i.getCollRec())) {
            player.canMove = false;
            break;
        } else {
            for (auto &z: wallList) {
                if (CheckCollisionRecs(player.getAdjRec(), z.getCollRec())) {
                    player.canMove = false;
                    break;
                } else {
                    player.canMove = true;
                }
            }
        }
    }
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

void Game::GameScreen::clearLevel() {
    dirtList.clear();
    memoryList.clear();
    boulderList.clear();
    wallList.clear();
}

void Game::GameScreen::finalDirtTexture() {
    /*
     * DIESE FUNKTION FUNKTIONIERT NOCH NICHT, ZUDEM SORGT SIE FÜR HARTEN LAG. ANDERS LÖSEN
     */

    if(currentFrame == 0 || currentFrame == 1 || currentFrame == 2 || currentFrame == 3) {
        for(auto &d : dirtList) { // DIRT, welches wir überprüfen
            // Gucken wo es collided, um zu sehen welche Textur es ist
            if (d.active) {
                for (auto &c: dirtList) { // CHECKT FÜR COLLISION MIT ANDEREN Dirt
                    //Check for above
                    if (CheckCollisionRecs(d.getadjRecUp(), c.getCollRec())) {
                        if (c.active) {
                            d.upClear = false;
                        }
                        break;
                    } else {
                        for (auto &w: wallList) { //CHECKT FÜR COLLISION MIT Walls
                            if (CheckCollisionRecs(d.getadjRecUp(), w.getCollRec())) {
                                d.upClear = false;
                                break;
                            } else {
                                d.upClear = true;
                                break;
                            }
                        }
                    }
                }
                for (auto &c: dirtList) { // CHECKT FÜR COLLISION MIT ANDEREN Dirt
                    //Check for above
                    if (CheckCollisionRecs(d.getadjRecLeft(), c.getCollRec())) {
                        if (c.active) {
                            d.leftClear = false;
                        }
                        break;
                    } else {
                        for (auto &w: wallList) { //CHECKT FÜR COLLISION MIT Walls
                            if (CheckCollisionRecs(d.getadjRecLeft(), w.getCollRec())) {
                                d.leftClear = false;
                                break;
                            } else {
                                d.leftClear = true;
                                break;
                            }
                        }
                    }
                }
                for (auto &c: dirtList) { // CHECKT FÜR COLLISION MIT ANDEREN Dirt
                    //Check for above
                    if (CheckCollisionRecs(d.getadjRecDown(), c.getCollRec())) {
                        if (c.active) {
                            d.downClear = false;
                        }
                        break;
                    } else {
                        for (auto &w: wallList) { //CHECKT FÜR COLLISION MIT Walls
                            if (CheckCollisionRecs(d.getadjRecDown(), w.getCollRec())) {
                                d.downClear = false;
                                break;
                            } else {
                                d.downClear = true;
                                break;
                            }
                        }
                    }
                }
                for (auto &c: dirtList) { // CHECKT FÜR COLLISION MIT ANDEREN Dirt
                    //Check for above
                    if (CheckCollisionRecs(d.getadjRecRight(), c.getCollRec())) {
                        if (c.active) {
                            d.rightClear = false;
                        }
                        break;
                    } else {
                        for (auto &w: wallList) { //CHECKT FÜR COLLISION MIT Walls
                            if (CheckCollisionRecs(d.getadjRecRight(), w.getCollRec())) {
                                d.rightClear = false;
                                break;
                            } else {
                                d.rightClear = true;
                                break;
                            }
                        }
                    }
                }

                //FrameRec festlegen
                // Abfrage ist korrekt
                switch (d.upClear) {
                    case true:
                        switch (d.downClear) {
                            case true:
                                switch (d.rightClear) {
                                    case true:
                                        switch (d.leftClear) {
                                            case true:
                                                d.frameRec_dirtT = {24.0f * 3, 24.0f * 3, (float) dirtT.width / 4,
                                                                    (float) dirtT.height / 4};
                                                break;
                                            case false:
                                                d.frameRec_dirtT = {24.0f * 2, 24.0f * 3, (float) dirtT.width / 4,
                                                                    (float) dirtT.height / 4};
                                                break;
                                        }
                                        break;
                                    case false:
                                        switch (d.leftClear) {
                                            case true:
                                                d.frameRec_dirtT = {24.0f * 0, 24.0f * 3, (float) dirtT.width / 4,
                                                                    (float) dirtT.height / 4};
                                                break;
                                            case false:
                                                d.frameRec_dirtT = {24.0f * 1, 24.0f * 3, (float) dirtT.width / 4,
                                                                    (float) dirtT.height / 4};
                                                break;
                                        }
                                        break;
                                }
                                break;
                            case false:
                                switch (d.rightClear) {
                                    case true:
                                        switch (d.leftClear) {
                                            case true:
                                                d.frameRec_dirtT = {24.0f * 3, 24.0f * 0, (float) dirtT.width / 4,
                                                                    (float) dirtT.height / 4};
                                                break;
                                            case false:
                                                d.frameRec_dirtT = {24.0f * 2, 24.0f * 0, (float) dirtT.width / 4,
                                                                    (float) dirtT.height / 4};
                                                break;
                                        }
                                        break;
                                    case false:
                                        switch (d.leftClear) {
                                            case true:
                                                d.frameRec_dirtT = {24.0f * 0, 24.0f * 0, (float) dirtT.width / 4,
                                                                    (float) dirtT.height / 4};
                                                break;
                                            case false:
                                                d.frameRec_dirtT = {24.0f * 1, 24.0f * 0, (float) dirtT.width / 4,
                                                                    (float) dirtT.height / 4};
                                                break;
                                        }
                                        break;
                                }
                                break;
                        }
                        break;
                    case false:
                        switch (d.downClear) {
                            case true:
                                switch (d.rightClear) {
                                    case true:
                                        switch (d.leftClear) {
                                            case true:
                                                d.frameRec_dirtT = {24.0f * 3, 24.0f * 2, (float) dirtT.width / 4,
                                                                    (float) dirtT.height / 4};
                                                break;
                                            case false:
                                                d.frameRec_dirtT = {24.0f * 2, 24.0f * 2, (float) dirtT.width / 4,
                                                                    (float) dirtT.height / 4};
                                                break;
                                        }
                                        break;
                                    case false:
                                        switch (d.leftClear) {
                                            case true:
                                                d.frameRec_dirtT = {24.0f * 0, 24.0f * 2, (float) dirtT.width / 4,
                                                                    (float) dirtT.height / 4};
                                                break;
                                            case false:
                                                d.frameRec_dirtT = {24.0f * 1, 24.0f * 2, (float) dirtT.width / 4,
                                                                    (float) dirtT.height / 4};
                                                break;
                                        }
                                        break;
                                }
                                break;
                            case false:
                                switch (d.rightClear) {
                                    case true:
                                        switch (d.leftClear) {
                                            case true:
                                                d.frameRec_dirtT = {24.0f * 3, 24.0f * 1, (float) dirtT.width / 4,
                                                                    (float) dirtT.height / 4};
                                                break;
                                            case false:
                                                d.frameRec_dirtT = {24.0f * 2, 24.0f * 1, (float) dirtT.width / 4,
                                                                    (float) dirtT.height / 4};
                                                break;
                                        }
                                        break;
                                    case false:
                                        switch (d.leftClear) {
                                            case true:
                                                d.frameRec_dirtT = {24.0f * 0, 24.0f * 1, (float) dirtT.width / 4,
                                                                    (float) dirtT.height / 4};
                                                break;
                                            case false:
                                                d.frameRec_dirtT = {24.0f * 1, 24.0f * 1, (float) dirtT.width / 4,
                                                                    (float) dirtT.height / 4};
                                                break;
                                        }
                                        break;
                                }
                                break;
                        }
                        break;
                }
            }
        }
    }
}

void Game::GameScreen::drawLevel() {
    framesCounter++;
    if (framesCounter >= (60 / framesSpeed)) {

        framesCounter = 0;
        currentFrame++;

        if (currentFrame > 10) currentFrame = 0;

        backgroundFrame.x = (float) currentFrame * (float) background.width / 11;
    }
    DrawTexturePro(background, backgroundFrame,
                   Rectangle{0, 0, backgroundFrame.width, backgroundFrame.height},
                   {}, 0, WHITE);

    Rectangle playerSize;
    playerSize.height = player.frameRec_left.height;
    playerSize.width = player.frameRec_left.width;
    playerSize.x = player.getPos().x;
    playerSize.y = player.getPos().y;

    DrawRectangle(player.getAdjRec().x, player.getAdjRec().y,player.getAdjRec().width, player.getAdjRec().height, MAGENTA);
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
        DrawTexturePro(i.getTexture(), i.frameRec_dirtT, dirtTSize, position, 0, WHITE);
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

void Game::GameScreen::drawMenu() {
    DrawTexturePro(menu, Rectangle{0, 0, (float) menu.width, (float) menu.height},
                   Rectangle{0, 0, (float) menu.width, (float) menu.height},
                   {}, 0, WHITE);
    DrawTexturePro(logoB.getTexture(), Rectangle{0, 0, (float) logoB.getTexture().width, (float) logoB.getTexture().height},
                   Rectangle{logoB.getPos().x, logoB.getPos().y, (float) logoB.getTexture().width, (float) logoB.getTexture().height},
                   {}, 0, WHITE);
    DrawTexturePro(startB.getTexture(), Rectangle{0, 0, (float) startB.getTexture().width, (float) startB.getTexture().height},
                   Rectangle{startB.getPos().x, startB.getPos().y, (float) startB.getTexture().width, (float) startB.getTexture().height},
                   {}, 0, WHITE);
    DrawTexturePro(galleryB.getTexture(), Rectangle{0, 0, (float) galleryB.getTexture().width, (float) galleryB.getTexture().height},
                   Rectangle{galleryB.getPos().x, galleryB.getPos().y, (float) galleryB.getTexture().width, (float) galleryB.getTexture().height},
                   {}, 0, galleryH);
    DrawTexturePro(exitB.getTexture(), Rectangle{0, 0, (float) exitB.getTexture().width, (float) exitB.getTexture().height},
                   Rectangle{exitB.getPos().x, exitB.getPos().y, (float) exitB.getTexture().width, (float) exitB.getTexture().height},
                   {}, 0, WHITE);
}

void Game::GameScreen::menuControls() {
    if(IsKeyPressed(KEY_S)) {
        if(counter<menuButtons.size()-1) {
            counter++;
        }
    } else if(IsKeyPressed(KEY_W)) {
        if(counter>0) {
            counter--;
        }
    }
    if(counter==0) { //start
        startB.setTexture(startH);
        galleryH = WHITE;
        exitB.setTexture(exit);
    } else if(counter==1) { //gallery
        //no highlight
        startB.setTexture(start);
        galleryH = YELLOW;
        exitB.setTexture(exit);
    } else if(counter==2) { //exit
        startB.setTexture(start);
        galleryH = WHITE;
        exitB.setTexture(exitH);
    }
}

void Game::GameScreen::ProcessInput() {
    if(IsKeyPressed(KEY_TWO)) { //switch to level
        if(counter==0) {
            display = 1;
        }
        if(counter==2) {
            CloseWindow();
        }
    }if(IsKeyPressed(KEY_ONE)) { //switch to menu
        display = 0;
    }
}

void Game::GameScreen::Update() {
    // Game code here. Interactions etc.
    ProcessInput();
    if(display==0) { // menu
        menuControls();
    }
    else if(display==1) { // level
        finalDirtTexture();
        playerInteractions();
        boulderFall();
    }
    if(IsKeyPressed(KEY_I)) {
        clearLevel();
    }
}

void Game::GameScreen::Draw() {
    switch (display) {
        case(0):
            drawMenu();
            break;
        case(1):
            drawLevel();
            break;
    }
}

Game::GameScreen::~GameScreen() {
    //unload all textures?
    //delete all objects?
    UnloadTexture(player.getTexture());
}
