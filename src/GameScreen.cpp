#include <iostream>
#include "raylib.h"
#include "LevelData.h"
#include "GameScreen.h"

Game::GameScreen::GameScreen() {
    readLevelData();
    LoadMenuTextures();
    InitAudioDevice();
    titleTrack = LoadSound("assets/audio/tracks/Titel-Track-WAV.wav");
}

void Game::GameScreen::LoadMenuTextures() {
    startScreen = LoadTexture(
            "assets/graphics/Animation/Sheets/Background/Startscreen/Start_Screen_idle_animation-Sheet.png");
    startScreenRec = {0.0f, 0.0f, (float) startScreen.width / 10, (float) startScreen.height / 6};
    // maybe load those two just in the constructor, we never go back to the display
    menu = LoadTexture("assets/graphics/Background/Home screen backgrounds new/Start Screen background.png");
    logo = LoadTexture("assets/graphics/Animation/Sheets/Logo/Logo-Sheet.png");
    logoFrame = {0.0f, 0.0f, (float) logo.width / 9, (float) logo.height};
    start = LoadTexture("assets/graphics/Text/Start Game.png");
    startH = LoadTexture("assets/graphics/Text/Start Game- Highlight.png");
    gallery = LoadTexture("assets/graphics/Text/Gallery.png");
    galleryH = LoadTexture("assets/graphics/Text/Gallery - Highlight.png");
    exit = LoadTexture("assets/graphics/Text/Exit Game.png");
    exitH = LoadTexture("assets/graphics/Text/Exit Game - Highlight.png");
    logoB = {Game::ScreenWidth / 3 - 20, Game::ScreenHeight / 9, logo};
    startB = {Game::ScreenWidth / 3 + 6, Game::ScreenHeight / 9 * 5, start};
    galleryB = {Game::ScreenWidth / 3, Game::ScreenHeight / 9 * 6, gallery};
    exitB = {Game::ScreenWidth / 3 - 1, Game::ScreenHeight / 9 * 7, exit};
    menuLoaded = true;
}

void Game::GameScreen::LoadLevelTextures() {
    background = LoadTexture(
            "assets/graphics/Animation/Sheets/Background/Background Animation - mit Color Palette.png");
    backgroundFrame = {0.0f, 0.0f, (float) background.width / 11, (float) background.height};
    dirtT = LoadTexture("assets/graphics/Template/Tiles/Tileset.png");
    dirtVanishAnim = LoadTexture("assets/graphics/Animation/Sheets/Objects/Tiles/Tiles.png");
    memories = LoadTexture("assets/graphics/Animation/Sheets/Objects/Polaroid-Sheet.png");
    frameRec_Memories = {0.0f, 0.0f, (float) memories.width / 7, (float) memories.height};
    crackedWall = LoadTexture("assets/graphics/Template/Wall_and_Door/Cracked_Wall_1.png");
    wall2 = LoadTexture("assets/graphics/Template/Wall_and_Door/wall_2.png");
    wall3 = LoadTexture("assets/graphics/Template/Wall_and_Door/wall_3.png");
    frameRec_Wall = {0.0f, 0.0f, (float) 24, 24};
    boulder_down = LoadTexture("assets/graphics/Animation/Sheets/Objects/Boulder/Boulder down-Sheet.png");
    boulder_up = LoadTexture("assets/graphics/Animation/Sheets/Objects/Boulder/Boulder up-Sheet.png");
    boulder_left = LoadTexture("assets/graphics/Animation/Sheets/Objects/Boulder/Boulder-left-Sheet.png");
    boulder_right = LoadTexture("assets/graphics/Animation/Sheets/Objects/Boulder/Boulder right-Sheet.png");
    frameRec_Boulder = {0.0f, 0.0f, (float) boulder_down.width / 5, (float) boulder_down.height};
    riegel = LoadTexture("assets/graphics/Template/Bar/1x1.png");
    frameRec_Riegel = {0.0f, 0.0f, (float) 24, 24};
    door = LoadTexture("assets/graphics/Template/Wall_and_Door/Door.png");
    frameRec_Door = {0.0f, 0.0f, (float) 24, 24};
    GameOver = LoadTexture("assets/graphics/Animation/Sheets/Screens/GameOver_Screen-Sheet.png");
    GameOverFrame = {0.0f, 0.0f, (float) GameOver.width / 2, (float) GameOver.height};
    hotbar = LoadTexture("assets/graphics/Other/Hotbar/Hotbar.png");
    numbers = LoadTexture("assets/graphics/Other/Hotbar/Collectibles/Numbers.png");
    levelLoaded = true;
}

void Game::GameScreen::LoadHubTextures() {
    hub = LoadTexture("assets/graphics/Background/HUB/hub1.png");
    hubFurniture = LoadTexture("assets/graphics/Background/HUB/hub_moebel_2.png");
    galleryInteractionText = LoadTexture("assets/graphics/Background/HUB/Gallery Book/Book text.png");
    bookOutline = LoadTexture("assets/graphics/Background/HUB/Gallery Book/Book_outline.png");
    bookAnimation = LoadTexture("assets/graphics/Background/HUB/Gallery Book/Book_animation.png");
    bookFrameRec = {0.0f, 0.0f, (float) bookAnimation.width / 7, (float) bookAnimation.height};
    compass = LoadTexture("assets/graphics/Animation/Sheets/Objects/Compass_received-Sheet.png");
    compassRec = {0, 0, 28, 28};
    hubLoaded = true;
}

void Game::GameScreen::LoadGalleryTextures() {
    CoreMem1 = LoadTexture("assets/graphics/Animation/Sheets/Gallery/Memory1-sheet.png");
    Mem1Frame = {0.0f, 0.0f, (float) CoreMem1.width, (float) CoreMem1.height};
    CoreMem2 = LoadTexture("assets/graphics/Animation/Sheets/Gallery/Memory2-sheet.png");
    Mem2Frame = {0.0f, 0.0f, (float) CoreMem2.width, (float) CoreMem2.height};
    CoreMem3 = LoadTexture("assets/graphics/Animation/Sheets/Gallery/Memory3-Sheet.png");
    Mem3Frame = {0.0f, 0.0f, (float) CoreMem3.width, (float) CoreMem3.height};
    galleryLoaded = true;
}

void Game::GameScreen::LoadRoomTextures() {

}

void Game::GameScreen::DeloadMenuTextures() {
    UnloadTexture(startScreen);
    UnloadTexture(menu);
    UnloadTexture(logo);
    UnloadTexture(start);
    UnloadTexture(startH);
    UnloadTexture(gallery);
    UnloadTexture(galleryH);
    UnloadTexture(exit);
    UnloadTexture(exitH);
    menuLoaded = false;
}

void Game::GameScreen::DeloadLevelTextures() {
    UnloadTexture(background);
    UnloadTexture(dirtVanishAnim);
    UnloadTexture(dirtT);
    UnloadTexture(memories);
    UnloadTexture(crackedWall);
    UnloadTexture(wall2);
    UnloadTexture(wall3);
    UnloadTexture(boulder_up);
    UnloadTexture(boulder_down);
    UnloadTexture(boulder_left);
    UnloadTexture(boulder_right);
    UnloadTexture(riegel);
    UnloadTexture(door);
    UnloadTexture(GameOver);
    UnloadTexture(hotbar);
    UnloadTexture(numbers);
    levelLoaded = false;
}

void Game::GameScreen::DeloadHubTextures() {
    UnloadTexture(hub);
    UnloadTexture(hubFurniture);
    UnloadTexture(galleryInteractionText);
    UnloadTexture(bookOutline);
    UnloadTexture(bookAnimation);
    UnloadTexture(compass);
    hubLoaded = false;
}

void Game::GameScreen::DeloadGalleryTextures() {
    UnloadTexture(CoreMem1);
    UnloadTexture(CoreMem2);
    UnloadTexture(CoreMem3);
    galleryLoaded = false;
}

void Game::GameScreen::DeloadRoomTextures() {

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

    if (!levelLoaded) {
        LoadLevelTextures();
    }

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
            boulderList.back().frameRec_Boulder = frameRec_Boulder;
        } else if (layout[i] == 8) { //Generate Boulder down
            boulderList.emplace_back(coordinates.x, coordinates.y, FallDown);
            boulderList.back().setTexture(boulder_down);
            boulderList.back().frameRec_Boulder = frameRec_Boulder;
        } else if (layout[i] == 9) { //Generate Boulder right
            boulderList.emplace_back(coordinates.x, coordinates.y, FallRight);
            boulderList.back().setTexture(boulder_right);
            boulderList.back().frameRec_Boulder = frameRec_Boulder;
        } else if (layout[i] == 10) { //Generate Boulder up
            boulderList.emplace_back(coordinates.x, coordinates.y, FallUp);
            boulderList.back().setTexture(boulder_up);
            boulderList.back().frameRec_Boulder = frameRec_Boulder;
        } else if (layout[i] == 4) { //Generate Memory
            memoryList.emplace_back(coordinates.x, coordinates.y);
            memoryList.back().setTexture(memories);
            memoryList.back().frameRec = frameRec_Memories;
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
    immortalList.emplace_back(192, 150);
    maxMemories = memoryList.size() + mortalList.size() + immortalList.size();
}

void Game::GameScreen::playerInteractions() {
    if (player.lives > 0) {
        player.updatePlayer();
        player.idleAnimation();
        for (auto &i: boulderList) { //CHECKT FÜR ÜBERSCHNEIDUNG BEI Boulders, UND FÜHRT BENÖTIGTE METHODEN AUS
            if (CheckCollisionRecs(player.getCollRec(), i.getCollRec())) {
                if (i.direction == 0 || i.direction == 1) {
                    float difference = (player.getCollRec().y - i.getCollRec().y);
                    if (difference < 0) {
                        difference *= -1;
                    }
                    if (difference <= 2) player.lives = 0; //Spieler stirbt
                } else if (i.direction == 2 || i.direction == 3) {
                    float difference = (player.getCollRec().x - i.getCollRec().x);
                    if (difference < 0) {
                        difference *= -1;
                    }
                    if (difference <= 2) player.lives = 0; //Spieler stirbt
                }
                // hier kann man active auf false setzen, dann in Draw die Todes animation abspielen. Danach
                // TExt aufploppen lassen wie "drücke rfür restart" oder so
            }
        }
        for (auto &mE: mortalList) { //CHECKT FÜR ÜBERSCHNEIDUNG BEI Boulders, UND FÜHRT BENÖTIGTE METHODEN AUS
            if (mE.active) {
                if (CheckCollisionRecs(player.getCollRec(), mE.getCollRec())) {
                    if ((player.getCollRec().x - mE.getCollRec().x) <= 2 &&
                        (player.getCollRec().y - mE.getCollRec().y) <= 2) {
                        player.lives = 0; //Spieler stirbt
                    }
                    // hier kann man active auf false setzen, dann in Draw die Todes animation abspielen. Danach
                    // TExt aufploppen lassen wie "drücke rfür restart" oder so
                }
            }
        }
        for (auto &iE: immortalList) { //CHECKT FÜR ÜBERSCHNEIDUNG BEI Boulders, UND FÜHRT BENÖTIGTE METHODEN AUS
            if (iE.active) {
                if (CheckCollisionRecs(player.getCollRec(), iE.getCollRec())) {
                    if ((player.getCollRec().x - iE.getCollRec().x) <= 2 &&
                        (player.getCollRec().y - iE.getCollRec().y) <= 2) {
                        player.lives = 0; //Spieler stirbt
                    }
                    // hier kann man active auf false setzen, dann in Draw die Todes animation abspielen. Danach
                    // TExt aufploppen lassen wie "drücke rfür restart" oder so
                }
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
                    i.setTexture(dirtVanishAnim);
                    i.frameRec_dirtT = {0, 0, 24, 24};
                }
            }
        }
        for (auto &d: doorList) { //CHECKT FÜR COLLISION BEI DIRT, UND FÜHRT BENÖTIGTE METHODEN AUS
            if (CheckCollisionRecs(player.getCollRec(), d.getCollRec()) && collected == memoryList.size()) {
                if (player.getPos().x == d.getPos().x && player.getPos().y == d.getPos().y) {
                    if (d.active) {
                        if (roomCounter == 1) { //switch to hub
                            display = 2;
                            initializeHubElements();
                            roomCounter = 0;
                        } else { // next level
                            nextDisplay = 1;
                            cutsceneNumber = 1;
                            display = 11;
                            roomCounter++;
                            hotbarDataLoaded = false;
                            generateMap();
                        }
                    }
                }
            }
        }
        // Interaction for adjacent spaces
        if (IsKeyDown(KEY_LEFT_CONTROL) || IsKeyDown(KEY_RIGHT_CONTROL)) {
            player.setAdjRec(player.getPos().x, player.getPos().y, 24, 24);
            if (!player.moving) {
                player.updatePlayer();
                if (player.diggingDone) {
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
                                i.setTexture(dirtVanishAnim);
                                i.frameRec_dirtT = {0, 0, 24, 24};
                            }
                        }
                    }
                }
            }
        }
        canPlayerMove();
        if (player.canMove && !dialogueManager.open) {
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
    /*
     * Boulder checken nicht nach Riegeln
     */
    for (auto &i: boulderList) { //BOULDERS
        i.updateBoulder();
        bool canFall = true;
        switch (i.direction) {
            case FallDown:
                for (auto &d: dirtList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.getAdjRec(), d.getCollRec())) {
                        if (d.active) {
                            if (i.adjRectangle.y == d.getCollRec().y) {
                                canFall = false;
                            }
                        }
                    }
                }
                for (auto &w: wallList) { //CHECKT FÜR COLLISION BEI Walls, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.adjRectangle, w.getCollRec())) {
                        if (i.adjRectangle.y == w.getCollRec().y) {
                            canFall = false;
                        }
                    }
                }
                for (auto &m: memoryList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.adjRectangle, m.getCollRec())) {
                        if (m.active) {
                            if (i.adjRectangle.y == m.getCollRec().y) {
                                canFall = false;
                            }
                        }
                    }
                }
                for (auto &immortal: immortalList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.adjRectangle, immortal.getCollRec())) {
                        if (immortal.active) {
                            if(immortal.getCollRec().y - i.getCollRec().y <= 6) {
                                canFall = false;
                            }
                        }
                    }
                }
                for (auto &otherBoulder: boulderList) {
                    if (&i != &otherBoulder) {
                        if (CheckCollisionRecs(i.adjRectangle, otherBoulder.getCollRec())) {
                            if (i.adjRectangle.y == otherBoulder.getCollRec().y) {
                                canFall = false;
                            }
                        }
                    }
                }
                if (canFall) {
                    i.fall();
                } else i.falling = false;
                break;
            case FallUp:
                for (auto &d: dirtList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.getAdjRec(), d.getCollRec())) {
                        if (d.active) {
                            if (i.adjRectangle.y == d.getCollRec().y) {
                                canFall = false;
                            }
                        }
                    }
                }
                for (auto &w: wallList) { //CHECKT FÜR COLLISION BEI Walls, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.adjRectangle, w.getCollRec())) {
                        if (i.adjRectangle.y == w.getCollRec().y) {
                            canFall = false;
                        }
                    }
                }
                for (auto &m: memoryList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.adjRectangle, m.getCollRec())) {
                        if (m.active) {
                            if (i.adjRectangle.y == m.getCollRec().y) {
                                canFall = false;
                            }
                        }
                    }
                }
                for (auto &immortal: immortalList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.adjRectangle, immortal.getCollRec())) {
                        if (immortal.active) {
                            if(i.getCollRec().y - immortal.getCollRec().y <= 6) {
                                canFall = false;
                            }
                        }
                    }
                }
                for (auto &otherBoulder: boulderList) {
                    if (&i != &otherBoulder) {
                        if (CheckCollisionRecs(i.adjRectangle, otherBoulder.getCollRec())) {
                            if (i.adjRectangle.y == otherBoulder.getCollRec().y) {
                                canFall = false;
                            }
                        }
                    }
                }
                if (canFall) {
                    i.fall();
                } else i.falling = false;
                break;
            case FallLeft:
                for (auto &d: dirtList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.getAdjRec(), d.getCollRec())) {
                        if (d.active) {
                            if (i.adjRectangle.x == d.getCollRec().x) {
                                canFall = false;
                            }
                        }
                    }
                }
                for (auto &w: wallList) { //CHECKT FÜR COLLISION BEI Walls, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.adjRectangle, w.getCollRec())) {
                        if (i.adjRectangle.x == w.getCollRec().x) {
                            canFall = false;
                        }
                    }
                }
                for (auto &m: memoryList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.adjRectangle, m.getCollRec())) {
                        if (m.active) {
                            if (i.adjRectangle.x == m.getCollRec().x) {
                                canFall = false;
                            }
                        }
                    }
                }
                for (auto &immortal: immortalList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.adjRectangle, immortal.getCollRec())) {
                        if (immortal.active) {
                            if(i.getCollRec().x - immortal.getCollRec().x <= 6) {
                                canFall = false;
                            }
                        }
                    }
                }
                for (auto &otherBoulder: boulderList) {
                    if (&i != &otherBoulder) {
                        if (CheckCollisionRecs(i.adjRectangle, otherBoulder.getCollRec())) {
                            if (i.adjRectangle.x == otherBoulder.getCollRec().x) {
                                canFall = false;
                            }
                        }
                    }
                }
                if (canFall) {
                    i.fall();
                } else i.falling = false;
                break;
            case FallRight:
                for (auto &d: dirtList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.getAdjRec(), d.getCollRec())) {
                        if (d.active) {
                            if (i.adjRectangle.x == d.getCollRec().x) {
                                canFall = false;
                            }
                        }
                    }
                }
                for (auto &w: wallList) { //CHECKT FÜR COLLISION BEI Walls, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.adjRectangle, w.getCollRec())) {
                        if (i.adjRectangle.x == w.getCollRec().x) {
                            canFall = false;
                        }
                    }
                }
                for (auto &m: memoryList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.adjRectangle, m.getCollRec())) {
                        if (m.active) {
                            if (i.adjRectangle.x == m.getCollRec().x) {
                                canFall = false;
                            }
                        }
                    }
                }
                for (auto &immortal: immortalList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.adjRectangle, immortal.getCollRec())) {
                        if (immortal.active) {
                            if(immortal.getCollRec().x - i.getCollRec().x <= 6) {
                                canFall = false;
                            }
                        }
                    }
                }
                for (auto &otherBoulder: boulderList) {
                    if (&i != &otherBoulder) {
                        if (CheckCollisionRecs(i.adjRectangle, otherBoulder.getCollRec())) {
                            if (i.adjRectangle.x == otherBoulder.getCollRec().x) {
                                canFall = false;
                            }
                        }
                    }
                }
                if (canFall) {
                    i.fall();
                } else i.falling = false;
                break;
        }
    }
}

void Game::GameScreen::canMortalMove() {
    for (auto &e: mortalList) { //enemy
        // right --> up --> left --> down --> idle

        if (e.active) {
            e.updateEnemy();

            // Check for right side
            bool canMoveRight = true;
            e.setAdjRec(e.getCollRec().x + 24, e.getCollRec().y, e.getCollRec().width, e.getCollRec().height);
            for (auto &d: dirtList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                if (CheckCollisionRecs(e.getAdjRec(), d.getCollRec())) {
                    if (d.active) {
                        if (e.adjRectangle.x == d.getCollRec().x) {
                            canMoveRight = false;
                        }
                    }
                }
            }
            for (auto &w: wallList) { //CHECKT FÜR COLLISION BEI Walls, UND FÜHRT BENÖTIGTE METHODEN AUS
                if (CheckCollisionRecs(e.getAdjRec(), w.getCollRec())) {
                    if (w.active) {
                        if (e.adjRectangle.x == w.getCollRec().x) {
                            canMoveRight = false;
                        }
                    }
                }
            }
            for (auto &m: memoryList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                if (CheckCollisionRecs(e.getAdjRec(), m.getCollRec())) {
                    if (m.active) {
                        if (e.adjRectangle.x == m.getCollRec().x) {
                            canMoveRight = false;
                        }
                    }
                }
            }
            for (auto &b: boulderList) {
                if (CheckCollisionRecs(e.getAdjRec(), b.getCollRec())) {
                    if (b.active) {
                        if (e.adjRectangle.x == b.getCollRec().x) {
                            canMoveRight = false;
                        }
                    }
                }
            }
            for (auto &d: doorList) {
                if (CheckCollisionRecs(e.getAdjRec(), d.getCollRec())) {
                    if (d.active) {
                        if (e.adjRectangle.x == d.getCollRec().x) {
                            canMoveRight = false;
                        }
                    }
                }
            }

            // Check for upwards
            bool canMoveUp = true;
            e.setAdjRec(e.getCollRec().x, e.getCollRec().y - 24, e.getCollRec().width, e.getCollRec().height);
            for (auto &d: dirtList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                if (CheckCollisionRecs(e.getAdjRec(), d.getCollRec())) {
                    if (d.active) {
                        if (e.adjRectangle.y == d.getCollRec().y) {
                            canMoveUp = false;
                        }
                    }
                }
            }
            for (auto &w: wallList) { //CHECKT FÜR COLLISION BEI Walls, UND FÜHRT BENÖTIGTE METHODEN AUS
                if (CheckCollisionRecs(e.getAdjRec(), w.getCollRec())) {
                    if (w.active) {
                        if (e.adjRectangle.y == w.getCollRec().y) {
                            canMoveUp = false;
                        }
                    }
                }
            }
            for (auto &m: memoryList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                if (CheckCollisionRecs(e.getAdjRec(), m.getCollRec())) {
                    if (m.active) {
                        if (e.adjRectangle.y == m.getCollRec().y) {
                            canMoveUp = false;
                        }
                    }
                }
            }
            for (auto &b: boulderList) {
                if (CheckCollisionRecs(e.getAdjRec(), b.getCollRec())) {
                    if (b.active) {
                        if (e.adjRectangle.y == b.getCollRec().y) {
                            canMoveUp = false;
                        }
                    }
                }
            }
            for (auto &d: doorList) {
                if (CheckCollisionRecs(e.getAdjRec(), d.getCollRec())) {
                    if (d.active) {
                        if (e.adjRectangle.y == d.getCollRec().y) {
                            canMoveUp = false;
                        }
                    }
                }
            }

            // Check for left side
            bool canMoveLeft = true;
            e.setAdjRec(e.getCollRec().x - 24, e.getCollRec().y, e.getCollRec().width, e.getCollRec().height);
            for (auto &d: dirtList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                if (CheckCollisionRecs(e.getAdjRec(), d.getCollRec())) {
                    if (d.active) {
                        if (e.adjRectangle.x == d.getCollRec().x) {
                            canMoveLeft = false;
                        }
                    }
                }
            }
            for (auto &w: wallList) { //CHECKT FÜR COLLISION BEI Walls, UND FÜHRT BENÖTIGTE METHODEN AUS
                if (CheckCollisionRecs(e.getAdjRec(), w.getCollRec())) {
                    if (w.active) {
                        if (e.adjRectangle.x == w.getCollRec().x) {
                            canMoveLeft = false;
                        }
                    }
                }
            }
            for (auto &m: memoryList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                if (CheckCollisionRecs(e.getAdjRec(), m.getCollRec())) {
                    if (m.active) {
                        if (e.adjRectangle.x == m.getCollRec().x) {
                            canMoveLeft = false;
                        }
                    }
                }
            }
            for (auto &b: boulderList) {
                if (CheckCollisionRecs(e.getAdjRec(), b.getCollRec())) {
                    if (b.active) {
                        if (e.adjRectangle.x == b.getCollRec().x) {
                            canMoveLeft = false;
                        }
                    }
                }
            }
            for (auto &d: doorList) {
                if (CheckCollisionRecs(e.getAdjRec(), d.getCollRec())) {
                    if (d.active) {
                        if (e.adjRectangle.x == d.getCollRec().x) {
                            canMoveLeft = false;
                        }
                    }
                }
            }

            // Check for downwards
            bool canMoveDown = true;
            e.setAdjRec(e.getCollRec().x, e.getCollRec().y + 24, e.getCollRec().width, e.getCollRec().height);
            for (auto &d: dirtList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                if (CheckCollisionRecs(e.getAdjRec(), d.getCollRec())) {
                    if (d.active) {
                        if (e.adjRectangle.y == d.getCollRec().y) {
                            canMoveDown = false;
                        }
                    }
                }
            }
            for (auto &w: wallList) { //CHECKT FÜR COLLISION BEI Walls, UND FÜHRT BENÖTIGTE METHODEN AUS
                if (CheckCollisionRecs(e.getAdjRec(), w.getCollRec())) {
                    if (w.active) {
                        if (e.adjRectangle.y == w.getCollRec().y) {
                            canMoveDown = false;
                        }
                    }
                }
            }
            for (auto &m: memoryList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                if (CheckCollisionRecs(e.getAdjRec(), m.getCollRec())) {
                    if (m.active) {
                        if (e.adjRectangle.y == m.getCollRec().y) {
                            canMoveDown = false;
                        }
                    }
                }
            }
            for (auto &b: boulderList) {
                if (CheckCollisionRecs(e.getAdjRec(), b.getCollRec())) {
                    if (b.active) {
                        if (e.adjRectangle.y == b.getCollRec().y) {
                            canMoveDown = false;
                        }
                    }
                }
            }
            for (auto &d: doorList) {
                if (CheckCollisionRecs(e.getAdjRec(), d.getCollRec())) {
                    if (d.active) {
                        if (e.adjRectangle.y == d.getCollRec().y) {
                            canMoveDown = false;
                        }
                    }
                }
            }

            if (!e.dead) {
                for (auto &b: boulderList) { //CHECKT FÜR ÜBERSCHNEIDUNG BEI Boulders, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(e.getCollRec(), b.getCollRec())) {
                        if ((e.getCollRec().x - b.getCollRec().x) <= 2 &&
                            (e.getCollRec().y - b.getCollRec().y) <= 2) {
                            e.dead = true;
                            e.currentFrame = 0;
                        }
                        // hier kann man active auf false setzen, dann in Draw die Todes animation abspielen. Danach
                        // TExt aufploppen lassen wie "drücke rfür restart" oder so
                    }
                }
                if (IsKeyPressed(KEY_P)) {
                    e.dead = true;
                    e.currentFrame = 0;
                }
            }

            if (!e.dead) {
                // determine path
                // If there is nothing around the enemy it freaks out, tries to move into every direction but ultimately doesn't move
                // this acts as a failsafe, sending it down and right until it has footing.
                // if there are bugs,this needs to be adjusted
                if (e.struggle == 3 && canMoveDown) {
                    e.direction = e.moveDown;
                    e.move();
                    e.moveAnimation();
                    break;
                }
                // find a cleaner solution
                if (e.struggle == 3 && (e.direction == e.moveDown || e.direction == e.moveRight)) {
                    if (!canMoveDown) {
                        if (canMoveRight) {
                            e.direction = e.moveRight;
                            e.move();
                            e.moveAnimation();
                            break;
                        } else {
                            e.struggle = 0;
                        }
                    }
                }
                if (canMoveRight && e.direction != e.moveDown && e.direction != e.moveLeft) {
                    if (e.direction == e.moveDown && canMoveLeft && canMoveRight) {
                        e.struggle = 0;
                        e.direction = e.moveLeft;
                        e.move();
                        e.moveAnimation();
                        break;
                    } else if (e.direction == e.moveRight && canMoveDown) {
                        e.direction = e.moveDown;
                        e.move();
                        e.moveAnimation();
                        e.struggle++;
                        break;
                    } else {
                        e.direction = e.moveRight;
                        e.move();
                        e.moveAnimation();
                        break;
                    }
                }
                if (canMoveUp && e.direction != e.moveRight && e.direction != e.moveDown) {
                    e.direction = e.moveUp;
                    e.move();
                    e.moveAnimation();
                    break;
                }
                if (canMoveLeft && e.direction != e.moveUp && e.direction != e.moveRight) {
                    e.direction = e.moveLeft;
                    e.move();
                    e.moveAnimation();
                    break;
                }
                if (canMoveDown && e.direction != e.moveUp) {
                    e.struggle = 0;
                    if (e.direction == e.moveLeft && canMoveLeft) {
                        e.direction = e.moveLeft;
                        e.move();
                        e.moveAnimation();
                        break;
                    } else {
                        e.struggle = 0;
                        e.direction = e.moveDown;
                        e.move();
                        e.moveAnimation();
                        break;
                    }
                } else {
                    e.struggle = 0;
                    e.direction = e.idle;
                    e.idleAnimation();
                    break;
                }
            } else {
                // enemy is dead
                if (!e.deathAnimDone) {
                    e.deathAnimation();
                }
                if (e.deathAnimDone) {
                    // get coordinates for memory generation
                    if (!e.memoryGenerated) {
                        e.active = false;
                        int xOne = e.getPos().x;
                        int xCor = (xOne / 24) * 24;
                        if (xOne % 24 > 11) {
                            xCor += 24;
                        }
                        int yOne = e.getPos().y;
                        int yCor = ((yOne - 30) / 24) * 24 + 30;
                        if ((yOne - 30) % 24 > 11) {
                            yCor += 24;
                        }
                        // spawn memory
                        /*
                         * Input code to search for open space in a 1(?) tile radius
                         * do that twice
                         * then add TWO memories
                         */
                        memoryList.emplace_back(xCor, yCor);
                        memoryList.back().setTexture(memories);
                        memoryList.back().frameRec = memoryList.front().frameRec;
                        memoryList.back().delay = memoryList.front().delay;
                        memoryList.back().frameCounter = memoryList.front().frameCounter;
                        memoryList.back().currentFrame = memoryList.front().currentFrame;
                        e.memoryGenerated = true;
                    }
                }
            }
        }
    }
}

void Game::GameScreen::canImmortalMove() {
    for (auto &e: immortalList) { //enemy
        // right --> up --> left --> down --> idle

        if (e.active) {
            e.updateEnemy();

            // Check for right side
            bool canMoveRight = true;
            e.setAdjRec(e.getCollRec().x + 24, e.getCollRec().y, e.getCollRec().width, e.getCollRec().height);
            for (auto &d: dirtList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                if (CheckCollisionRecs(e.getAdjRec(), d.getCollRec())) {
                    if (d.active) {
                        if (e.adjRectangle.x == d.getCollRec().x) {
                            canMoveRight = false;
                        }
                    }
                }
            }
            for (auto &w: wallList) { //CHECKT FÜR COLLISION BEI Walls, UND FÜHRT BENÖTIGTE METHODEN AUS
                if (CheckCollisionRecs(e.getAdjRec(), w.getCollRec())) {
                    if (w.active) {
                        if (e.adjRectangle.x == w.getCollRec().x) {
                            canMoveRight = false;
                        }
                    }
                }
            }
            for (auto &b: boulderList) {
                if (CheckCollisionRecs(e.getAdjRec(), b.getCollRec())) {
                    if (b.active) {
                        if(!b.falling) {
                            if (e.adjRectangle.x == b.getCollRec().x) {
                                canMoveRight = false;
                            }
                        } else {
                            if (b.getCollRec().x - e.adjRectangle.x <= 6) {
                                canMoveRight = false;
                            }
                        }
                    }
                }
            }
            for (auto &d: doorList) {
                if (CheckCollisionRecs(e.getAdjRec(), d.getCollRec())) {
                    if (d.active) {
                        if (e.adjRectangle.x == d.getCollRec().x) {
                            canMoveRight = false;
                        }
                    }
                }
            }
            // Check for upwards
            bool canMoveUp = true;
            e.setAdjRec(e.getCollRec().x, e.getCollRec().y - 24, e.getCollRec().width, e.getCollRec().height);
            for (auto &d: dirtList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                if (CheckCollisionRecs(e.getAdjRec(), d.getCollRec())) {
                    if (d.active) {
                        if (e.adjRectangle.y == d.getCollRec().y) {
                            canMoveUp = false;
                        }
                    }
                }
            }
            for (auto &w: wallList) { //CHECKT FÜR COLLISION BEI Walls, UND FÜHRT BENÖTIGTE METHODEN AUS
                if (CheckCollisionRecs(e.getAdjRec(), w.getCollRec())) {
                    if (w.active) {
                        if (e.adjRectangle.y == w.getCollRec().y) {
                            canMoveUp = false;
                        }
                    }
                }
            }
            for (auto &b: boulderList) {
                if (CheckCollisionRecs(e.getAdjRec(), b.getCollRec())) {
                    if (b.active) {
                        if(!b.falling) {
                            if (e.adjRectangle.y == b.getCollRec().y) {
                                canMoveUp = false;
                            }
                        } else {
                            if (b.getCollRec().y - e.adjRectangle.y <= 6) {
                                canMoveUp = false;
                            }
                        }
                    }
                }
            }
            for (auto &d: doorList) {
                if (CheckCollisionRecs(e.getAdjRec(), d.getCollRec())) {
                    if (d.active) {
                        if (e.adjRectangle.y == d.getCollRec().y) {
                            canMoveUp = false;
                        }
                    }
                }
            }
            // Check for left side
            bool canMoveLeft = true;
            e.setAdjRec(e.getCollRec().x - 24, e.getCollRec().y, e.getCollRec().width, e.getCollRec().height);
            for (auto &d: dirtList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                if (CheckCollisionRecs(e.getAdjRec(), d.getCollRec())) {
                    if (d.active) {
                        if (e.adjRectangle.x == d.getCollRec().x) {
                            canMoveLeft = false;
                        }
                    }
                }
            }
            for (auto &w: wallList) { //CHECKT FÜR COLLISION BEI Walls, UND FÜHRT BENÖTIGTE METHODEN AUS
                if (CheckCollisionRecs(e.getAdjRec(), w.getCollRec())) {
                    if (w.active) {
                        if (e.adjRectangle.x == w.getCollRec().x) {
                            canMoveLeft = false;
                        }
                    }
                }
            }
            for (auto &b: boulderList) {
                if (CheckCollisionRecs(e.getAdjRec(), b.getCollRec())) {
                    if (b.active) {
                        if(!b.falling) {
                            if (e.adjRectangle.x == b.getCollRec().x) {
                                canMoveLeft = false;
                            }
                        } else {
                            if (e.getAdjRec().x - b.getCollRec().x <= 6) {
                                canMoveLeft = false;
                            }
                        }
                    }
                }
            }
            for (auto &d: doorList) {
                if (CheckCollisionRecs(e.getAdjRec(), d.getCollRec())) {
                    if (d.active) {
                        if (e.adjRectangle.x == d.getCollRec().x) {
                            canMoveLeft = false;
                        }
                    }
                }
            }
            // Check for downwards
            bool canMoveDown = true;
            e.setAdjRec(e.getCollRec().x, e.getCollRec().y + 24, e.getCollRec().width, e.getCollRec().height);
            for (auto &d: dirtList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                if (CheckCollisionRecs(e.getAdjRec(), d.getCollRec())) {
                    if (d.active) {
                        if (e.adjRectangle.y == d.getCollRec().y) {
                            canMoveDown = false;
                        }
                    }
                }
            }
            for (auto &w: wallList) { //CHECKT FÜR COLLISION BEI Walls, UND FÜHRT BENÖTIGTE METHODEN AUS
                if (CheckCollisionRecs(e.getAdjRec(), w.getCollRec())) {
                    if (w.active) {
                        if (e.adjRectangle.y == w.getCollRec().y) {
                            canMoveDown = false;
                        }
                    }
                }
            }
            for (auto &b: boulderList) {
                if (CheckCollisionRecs(e.getAdjRec(), b.getCollRec())) {
                    if (b.active) {
                        if(!b.falling) {
                            if (e.adjRectangle.y == b.getCollRec().y) {
                                canMoveDown = false;
                            }
                        } else {
                            if (b.getCollRec().y - e.adjRectangle.y <= 6) {
                                canMoveDown = false;
                            }
                        }
                    }
                }
            }
            for (auto &d: doorList) {
                if (CheckCollisionRecs(e.getAdjRec(), d.getCollRec())) {
                    if (d.active) {
                        if (e.adjRectangle.y == d.getCollRec().y) {
                            canMoveDown = false;
                        }
                    }
                }
            }

            if (!e.hasEaten) {
                for (auto &m: memoryList) { //CHECKT FÜR ÜBERSCHNEIDUNG BEI Boulders, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(e.getCollRec(), m.getCollRec())) {
                        if (e.getCollRec().x == m.getCollRec().x && e.getCollRec().y == m.getCollRec().y) {
                            e.hasEaten = true;
                            e.currentFrame = 0;
                            m.active = false;
                            m.collected = true;
                        }
                        // hier kann man active auf false setzen, dann in Draw die Todes animation abspielen. Danach
                        // TExt aufploppen lassen wie "drücke rfür restart" oder so
                    }
                }
                if (IsKeyPressed(KEY_U)) {
                    e.hasEaten = true;
                    e.currentFrame = 0;
                }
            }

            if (!e.hasEaten) {
                // determine path
                // If there is nothing around the enemy it freaks out, tries to move into every direction but ultimately doesn't move
                // this acts as a failsafe, sending it down and right until it has footing.
                // if there are bugs,this needs to be adjusted
                if (e.struggle == 3 && canMoveDown) {
                    e.direction = e.moveDown;
                    e.move();
                    e.moveAnimation();
                    break;
                }
                // find a cleaner solution
                if (e.struggle == 3 && (e.direction == e.moveDown || e.direction == e.moveRight)) {
                    if (!canMoveDown) {
                        if (canMoveRight) {
                            e.direction = e.moveRight;
                            e.move();
                            e.moveAnimation();
                            break;
                        } else {
                            e.struggle = 0;
                        }
                    }
                }
                if (canMoveRight && e.direction != e.moveDown && e.direction != e.moveLeft) {
                    if (e.direction == e.moveDown && canMoveLeft && canMoveRight) {
                        e.struggle = 0;
                        e.direction = e.moveLeft;
                        e.move();
                        e.moveAnimation();
                        break;
                    } else if (e.direction == e.moveRight && canMoveDown) {
                        e.direction = e.moveDown;
                        e.move();
                        e.moveAnimation();
                        e.struggle++;
                        break;
                    } else {
                        e.direction = e.moveRight;
                        e.move();
                        e.moveAnimation();
                        break;
                    }
                }
                if (canMoveUp && e.direction != e.moveRight && e.direction != e.moveDown) {
                    e.direction = e.moveUp;
                    e.move();
                    e.moveAnimation();
                    break;
                }
                if (canMoveLeft && e.direction != e.moveUp && e.direction != e.moveRight) {
                    e.direction = e.moveLeft;
                    e.move();
                    e.moveAnimation();
                    break;
                }
                if (canMoveDown && e.direction != e.moveUp) {
                    e.struggle = 0;
                    if (e.direction == e.moveLeft && canMoveLeft) {
                        e.direction = e.moveLeft;
                        e.move();
                        e.moveAnimation();
                        break;
                    } else {
                        e.struggle = 0;
                        e.direction = e.moveDown;
                        e.move();
                        e.moveAnimation();
                        break;
                    }
                } else {
                    e.struggle = 0;
                    e.direction = e.idle;
                    e.idleAnimation();
                    break;
                }
            } else {
                // enemy has eaten a memory
                // get coordinates for memory generation
                if (e.active) {
                    e.active = false;
                    int xOne = e.getPos().x;
                    int xCor = (xOne / 24) * 24;
                    if (xOne % 24 > 11) {
                        xCor += 24;
                    }
                    int yOne = e.getPos().y;
                    int yCor = ((yOne - 30) / 24) * 24 + 30;
                    if ((yOne - 30) % 24 > 11) {
                        yCor += 24;
                    }
                    // spawn mortal Enemy
                    mortalList.emplace_back(xCor, yCor);
                }
            }
        }
    }
}

void Game::GameScreen::clearLevel() {
    dirtList.clear();
    memoryList.clear();
    boulderList.clear();
    mortalList.clear();
    immortalList.clear();
    wallList.clear();
    riegelList.clear();
    doorList.clear();
    levelLayout = {};
    UnloadTexture(hotbarLevel); //Nur machen, wenn actually needed?
    UnloadTexture(hotbarArea);
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

void Game::GameScreen::drawCompass() {
    compassCounter++;
    if (compassCounter >= (60 / framesSpeed)) {

        compassCounter = 0;
        compassFrame++;
        int depictedFrame = compassFrame;

        if (compassFrame > 17) depictedFrame = 0;

        compassRec.x = (float) (depictedFrame % 6) * (float) compass.width / 6;
        compassRec.y = (depictedFrame / 6) * ((float) compass.height / 3);
    }
    DrawTexturePro(compass, compassRec,
                   Rectangle{0, 0, compassRec.width, compassRec.height},
                   {}, 0, WHITE);
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
    //DrawRectangle((int) player.getAdjRec().x, (int) player.getAdjRec().y, (int) player.getAdjRec().width, (int) player.getAdjRec().height, MAGENTA);
    //DrawRectangle((int) player.getCollRec().x, (int) player.getCollRec().y, (int) player.getCollRec().width, (int) player.getCollRec().height, YELLOW);
    for (auto &i: dirtList) { //DIRT
        if (i.active) {
            // add i.drawDirt();
            Vector2 position = i.getPos();
            position.x *= -1 / 2;
            position.y *= -1 / 2;
            Rectangle dirtTSize{i.getPos().x, i.getPos().y, 24, 24};
            DrawTexturePro(i.getTexture(), i.frameRec_dirtT, dirtTSize, position, 0, WHITE);
        } else if (!i.vanished) {
            i.vanishAnimation();
        }
    }
    for (auto &i: memoryList) { //MEMORIES
        if (i.active) {
            i.drawMemory();
        }
    }
    for (auto &i: doorList) { //door
        // add i.drawDoor();
        Vector2 position = i.getPos();
        position.x *= -1 / 2;
        position.y *= -1 / 2;
        Rectangle doorSize{i.getPos().x, i.getPos().y, 24, 24};
        DrawTexturePro(i.getTexture(), frameRec_Riegel, doorSize, position, 0, WHITE);
    }
    player.drawPlayer();
    for (auto &mE: mortalList) {
        if (mE.active) {
            mE.drawEnemy();
        }
    }
    for (auto &iE: immortalList) {
        if (iE.active) {
            iE.drawEnemy();
        }
    }
    for (auto &i: boulderList) { //BOULDERS
        i.drawBoulder();
        // if this is only supposed to play when they're falling, add bool moving to boulders
        // set it to true when they're moving and false if not.
        // if its false, current frame stays at 0
    }
    for (auto &i: wallList) { //WALLS
        // add i.drawWall();
        Vector2 position = i.getPos();
        position.x *= -1 / 2;
        position.y *= -1 / 2;
        Rectangle wallSize{i.getPos().x, i.getPos().y, 24, 24};
        DrawTexturePro(i.getTexture(), frameRec_Wall, wallSize, position, 0, WHITE);
    }
    for (auto &i: riegelList) { //Riegel
        // add i.drawRiegel();
        Vector2 position = i.getPos();
        position.x *= -1 / 2;
        position.y *= -1 / 2;
        Rectangle riegelSize{i.getPos().x, i.getPos().y, 24, 24};
        DrawTexturePro(i.getTexture(), frameRec_Riegel, riegelSize, position, 0, WHITE);
    }
    DrawText(TextFormat("Current FPS: %i", GetFPS()), 10, 5, 15, WHITE);
    DrawText(TextFormat("Paws Of Memories"), 170, 5, 15, WHITE);
    //DrawText(TextFormat("Collected: %i", collected), 10, 31, 15, WHITE);

    if (!hotbarDataLoaded) {
        switch (roomCounter) { // WERTE ANPASSEN
            case 0: // Momentan korrekt
                hotbarLevel = LoadTexture("assets/graphics/Other/Hotbar/Level/1_3.png");
                hotbarArea = LoadTexture("assets/graphics/Other/Hotbar/Area/1_3.png");
                break;
            case 1: // Momentan korrekt
                hotbarLevel = LoadTexture("assets/graphics/Other/Hotbar/Level/1_3.png");
                hotbarArea = LoadTexture("assets/graphics/Other/Hotbar/Area/2_3.png");
                break;
            case 2: // Doesn't exist yet
                hotbarLevel = LoadTexture("assets/graphics/Other/Hotbar/Level/1_3.png");
                hotbarArea = LoadTexture("assets/graphics/Other/Hotbar/Area/3_3.png");
                break;
            case 3: // Doesn't exist yet
                hotbarLevel = LoadTexture("assets/graphics/Other/Hotbar/Level/2_3.png");
                hotbarArea = LoadTexture("assets/graphics/Other/Hotbar/Area/1_3.png");
                break;
            case 4: // Doesn't exist yet
                hotbarLevel = LoadTexture("assets/graphics/Other/Hotbar/Level/2_3.png");
                hotbarArea = LoadTexture("assets/graphics/Other/Hotbar/Area/2_3.png");
                break;
            case 5: // Doesn't exist yet
                hotbarLevel = LoadTexture("assets/graphics/Other/Hotbar/Level/2_3.png");
                hotbarArea = LoadTexture("assets/graphics/Other/Hotbar/Area/3_3.png");
                break;
            case 6: // Doesn't exist yet
                hotbarLevel = LoadTexture("assets/graphics/Other/Hotbar/Level/3_3.png");
                hotbarArea = LoadTexture("assets/graphics/Other/Hotbar/Area/1_3.png");
                break;
            case 7: // Doesn't exist yet
                hotbarLevel = LoadTexture("assets/graphics/Other/Hotbar/Level/3_3.png");
                hotbarArea = LoadTexture("assets/graphics/Other/Hotbar/Area/2_3.png");
                break;
            case 8: // Doesn't exist yet
                hotbarLevel = LoadTexture("assets/graphics/Other/Hotbar/Level/3_3.png");
                hotbarArea = LoadTexture("assets/graphics/Other/Hotbar/Area/3_3.png");
                break;
        }
        hotbarDataLoaded = true;
    }

    // if(roomCounter != NPCRooms)
    DrawTexturePro(hotbar, Rectangle{0, 0, (float) hotbar.width, (float) hotbar.height},
                   Rectangle{314, 1, (float) hotbar.width, (float) hotbar.height}, {}, 0, WHITE);
    DrawTexturePro(hotbarLevel, Rectangle{0, 0, (float) hotbarLevel.width, (float) hotbarLevel.height},
                   Rectangle{372, 8, (float) hotbarLevel.width, (float) hotbarLevel.height}, {}, 0, WHITE);
    DrawTexturePro(hotbarArea, Rectangle{0, 0, (float) hotbarArea.width, (float) hotbarArea.height},
                   Rectangle{425, 8, (float) hotbarArea.width, (float) hotbarArea.height}, {}, 0, WHITE);

    // Numbers are 1 to high, since 0 doesn't exist
    // Determine and draw first number
    firstNumber = {float(collected * 7), 0, (float) numbers.width / 9, (float) numbers.height};
    DrawTexturePro(numbers, firstNumber, Rectangle{338, 8, (float) numbers.width / 9, (float) numbers.height}, {}, 0,
                   WHITE);
    // Determine and draw second number
    secondNumber = {(float) maxMemories * 7, 0, (float) numbers.width / 9, (float) numbers.height};
    DrawTexturePro(numbers, secondNumber, Rectangle{355, 8, (float) numbers.width / 9, (float) numbers.height}, {}, 0,
                   WHITE);

    // Dialogue
    if (dialogueManager.open) {
        dialogueManager.drawDialogueBox(dialogueManager.dialogue);
        dialogueManager.drawContinousText("assets/textFiles/testFile.txt");
    }
}

void Game::GameScreen::drawMenu() {
    framesCounter++;
    if (framesCounter >= (60 / framesSpeed)) {

        framesCounter = 0;
        if (delay == 0) currentFrame++;

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

void Game::GameScreen::drawHub() {
    DrawTexturePro(hub, Rectangle{0, 0, (float) hub.width, (float) hub.height},
                   Rectangle{0, 0, (float) hub.width, (float) hub.height},
                   {}, 0, WHITE);
    //draw other objects
    //draw player
    if (player.getPos().x < npc.getPos().x && npc.frameRecNPC.width > 0) {
        npc.frameRecNPC.width *= -1;
    } else if (player.getPos().x >= npc.getPos().x && npc.frameRecNPC.width < 0) {
        npc.frameRecNPC.width *= -1;
    }
    if (player.getPos().y < npc.getPos().y + 12) {
        player.drawPlayerHub();
        npc.drawNPC();
    } else {
        npc.drawNPC();
        player.drawPlayerHub();
    }

    for (auto &furnitureTexture: furnitureTextures) {
        if (CheckCollisionRecs(player.getCollRec(), furnitureTexture)) {
            DrawTexturePro(hubFurniture, furnitureTexture, furnitureTexture, {}, 0, WHITE);
        }
    }

    if (CheckCollisionRecs(player.getCollRec(), galleryInterac) && !bookAnim) {
        DrawTexturePro(bookOutline,
                       Rectangle{8.0f, 10.0f, (float) bookOutline.width - 16, (float) bookOutline.height - 21},
                       Rectangle{240.0f, 144.0f, (float) bookOutline.width - 16, (float) bookOutline.height - 21}, {},
                       0, WHITE);
        DrawTexturePro(galleryInteractionText, Rectangle{0.0f, 0.0f, (float) galleryInteractionText.width,
                                                         (float) galleryInteractionText.height},
                       Rectangle{player.getPos().x - 57, player.getPos().y - 23, (float) galleryInteractionText.width,
                                 (float) galleryInteractionText.height}, {}, 0, WHITE);
    }

    if (CheckCollisionRecs(player.getCollRec(), interacCollision[1]) ||
        CheckCollisionRecs(player.getCollRec(), interacCollision[2]) ||
        CheckCollisionRecs(player.getCollRec(), interacCollision[3])) {
        DrawTexturePro(galleryInteractionText, Rectangle{0.0f, 0.0f, 42, (float) galleryInteractionText.height},
                       Rectangle{player.getPos().x - 9, player.getPos().y - 23, 42,
                                 (float) galleryInteractionText.height}, {}, 0, WHITE);
    }

    if (bookAnim) {
        DrawTexturePro(bookAnimation, bookFrameRec,
                       Rectangle{213, 133, bookFrameRec.width, bookFrameRec.height},
                       {}, 0, WHITE);
        framesCounter++;
        if (framesCounter >= (60 / framesSpeed)) {

            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 6) {
                currentFrame = 0;
                bookAnim = false;
                bookAnimDone = true;
            }

            bookFrameRec.x = (float) currentFrame * (float) bookAnimation.width / 7;
        }
    }

    if (CheckCollisionRecs(player.getCollRec(), npc.interactionBoxNPC) && !player.compassCollected) {
        DrawTexturePro(galleryInteractionText, Rectangle{0.0f, 0.0f, 42, (float) galleryInteractionText.height},
                       Rectangle{player.getPos().x - 9, player.getPos().y - 23, 42,
                                 (float) galleryInteractionText.height}, {}, 0, WHITE);
    }

    /*
    for (auto &furniture: furnitureCollision) {
        DrawRectangleRec(furniture, MAGENTA);
    }*/
}

void Game::GameScreen::hubPlayerInteractions() {
    player.updatePlayer();
    hubCanPlayerMove();
    if (player.canMove && !bookAnim) {
        player.hubMove();
    } else {
        if (IsKeyPressed(KEY_A) && player.r0l1 != 1) {
            player.hubIdleLeft = player.idleLeftSitting;
            player.idleFrame = 0;
            player.r0l1 = 1;
        } else if (IsKeyPressed(KEY_D) && player.r0l1 != 0) {
            player.hubIdleRight = player.idleRightSitting;
            player.idleFrame = 0;
            player.r0l1 = 0;
        }
        player.moving = false;
    }

    if (CheckCollisionRecs(player.getCollRec(), interacCollision[0]) && !bookAnim) {  // Gallery
        if (IsKeyPressed(KEY_E)) {
            currentFrame = 0;
            framesCounter = 0;
            bookAnim = true;
            wasInHub = true;
        }
    } else if (CheckCollisionRecs(player.getCollRec(), interacCollision[1])) { // Level 1
        if (IsKeyPressed(KEY_E)) {
            roomCounter = 0;
            display = 1;
            hotbarDataLoaded = false;
            generateMap();
            currentFrame = 0;
        }
    }  /*else if(CheckCollisionRecs(player.getCollRec(), interacCollision[2])) { // Level 2
        roomCounter = 0;
        display = 1;
        hotbarDataLoaded = false;
        generateMap();
        currentFrame = 0;
    } else if(CheckCollisionRecs(player.getCollRec(), interacCollision[3])) { // Level 3
        roomCounter = 0;
        display = 1;
        hotbarDataLoaded = false;
        generateMap();
        currentFrame = 0;
    }*/

    if (bookAnimDone) {
        display = 3;
        drawGallery();
        currentFrame = 0;
        galCounter = 0;
        bookAnimDone = false;
    }

    if (CheckCollisionRecs(player.getCollRec(), npc.interactionBoxNPC)) {  // Gallery
        if (IsKeyPressed(KEY_E) && !player.compassCollected) {
            player.compassCollected = true;
            npc.currentFrame = 0;
            npc.frameCounter = 0;
            npc.compassGiven = true;
        }
    }

    if (player.moving) player.hubMoveAnimation();
    else player.hubIdleAnimation();

}

void Game::GameScreen::hubCanPlayerMove() {
    // Checkt Collision & Hub boundaries, und gibt wieder ob der  Spieler sich bewegen darf
    if (player.getAdjRec().x >= -2 && player.getAdjRec().x <= 458 && player.getAdjRec().y >= 84 &&
        player.getAdjRec().y <= 247) {
        player.canMove = true;
        if (CheckCollisionRecs(player.getAdjRec(), npc.getCollRec())) {
            player.canMove = false;
        }
        for (auto &f: furnitureCollision) {
            if (CheckCollisionRecs(player.getAdjRec(), f)) {
                player.canMove = false;
                break;
            }
        }
    } else {
        player.canMove = false;
    }
}

void Game::GameScreen::initializeHubElements() {
    // spawn the Rectangles for collision & interactions
    // InitPlayer(SpawnPointX, SpawnPointY); festgelegt auf iwas?
    InitPlayer(120, 135);
    npc.initialiseNPC(320, 135, 0);

    // Das sind die Bereiche der Textur, die über dem Spieler gezeichnet werden.
    texPlantTop = {0.0f, 72.0f, 30.0f, 70.0f};
    texChairLamp = {0.0f, 146.0f, 82.0f, 73.0f};
    texTable = {190.0f, 141.0f, 81.0f, 19.0f};
    texBox = {405.0f, 213.0f, 31.0f, 10.0f};
    texCatTree = {403.0f, 106.0f, 77.0f, 77.0f};
    texTable2 = {437.0f,181.0f,43.0f,17.0f};
    texPlant2 = {442.0,149.0f,37.0f,34.0f};
    //Rectangle texTable2; //if necessary
    //Rectangle texShelf; // If secret room is desired
    furnitureTextures = {texPlantTop, texChairLamp, texTable, texBox, texCatTree, texTable2, texPlant2};

    //Das sind die Hitboxen, wo der Spieler nicht hindarf.
    // @Nicole. du kannst mit den Werten was rumspielen um zu gucken was gut aussieht. Mit der Seite https://pixspy.com/ kannste gucken welche koordinate die ixel haben wenn dus brauchst.
    tableBook = {191.0f, 160.0f, 80.0f, 27.0f}; // mostly fixed
    chair1 = {27.0f, 187.0f, 54.0f, 24.0f}; // not yet fixed
    lamp = {21.0f, 201.0f, 4.0f, 14.0f}; // not yet fixed
    chair2 = {0.0f,219.0f,21.0f,1.0f};
    plant = {0.0f,142.0f,22.0f,30.0f};
    table2 = {438.0f,194.0f,43.0f,48.0f};
    box = {407.0f, 220.0f, 31.0f, 0.0f};
    clock = {5.0f,95.0f,32.0f,0.0f};
    shelf = {431.0f,98.0f,50.0f,0.0f};
    catTree = {437.0f,181.0f,4.0f,3.0f};
    furnitureCollision = {tableBook, chair1, lamp, chair2, plant, table2, box, clock, shelf, catTree};

    //Interaction Collisionboxes
    galleryInterac = {185.0f, 145.0f, 90.0f, 55.0f};
    doorInterac1 = {73.0f, 90.0f, 21.0f, 10.0f};
    doorInterac2 = {289.0f, 90.0f, 21.0f, 10.0f};
    doorInterac3 = {385.0f, 90.0f, 21.0f, 10.0f};
    interacCollision = {galleryInterac, doorInterac1, doorInterac2, doorInterac3};
}

void Game::GameScreen::drawStartScreen() {
    // CURRENTLY UNUSED, TEXTURE DOESN'T SEEM TO BE WORKING?
    framesCounter++;
    if (framesCounter >= (50 / framesSpeed)) {

        framesCounter = 0;
        currentFrame++;

        if (currentFrame > 59) currentFrame = 0;

        startScreenRec.x = (currentFrame / 6) * (float) startScreen.width / 10;
        startScreenRec.y = (currentFrame % 6) * (float) startScreen.height / 6;
    }
    DrawTexturePro(startScreen, startScreenRec,
                   Rectangle{0, 0, startScreenRec.width, startScreenRec.height},
                   {}, 0, WHITE);
}

void Game::GameScreen::drawGameOver() {

    framesCounter++;
    if (framesCounter >= (60 / framesSpeed)) {

        framesCounter = 0;
        backgroundDelay++;

        if (backgroundDelay == 2) {
            currentFrame++;
            backgroundDelay = 0;
        }

        if (currentFrame > 10) currentFrame = 0;

        backgroundFrame.x = (float) currentFrame * (float) background.width / 11;

        GameOverFrame.x = (float) currentFrame * (float) GameOver.width / 2;
    }


    DrawTexturePro(background, backgroundFrame,
                   Rectangle{0, 0, backgroundFrame.width, backgroundFrame.height},
                   {}, 0, WHITE);
    DrawTexturePro(GameOver, GameOverFrame,
                   Rectangle{0, 0, GameOverFrame.width, GameOverFrame.height},
                   {}, 0, WHITE);
}

void Game::GameScreen::drawGallery() {
    switch (galCounter) {
        case 0:
            DrawTexturePro(CoreMem1, Mem1Frame, Rectangle{0, 0, (float) CoreMem1.width, (float) CoreMem1.height},
                           {}, 0, WHITE);
            framesCounter++;
            if (framesCounter >= (60 / framesSpeed)) {

                framesCounter = 0;
                currentFrame++;

                if (currentFrame > 34 && CoreMemory1) {
                    currentFrame = 35;
                } else if (currentFrame > 23 && !CoreMemory1) {
                    currentFrame = 24;
                }

                Mem1Frame.x = (float) currentFrame * (float) CoreMem1.width / 36;
            }
            break;
        case 1:
            DrawTexturePro(CoreMem2, Mem2Frame, Rectangle{0, 0, (float) CoreMem2.width, (float) CoreMem2.height},
                           {}, 0, WHITE);
            framesCounter++;
            if (framesCounter >= (60 / framesSpeed)) {

                framesCounter = 0;
                currentFrame++;

                if (currentFrame > 34 && CoreMemory2) {
                    currentFrame = 35;// there are 6 rows in this spritesheet
                } else if (currentFrame > 23 && !CoreMemory2) {
                    currentFrame = 24;
                }
                Mem2Frame.x =
                        (float) (currentFrame % 6) * (float) CoreMem2.width / 6; // there are 6 rows in this spritesheet
                Mem2Frame.y = (float) (currentFrame / 6) * (float) CoreMem2.height / 6;
            }
            break;
        case 2:
            DrawTexturePro(CoreMem3, Mem3Frame, Rectangle{0, 0, (float) CoreMem3.width, (float) CoreMem3.height},
                           {}, 0, WHITE);
            framesCounter++;
            if (framesCounter >= (60 / framesSpeed)) {

                framesCounter = 0;
                currentFrame++;

                if (currentFrame > 34 && CoreMemory3) {
                    currentFrame = 35;
                } else if (currentFrame > 23 && !CoreMemory3) {
                    currentFrame = 24;
                }
                Mem3Frame.x = (float) currentFrame * (float) CoreMem3.width / 36;

            }
            break;
    }
}

void Game::GameScreen::GameOverControls() {
    if (IsKeyPressed(KEY_ESCAPE)) { //Return to menu
        display = 0;
    }
    if (IsKeyPressed(KEY_R)) { //Restart the level
        clearLevel();
        generateMap();
        hotbarDataLoaded = false;
        display = 1;
    }
}

void Game::GameScreen::galControls() {
    if ((IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) && galCounter > 0) {
        galCounter--;
        currentFrame = 0;
    }
    if ((IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) && galCounter < 2) {
        galCounter++;
        currentFrame = 0;
    }
}

void Game::GameScreen::menuControls() {
    if ((IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) && (counter < menuButtons.size() - 1)) {
        counter++;
    } else if ((IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) && (counter > 0)) {
        counter--;
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

void Game::GameScreen::playMusicAndSounds() {
    // Title Music
    if (menuLoaded) {
        if (!IsSoundPlaying(titleTrack)) PlaySound(titleTrack);
    } else {
        StopSound(titleTrack);
    }
    switch (display) {
        case (0):
            // additional Menu Music/Sounds
            break;
        case (1):
            // Level Music  and Sounds
            break;
        case (2):
            // Hub Music and Sounds
            break;
        case (3):
            // Gallery Music and Sounds
            break;
        case (4):
            // GameOver Music and Sounds
            break;
        case (10):
            // additional StartScreen Music/Sounds
            break;
        case (11):
            // additional Cutscene Music/Sounds
            break;
    }
}

void Game::GameScreen::ProcessInput() {
    if (IsKeyPressed(KEY_ENTER) && display == 0) { //switch to level
        if (counter == 0) {
            display = 1;
            hotbarDataLoaded = false;
            generateMap();
            currentFrame = 0;
        }
        if (counter == 1) {
            display = 3;
            drawGallery();
            currentFrame = 0;
            galCounter = 0;
        }
        if (counter == 2) {
            CloseWindow();
        }
    } else {
        if (IsKeyPressed(KEY_ENTER) && display == 10) {
            cutsceneManager.drawCutscene(0);
            display = 11;
            nextDisplay = 0;
            delay = 1;
            currentFrame = 0;
        }
    }
    if (IsKeyPressed(KEY_ESCAPE) && !wasInHub) { //switch to menu
        if (!furnitureTextures.empty() && !furnitureCollision.empty() &&
            !interacCollision.empty()) { // Wenn man vom Hub weggeht
            furnitureCollision.clear();
            furnitureTextures.clear();
            interacCollision.clear();
        }
        display = 0;
        delay = 1;
        currentFrame = 0;
        bookAnimDone = false;
    } else if (IsKeyPressed(KEY_ESCAPE) && wasInHub) {
        display = 2;
        initializeHubElements();
        roomCounter = 0;
        wasInHub = false;
    }
    if (IsKeyPressed(KEY_H)) {
        display = 2;
        initializeHubElements();
        roomCounter = 0;
    }
    if (display == 1) {
        if (!dialogueManager.open && (IsKeyPressed(KEY_ONE) || IsKeyPressed(KEY_TWO) || IsKeyPressed(KEY_THREE))) {
            if (IsKeyPressed(KEY_ONE)) {
                dialogueManager.dialogue = 0;
            } else if (IsKeyPressed(KEY_TWO)) {
                dialogueManager.dialogue = 1;
            } else if (IsKeyPressed(KEY_THREE)) {
                dialogueManager.dialogue = 2;
            }
            dialogueManager.open = true;
        } else if (dialogueManager.open) {
            if (!dialogueManager.dialogueDone) {
                if (IsKeyPressed(KEY_ENTER)) {
                    dialogueManager.dialogueSkip();
                }
            } else {
                if (IsKeyPressed(KEY_ENTER)) {
                    dialogueManager.resetState();
                }
            }
        }
    }
}

void Game::GameScreen::Update() {
    // Game code here. Interactions etc.
    ProcessInput();
    playMusicAndSounds();
    if (display == 0) { // menu
        menuControls();
    } else if (display == 1) { // level
        finalDirtTexture();
        playerInteractions();
        boulderFall();
        canMortalMove();
        canImmortalMove();
        RiegelPush();
        if (!player.active) {
            display = 4;
        }
    } else if (display == 2) { // hub
        hubPlayerInteractions();
    } else if (display == 3) { //gallery
        galControls();
    } else if (display == 4) { //Game Over Screen
        GameOverControls();
        if (!player.active) {
            generateMap();
            player.lives = 3;
            player.active = true;
        }
    } else if(display != 2|| display != 3) {
        wasInHub = false;
    }
    if (IsKeyPressed(KEY_I)) {
        clearLevel();
    }
}

void Game::GameScreen::Draw() {
    switch (display) {
        case (0):
            if (!menuLoaded) {
                LoadMenuTextures();
            }
            if (levelLoaded) DeloadLevelTextures();
            if (hubLoaded) DeloadHubTextures();
            if (galleryLoaded) DeloadGalleryTextures();
            drawMenu();
            break;
        case (1):
            if (menuLoaded) DeloadMenuTextures();
            if (hubLoaded) DeloadHubTextures();
            if (galleryLoaded) DeloadGalleryTextures();
            drawLevel();
            break;
        case (2):
            if (!hubLoaded) {
                LoadHubTextures();
            }
            if (levelLoaded) DeloadLevelTextures();
            if (menuLoaded) DeloadMenuTextures();
            if (galleryLoaded) DeloadGalleryTextures();
            drawHub();
            if (player.compassCollected) {
                drawCompass();
            }
            break;
        case (3):
            if (!galleryLoaded) {
                LoadGalleryTextures();
            }
            if (levelLoaded) DeloadLevelTextures();
            if (hubLoaded) DeloadHubTextures();
            if (menuLoaded) DeloadMenuTextures();
            drawGallery();
            break;
        case (4):
            if (!levelLoaded) {
                LoadLevelTextures();
            }
            if (menuLoaded) DeloadMenuTextures();
            if (hubLoaded) DeloadHubTextures();
            if (galleryLoaded) DeloadGalleryTextures();
            drawGameOver();
            break;
        case (10): //unused rn, problems with texture
            if (!menuLoaded) {
                LoadMenuTextures();
            }
            if (levelLoaded) DeloadLevelTextures();
            if (hubLoaded) DeloadHubTextures();
            if (galleryLoaded) DeloadGalleryTextures();
            drawStartScreen();
            break;
        case (11):
            cutsceneManager.drawCutscene(cutsceneNumber);
            if (cutsceneManager.cutsceneDone) {
                display = nextDisplay;
                cutsceneManager.cutsceneDone = false;
            }
            break;
    }
}

Game::GameScreen::~GameScreen() {
    //unload all textures?
    //delete all objects?
    //UnloadTexture(player.getTexture());
    for (auto music: musicTracks) {
        UnloadSound(music);
    }
    for (auto sound: sounds) {
        UnloadSound(sound);
    }
    CloseAudioDevice();
}
