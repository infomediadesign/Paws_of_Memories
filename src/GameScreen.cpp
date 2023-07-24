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
    crackedWall = LoadTexture("assets/graphics/Template/Wall_and_Door/Cracked_Wall_1.png");
    wall2 = LoadTexture("assets/graphics/Template/Wall_and_Door/wall_2.png");
    wall3 = LoadTexture("assets/graphics/Template/Wall_and_Door/wall_3.png");
    boulder_down = LoadTexture("assets/graphics/Animation/Sheets/Objects/Boulder/Boulder down-Sheet.png");
    boulder_up = LoadTexture("assets/graphics/Animation/Sheets/Objects/Boulder/Boulder up-Sheet.png");
    boulder_left = LoadTexture("assets/graphics/Animation/Sheets/Objects/Boulder/Boulder-left-Sheet.png");
    boulder_right = LoadTexture("assets/graphics/Animation/Sheets/Objects/Boulder/Boulder right-Sheet.png");
    riegel = LoadTexture("assets/graphics/Template/Bar/1x1.png");
    door = LoadTexture("assets/graphics/Template/Wall_and_Door/Door.png");

    frameRec_Memories = {0.0f, 0.0f, (float) memories.width / 7, (float) memories.height};
    frameRec_Boulder = {0.0f, 0.0f, (float) boulder_down.width / 5, (float) boulder_down.height};
    frameRec_Wall = {0.0f, 0.0f, (float) 24, 24};
    frameRec_Riegel = {0.0f, 0.0f, (float) 24, 24};
    frameRec_Door = {0.0f, 0.0f, (float) 24, 24};
}

void Game::GameScreen::InitPlayer(int valueX, int valueY) {
    Vector2 playerStartPosition;
    //playerStartPosition.x = array place;
    //playerStartPosition.y = array place;
    //for now:
    playerStartPosition.x = (float) valueX;
    playerStartPosition.y = (float) valueY;
    player.setPos(playerStartPosition.x, playerStartPosition.y);
    player.target_x = playerStartPosition.x;
    player.target_y = playerStartPosition.y;
    player.active = true;
}

void Game::GameScreen::readLevelData() {
    for (int i = 0; i < ((Game::ScreenHeight / 24) - 1) * ((Game::ScreenWidth / 24)); i++) {
        levelLayout = levelData.returnLevelLayout();
    }
}

void Game::GameScreen::generateMap() {
    // import Level Data, in this case an array, from LevelData.h. Use the functions from the class (not working yet)
    // It should create the current level

    clearLevel();
    collected = 0;
    int doorCount = 0;
    int layout[((Game::ScreenHeight / 24) - 1) * ((Game::ScreenWidth / 24))];
    levelData.createLevel(levelData.fileNames[roomCounter]);
    readLevelData();
    for (int i = 0; i < sizeof(layout) / sizeof(int); i++) {
        layout[i] = levelLayout[i];
    }

    for (int i = 0; i < sizeof(layout) / sizeof(int); i++) { //geht den Array durch
        int xPos = (i % 20) * 24; // gibt einen Wert von 0-19 * 24
        int yPos = (i / 20) * 24 + 30; // geht alle 20 Tiles in eine neue Zeile
        Vector2 coordinates = {(float) xPos, (float) yPos}; //erstellt Vektor
        if (layout[i] == 0) {
            //Draw Nothing
        } else if (layout[i] == 1) { // Generate Player
            InitPlayer((int) coordinates.x, (int) coordinates.y);
        } else if (layout[i] == 2) { //Generate Dirt
            dirtList.emplace_back(coordinates.x, coordinates.y); // Objekt zu Vektor hinzfügen, textur geben
            dirtList.back().setTexture(dirtT);
            //Generate Boulders
        } else if (layout[i] == 3) { //Generate Boulder left
            boulderList.emplace_back(coordinates.x, coordinates.y, FallLeft);
            boulderList.back().setTexture(boulder_left);
        } else if (layout[i] == 8) { //Generate Boulder down
            boulderList.emplace_back(coordinates.x, coordinates.y, FallDown);
            boulderList.back().setTexture(boulder_down);
        } else if (layout[i] == 9) { //Generate Boulder right
            boulderList.emplace_back(coordinates.x, coordinates.y, FallRight);
            boulderList.back().setTexture(boulder_right);
        } else if (layout[i] == 10) { //Generate Boulder up
            boulderList.emplace_back(coordinates.x, coordinates.y, FallUp);
            boulderList.back().setTexture(boulder_up);

        } else if (layout[i] == 4) { //Generate Memory
            memoryList.emplace_back(coordinates.x, coordinates.y);
            memoryList.back().setTexture(memories);
        } else if (layout[i] == 5) { //generate Riegel
            riegelList.emplace_back(coordinates.x, coordinates.y);
            riegelList.back().setTexture(riegel);
        } else if (layout[i] == 6) { //Generate Wall
            wallList.emplace_back(coordinates.x, coordinates.y);
            int randTexture = std::rand() % 2;
            switch (randTexture) {
                default:
                    wallList.back().setTexture(crackedWall);
                    break;
                case 1:
                    wallList.back().setTexture(wall2);
                    break;
                case 2:
                    wallList.back().setTexture(wall3);
                    break;
            }
        } else if (layout[i] == 7) { //Generate Door
            doorList.emplace_back(coordinates.x, coordinates.y, doorCount);
            doorList.back().setTexture(door);
            doorCount++;
        } else {}
    }
}

void Game::GameScreen::playerInteractions() {
    if (player.lives > 0) {
        player.updatePlayer();
        player.idleAnimation();
        for (auto &i: boulderList) { //CHECKT FÜR ÜBERSCHNEIDUNG BEI Boulders, UND FÜHRT BENÖTIGTE METHODEN AUS
            if (CheckCollisionRecs(player.getCollRec(), i.getCollRec())) {
                if ((player.getCollRec().x - i.getCollRec().x) <= 2 &&
                    (player.getCollRec().y - i.getCollRec().y) <= 2) {
                    player.lives = 0; //Spieler stirbt
                }
                // hier kann man active auf false setzen, dann in Draw die Todes animation abspielen. Danach
                // TExt aufploppen lassen wie "drücke rfür restart" oder so
            }
        }
        for (auto &i: memoryList) { //CHECKT FÜR COLLISION BEI MEMORYS, UND FÜHRT BENÖTIGTE METHODEN AUS
            if (CheckCollisionRecs(player.getCollRec(), i.getCollRec())) {
                if (i.active) {
                    collected++;
                    i.active = false;
                    i.collected = true;
                }
            }
        }
        for (auto &i: dirtList) { //CHECKT FÜR COLLISION BEI DIRT, UND FÜHRT BENÖTIGTE METHODEN AUS
            if (CheckCollisionRecs(player.getCollRec(), i.getCollRec())) {
                if (i.active) {
                    i.active = false;
                }
            }
        }
        for (auto &d: doorList) { //CHECKT FÜR COLLISION BEI DIRT, UND FÜHRT BENÖTIGTE METHODEN AUS
            if (CheckCollisionRecs(player.getCollRec(), d.getCollRec()) && collected == memoryList.size()) {
                if (d.active) {
                    roomCounter++;
                    generateMap();
                }
            }
        }
        // Interaction for adjacent spaces
        if (IsKeyDown(KEY_LEFT_CONTROL) || IsKeyDown(KEY_RIGHT_CONTROL)) {
            player.setAdjRec(player.getPos().x, player.getPos().y, 24, 24);
            if (!player.moving) {
                player.updatePlayer();
                for (auto &i: memoryList) { //CHECKT FÜR COLLISION BEI MEMORYS, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(player.getAdjRec(), i.getCollRec())) {
                        if (i.active) {
                            collected++;
                            i.active = false;
                            i.collected = true;
                        }
                    }
                }
                for (auto &i: dirtList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(player.getAdjRec(), i.getCollRec())) {
                        if (i.active) {
                            i.active = false;
                        }
                    }
                }
            }
        }
        canPlayerMove();
        if (player.canMove) {
            player.move();
            player.moveDigAnimation();
        }
    } //players lives are 0
    else {
        player.deathAnimation();
    }
}

void Game::GameScreen::canPlayerMove() {
    //this is kinda scuffed rn
    //When we moved to another room that didn't have all objects, collision wouldn't work since it depends on every object
    //Implemented all possibilities rn, hopefully there is a cleaner method we can change to later
    if (!player.moving) {
        for (auto &z: wallList) {
            if (CheckCollisionRecs(player.getAdjRec(), z.getCollRec())) {
                player.canMove = false;
                break;
            } else {
                if (!boulderList.empty()) {
                    for (auto &i: boulderList) {
                        if (CheckCollisionRecs(player.getAdjRec(), i.getCollRec())) {
                            player.canMove = false;
                            break;
                        } else {
                            if (!riegelList.empty()) {
                                for (auto &g: riegelList) {
                                    if (CheckCollisionRecs(player.getAdjRec(), g.getCollRec())) {
                                        player.canMove = false;
                                        break;
                                    } else {
                                        for (auto &d: doorList) {
                                            if (CheckCollisionRecs(player.getAdjRec(), d.getCollRec()) &&
                                                collected != memoryList.size()) {
                                                player.canMove = false;
                                                break;
                                            } else {
                                                player.canMove = true;
                                            }
                                        }
                                    }
                                }
                            } else {
                                for (auto &d: doorList) {
                                    if (CheckCollisionRecs(player.getAdjRec(), d.getCollRec()) &&
                                        collected != memoryList.size()) {
                                        player.canMove = false;
                                        break;
                                    } else {
                                        player.canMove = true;
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (!riegelList.empty()) {
                        for (auto &g: riegelList) {
                            if (CheckCollisionRecs(player.getAdjRec(), g.getCollRec())) {
                                player.canMove = false;
                                break;
                            } else {
                                for (auto &d: doorList) {
                                    if (CheckCollisionRecs(player.getAdjRec(), d.getCollRec()) &&
                                        collected != memoryList.size()) {
                                        player.canMove = false;
                                        break;
                                    } else {
                                        player.canMove = true;
                                    }
                                }
                            }
                        }
                    } else {
                        for (auto &d: doorList) {
                            if (CheckCollisionRecs(player.getAdjRec(), d.getCollRec()) &&
                                collected != memoryList.size()) {
                                player.canMove = false;
                                break;
                            } else {
                                player.canMove = true;
                            }
                        }
                    }
                }
            }
        }
    }
}

void Game::GameScreen::canRiegelMove() {
    for (auto &i: riegelList) { //Riegel
        i.ColUpdate();

        for (auto &z: dirtList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
            if (CheckCollisionRecs(i.getAdjRec(), z.getCollRec())) {
                i.riegelCanMove = false;
            }
        }
        for (auto &z: wallList) { //CHECKT FÜR COLLISION BEI Walls, UND FÜHRT BENÖTIGTE METHODEN AUS
            if (CheckCollisionRecs(i.adjRectangle, z.getCollRec())) {
                i.riegelCanMove = false;
            }
        }
        for (auto &z: memoryList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
            if (CheckCollisionRecs(i.adjRectangle, z.getCollRec())) {
                i.riegelCanMove = false;
            }
        }
    }
}

void Game::GameScreen::setRScale(float test) {
    this->rScale = test;
}

void Game::GameScreen::RiegelPush() {
    for (auto &i: riegelList) {
        i.renderScale = rScale;
        i.move();
    }
}

void Game::GameScreen::boulderFall() {
    for (auto &i: boulderList) { //BOULDERS
        i.updateBoulder();
        switch (i.direction) {
            case FallDown:
                for (auto &d: dirtList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.getAdjRec(), d.getCollRec())) {
                        if (!d.active) {
                            i.fall();
                        }
                    } else {
                        for (auto &w: wallList) { //CHECKT FÜR COLLISION BEI Walls, UND FÜHRT BENÖTIGTE METHODEN AUS
                            if (CheckCollisionRecs(i.adjRectangle, w.getCollRec())) {
                                if (!w.active) {
                                    i.fall();
                                }
                            } else {
                                for (auto &m: memoryList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                                    if (CheckCollisionRecs(i.adjRectangle, m.getCollRec())) {
                                        if (!m.active) {
                                            i.fall();
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            case FallUp:
                for (auto &d: dirtList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.getAdjRec(), d.getCollRec())) {
                        if (!d.active) {
                            i.fall();
                        }
                    } else {
                        for (auto &w: wallList) { //CHECKT FÜR COLLISION BEI Walls, UND FÜHRT BENÖTIGTE METHODEN AUS
                            if (CheckCollisionRecs(i.adjRectangle, w.getCollRec())) {
                                if (!w.active) {
                                    i.fall();
                                }
                            } else {
                                for (auto &m: memoryList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                                    if (CheckCollisionRecs(i.adjRectangle, m.getCollRec())) {
                                        if (!m.active) {
                                            i.fall();
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            case FallLeft:
                for (auto &d: dirtList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.getAdjRec(), d.getCollRec())) {
                        if (!d.active) {
                            i.fall();
                        }
                    } else {
                        for (auto &w: wallList) { //CHECKT FÜR COLLISION BEI Walls, UND FÜHRT BENÖTIGTE METHODEN AUS
                            if (CheckCollisionRecs(i.adjRectangle, w.getCollRec())) {
                                if (!w.active) {
                                    i.fall();
                                }
                            } else {
                                for (auto &m: memoryList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                                    if (CheckCollisionRecs(i.adjRectangle, m.getCollRec())) {
                                        if (!m.active) {
                                            i.fall();
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            case FallRight:
                for (auto &d: dirtList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.getAdjRec(), d.getCollRec())) {
                        if (!d.active) {
                            i.fall();
                        }
                    } else {
                        for (auto &w: wallList) { //CHECKT FÜR COLLISION BEI Walls, UND FÜHRT BENÖTIGTE METHODEN AUS
                            if (CheckCollisionRecs(i.adjRectangle, w.getCollRec())) {
                                if (!w.active) {
                                    i.fall();
                                }
                            } else {
                                for (auto &m: memoryList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                                    if (CheckCollisionRecs(i.adjRectangle, m.getCollRec())) {
                                        if (!m.active) {
                                            i.fall();
                                        }
                                    }
                                }
                            }
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
    riegelList.clear();
    doorList.clear();
    levelLayout = {};
}

void Game::GameScreen::finalDirtTexture() {
    /*
     * DIESE FUNKTION FUNKTIONIERT NOCH NICHT, ZUDEM SORGT SIE FÜR HARTEN LAG. ANDERS LÖSEN
     */

    if (framesCounter == 0 || framesCounter == 2 || framesCounter == 4 || framesCounter == 6 ||
        framesCounter == 8) {
        for (auto &d: dirtList) { // DIRT, welches wir überprüfen
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
                                                d.frameRec_dirtT = {24.0f * 3, 24.0f * 3,
                                                                    (float) dirtT.width / 4,
                                                                    (float) dirtT.height / 4};
                                                break;
                                            case false:
                                                d.frameRec_dirtT = {24.0f * 2, 24.0f * 3,
                                                                    (float) dirtT.width / 4,
                                                                    (float) dirtT.height / 4};
                                                break;
                                        }
                                        break;
                                    case false:
                                        switch (d.leftClear) {
                                            case true:
                                                d.frameRec_dirtT = {24.0f * 0, 24.0f * 3,
                                                                    (float) dirtT.width / 4,
                                                                    (float) dirtT.height / 4};
                                                break;
                                            case false:
                                                d.frameRec_dirtT = {24.0f * 1, 24.0f * 3,
                                                                    (float) dirtT.width / 4,
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
                                                d.frameRec_dirtT = {24.0f * 3, 24.0f * 0,
                                                                    (float) dirtT.width / 4,
                                                                    (float) dirtT.height / 4};
                                                break;
                                            case false:
                                                d.frameRec_dirtT = {24.0f * 2, 24.0f * 0,
                                                                    (float) dirtT.width / 4,
                                                                    (float) dirtT.height / 4};
                                                break;
                                        }
                                        break;
                                    case false:
                                        switch (d.leftClear) {
                                            case true:
                                                d.frameRec_dirtT = {24.0f * 0, 24.0f * 0,
                                                                    (float) dirtT.width / 4,
                                                                    (float) dirtT.height / 4};
                                                break;
                                            case false:
                                                d.frameRec_dirtT = {24.0f * 1, 24.0f * 0,
                                                                    (float) dirtT.width / 4,
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
                                                d.frameRec_dirtT = {24.0f * 3, 24.0f * 2,
                                                                    (float) dirtT.width / 4,
                                                                    (float) dirtT.height / 4};
                                                break;
                                            case false:
                                                d.frameRec_dirtT = {24.0f * 2, 24.0f * 2,
                                                                    (float) dirtT.width / 4,
                                                                    (float) dirtT.height / 4};
                                                break;
                                        }
                                        break;
                                    case false:
                                        switch (d.leftClear) {
                                            case true:
                                                d.frameRec_dirtT = {24.0f * 0, 24.0f * 2,
                                                                    (float) dirtT.width / 4,
                                                                    (float) dirtT.height / 4};
                                                break;
                                            case false:
                                                d.frameRec_dirtT = {24.0f * 1, 24.0f * 2,
                                                                    (float) dirtT.width / 4,
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
                                                d.frameRec_dirtT = {24.0f * 3, 24.0f * 1,
                                                                    (float) dirtT.width / 4,
                                                                    (float) dirtT.height / 4};
                                                break;
                                            case false:
                                                d.frameRec_dirtT = {24.0f * 2, 24.0f * 1,
                                                                    (float) dirtT.width / 4,
                                                                    (float) dirtT.height / 4};
                                                break;
                                        }
                                        break;
                                    case false:
                                        switch (d.leftClear) {
                                            case true:
                                                d.frameRec_dirtT = {24.0f * 0, 24.0f * 1,
                                                                    (float) dirtT.width / 4,
                                                                    (float) dirtT.height / 4};
                                                break;
                                            case false:
                                                d.frameRec_dirtT = {24.0f * 1, 24.0f * 1,
                                                                    (float) dirtT.width / 4,
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

    DrawRectangle((int) player.getAdjRec().x, (int) player.getAdjRec().y, (int) player.getAdjRec().width,
                  (int) player.getAdjRec().height, MAGENTA);
    //DrawRectangle((int) player.getCollRec().x, (int) player.getCollRec().y, (int) player.getCollRec().width, (int) player.getCollRec().height, YELLOW);
    if (player.canMove && player.lives > 0 && (player.animation_up || player.animation_down || player.animation_right ||
                                               player.animation_left)) {
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
        if (player.lives > 0 && player.r0l1 == 0 && !player.moving && !player.diggingUp && !player.diggingLeft &&
            !player.diggingDown &&
            !player.diggingRight) {
            DrawTexturePro(player.player_idleRight, player.frameRec_iR, playerSize, {}, 0,
                           WHITE);
        }
        if (player.lives > 0 && player.r0l1 == 1 && !player.moving && !player.diggingUp && !player.diggingLeft &&
            !player.diggingDown &&
            !player.diggingRight) {
            DrawTexturePro(player.player_idleLeft, player.frameRec_iL, playerSize, {}, 0,
                           WHITE);
        } else {
            if (player.lives <= 0) {
                if (player.r0l1 == 0) {
                    DrawTexturePro(player.playerDeath_right, player.frameRec_deathRight, playerSize, {}, 0, WHITE);
                } else {
                    DrawTexturePro(player.playerDeath_left, player.frameRec_deathLeft, playerSize, {}, 0, WHITE);
                }
            } else {
                if (player.diggingRight) {
                    DrawTexturePro(player.player_digRight, player.frameRec_digRight, playerSize, {}, 0, WHITE);
                }
                if (player.diggingUp) {
                    DrawTexturePro(player.player_digUp, player.frameRec_digUp, playerSize, {}, 0, WHITE);
                }
                if (player.diggingLeft) {
                    DrawTexturePro(player.player_digLeft, player.frameRec_digLeft, playerSize, {}, 0, WHITE);
                }
                if (player.diggingDown) {
                    DrawTexturePro(player.player_digDown, player.frameRec_digDown, playerSize, {}, 0, WHITE);
                }
            }
        }
    }

    for (auto &i: dirtList) { //DIRT
        if (i.active) {
            Vector2 position = i.getPos();
            position.x *= -1 / 2;
            position.y *= -1 / 2;
            Rectangle dirtTSize{i.getPos().x, i.getPos().y, 24, 24};
            DrawTexturePro(i.getTexture(), i.frameRec_dirtT, dirtTSize, position, 0, WHITE);
        }
    }
    for (auto &i: memoryList) { //MEMORIES
        if (i.active) {
            Vector2 position = i.getPos();
            position.x *= -1 / 2;
            position.y *= -1 / 2;
            Rectangle memoriesSize{i.getPos().x, i.getPos().y, 24, 24};
            DrawTexturePro(i.getTexture(), frameRec_Memories, memoriesSize, position, 0, WHITE);
        }
    }
    for (auto &i: boulderList) { //BOULDERS
        Vector2 position = i.getPos();
        position.x *= -1 / 2;
        position.y *= -1 / 2;
        Rectangle boulderSize{i.getPos().x, i.getPos().y, 24, 24};
        DrawTexturePro(i.getTexture(), frameRec_Boulder, boulderSize, position, 0, WHITE);
    }
    for (auto &i: wallList) { //WALLS
        Vector2 position = i.getPos();
        position.x *= -1 / 2;
        position.y *= -1 / 2;
        Rectangle wallSize{i.getPos().x, i.getPos().y, 24, 24};
        DrawTexturePro(i.getTexture(), frameRec_Wall, wallSize, position, 0, WHITE);
    }
    for (auto &i: riegelList) { //Riegel
        Vector2 position = i.getPos();
        position.x *= -1 / 2;
        position.y *= -1 / 2;
        Rectangle riegelSize{i.getPos().x, i.getPos().y, 24, 24};
        DrawTexturePro(i.getTexture(), frameRec_Riegel, riegelSize, position, 0, WHITE);
    }
    for (auto &i: doorList) { //door
        Vector2 position = i.getPos();
        position.x *= -1 / 2;
        position.y *= -1 / 2;
        Rectangle doorSize{i.getPos().x, i.getPos().y, 24, 24};
        DrawTexturePro(i.getTexture(), frameRec_Riegel, doorSize, position, 0, WHITE);
    }
    DrawText(TextFormat("Current FPS: %i", GetFPS()), 10, 5, 15, WHITE);
    DrawText(TextFormat("Paws Of Memories"), 190, 5, 15, WHITE);
    DrawText(TextFormat("Collected: %i", collected), 390, 5, 15, WHITE);
}

void Game::GameScreen::drawMenu() {
    framesCounter++;
    if (framesCounter >= (60 / framesSpeed)) {

        framesCounter = 0;
        if(delay == 0) currentFrame++;

        if (currentFrame == 0 && delay != 0) delay++;
        if (currentFrame == 8) {
            delay++;
            currentFrame = 0;
        }
        if (delay == 20) delay = 0;

        logoFrame.x = (float) currentFrame * (float) logo.width / 9;
    }
    DrawTexturePro(menu, Rectangle{0, 0, (float) menu.width, (float) menu.height},
                   Rectangle{0, 0, (float) menu.width, (float) menu.height},
                   {}, 0, WHITE);
    DrawTexturePro(logo, logoFrame, Rectangle{logoB.getPos().x, logoB.getPos().y,
                   (float) logoFrame.width, (float) logoFrame.height},
                   {}, 0,
                   WHITE);
    DrawTexturePro(startB.getTexture(),
                   Rectangle{0, 0, (float) startB.getTexture().width, (float) startB.getTexture().height},
                   Rectangle{startB.getPos().x, startB.getPos().y, (float) startB.getTexture().width,
                             (float) startB.getTexture().height},
                   {}, 0, WHITE);
    DrawTexturePro(galleryB.getTexture(),
                   Rectangle{0, 0, (float) galleryB.getTexture().width, (float) galleryB.getTexture().height},
                   Rectangle{galleryB.getPos().x, galleryB.getPos().y, (float) galleryB.getTexture().width,
                             (float) galleryB.getTexture().height},
                   {}, 0, WHITE);
    DrawTexturePro(exitB.getTexture(),
                   Rectangle{0, 0, (float) exitB.getTexture().width, (float) exitB.getTexture().height},
                   Rectangle{exitB.getPos().x, exitB.getPos().y, (float) exitB.getTexture().width,
                             (float) exitB.getTexture().height},
                   {}, 0, WHITE);
}

void Game::GameScreen::menuControls() {
    if (IsKeyPressed(KEY_S)) {
        if (counter < menuButtons.size() - 1) {
            counter++;
        }
    } else if (IsKeyPressed(KEY_W)) {
        if (counter > 0) {
            counter--;
        }
    }
    if (counter == 0) { //start
        startB.setTexture(startH);
        galleryB.setTexture(gallery);
        exitB.setTexture(exit);
    } else if (counter == 1) { //gallery
        //no highlight
        startB.setTexture(start);
        galleryB.setTexture(galleryH);
        exitB.setTexture(exit);
    } else if (counter == 2) { //exit
        startB.setTexture(start);
        galleryB.setTexture(gallery);
        exitB.setTexture(exitH);
    }
}

void Game::GameScreen::ProcessInput() {
    if (IsKeyPressed(KEY_ENTER)) { //switch to level
        if (counter == 0) {
            display = 1;
            currentFrame = 0;
        }
        if (counter == 2) {
            CloseWindow();
        }
    }
    if (IsKeyPressed(KEY_ESCAPE)) { //switch to menu
        display = 0;
        delay = 1;
        currentFrame = 0;
    }
}

void Game::GameScreen::Update() {
    // Game code here. Interactions etc.
    ProcessInput();
    if (display == 0) { // menu
        menuControls();
    } else if (display == 1) { // level
        finalDirtTexture();
        playerInteractions();
        boulderFall();
        RiegelPush();
        if (!player.active) {
            generateMap();
            player.lives = 3;
            player.active = true;
        }
    }
    if (IsKeyPressed(KEY_I)) {
        clearLevel();
    }
}

void Game::GameScreen::Draw() {
    switch (display) {
        case (0):
            drawMenu();
            break;
        case (1):
            drawLevel();
            break;
    }
}

Game::GameScreen::~GameScreen() {
    //unload all textures?
    //delete all objects?
    UnloadTexture(player.getTexture());
}
