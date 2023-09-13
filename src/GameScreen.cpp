#include <iostream>
#include "raylib.h"
#include "LevelData.h"
#include "GameScreen.h"

Game::GameScreen::GameScreen() {
    readLevelData();
    LoadMenuTextures();
    InitAudioDevice();
    titleTrack = LoadSound("assets/audio/tracks/Titel-Track-WAV.wav");
    inGameTrack = LoadSound("assets/audio/tracks/Ingamemusic.wav");
    intro = LoadSound("assets/audio/tracks/Intro2.wav");
    musicTracks = {titleTrack, inGameTrack, intro};
    hover = LoadSound("assets/audio/sfx/hover.wav");
    select = LoadSound("assets/audio/sfx/auswahl.wav");
    purr = LoadSound("assets/audio/sfx/purr_snorr.wav");
    catWalk = LoadSound("assets/audio/sfx/Footsteps2.wav");
    meow = LoadSound("assets/audio/sfx/Miau.wav");
    catLick = LoadSound("assets/audio/sfx/katze_lecken.wav");
    dig = LoadSound("assets/audio/sfx/Dig.wav");
    memoryGathered = LoadSound("assets/audio/sfx/memories_einsammeln.wav");
    SetSoundVolume(memoryGathered, 1.0f);
    movingBoulder = LoadSound("assets/audio/sfx/boulder_sound.wav");
    flame = LoadSound("assets/audio/sfx/flammen.wav");
    doorOpen = LoadSound("assets/audio/sfx/Tuer.wav");
    openGallery = LoadSound("assets/audio/sfx/open_gallery.wav");
    galleryFlip = LoadSound("assets/audio/sfx/gallery_blaettern.wav");
    galleryPaste = LoadSound("assets/audio/sfx/gallery_kleben.wav");
    sounds = {hover, select, purr,  catWalk, meow, catLick,  dig, memoryGathered, movingBoulder, flame, doorOpen, openGallery, galleryFlip, galleryPaste};
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
    exitH = LoadTexture("assets/graphics/Text/Exit_Game_Highlight.png");
    logoB = {Game::ScreenWidth / 3 - 20, Game::ScreenHeight / 9, logo};
    startB = {Game::ScreenWidth / 3 + 6, Game::ScreenHeight / 9 * 5, start};
    galleryB = {Game::ScreenWidth / 3, Game::ScreenHeight / 9 * 6, gallery};
    exitB = {Game::ScreenWidth / 3 - 1, Game::ScreenHeight / 9 * 7, exit};
    startContinue = LoadTexture("assets/graphics/Text/Press Space to continue.png");
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
    wall2 = LoadTexture("assets/graphics/Template/Wall_and_Door/walls and door NEW/Wall_New-0001.png");
    wall3 = LoadTexture("assets/graphics/Template/Wall_and_Door/walls and door NEW/Wall_New-0002.png");
    frameRec_Wall = {0.0f, 0.0f, (float) 24, 24};
    boulder_down = LoadTexture("assets/graphics/Animation/Sheets/Objects/Boulder/Boulder down-Sheet.png");
    boulder_up = LoadTexture("assets/graphics/Animation/Sheets/Objects/Boulder/Boulder up-Sheet.png");
    boulder_left = LoadTexture("assets/graphics/Animation/Sheets/Objects/Boulder/Boulder-left-Sheet.png");
    boulder_right = LoadTexture("assets/graphics/Animation/Sheets/Objects/Boulder/Boulder right-Sheet.png");
    frameRec_Boulder = {0.0f, 0.0f, (float) boulder_down.width / 5, (float) boulder_down.height};
    riegelW = LoadTexture("assets/graphics/Template/Bar/New/horizontal.png");
    riegelS = LoadTexture("assets/graphics/Template/Bar/New/vertical.png");
    frameRec_Riegel = {0.0f, 0.0f, (float) 24, 24};
    door = LoadTexture("assets/graphics/Animation/Sheets/Objects/Door animation new.png");
    frameRec_Door = {0.0f, 0.0f, (float) door.width / 3, (float) door.height};

    texMortalDeath = LoadTexture("assets/graphics/Animation/Sheets/Enemies/Enemy_1_(Destructible)/Defeated_Animation-Sheet.png");
    texMortalIdle = LoadTexture("assets/graphics/Animation/Sheets/Enemies/Enemy_1_(Destructible)/Idle_animation-Sheet.png");
    texMortalUp = LoadTexture("assets/graphics/Animation/Sheets/Enemies/Enemy_1_(Destructible)/Movement_back-Sheet.png");
    texMortalLeft = LoadTexture("assets/graphics/Animation/Sheets/Enemies/Enemy_1_(Destructible)/Movement_left-Sheet.png");
    texMortalDown = LoadTexture("assets/graphics/Animation/Sheets/Enemies/Enemy_1_(Destructible)/Movement_front-Sheet.png");
    texMortalRight = LoadTexture("assets/graphics/Animation/Sheets/Enemies/Enemy_1_(Destructible)/Movement_right-Sheet.png");
    recMortalDeath = {0, 0, (float) texMortalDeath.width / 6, (float) texMortalDeath.height};
    recMortalIdle = {0, 0, (float) texMortalIdle.width / 9, (float) texMortalIdle.height};
    recMortalUp = {0, 0, (float) texMortalUp.width / 9, (float) texMortalUp.height};
    recMortalLeft = {0, 0, (float) texMortalLeft.width / 9, (float) texMortalLeft.height};
    recMortalDown = {0, 0, (float) texMortalDown.width / 9, (float) texMortalDown.height};
    recMortalRight = {0, 0, (float) texMortalRight.width / 9, (float) texMortalRight.height};
    texImmortalIdle = LoadTexture("assets/graphics/Animation/Sheets/Enemies/Enemy_2_(Indestructible)/Purple (Final)/Idle_Animation-Sheet.png");
    texImmortalUp = LoadTexture("assets/graphics/Animation/Sheets/Enemies/Enemy_2_(Indestructible)/Purple (Final)/Movement_back-Sheet.png");
    texImmortalLeft = LoadTexture("assets/graphics/Animation/Sheets/Enemies/Enemy_2_(Indestructible)/Purple (Final)/Movement_left-Sheet.png");
    texImmortalDown = LoadTexture("assets/graphics/Animation/Sheets/Enemies/Enemy_2_(Indestructible)/Purple (Final)/Movement_front-Sheet.png");
    texImmortalRight = LoadTexture("assets/graphics/Animation/Sheets/Enemies/Enemy_2_(Indestructible)/Purple (Final)/Movement_right-Sheet.png");
    recImmortalIdle = {0, 0, (float) texImmortalIdle.width / 9, (float) texImmortalIdle.height};
    recImmortalUp = {0, 0, (float) texImmortalUp.width / 9, (float) texImmortalUp.height};
    recImmortalLeft = {0, 0, (float) texImmortalLeft.width / 9, (float) texImmortalLeft.height};
    recImmortalDown = {0, 0, (float) texImmortalDown.width / 9, (float) texImmortalDown.height};
    recImmortalRight = {0, 0, (float) texImmortalRight.width / 9, (float) texImmortalRight.height};

    openDoor = LoadTexture("assets/graphics/Template/Wall_and_Door/walls and door NEW/Door_Open.png");
    compass = LoadTexture("assets/graphics/Animation/Sheets/Objects/Compass_received-Sheet.png");
    compassRec = {0, 0, 28, 28};
    GameOver = LoadTexture("assets/graphics/Animation/Sheets/Screens/GameOver_Screen-Sheet.png");
    GameOverFrame = {0.0f, 0.0f, (float) GameOver.width / 2, (float) GameOver.height};
    restart = LoadTexture("assets/graphics/Text/Restart_Game.png");
    restartHighlighted = LoadTexture("assets/graphics/Text/Restart_Game_Highlight.png");
    returnMenu = LoadTexture("assets/graphics/Text/Menu.png");
    returnMenuHighlighted = LoadTexture("assets/graphics/Text/Menu_Highlight.png");
    goRestartB.setTexture(restartHighlighted);
    goMenuB.setTexture(returnMenu);
    hotbar = LoadTexture("assets/graphics/Other/Hotbar/Hotbar.png");
    numbers = LoadTexture("assets/graphics/Other/Hotbar/Collectibles/Numbers.png");
    texResumeB = LoadTexture("assets/graphics/Text/Resume.png");
    texGalleryB = LoadTexture("assets/graphics/Text/Gallery.png");
    texMenuB = LoadTexture("assets/graphics/Text/Menu.png");
    texResumeHighlightB = LoadTexture("assets/graphics/Text/Resume_Highlight.png");
    texGalleryHighlightB = LoadTexture("assets/graphics/Text/Gallery - Highlight.png");
    texMenuHighlightB = LoadTexture("assets/graphics/Text/Menu_Highlight.png");
    pauseScreen = LoadTexture("assets/graphics/Animation/Sheets/Screens/Ingame_menu-Sheet.png");
    pauseScreenRec = {0, 0, (float) pauseScreen.width / 52, (float) pauseScreen.height};
    pResumeB.setTexture(texResumeB);
    pGalleryB.setTexture(texGalleryB);
    pMenuB.setTexture(texMenuB);
    levelLoaded = true;
}

void Game::GameScreen::LoadHubTextures() {
    hub = LoadTexture("assets/graphics/Background/HUB/hub1.png");
    hubFurniture = LoadTexture("assets/graphics/Background/HUB/hub_moebel_2.png");
    galleryInteractionText = LoadTexture("assets/graphics/Background/HUB/Gallery Book/Book text.png");
    bookOutline = LoadTexture("assets/graphics/Background/HUB/Gallery Book/Book_outline.png");
    bookAnimation = LoadTexture("assets/graphics/Background/HUB/Gallery Book/Book_animation.png");
    bookFrameRec = {0.0f, 0.0f, (float) bookAnimation.width / 7, (float) bookAnimation.height};
    restart = LoadTexture("assets/graphics/Text/Restart_Game.png");
    restartHighlighted = LoadTexture("assets/graphics/Text/Restart_Game_Highlight.png");
    returnMenu = LoadTexture("assets/graphics/Text/Menu.png");
    returnMenuHighlighted = LoadTexture("assets/graphics/Text/Menu_Highlight.png");
    texHubDoorAnim = LoadTexture("assets/graphics/Background/HUB/animations/door_opening animation_2.png");
    hubDoorAnimRec = {0.0f, 0.0f, (float) texHubDoorAnim.width / 3, (float) texHubDoorAnim.height};
    if (!level2Unlocked) texLevel2Locked = LoadTexture("assets/graphics/Background/HUB/assets/Level2_off.png");
    if (!level3Unlocked) texLevel3Locked = LoadTexture("assets/graphics/Background/HUB/assets/Level3_off.png");
    if (!level2Unlocked || !level3Unlocked)
        texHubDoorClosed = LoadTexture("assets/graphics/Background/HUB/assets/locked_door.png");
    hubLoaded = true;
}

void Game::GameScreen::LoadGalleryTextures() {
    //Forward flipping
    //Memory 1
    CoreMem1Unl = LoadTexture("assets/graphics/Animation/Sheets/Gallery/Book_opening/Gallery_opening_book_memory1.png");
    Mem1FrameUnl = {0.0f, 0.0f, (float) CoreMem1Unl.width, (float) CoreMem1Unl.height};
    CoreMem1L = LoadTexture("assets/graphics/Animation/Sheets/Gallery/Book_opening/Gallery_opening_book.png");
    Mem1FrameL = {0.0f, 0.0f, (float) CoreMem1L.width, (float) CoreMem1L.height};
    //Memory 2
    CoreMem2Unl = LoadTexture(
            "assets/graphics/Animation/Sheets/Gallery/Pageturn/Forward/Pageturn_forward_memory1+memory2.png");
    Mem2FrameUnl = {0.0f, 0.0f, (float) CoreMem2Unl.width, (float) CoreMem2Unl.height};
    CoreMem2L = LoadTexture(
            "assets/graphics/Animation/Sheets/Gallery/Pageturn/Forward/Pageturn_forward_memory1+blank.png");
    Mem2FrameL = {0.0f, 0.0f, (float) CoreMem2L.width, (float) CoreMem2L.height};
    //Memory 3
    CoreMem3Unl = LoadTexture(
            "assets/graphics/Animation/Sheets/Gallery/Pageturn/Forward/Pageturn_forward_memory2+memory3.png");
    Mem3FrameUnl = {0.0f, 0.0f, (float) CoreMem3Unl.width, (float) CoreMem3Unl.height};
    CoreMem3L = LoadTexture(
            "assets/graphics/Animation/Sheets/Gallery/Pageturn/Forward/Pageturn_forward_memory2+blank.png");
    Mem3FrameL = {0.0f, 0.0f, (float) CoreMem3L.width, (float) CoreMem3L.height};
    //blank page
    blank = LoadTexture("assets/graphics/Animation/Sheets/Gallery/Pageturn/Forward/Pageturn_forward_blank.png");
    blankFrame = {0.0f, 0.0f, (float) blank.width, (float) blank.height};

    //backward flipping
    //Memory 1
    b_CoreMem1Unl = LoadTexture(
            "assets/graphics/Animation/Sheets/Gallery/Pageturn/Backward/Pageturn_backward_memory2+memory1.png");
    b_Mem1FrameUnl = {0.0f, 0.0f, (float) b_CoreMem1Unl.width, (float) b_CoreMem1Unl.height};
    //if memory 1 is locked, all memories are locked -> blank

    //Memory 2
    b_CoreMem2Unl = LoadTexture(
            "assets/graphics/Animation/Sheets/Gallery/Pageturn/Backward/Pageturn_backward_memory3+memory2.png");
    b_Mem2FrameUnl = {0.0f, 0.0f, (float) b_CoreMem2Unl.width, (float) b_CoreMem2Unl.height};

    //Memory 1 but not 2
    b_CoreMem1No2 = LoadTexture(
            "assets/graphics/Animation/Sheets/Gallery/Pageturn/Backward/Pageturn_backward_blank+memory1.png");
    b_Mem1No2Frame = {0.0f, 0.0f, (float) b_CoreMem1No2.width, (float) b_CoreMem1No2.height};

    //Memory 2 but not 3
    b_CoreMem2No3 = LoadTexture(
            "assets/graphics/Animation/Sheets/Gallery/Pageturn/Backward/Pageturn_backward_blank+memory2.png");
    b_Mem2No3Frame = {0.0f, 0.0f, (float) b_CoreMem2No3.width, (float) b_CoreMem2No3.height};

    //blank page
    b_blank = LoadTexture(
            "assets/graphics/Animation/Sheets/Gallery/Pageturn/Backward/Pageturn_backward_blank.png"); // all memories locked
    b_blankFrame = {0.0f, 0.0f, (float) b_blank.width, (float) b_blank.height};
    galleryLoaded = true;
}

void Game::GameScreen::LoadRoomTextures() {
    compass = LoadTexture("assets/graphics/Animation/Sheets/Objects/Compass_received-Sheet.png");
    compassRec = {0, 0, 28, 28};
    galleryInteractionText = LoadTexture("assets/graphics/Background/HUB/Gallery Book/Book text.png");
    texHubDoorClosed = LoadTexture("assets/graphics/Background/HUB/assets/locked_door_2.png");
    texHubDoorAnim = LoadTexture("assets/graphics/Background/HUB/animations/door_opening animation_2.png");
    hubDoorAnimRec = {0.0f, 0.0f, (float) texHubDoorAnim.width / 3, (float) texHubDoorAnim.height};
    switch (preRoomCounter) {
        case 0: // Grandma
            npcAge = 0;
            grandmaFurniture = LoadTexture("assets/graphics/Background/HUB/gma_raum_moebel.png");
            if (!tutorialUnlocked) {
                texTutorialLocked = LoadTexture("assets/graphics/Background/HUB/assets/Tutorial_off.png");
            }
            if (!level1Unlocked) texLevel1Locked = LoadTexture("assets/graphics/Background/HUB/assets/Level1_off.png");
            roomTexture = LoadTexture("assets/graphics/Background/HUB/raum1.png");
            break;
        case 1: // Adult
            npcAge = 1;
            roomTexture = LoadTexture("assets/graphics/Background/HUB/raum2.png");
            break;
        case 2: // Teen
            npcAge = 2;
            roomTexture = LoadTexture("assets/graphics/Background/HUB/raum 3.png");
            break;
    }
    preRoomLoaded = true;
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
    UnloadTexture(startContinue);
    menuLoaded = false;
}

void Game::GameScreen::DeloadLevelTextures() {
    UnloadTexture(background);
    UnloadTexture(dirtVanishAnim);
    UnloadTexture(dirtT);
    UnloadTexture(memories);
    UnloadTexture(wall2);
    UnloadTexture(wall3);
    UnloadTexture(boulder_up);
    UnloadTexture(boulder_down);
    UnloadTexture(boulder_left);
    UnloadTexture(boulder_right);
    UnloadTexture(riegelW);
    UnloadTexture(riegelS);
    UnloadTexture(door);
    UnloadTexture(openDoor);
    UnloadTexture(texMortalDeath);
    UnloadTexture(texMortalIdle);
    UnloadTexture(texMortalUp);
    UnloadTexture(texMortalLeft);
    UnloadTexture(texMortalDown);
    UnloadTexture(texMortalRight);
    UnloadTexture(texImmortalIdle);
    UnloadTexture(texImmortalUp);
    UnloadTexture(texImmortalLeft);
    UnloadTexture(texImmortalDown);
    UnloadTexture(texImmortalRight);
    UnloadTexture(compass);
    UnloadTexture(GameOver);
    UnloadTexture(hotbar);
    UnloadTexture(numbers);
    UnloadTexture(texResumeB);
    UnloadTexture(texGalleryB);
    UnloadTexture(texMenuB);
    UnloadTexture(texResumeHighlightB);
    UnloadTexture(texGalleryHighlightB);
    UnloadTexture(texMenuHighlightB);
    UnloadTexture(pauseScreen);
    levelLoaded = false;
}

void Game::GameScreen::DeloadHubTextures() {
    UnloadTexture(hub);
    UnloadTexture(hubFurniture);
    UnloadTexture(galleryInteractionText);
    UnloadTexture(bookOutline);
    UnloadTexture(bookAnimation);
    UnloadTexture(texHubDoorAnim);
    if (IsTextureReady(texLevel2Locked)) UnloadTexture(texLevel2Locked);
    if (IsTextureReady(texLevel3Locked)) UnloadTexture(texLevel3Locked);
    if (IsTextureReady(texHubDoorClosed)) UnloadTexture(texHubDoorClosed);
    hubLoaded = false;
}

void Game::GameScreen::DeloadGalleryTextures() {
    UnloadTexture(CoreMem1Unl);
    UnloadTexture(CoreMem2Unl);
    UnloadTexture(CoreMem3Unl);
    galleryLoaded = false;
}

void Game::GameScreen::DeloadRoomTextures() {
    UnloadTexture(roomTexture);
    UnloadTexture(texHubDoorAnim);
    UnloadTexture(galleryInteractionText);
    if (IsTextureReady(grandmaFurniture)) UnloadTexture(grandmaFurniture);
    if (IsTextureReady(texTutorialLocked)) UnloadTexture(texTutorialLocked);
    if (IsTextureReady(texLevel1Locked)) UnloadTexture(texLevel1Locked);
    UnloadTexture(texHubDoorClosed);
    preRoomLoaded = false;
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
    std::vector<Game::Riegel> Vertical;
    std::vector<Game::Riegel> Horizontal;

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
        } else if (layout[i] == 21||layout[i] == 31 ||layout[i] == 32 ||layout[i] == 33) { //generate Riegel
            switch (layout[i]) {
                case 21:
                    Vertical.emplace_back(coordinates.x,coordinates.y,Vertical.back().Senkrecht);
                    Vertical.back().setTexture(riegelS);
                    if (layout[i+20] == 22 || layout[i+20] == 23) {
                        Vertical.back().size++;
                        if (layout[i+40] == 22 || layout[i+40] == 23) {
                            Vertical.back().size++;
                            if (layout[i+60] == 22 || layout[i+60] == 23) {
                                Vertical.back().size++;
                            }
                        }
                    }
                    break;
                case 31:
                    Horizontal.emplace_back(coordinates.x,coordinates.y,Horizontal.back().Waagerecht);
                    Horizontal.back().setTexture(riegelW);
                    break;
                case 32:
                    Horizontal.back().size++;
                    break;
                case 33:
                    Horizontal.back().size++;
                    break;
            }
        } else if (layout[i] == 6) { //Generate Wall
            wallList.emplace_back(coordinates.x, coordinates.y);
            int randTexture = std::rand() % 2;
            if (randTexture == 0) {
                wallList.back().setTexture(wall3);
            } else {
                wallList.back().setTexture(wall2);
            }
        } else if (layout[i] == 7) { //Generate Door
            doorList.emplace_back(coordinates.x, coordinates.y, 1);
            doorList.back().setTexture(door);
            doorList.back().frameRec = frameRec_Door;
        } else if (layout[i] == 50) { //Generate Door
            doorList.emplace_back(coordinates.x, coordinates.y, 0);
            doorList.back().setTexture(openDoor);
        } else if (layout[i] == 15) { //Generate Mortal Enemy
            mortalList.emplace_back(coordinates.x, coordinates.y);
            mortalList.back().texDeath = texMortalDeath;
            mortalList.back().texIdle = texMortalIdle;
            mortalList.back().texUp = texMortalUp;
            mortalList.back().texLeft = texMortalLeft;
            mortalList.back().texDown = texMortalDown;
            mortalList.back().texRight = texMortalRight;
            mortalList.back().recDeath = recMortalDeath;
            mortalList.back().recIdle = recMortalIdle;
            mortalList.back().recUp = recMortalUp;
            mortalList.back().recLeft = recMortalLeft;
            mortalList.back().recDown = recMortalDown;
            mortalList.back().recRight = recMortalRight;
        } else if (layout[i] == 16) { //Generate Immortal Enemy
            immortalList.emplace_back(coordinates.x, coordinates.y);
            immortalList.back().texIdle = texImmortalIdle;
            immortalList.back().texUp = texImmortalUp;
            immortalList.back().texLeft = texImmortalLeft;
            immortalList.back().texDown = texImmortalDown;
            immortalList.back().texRight = texImmortalRight;
            immortalList.back().recIdle = recImmortalIdle;
            immortalList.back().recUp = recImmortalUp;
            immortalList.back().recLeft = recImmortalLeft;
            immortalList.back().recDown = recImmortalDown;
            immortalList.back().recRight = recImmortalRight;
        } else {}
    }
    //immortalList.emplace_back(192, 150);
    riegelList.insert(riegelList.end(), Vertical.begin(), Vertical.end());
    riegelList.insert(riegelList.end(), Horizontal.begin(), Horizontal.end());
    maxMemories = (int) memoryList.size();
    if (!boulderList.empty()) maxMemories += (int) (mortalList.size() * 2);
    if (!memoryList.empty() && !boulderList.empty()) maxMemories += (int) immortalList.size();
    if(roomCounter == 4) maxMemories = (int) memoryList.size();
    for(auto &r: riegelList) {
        r.ColUpdate();
    }
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
                    if (difference <= 2) {
                        player.lives = 0; //Spieler stirbt
                        hasBeenPlayed = false;
                    }
                } else if (i.direction == 2 || i.direction == 3) {
                    float difference = (player.getCollRec().x - i.getCollRec().x);
                    if (difference < 0) {
                        difference *= -1;
                    }
                    if (difference <= 2) {
                        player.lives = 0; //Spieler stirbt
                        hasBeenPlayed = false;
                    }
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
                        hasBeenPlayed = false;
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
                        hasBeenPlayed = false;
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
                    playMemorySound = true;
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
            if (CheckCollisionRecs(player.getCollRec(), d.getCollRec()) && collected == maxMemories) {
                if (player.getPos().x == d.getPos().x && player.getPos().y == d.getPos().y) {
                    if (d.active && d.type == 1) {
                        if (roomCounter == 2 || roomCounter == 5 || roomCounter == 8 ||
                            roomCounter == 11) { //switch to hub
                            if (roomCounter == 2) {
                                tutorialUnlocked = false;
                                level1Unlocked = true;
                                nextDisplay = 2;
                                cutsceneNumber = 4;
                                display = 11;

                                currentFrame = 0;
                                framesCounter = 0;
                                initializeHubElements();
                                roomCounter = 0;
                                levelDoorOpened = false;
                            } else if (roomCounter == 5) {
                                nextDisplay = 2;
                                cutsceneNumber = 2;
                                display = 11;
                                level2Unlocked = true;
                                currentFrame = 0;
                                framesCounter = 0;
                                initializeHubElements();
                                roomCounter = 0;
                                CoreMemory1 = true;
                                levelDoorOpened = false;
                            } else if (roomCounter == 8) {
                                nextDisplay = 2;
                                cutsceneNumber = 3;
                                display = 11;
                                level3Unlocked = true;
                                currentFrame = 0;
                                framesCounter = 0;
                                initializeHubElements();
                                roomCounter = 0;
                                CoreMemory2 = true;
                                levelDoorOpened = false;
                            } else if (roomCounter == 11) {
                                nextDisplay = 0;//mark
                                cutsceneNumber = 4;
                                display = 11;
                                currentFrame = 0;
                                framesCounter = 0;
                                initializeHubElements();
                                roomCounter = 0;
                                CoreMemory3 = true;
                                levelDoorOpened = false;
                            }
                        } else { // next level
                            nextDisplay = 1;
                            cutsceneNumber = 1;
                            display = 11;
                            roomCounter++;
                            hotbarDataLoaded = false;
                            generateMap();
                            levelDoorOpened = false;
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
                                playMemorySound = true;
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
                                                (collected != maxMemories || d.type == 0)) {
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
                                    (collected != maxMemories || d.type == 0)) {
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
                                    (collected != maxMemories || d.type == 0)) {
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
                            (collected != maxMemories || d.type == 0)) {
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

bool Game::GameScreen::canRiegelMove(Game::Riegel &riegel) {
    switch (riegel.directionR) {
        case 0:
            allGameObjects.insert(allGameObjects.end(), riegelList.begin(), riegelList.end());
            allGameObjects.insert(allGameObjects.end(), dirtList.begin(), dirtList.end());
            allGameObjects.insert(allGameObjects.end(), memoryList.begin(), memoryList.end());
            allGameObjects.insert(allGameObjects.end(), wallList.begin(), wallList.end());
            allGameObjects.insert(allGameObjects.end(), doorList.begin(), doorList.end());
            allGameObjects.push_back(player);
            allGameObjects.insert(allGameObjects.end(), boulderList.begin(), boulderList.end());
            allGameObjects.insert(allGameObjects.end(), mortalList.begin(), mortalList.end());
            allGameObjects.insert(allGameObjects.end(), immortalList.begin(), immortalList.end());
            for(int i = 0; i<riegelList.size(); i++) {
                if(&riegelList.at(i) == &riegel) {
                    allGameObjects.erase(allGameObjects.begin()+i);
                    break;
                }
            }
            for (auto &gO: allGameObjects) { // checks all static objects
                if (CheckCollisionRecs(riegel.adjDetection1, gO.getCollRec())) {
                    if (gO.active) {
                        // move the bar back to the previous pos
                        riegel.setPos(riegel.adjDetection1.x + 24, riegel.getPos().y);
                        allGameObjects.clear();
                        return false;
                    }
                }
                if (CheckCollisionRecs(riegel.adjDetection2, gO.getCollRec())) {
                    if (gO.active) {
                        // move the bar back to the previous pos
                        riegel.setPos(riegel.adjDetection2.x - (float) (24*riegel.size),  riegel.getPos().y);
                        allGameObjects.clear();
                        return false;
                    }
                }
            }
            break;
        case 1:
            allGameObjects.insert(allGameObjects.end(), riegelList.begin(), riegelList.end());
            allGameObjects.insert(allGameObjects.end(), dirtList.begin(), dirtList.end());
            allGameObjects.insert(allGameObjects.end(), memoryList.begin(), memoryList.end());
            allGameObjects.insert(allGameObjects.end(), wallList.begin(), wallList.end());
            allGameObjects.insert(allGameObjects.end(), doorList.begin(), doorList.end());
            allGameObjects.push_back(player);
            allGameObjects.insert(allGameObjects.end(), boulderList.begin(), boulderList.end());
            allGameObjects.insert(allGameObjects.end(), mortalList.begin(), mortalList.end());
            allGameObjects.insert(allGameObjects.end(), immortalList.begin(), immortalList.end());
            for(int i = 0; i<riegelList.size(); i++) {
                if(&riegelList.at(i) == &riegel) {
                    allGameObjects.erase(allGameObjects.begin()+i);
                    break;
                }
            }
            for (auto &gO: allGameObjects) { // checks all static objects
                if (CheckCollisionRecs(riegel.adjDetection1, gO.getCollRec())) {
                    if (gO.active) {
                        // move the bar back to the previous pos
                        riegel.setPos(riegel.getPos().x, riegel.adjDetection1.y + 24);
                        allGameObjects.clear();
                        return false;
                    }
                }
                if (CheckCollisionRecs(riegel.adjDetection2, gO.getCollRec())) {
                    if (gO.active) {
                        // move the bar back to the previous pos
                        riegel.setPos(riegel.getPos().x, riegel.adjDetection2.y - (float) (24*riegel.size));
                        allGameObjects.clear();
                        return false;
                    }
                }
            }
            break;
    }
    allGameObjects.clear();
    return true;
}

void Game::GameScreen::setRScale(float test) {
    this->rScale = test;
}

void Game::GameScreen::RiegelPush() {
//    canRiegelMove();
    for (auto &i: riegelList) {
        Vector2 mousePosition = GetMousePosition();

        mousePosition.x /= rScale;
        mousePosition.y /= rScale;
        if (CheckCollisionPointRec(mousePosition, i.getCollRec()) &&
            IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            i.originalX = (int) i.getPos().x;
            i.originalY = (int)i.getPos().y;
            i.selected = true;
        }
        if (CheckCollisionPointRec(mousePosition, i.getCollRec()) &&
            IsMouseButtonDown(MOUSE_LEFT_BUTTON) && i.selected) {
            i.renderScale = rScale;
            i.ColUpdate();
            if(canRiegelMove(i)) {
                i.move();
            } else i.selected = false;
        } else if (!CheckCollisionPointRec(mousePosition, i.getCollRec()) &&
                   IsMouseButtonDown(MOUSE_LEFT_BUTTON) && i.selected) {
            i.renderScale = rScale;
            i.pos.x = (float) i.originalX;
            i.pos.y = (float) i.originalY;
            i.ColUpdate();
        } else {
            i.renderScale = rScale;
            int xOne = (int) i.getPos().x;
            int xCor = (xOne / 24) * 24;
            if (xOne % 24 > 11) {
                xCor += 24;
            }
            i.pos.x = (float) xCor;
            int yOne = (int) i.getPos().y;
            int yCor = ((yOne - 30) / 24) * 24 + 30;
            if ((yOne - 30) % 24 > 11) {
                yCor += 24;
            }
            i.pos.y = (float) yCor;
            i.ColUpdate();
            i.selected = false;
        }
    }
}

void Game::GameScreen::boulderFall() {
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
                for (auto &d: doorList) { //CHECKT FÜR COLLISION BEI Doors, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.adjRectangle, d.getCollRec())) {
                        if (i.adjRectangle.y == d.getCollRec().y) {
                            canFall = false;
                        }
                    }
                }
                for (auto &r: riegelList) { //CHECKT FÜR COLLISION BEI Riegeln, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.adjRectangle, r.getCollRec())) {
                        if (i.adjRectangle.y == r.getCollRec().y) {
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
                            if (immortal.getCollRec().y - i.getCollRec().y <= 6) {
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
                for (auto &d: doorList) { //CHECKT FÜR COLLISION BEI Doors, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.adjRectangle, d.getCollRec())) {
                        if (i.adjRectangle.y == d.getCollRec().y) {
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
                for (auto &r: riegelList) { //CHECKT FÜR COLLISION BEI Riegeln, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.adjRectangle, r.getCollRec())) {
                        if(r.directionR == 1) {
                            if (i.adjRectangle.y == (r.getCollRec().y + ((float) r.size * 24 - 24))) {
                                canFall = false;
                            }
                        } else {
                            if (i.adjRectangle.y == r.getCollRec().y) {
                                canFall = false;
                            }
                        }
                    }
                }
                for (auto &immortal: immortalList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.adjRectangle, immortal.getCollRec())) {
                        if (immortal.active) {
                            if (i.getCollRec().y - immortal.getCollRec().y <= 6) {
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
                for (auto &d: doorList) { //CHECKT FÜR COLLISION BEI Doors, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.adjRectangle, d.getCollRec())) {
                        if (i.adjRectangle.x == d.getCollRec().x) {
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
                for (auto &r: riegelList) { //CHECKT FÜR COLLISION BEI Riegeln, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.adjRectangle, r.getCollRec())) {
                        if(r.directionR == 0) {
                            if (i.adjRectangle.x == (r.getCollRec().x + ((float) r.size * 24 - 24))) {
                                canFall = false;
                            }
                        } else {
                            if (i.adjRectangle.x == r.getCollRec().x) {
                                canFall = false;
                            }
                        }
                    }
                }
                for (auto &immortal: immortalList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.adjRectangle, immortal.getCollRec())) {
                        if (immortal.active) {
                            if (i.getCollRec().x - immortal.getCollRec().x <= 6) {
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
                for (auto &d: doorList) { //CHECKT FÜR COLLISION BEI Doors, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.adjRectangle, d.getCollRec())) {
                        if (i.adjRectangle.x == d.getCollRec().x) {
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
                for (auto &r: riegelList) { //CHECKT FÜR COLLISION BEI Riegeln, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.adjRectangle, r.getCollRec())) {
                        if (i.adjRectangle.x == r.getCollRec().x) {
                            canFall = false;
                        }
                    }
                }
                for (auto &immortal: immortalList) { //CHECKT FÜR COLLISION BEI Dirt, UND FÜHRT BENÖTIGTE METHODEN AUS
                    if (CheckCollisionRecs(i.adjRectangle, immortal.getCollRec())) {
                        if (immortal.active) {
                            if (immortal.getCollRec().x - i.getCollRec().x <= 6) {
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
            for (auto &r: riegelList) { //CHECKT FÜR COLLISION BEI Riegeln, UND FÜHRT BENÖTIGTE METHODEN AUS
                if (CheckCollisionRecs(e.adjRectangle, r.getCollRec())) {
                    if (e.adjRectangle.x == r.getCollRec().x) {
                        canMoveRight = false;
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
            for (auto &r: riegelList) { //CHECKT FÜR COLLISION BEI Riegeln, UND FÜHRT BENÖTIGTE METHODEN AUS
                if (CheckCollisionRecs(e.adjRectangle, r.getCollRec())) {
                    if(r.directionR == 0) {
                        if (e.adjRectangle.y == r.getCollRec().y) {
                            canMoveUp = false;
                        }
                    } else {
                        if (e.adjRectangle.y == r.getCollRec().y + ((float) r.size * 24 - 24)) {
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
            for (auto &r: riegelList) { //CHECKT FÜR COLLISION BEI Riegeln, UND FÜHRT BENÖTIGTE METHODEN AUS
                if (CheckCollisionRecs(e.adjRectangle, r.getCollRec())) {
                    if(r.directionR == 0) {
                        if (e.adjRectangle.x == (r.getCollRec().x + ((float) r.size * 24 - 24))) {
                            canMoveLeft = false;
                        }
                    } else {
                        if (e.adjRectangle.x == r.getCollRec().x) {
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
            for (auto &r: riegelList) { //CHECKT FÜR COLLISION BEI Riegeln, UND FÜHRT BENÖTIGTE METHODEN AUS
                if (CheckCollisionRecs(e.adjRectangle, r.getCollRec())) {
                    if (e.adjRectangle.y == r.getCollRec().y) {
                        canMoveDown = false;
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
            }
            if (!e.dead) {
                // determine path
                // If there is nothing around the enemy it freaks out, tries to move into every direction but ultimately doesn't move
                // this acts as a failsafe, sending it down and right until it has footing.
                // if there are bugs,this needs to be adjusted
                if(e.struggle < 4) {
                    switch (e.direction) {
                        case 0: // idle
                            e.struggle = 0;
                            if(!canMoveLeft && !canMoveDown && !canMoveRight && !canMoveUp) {
                                e.direction = e.idle;
                            }
                            if((canMoveRight && canMoveUp && canMoveDown && canMoveLeft) || (canMoveRight && !canMoveUp && canMoveDown && !canMoveLeft) || (!canMoveRight && !canMoveUp && canMoveDown && !canMoveLeft) || (canMoveRight && canMoveUp && canMoveDown && !canMoveLeft)) {
                                e.direction = e.moveDown;
                            } else if((canMoveRight && canMoveUp && !canMoveDown && canMoveLeft) || (canMoveRight && canMoveUp && !canMoveDown && !canMoveLeft) || (canMoveRight && !canMoveUp && !canMoveDown && canMoveLeft) || (canMoveRight && !canMoveUp && !canMoveDown && !canMoveLeft)) {
                                e.direction = e.moveRight;
                            } else if((!canMoveRight && canMoveUp && canMoveDown && canMoveLeft) || (!canMoveRight && canMoveUp && !canMoveDown && canMoveLeft) || (!canMoveRight && canMoveUp && !canMoveDown && !canMoveLeft)) {
                                e.direction = e.moveUp;
                            } else if((!canMoveRight && !canMoveUp && canMoveDown && canMoveLeft) || (!canMoveRight && !canMoveUp && !canMoveDown && canMoveLeft)) {
                                e.direction = e.moveLeft;
                            }
                            break;
                        case 1: // Up
                            if(canMoveRight) {
                                e.struggle++;
                                e.direction = e.moveRight;
                            } else if(canMoveUp) {
                                e.struggle = 0;
                                e.direction = e.moveUp;
                            } else if(canMoveLeft) {
                                e.struggle = 0;
                                e.direction = e.moveLeft;
                            } else if(canMoveDown) {
                                e.struggle = 0;
                                e.direction = e.moveDown;
                            } else {
                                e.struggle = 0;
                                e.direction = e.idle;
                            }
                            if(e.struggle > 3) e.direction = e.moveLeft;
                            break;
                        case 2:  // Left
                            if(canMoveUp) {
                                e.struggle++;
                                e.direction = e.moveUp;
                            } else if(canMoveLeft) {
                                e.struggle = 0;
                                e.direction = e.moveLeft;
                            } else if(canMoveDown) {
                                e.struggle = 0;
                                e.direction = e.moveDown;
                            } else if(canMoveRight) {
                                e.struggle = 0;
                                e.direction = e.moveRight;
                            } else {
                                e.struggle = 0;
                                e.direction = e.idle;
                            }
                            if(e.struggle > 3) e.direction = e.moveDown;
                            break;
                        case 3: // Down
                            if(canMoveLeft) {
                                e.struggle++;
                                e.direction = e.moveLeft;
                            } else if(canMoveDown) {
                                e.struggle = 0;
                                e.direction = e.moveDown;
                            } else if(canMoveRight) {
                                e.struggle = 0;
                                e.direction = e.moveRight;
                            } else if(canMoveUp) {
                                e.struggle = 0;
                                e.direction = e.moveUp;
                            } else {
                                e.struggle = 0;
                                e.direction = e.idle;
                            }
                            if(e.struggle > 3) e.direction = e.moveRight;
                            break;
                        case 4: // Right
                            if(canMoveDown) {
                                e.struggle = 0;
                                e.struggle++;
                                e.direction = e.moveDown;
                            } else if(canMoveRight) {
                                e.struggle = 0;
                                e.direction = e.moveRight;
                            } else if(canMoveUp) {
                                e.struggle = 0;
                                e.direction = e.moveUp;
                            } else if(canMoveLeft) {
                                e.struggle = 0;
                                e.direction = e.moveLeft;
                            } else {
                                e.struggle = 0;
                                e.direction = e.idle;
                            }
                            if(e.struggle > 3) e.direction = e.moveUp;
                            break;
                    }
                    if(e.struggle < 4) {
                        if(e.direction == e.idle) {
                            e.idleAnimation();
                        } else {
                            e.move();
                            e.moveAnimation();
                        }
                    } else {
                        /*
                            bool canMoveEverywhere = true;
                            if(!canMoveLeft || !canMoveUp || !canMoveDown || !canMoveRight) canMoveEverywhere = false;
                            if((e.direction == e.moveRight || e.direction == e.moveUp || e.direction == e.moveDown || e.direction == e.moveLeft) && canMoveEverywhere) {
                         */
                        if((e.direction == e.moveRight && canMoveRight) || (e.direction == e.moveUp && canMoveUp) || (e.direction == e.moveDown && canMoveDown) || (e.direction == e.moveLeft && canMoveLeft)) {
                            e.move();
                            e.moveAnimation();
                        } else {
                            e.struggle = 0;
                            e.direction = e.idle;
                        }
                    }
                } else {
                    /*
                        bool canMoveEverywhere = true;
                        if(!canMoveLeft || !canMoveUp || !canMoveDown || !canMoveRight) canMoveEverywhere = false;
                        if((e.direction == e.moveRight || e.direction == e.moveUp || e.direction == e.moveDown || e.direction == e.moveLeft) && canMoveEverywhere) {
                     */
                    if((e.direction == e.moveRight && canMoveRight) || (e.direction == e.moveUp && canMoveUp) || (e.direction == e.moveDown && canMoveDown) || (e.direction == e.moveLeft && canMoveLeft)) {
                        e.move();
                        e.moveAnimation();
                    } else {
                        e.struggle = 0;
                        e.direction = e.idle;
                    }
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
                        int xOne = (int) e.getPos().x;
                        int xCor = (xOne / 24) * 24;
                        if (xOne % 24 > 11) {
                            xCor += 24;
                        }
                        int yOne = (int) e.getPos().y;
                        int yCor = ((yOne - 30) / 24) * 24 + 30;
                        if ((yOne - 30) % 24 > 11) {
                            yCor += 24;
                        }

                        enemySpawnMemory(xCor, yCor);
                        enemySpawnMemory(xCor, yCor);

                        // spawn memory
                        /*
                         * Input code to search for open space in a 1(?) tile radius
                         * do that twice
                         * then add TWO memories
                         */
                        e.memoryGenerated = true;
                    }
                }
            }
        }
    }
}

void Game::GameScreen::enemySpawnMemory(int valX, int valY) {
    allGameObjects.insert(allGameObjects.end(), dirtList.begin(), dirtList.end());
    allGameObjects.insert(allGameObjects.end(), boulderList.begin(), boulderList.end());
    allGameObjects.insert(allGameObjects.end(), memoryList.begin(), memoryList.end());
    allGameObjects.insert(allGameObjects.end(), riegelList.begin(), riegelList.end());
    allGameObjects.insert(allGameObjects.end(), wallList.begin(), wallList.end());
    allGameObjects.insert(allGameObjects.end(), doorList.begin(), doorList.end());
    allGameObjects.insert(allGameObjects.end(), mortalList.begin(), mortalList.end());
    allGameObjects.insert(allGameObjects.end(), immortalList.begin(), immortalList.end());
    bool centerFree = true;
    bool centerBottomFree = true;
    bool centerRightFree = true;
    bool centerLeftFree = true;
    bool centerUpFree = true;
    bool downRightFree = true;
    bool downLeftFree = true;
    bool upRightFree = true;
    bool upLeftFree = true;
    bool generated = false;
    Rectangle freeSpace = {(float) valX, (float) valY, 24, 24};
    for (auto &gO: allGameObjects) {
        if (CheckCollisionRecs(freeSpace, gO.getCollRec()) && gO.active) {
            centerFree = false;
        }
    }
    if (centerFree) {
        memoryList.emplace_back(freeSpace.x, freeSpace.y);
        memoryList.back().setTexture(memories);
        memoryList.back().frameRec = memoryList.front().frameRec;
        memoryList.back().delay = memoryList.front().delay;
        memoryList.back().frameCounter = memoryList.front().frameCounter;
        memoryList.back().currentFrame = memoryList.front().currentFrame;
        generated = true;
    }
    if (!generated) {
        freeSpace = {(float) valX, (float) valY + 24, 24, 24};
        for (auto &gO: allGameObjects) {
            if (CheckCollisionRecs(freeSpace, gO.getCollRec()) && gO.active) {
                centerBottomFree = false;
            }
        }
        if (centerBottomFree) {
            memoryList.emplace_back(freeSpace.x, freeSpace.y);
            memoryList.back().setTexture(memories);
            memoryList.back().frameRec = memoryList.front().frameRec;
            memoryList.back().delay = memoryList.front().delay;
            memoryList.back().frameCounter = memoryList.front().frameCounter;
            memoryList.back().currentFrame = memoryList.front().currentFrame;
            generated = true;
        }
        if (!generated) {
            freeSpace = {(float) valX + 24, (float) valY, 24, 24};
            for (auto &gO: allGameObjects) {
                if (CheckCollisionRecs(freeSpace, gO.getCollRec()) && gO.active) {
                    centerRightFree = false;
                }
            }
            if (centerRightFree) {
                memoryList.emplace_back(freeSpace.x, freeSpace.y);
                memoryList.back().setTexture(memories);
                memoryList.back().frameRec = memoryList.front().frameRec;
                memoryList.back().delay = memoryList.front().delay;
                memoryList.back().frameCounter = memoryList.front().frameCounter;
                memoryList.back().currentFrame = memoryList.front().currentFrame;
                generated = true;
            }
            if (!generated) {
                freeSpace = {(float) valX - 24, (float) valY, 24, 24};
                for (auto &gO: allGameObjects) {
                    if (CheckCollisionRecs(freeSpace, gO.getCollRec()) && gO.active) {
                        centerLeftFree = false;
                    }
                }
                if (centerLeftFree) {
                    memoryList.emplace_back(freeSpace.x, freeSpace.y);
                    memoryList.back().setTexture(memories);
                    memoryList.back().frameRec = memoryList.front().frameRec;
                    memoryList.back().delay = memoryList.front().delay;
                    memoryList.back().frameCounter = memoryList.front().frameCounter;
                    memoryList.back().currentFrame = memoryList.front().currentFrame;
                    generated = true;
                }
                if (!generated) {
                    freeSpace = {(float) valX, (float) valY - 24, 24, 24};
                    for (auto &gO: allGameObjects) {
                        if (CheckCollisionRecs(freeSpace, gO.getCollRec()) && gO.active) {
                            centerUpFree = false;
                        }
                    }
                    if (centerUpFree) {
                        memoryList.emplace_back(freeSpace.x, freeSpace.y);
                        memoryList.back().setTexture(memories);
                        memoryList.back().frameRec = memoryList.front().frameRec;
                        memoryList.back().delay = memoryList.front().delay;
                        memoryList.back().frameCounter = memoryList.front().frameCounter;
                        memoryList.back().currentFrame = memoryList.front().currentFrame;
                        generated = true;
                    }
                    if (!generated) {
                        freeSpace = {(float) valX + 24, (float) valY + 24, 24, 24};
                        for (auto &gO: allGameObjects) {
                            if (CheckCollisionRecs(freeSpace, gO.getCollRec()) && gO.active) {
                                downRightFree = false;
                            }
                        }
                        if (downRightFree) {
                            memoryList.emplace_back(freeSpace.x, freeSpace.y);
                            memoryList.back().setTexture(memories);
                            memoryList.back().frameRec = memoryList.front().frameRec;
                            memoryList.back().delay = memoryList.front().delay;
                            memoryList.back().frameCounter = memoryList.front().frameCounter;
                            memoryList.back().currentFrame = memoryList.front().currentFrame;
                            generated = true;
                        }
                        if (!generated) {
                            freeSpace = {(float) valX - 24, (float) valY + 24, 24, 24};
                            for (auto &gO: allGameObjects) {
                                if (CheckCollisionRecs(freeSpace, gO.getCollRec()) && gO.active) {
                                    downLeftFree = false;
                                }
                            }
                            if (downLeftFree) {
                                memoryList.emplace_back(freeSpace.x, freeSpace.y);
                                memoryList.back().setTexture(memories);
                                memoryList.back().frameRec = memoryList.front().frameRec;
                                memoryList.back().delay = memoryList.front().delay;
                                memoryList.back().frameCounter = memoryList.front().frameCounter;
                                memoryList.back().currentFrame = memoryList.front().currentFrame;
                                generated = true;
                            }
                            if (!generated) {
                                freeSpace = {(float) valX + 24, (float) valY - 24, 24, 24};
                                for (auto &gO: allGameObjects) {
                                    if (CheckCollisionRecs(freeSpace, gO.getCollRec()) && gO.active) {
                                        upRightFree = false;
                                    }
                                }
                                if (upRightFree) {
                                    memoryList.emplace_back(freeSpace.x, freeSpace.y);
                                    memoryList.back().setTexture(memories);
                                    memoryList.back().frameRec = memoryList.front().frameRec;
                                    memoryList.back().delay = memoryList.front().delay;
                                    memoryList.back().frameCounter = memoryList.front().frameCounter;
                                    memoryList.back().currentFrame = memoryList.front().currentFrame;
                                    generated = true;
                                }
                                if (!generated) {
                                    freeSpace = {(float) valX + 24, (float) valY - 24, 24, 24};
                                    for (auto &gO: allGameObjects) {
                                        if (CheckCollisionRecs(freeSpace, gO.getCollRec()) && gO.active) {
                                            upLeftFree = false;
                                        }
                                    }
                                    if (upLeftFree) {
                                        memoryList.emplace_back(freeSpace.x, freeSpace.y);
                                        memoryList.back().setTexture(memories);
                                        memoryList.back().frameRec = memoryList.front().frameRec;
                                        memoryList.back().delay = memoryList.front().delay;
                                        memoryList.back().frameCounter = memoryList.front().frameCounter;
                                        memoryList.back().currentFrame = memoryList.front().currentFrame;
                                        generated = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    allGameObjects.clear();
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
            for (auto &r: riegelList) { //CHECKT FÜR COLLISION BEI Riegeln, UND FÜHRT BENÖTIGTE METHODEN AUS
                if (CheckCollisionRecs(e.adjRectangle, r.getCollRec())) {
                    if (e.adjRectangle.x == r.getCollRec().x) {
                        canMoveRight = false;
                    }
                }
            }
            for (auto &b: boulderList) {
                if (CheckCollisionRecs(e.getAdjRec(), b.getCollRec())) {
                    if (b.active) {
                        if (!b.falling) {
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
            for (auto &r: riegelList) { //CHECKT FÜR COLLISION BEI Riegeln, UND FÜHRT BENÖTIGTE METHODEN AUS
                if (CheckCollisionRecs(e.adjRectangle, r.getCollRec())) {
                    if(r.directionR == 0) {
                        if (e.adjRectangle.y == r.getCollRec().y) {
                            canMoveUp = false;
                        }
                    } else {
                        if (e.adjRectangle.y == r.getCollRec().y + ((float) r.size * 24 - 24)) {
                            canMoveUp = false;
                        }
                    }
                }
            }
            for (auto &b: boulderList) {
                if (CheckCollisionRecs(e.getAdjRec(), b.getCollRec())) {
                    if (b.active) {
                        if (!b.falling) {
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
            for (auto &r: riegelList) { //CHECKT FÜR COLLISION BEI Riegeln, UND FÜHRT BENÖTIGTE METHODEN AUS
                if (CheckCollisionRecs(e.adjRectangle, r.getCollRec())) {
                    if(r.directionR == 0) {
                        if (e.adjRectangle.x == (r.getCollRec().x + ((float) r.size * 24 - 24))) {
                            canMoveLeft = false;
                        }
                    } else {
                        if (e.adjRectangle.x == r.getCollRec().x) {
                            canMoveLeft = false;
                        }
                    }
                }
            }
            for (auto &b: boulderList) {
                if (CheckCollisionRecs(e.getAdjRec(), b.getCollRec())) {
                    if (b.active) {
                        if (!b.falling) {
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
            for (auto &r: riegelList) { //CHECKT FÜR COLLISION BEI Riegeln, UND FÜHRT BENÖTIGTE METHODEN AUS
                if (CheckCollisionRecs(e.adjRectangle, r.getCollRec())) {
                    if (e.adjRectangle.y == r.getCollRec().y) {
                        canMoveDown = false;
                    }
                }
            }
            for (auto &b: boulderList) {
                if (CheckCollisionRecs(e.getAdjRec(), b.getCollRec())) {
                    if (b.active) {
                        if (!b.falling) {
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
                    if (m.active) {
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
                }
            }

            if (!e.hasEaten) {
                // determine path
                // If there is nothing around the enemy it freaks out, tries to move into every direction but ultimately doesn't move
                // this acts as a failsafe, sending it down and right until it has footing.
                // if there are bugs,this needs to be adjusted
                if(e.struggle < 4) {
                    switch (e.direction) {
                        case 0: // idle
                            e.struggle = 0;
                            if(!canMoveLeft && !canMoveDown && !canMoveRight && !canMoveUp) {
                                e.direction = e.idle;
                            }
                            if((canMoveRight && canMoveUp && canMoveDown && canMoveLeft) || (canMoveRight && !canMoveUp && canMoveDown && !canMoveLeft) || (!canMoveRight && !canMoveUp && canMoveDown && !canMoveLeft) || (canMoveRight && canMoveUp && canMoveDown && !canMoveLeft)) {
                                e.direction = e.moveDown;
                            } else if((canMoveRight && canMoveUp && !canMoveDown && canMoveLeft) || (canMoveRight && canMoveUp && !canMoveDown && !canMoveLeft) || (canMoveRight && !canMoveUp && !canMoveDown && canMoveLeft) || (canMoveRight && !canMoveUp && !canMoveDown && !canMoveLeft)) {
                                e.direction = e.moveRight;
                            } else if((!canMoveRight && canMoveUp && canMoveDown && canMoveLeft) || (!canMoveRight && canMoveUp && !canMoveDown && canMoveLeft) || (!canMoveRight && canMoveUp && !canMoveDown && !canMoveLeft)) {
                                e.direction = e.moveUp;
                            } else if((!canMoveRight && !canMoveUp && canMoveDown && canMoveLeft) || (!canMoveRight && !canMoveUp && !canMoveDown && canMoveLeft)) {
                                e.direction = e.moveLeft;
                            }
                            break;
                        case 1: // Up
                            if(canMoveRight) {
                                e.struggle++;
                                e.direction = e.moveRight;
                            } else if(canMoveUp) {
                                e.struggle = 0;
                                e.direction = e.moveUp;
                            } else if(canMoveLeft) {
                                e.struggle = 0;
                                e.direction = e.moveLeft;
                            } else if(canMoveDown) {
                                e.struggle = 0;
                                e.direction = e.moveDown;
                            } else {
                                e.struggle = 0;
                                e.direction = e.idle;
                            }
                            if(e.struggle > 3) e.direction = e.moveLeft;
                            break;
                        case 2:  // Left
                            if(canMoveUp) {
                                e.struggle++;
                                e.direction = e.moveUp;
                            } else if(canMoveLeft) {
                                e.struggle = 0;
                                e.direction = e.moveLeft;
                            } else if(canMoveDown) {
                                e.struggle = 0;
                                e.direction = e.moveDown;
                            } else if(canMoveRight) {
                                e.struggle = 0;
                                e.direction = e.moveRight;
                            } else {
                                e.struggle = 0;
                                e.direction = e.idle;
                            }
                            if(e.struggle > 3) e.direction = e.moveDown;
                            break;
                        case 3: // Down
                            if(canMoveLeft) {
                                e.struggle++;
                                e.direction = e.moveLeft;
                            } else if(canMoveDown) {
                                e.struggle = 0;
                                e.direction = e.moveDown;
                            } else if(canMoveRight) {
                                e.struggle = 0;
                                e.direction = e.moveRight;
                            } else if(canMoveUp) {
                                e.struggle = 0;
                                e.direction = e.moveUp;
                            } else {
                                e.struggle = 0;
                                e.direction = e.idle;
                            }
                            if(e.struggle > 3) e.direction = e.moveRight;
                            break;
                        case 4: // Right
                            if(canMoveDown) {
                                e.struggle = 0;
                                e.struggle++;
                                e.direction = e.moveDown;
                            } else if(canMoveRight) {
                                e.struggle = 0;
                                e.direction = e.moveRight;
                            } else if(canMoveUp) {
                                e.struggle = 0;
                                e.direction = e.moveUp;
                            } else if(canMoveLeft) {
                                e.struggle = 0;
                                e.direction = e.moveLeft;
                            } else {
                                e.struggle = 0;
                                e.direction = e.idle;
                            }
                            if(e.struggle > 3) e.direction = e.moveUp;
                            break;
                    }
                    if(e.struggle < 4) {
                        if(e.direction == e.idle) {
                            e.idleAnimation();
                        } else {
                            e.move();
                            e.moveAnimation();
                        }
                    } else {
                        if((e.direction == e.moveRight && canMoveRight) || (e.direction == e.moveUp && canMoveUp) || (e.direction == e.moveDown && canMoveDown) || (e.direction == e.moveLeft && canMoveLeft)) {
                            e.move();
                            e.moveAnimation();
                        } else {
                            e.struggle = 0;
                            e.direction = e.idle;
                        }
                    }
                } else {
                    if((e.direction == e.moveRight && canMoveRight) || (e.direction == e.moveUp && canMoveUp) || (e.direction == e.moveDown && canMoveDown) || (e.direction == e.moveLeft && canMoveLeft)) {
                        e.move();
                        e.moveAnimation();
                    } else {
                        e.struggle = 0;
                        e.direction = e.idle;
                    }
                }
            } else {
                // enemy has eaten a memory
                // get coordinates for memory generation
                if (e.active) {
                    e.active = false;
                    int xOne = (int) e.getPos().x;
                    int xCor = (xOne / 24) * 24;
                    if (xOne % 24 > 11) {
                        xCor += 24;
                    }
                    int yOne = (int) e.getPos().y;
                    int yCor = ((yOne - 30) / 24) * 24 + 30;
                    if ((yOne - 30) % 24 > 11) {
                        yCor += 24;
                    }
                    // spawn mortal Enemy
                    mortalList.emplace_back(xCor, yCor);
                    mortalList.back().direction = e.direction;
                    mortalList.back().texDeath = texMortalDeath;
                    mortalList.back().texIdle = texMortalIdle;
                    mortalList.back().texUp = texMortalUp;
                    mortalList.back().texLeft = texMortalLeft;
                    mortalList.back().texDown = texMortalDown;
                    mortalList.back().texRight = texMortalRight;
                    mortalList.back().recDeath = recMortalDeath;
                    mortalList.back().recIdle = recMortalIdle;
                    mortalList.back().recUp = recMortalUp;
                    mortalList.back().recLeft = recMortalLeft;
                    mortalList.back().recDown = recMortalDown;
                    mortalList.back().recRight = recMortalRight;
                    allGameObjects.emplace_back(mortalList.back());
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
    allGameObjects.clear();
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
    if (!gamePaused) framesCounter++;
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
            if (gamePaused) i.frameCounter = 0;
            i.drawMemory();
        }
    }
    for (auto &i: doorList) { //door
        i.drawDoor();
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
        if (gamePaused) i.frameCounter = 0;
        i.drawBoulder();
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
        i.drawRiegel();
    }
    //DrawText(TextFormat("Current FPS: %i", GetFPS()), 10, 5, 15, WHITE);
    //DrawText(TextFormat("Paws Of Memories"), 170, 5, 15, WHITE);
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
            case 3: // Momentan korrekt
                hotbarLevel = LoadTexture("assets/graphics/Other/Hotbar/Level/1_3.png");
                hotbarArea = LoadTexture("assets/graphics/Other/Hotbar/Area/1_3.png");
                break;
            case 4: // Momentan korrekt
                hotbarLevel = LoadTexture("assets/graphics/Other/Hotbar/Level/1_3.png");
                hotbarArea = LoadTexture("assets/graphics/Other/Hotbar/Area/2_3.png");
                break;
            case 5: // Doesn't exist yet
                hotbarLevel = LoadTexture("assets/graphics/Other/Hotbar/Level/1_3.png");
                hotbarArea = LoadTexture("assets/graphics/Other/Hotbar/Area/3_3.png");
                break;
            case 6: // Doesn't exist yet
                hotbarLevel = LoadTexture("assets/graphics/Other/Hotbar/Level/2_3.png");
                hotbarArea = LoadTexture("assets/graphics/Other/Hotbar/Area/1_3.png");
                break;
            case 7: // Doesn't exist yet
                hotbarLevel = LoadTexture("assets/graphics/Other/Hotbar/Level/2_3.png");
                hotbarArea = LoadTexture("assets/graphics/Other/Hotbar/Area/2_3.png");
                break;
            case 8: // Doesn't exist yet
                hotbarLevel = LoadTexture("assets/graphics/Other/Hotbar/Level/2_3.png");
                hotbarArea = LoadTexture("assets/graphics/Other/Hotbar/Area/3_3.png");
                break;
            case 9: // Doesn't exist yet
                hotbarLevel = LoadTexture("assets/graphics/Other/Hotbar/Level/3_3.png");
                hotbarArea = LoadTexture("assets/graphics/Other/Hotbar/Area/1_3.png");
                break;
            case 10: // Doesn't exist yet
                hotbarLevel = LoadTexture("assets/graphics/Other/Hotbar/Level/3_3.png");
                hotbarArea = LoadTexture("assets/graphics/Other/Hotbar/Area/2_3.png");
                break;
            case 11: // Doesn't exist yet
                hotbarLevel = LoadTexture("assets/graphics/Other/Hotbar/Level/3_3.png");
                hotbarArea = LoadTexture("assets/graphics/Other/Hotbar/Area/3_3.png");
                break;
        }
        hotbarDataLoaded = true;
    }

    DrawTexturePro(hotbar, Rectangle{0, 0, (float) hotbar.width, (float) hotbar.height},
                   Rectangle{314, 1, (float) hotbar.width, (float) hotbar.height}, {}, 0, WHITE);
    if(roomCounter > 2) {
        DrawTexturePro(hotbarLevel, Rectangle{0, 0, (float) hotbarLevel.width, (float) hotbarLevel.height},
                       Rectangle{372, 8, (float) hotbarLevel.width, (float) hotbarLevel.height}, {}, 0, WHITE);
        DrawTexturePro(hotbarArea, Rectangle{0, 0, (float) hotbarArea.width, (float) hotbarArea.height},
                       Rectangle{425, 8, (float) hotbarArea.width, (float) hotbarArea.height}, {}, 0, WHITE);
    } else { // Tutorial
        DrawTexturePro(hotbarLevel, Rectangle{0, 0, (float) 16, (float) hotbarLevel.height},
                       Rectangle{372, 8, (float) 16, (float) hotbarLevel.height}, {}, 0, WHITE);
        DrawTexturePro(numbers, Rectangle {0, 0, 6, (float) numbers.height}, Rectangle{390, 8, (float) numbers.width / 9, (float) numbers.height}, {}, 0,
                       WHITE);
        DrawTexturePro(hotbarLevel, Rectangle{29, 0, (float) 13, (float) hotbarLevel.height},
                       Rectangle{401, 8, (float) 14, (float) hotbarLevel.height}, {}, 0, WHITE);
        DrawTexturePro(hotbarArea, Rectangle{0, 0, (float) hotbarArea.width, (float) hotbarArea.height},
                       Rectangle{425, 8, (float) hotbarArea.width, (float) hotbarArea.height}, {}, 0, WHITE);
    }

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
    if (!level2Unlocked) {
        DrawTexture(texLevel2Locked, 274, 31, WHITE);
        DrawTexture(texHubDoorClosed, 275, 49, WHITE);
    } else {
        if (CheckCollisionRecs(player.getCollRec(), interacCollision[2])) {
            DrawTexturePro(galleryInteractionText, Rectangle{0.0f, 0.0f, 42, (float) galleryInteractionText.height},
                           Rectangle{player.getPos().x - 9, player.getPos().y - 23, 42,
                                     (float) galleryInteractionText.height}, {}, 0, WHITE);
        }
    }
    if (!level3Unlocked) {
        DrawTexture(texLevel3Locked, 370, 31, WHITE);
        DrawTexture(texHubDoorClosed, 371, 49, WHITE);
    } else {
        if (CheckCollisionRecs(player.getCollRec(), interacCollision[3])) {
            DrawTexturePro(galleryInteractionText, Rectangle{0.0f, 0.0f, 42, (float) galleryInteractionText.height},
                           Rectangle{player.getPos().x - 9, player.getPos().y - 23, 42,
                                     (float) galleryInteractionText.height}, {}, 0, WHITE);
        }
    }
    if (CheckCollisionRecs(player.getCollRec(), interacCollision[1])) { // Raum 1
        if (CheckCollisionRecs(player.getCollRec(), interacCollision[1])) {
            DrawTexturePro(galleryInteractionText, Rectangle{0.0f, 0.0f, 42, (float) galleryInteractionText.height},
                           Rectangle{player.getPos().x - 9, player.getPos().y - 23, 42,
                                     (float) galleryInteractionText.height}, {}, 0, WHITE);
        }
        if (hubDoorOpened) {
            framesCounter++;
            DrawTexturePro(texHubDoorAnim, hubDoorAnimRec,
                           Rectangle{59, 49, hubDoorAnimRec.width, hubDoorAnimRec.height},
                           {}, 0, WHITE);
            if (framesCounter >= (60 / framesSpeed)) {

                framesCounter = 0;
                currentFrame++;

                if (currentFrame > 2) {
                    currentFrame = 0;
                    hubDoorAnimDone = true;
                }
                hubDoorAnimRec.x = (float) currentFrame * (float) texHubDoorAnim.width / 3;
            }
        }
    } else if (CheckCollisionRecs(player.getCollRec(), interacCollision[2])) { // Raum 2
        if (hubDoorOpened) {
            framesCounter++;
            DrawTexturePro(texHubDoorAnim, hubDoorAnimRec,
                           Rectangle{275, 49, hubDoorAnimRec.width, hubDoorAnimRec.height},
                           {}, 0, WHITE);
            if (framesCounter >= (60 / framesSpeed)) {

                framesCounter = 0;
                currentFrame++;

                if (currentFrame > 2) {
                    currentFrame = 0;
                    hubDoorAnimDone = true;
                }
                hubDoorAnimRec.x = (float) currentFrame * (float) texHubDoorAnim.width / 3;
            }
        }
    } else if (CheckCollisionRecs(player.getCollRec(), interacCollision[3])) { // Raum 3
        if (hubDoorOpened) {
            framesCounter++;
            DrawTexturePro(texHubDoorAnim, hubDoorAnimRec,
                           Rectangle{371, 49, hubDoorAnimRec.width, hubDoorAnimRec.height},
                           {}, 0, WHITE);
            if (framesCounter >= (60 / framesSpeed)) {

                framesCounter = 0;
                currentFrame++;

                if (currentFrame > 2) {
                    currentFrame = 0;
                    hubDoorAnimDone = true;
                }
                hubDoorAnimRec.x = (float) currentFrame * (float) texHubDoorAnim.width / 3;
            }
        }
    }
    //draw player
    player.drawPlayerHub();

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
    // Dialogue
    /*
    if (dialogueManager.open) {
        dialogueManager.drawDialogueBox(dialogueManager.dialogue);
        dialogueManager.drawContinousText("assets/textFiles/testFile.txt");
    }

    for (auto &furniture: furnitureCollision) {
        DrawRectangleRec(furniture, MAGENTA);
    }*/
}

void Game::GameScreen::hubPlayerInteractions() {
    player.updatePlayer();
    hubCanPlayerMove();
    if (player.canMove && !bookAnim && !hubDoorOpened) {
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
    } else if (CheckCollisionRecs(player.getCollRec(), interacCollision[1])) { // Raum 1
        if (!hubDoorOpened) {
            if (IsKeyPressed(KEY_E)) {
                hubDoorOpened = true;
            }
        } else if (hubDoorAnimDone) {
            preRoomCounter = 0;
            display = 5;
            initializePreRoomElements();
            currentFrame = 0;
            hubDoorOpened = false;
            hubDoorAnimDone = false;
        }
    } else if (CheckCollisionRecs(player.getCollRec(), interacCollision[2])) { // Raum 2
        if (level2Unlocked) {
            if (!hubDoorOpened) {
                if (IsKeyPressed(KEY_E)) {
                    hubDoorOpened = true;
                }
            } else if (hubDoorAnimDone) {
                preRoomCounter = 1;
                display = 5;
                initializePreRoomElements();
                currentFrame = 0;
                hubDoorOpened = false;
                hubDoorAnimDone = false;
            }
        }
    } else if (CheckCollisionRecs(player.getCollRec(), interacCollision[3])) { // Raum 3
        if (level3Unlocked) {
            if (!hubDoorOpened) {
                if (IsKeyPressed(KEY_E)) {
                    hubDoorOpened = true;
                }
            } else if (hubDoorAnimDone) {
                preRoomCounter = 2;
                display = 5;
                initializePreRoomElements();
                currentFrame = 0;
                hubDoorOpened = false;
                hubDoorAnimDone = false;
            }
        }
    }

    if (bookAnimDone) {
        display = 3;
        drawGallery();
        currentFrame = 0;
        galCounter = 0;
        bookAnimDone = false;
    }

    if (player.moving) player.hubMoveAnimation();
    else player.hubIdleAnimation();

}

void Game::GameScreen::hubCanPlayerMove() {
    // Checkt Collision & Hub boundaries, und gibt wieder ob der  Spieler sich bewegen darf
    if (player.getAdjRec().x >= -2 && player.getAdjRec().x <= 458 && player.getAdjRec().y >= 84 &&
        player.getAdjRec().y <= 247) {
        player.canMove = true;
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

    // Das sind die Bereiche der Textur, die über dem Spieler gezeichnet werden.
    texPlantTop = {0.0f, 72.0f, 30.0f, 70.0f};
    texChairLamp = {0.0f, 146.0f, 82.0f, 43.0f};
    texTable = {190.0f, 141.0f, 81.0f, 19.0f};
    texBox = {405.0f, 213.0f, 31.0f, 10.0f};
    texCatTree = {403.0f, 106.0f, 77.0f, 77.0f};
    texTable2 = {437.0f, 181.0f, 43.0f, 17.0f};
    texPlant2 = {442.0, 149.0f, 37.0f, 34.0f};
    //Rectangle texTable2; //if necessary
    //Rectangle texShelf; // If secret room is desired
    furnitureTextures = {texPlantTop, texChairLamp, texTable, texBox, texCatTree, texTable2, texPlant2};

    //Das sind die Hitboxen, wo der Spieler nicht hindarf.
    // @Nicole. du kannst mit den Werten was rumspielen um zu gucken was gut aussieht. Mit der Seite https://pixspy.com/ kannste gucken welche koordinate die ixel haben wenn dus brauchst.
    tableBook = {191.0f, 160.0f, 80.0f, 27.0f}; // mostly fixed
    chair1 = {27.0f, 187.0f, 54.0f, 10.0f}; // not yet fixed
    lamp = {21.0f, 201.0f, 4.0f, 14.0f}; // not yet fixed
    chair2 = {0.0f, 219.0f, 21.0f, 10.0f};
    plant = {0.0f, 142.0f, 22.0f, 30.0f};
    table2 = {438.0f, 194.0f, 43.0f, 48.0f};
    box = {407.0f, 220.0f, 31.0f, 0.0f};
    clock = {5.0f, 95.0f, 32.0f, 0.0f};
    shelf = {431.0f, 98.0f, 50.0f, 0.0f};
    catTree = {437.0f, 181.0f, 4.0f, 3.0f};
    furnitureCollision = {tableBook, chair1, lamp, chair2, plant, table2, box, clock, shelf, catTree};

    //Interaction Collisionboxes
    galleryInterac = {185.0f, 145.0f, 90.0f, 55.0f};
    doorInterac1 = {73.0f, 90.0f, 21.0f, 10.0f};
    doorInterac2 = {289.0f, 90.0f, 21.0f, 10.0f};
    doorInterac3 = {385.0f, 90.0f, 21.0f, 10.0f};
    interacCollision = {galleryInterac, doorInterac1, doorInterac2, doorInterac3};
}

void Game::GameScreen::preRoomPlayerInteractions() {
    player.updatePlayer();
    preRoomCanPlayerMove();
    if (player.canMove) {
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

    // NPC interaction code; noch anzupassen
    if (CheckCollisionRecs(player.getCollRec(), npc.interactionBoxNPC)) {
        if (IsKeyPressed(KEY_E) && !dialogueManager.open) {
            dialogueManager.open = true;
        } else if (dialogueManager.open) {
            if (!dialogueManager.dialogueDone) {
                if (IsKeyPressed(KEY_ENTER)) {
                    dialogueManager.dialogueSkip();
                }
            } else {
                if (IsKeyPressed(KEY_ENTER)) {
                    if(player.compassCollected && dialogueManager.dialogueDone) {
                        compassGiven = true;
                    }
                    dialogueManager.resetState();
                }
            }
        }
    }
    if (CheckCollisionRecs(player.getCollRec(), preRoomInteracCollision[0])) { // Level
        if (preRoomCounter == 0 && !level1Unlocked) {
            //do nothing
        } else {
            if(preRoomCounter == 0 && !player.compassCollected) {
                if (IsKeyPressed(KEY_E) && !dialogueManager.open) {
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
            } else {
                if (!hubDoorOpened) {
                    if (IsKeyPressed(KEY_E)) {
                        hubDoorOpened = true;
                    }
                } else if (hubDoorAnimDone) {
                    roomCounter = (preRoomCounter + 1) * 3;
                    display = 1;
                    hotbarDataLoaded = false;
                    generateMap();
                    currentFrame = 0;
                    hubDoorOpened = false;
                    hubDoorAnimDone = false;
                }
            }
        }
    } else if (CheckCollisionRecs(player.getCollRec(), preRoomInteracCollision[1]) && !tutorialUnlocked) { // Hub
        if (IsKeyPressed(KEY_E)) {
            display = 2;
            initializeHubElements();
            currentFrame = 0;
        }
    } else {
        if (preRoomCounter == 0) {
            if (CheckCollisionRecs(player.getCollRec(), preRoomInteracCollision[2])) { // Tutorial
                if (tutorialUnlocked) {
                    if (!hubDoorOpened) {
                        if (IsKeyPressed(KEY_E)) {
                            hubDoorOpened = true;
                        }
                    } else if (hubDoorAnimDone) {
                        roomCounter = 0; // anpassen
                        display = 1;
                        hotbarDataLoaded = false;
                        generateMap();
                        currentFrame = 0;
                        hubDoorOpened = false;
                        hubDoorAnimDone = false;
                    }
                }
            }
        }
    }

    if (player.moving) player.hubMoveAnimation();
    else player.hubIdleAnimation();
}

void Game::GameScreen::preRoomCanPlayerMove() {
// Checkt Collision & Hub boundaries, und gibt wieder ob der  Spieler sich bewegen darf
    if (player.getAdjRec().x >= 60 && player.getAdjRec().x <= 196 && player.getAdjRec().y >= 96 &&
        player.getAdjRec().y <= 205 && (preRoomCounter == 1 || preRoomCounter == 2)) {
        player.canMove = true;
        if (CheckCollisionRecs(player.getAdjRec(), npc.getCollRec())) {
            player.canMove = false;
        }
        for (auto &f: preRoomCollision) {
            if (CheckCollisionRecs(player.getAdjRec(), f)) {
                player.canMove = false;
                break;
            }
        }
    } else if (player.getAdjRec().x >= 60 && player.getAdjRec().x <= 213 && player.getAdjRec().y >= 96 &&
               player.getAdjRec().y <= 205 && preRoomCounter == 0) {
        player.canMove = true;
        if (CheckCollisionRecs(player.getAdjRec(), npc.getCollRec())) {
            player.canMove = false;
        }
        for (auto &f: preRoomCollision) {
            if (CheckCollisionRecs(player.getAdjRec(), f)) {
                player.canMove = false;
                break;
            }
        }
    } else {
        player.canMove = false;
    }
    if (dialogueManager.open) {
        player.canMove = false;
    }
}

void Game::GameScreen::initializePreRoomElements() {
    // spawn the Rectangles for collision & interactions
    // InitPlayer(SpawnPointX, SpawnPointY); festgelegt auf iwas?

    //Das sind die Hitboxen, wo der Spieler nicht hindarf.
    grandmaBed = {60, 112, 51, 41};
    grandmaTable = {192, 176, 43, 53};
    adultBed = {60, 117, 51, 35};
    adultWardrobe = {60, 163, 45, 30};
    adultBoots = {112, 104, 16, 5};
    adultCan = {206, 116, 13, 17};
    teenBed = {60, 112, 51, 38};
    teenTeddy = {60, 150, 28, 17};
    teenWardrobe = {186, 112, 33, 6};
    teenTower = {208, 113, 11, 24};

    //Interaction Collisionboxes
    grandmaTutorialDoor = {122, 105, 20, 10};
    grandmaLevelDoor = {194, 105, 20, 10};
    grandmaToHub = {150, 220, 12, 15};
    adultLevelDoor = {146, 105, 20, 10};
    adultToHub = {150, 220, 12, 15};
    teenLevelDoor = {146, 105, 20, 10};
    teenToHub = {150, 220, 12, 15};

    switch (preRoomCounter) {
        case 0: // Grandma
            InitPlayer(143, 205);
            npcAge = 0;
            dialogueManager.dialogue = 0;
            preRoomCollision = {grandmaBed, grandmaTable};
            preRoomInteracCollision = {grandmaLevelDoor, grandmaToHub, grandmaTutorialDoor};
            break;
        case 1: // Adult
            InitPlayer(145, 205);
            npcAge = 1;
            dialogueManager.dialogue = 1;
            preRoomCollision = {adultBed, adultWardrobe, adultBoots, adultCan};
            preRoomInteracCollision = {adultLevelDoor, adultToHub};
            break;
        case 2: // Teen
            InitPlayer(145, 205);
            npcAge = 2;
            dialogueManager.dialogue = 2;
            preRoomCollision = {teenBed, teenTeddy, teenWardrobe, teenTower};
            preRoomInteracCollision = {teenLevelDoor, teenToHub};
            break;
    }
    npc.initialiseNPC(120, 135, npcAge);
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
    DrawTexture(startContinue, 200, 230, WHITE);
}

void Game::GameScreen::drawGameOver() {
    framesCounter++;
    if (framesCounter >= (180 / framesSpeed)) {

        framesCounter = 0;
        currentFrame++;

        if (currentFrame == 1 || currentFrame == 6) {
            deathLogoFrame++;
            if (deathLogoFrame > 1) {
                deathLogoFrame = 0;
            }
        }
        if (currentFrame > 10) {
            currentFrame = 0;
        }

        backgroundFrame.x = (float) currentFrame * (float) background.width / 11;

        GameOverFrame.x = (float) deathLogoFrame * (float) GameOver.width / 2;
    }


    DrawTexturePro(background, backgroundFrame,
                   Rectangle{0, 0, backgroundFrame.width, backgroundFrame.height},
                   {}, 0, WHITE);
    DrawTexturePro(GameOver, GameOverFrame,
                   Rectangle{0, 0, GameOverFrame.width, GameOverFrame.height},
                   {}, 0, WHITE);

    if(gameOverCounter == 0){
        goRestartB.setTexture(restartHighlighted);
        goMenuB.setTexture(returnMenu);
        DrawTexturePro(goRestartB.getTexture(), Rectangle{0, 0, (float) goRestartB.getTexture().width, (float) goRestartB.getTexture().height},
                       Rectangle{goRestartB.getPos().x - 45, goRestartB.getPos().y, (float) goRestartB.getTexture().width,
                                 (float) goRestartB.getTexture().height},
                       {}, 0, WHITE);
    }else if (gameOverCounter ==1){
        goRestartB.setTexture(restart);
        DrawTexturePro(goRestartB.getTexture(), Rectangle{0, 0, (float) goRestartB.getTexture().width, (float) goRestartB.getTexture().height},
                       Rectangle{goRestartB.getPos().x, goRestartB.getPos().y, (float) goRestartB.getTexture().width,
                                 (float) goRestartB.getTexture().height},
                       {}, 0, WHITE);
        goMenuB.setTexture(returnMenuHighlighted);
    }
    DrawTexturePro(goMenuB.getTexture(), Rectangle{0, 0, (float) goMenuB.getTexture().width, (float) goMenuB.getTexture().height},
                   Rectangle{goMenuB.getPos().x, goMenuB.getPos().y, (float) goMenuB.getTexture().width,
                             (float) goMenuB.getTexture().height},
                   {}, 0, WHITE);
}

void Game::GameScreen::drawGallery() {
    switch (galCounter) {
        case 0:
            if (CoreMemory1 && galForw) {//Mem1 unlocked
                framesCounter++;
                DrawTexturePro(CoreMem1Unl, Mem1FrameUnl,
                               Rectangle{0, 0, (float) CoreMem1Unl.width, (float) CoreMem1Unl.height},
                               {}, 0, WHITE);
                if (framesCounter >= (60 / framesSpeed)) {

                    framesCounter = 0;
                    currentFrame++;
                    if (currentFrame > 14) currentFrame = 15;

                    Mem1FrameUnl.x = (float) (currentFrame / 4) * (float) CoreMem1Unl.width / 4;
                    Mem1FrameUnl.y = (float) (currentFrame % 4) * (float) CoreMem1Unl.height / 4;
                }

            } else if (!CoreMemory1 && galForw) {//Mem1 locked
                framesCounter++;
                DrawTexturePro(CoreMem1L, Mem1FrameL,
                               Rectangle{0, 0, (float) CoreMem1L.width, (float) CoreMem1L.height},
                               {}, 0, WHITE);
                if (framesCounter >= (60 / framesSpeed)) {

                    framesCounter = 0;
                    currentFrame++;
                    if (currentFrame > 14) currentFrame = 15;

                    Mem1FrameL.x = (float) (currentFrame / 4) * (float) CoreMem1L.width / 4;
                    Mem1FrameL.y = (float) (currentFrame % 4) * (float) CoreMem1L.height / 4;
                }
            } else if (!CoreMemory1 && !CoreMemory2 && !CoreMemory3 &&
                       galForw) { //All Memories locked, this needs to be in all cases
                framesCounter++;
                DrawTexturePro(blank, blankFrame,
                               Rectangle{0, 0, (float) blank.width, (float) blank.height},
                               {}, 0, WHITE);
                if (framesCounter >= (60 / framesSpeed)) {

                    framesCounter = 0;
                    currentFrame++;
                    if (currentFrame > 14) currentFrame = 15;

                    blankFrame.x = (float) (currentFrame / 4) * (float) blank.width / 4;
                    blankFrame.y = (float) (currentFrame % 4) * (float) blank.height / 4;
                }
            }
            //backward flipping
            if (CoreMemory1 && CoreMemory2 && galBackw) { //Memory 1 and 2 unlocked
                framesCounter++;
                DrawTexturePro(b_CoreMem1Unl, b_Mem1FrameUnl,
                               Rectangle{0, 0, (float) b_CoreMem1Unl.width, (float) b_CoreMem1Unl.height},
                               {}, 0, WHITE);
                if (framesCounter >= (60 / framesSpeed)) {

                    framesCounter = 0;
                    currentFrame++;
                    if (currentFrame > 7) currentFrame = 8;

                    b_Mem1FrameUnl.x = (float) (currentFrame / 3) * (float) b_CoreMem1Unl.width / 3;
                    b_Mem1FrameUnl.y = (float) (currentFrame % 3) * (float) b_CoreMem1Unl.height / 3;
                }
            } else if (CoreMemory1 && !CoreMemory2 && galBackw) {
                framesCounter++;
                DrawTexturePro(b_CoreMem1No2, b_Mem1No2Frame,
                               Rectangle{0, 0, (float) b_CoreMem1No2.width, (float) b_CoreMem1No2.height},
                               {}, 0, WHITE);
                if (framesCounter >= (60 / framesSpeed)) {

                    framesCounter = 0;
                    currentFrame++;
                    if (currentFrame > 7) currentFrame = 8;

                    b_Mem1No2Frame.x = (float) (currentFrame / 3) * (float) b_CoreMem1No2.width / 3;
                    b_Mem1No2Frame.y = (float) (currentFrame % 3) * (float) b_CoreMem1No2.height / 3;
                }
            } else if (!CoreMemory1 && !CoreMemory2 && !CoreMemory3 &&
                       galBackw) { //All Memories locked, this needs to be in all cases
                framesCounter++;
                DrawTexturePro(b_blank, b_blankFrame,
                               Rectangle{0, 0, (float) b_blank.width, (float) b_blank.height},
                               {}, 0, WHITE);
                if (framesCounter >= (60 / framesSpeed)) {

                    framesCounter = 0;
                    currentFrame++;
                    if (currentFrame > 7) currentFrame = 8;

                    b_blankFrame.x = (float) (currentFrame / 3) * (float) b_blank.width / 3;
                    b_blankFrame.y = (float) (currentFrame % 3) * (float) b_blank.height / 3;
                }
            }
            break;
        case 1:
            if (CoreMemory2 && galForw) { // Mem 2 unlocked
                framesCounter++;
                DrawTexturePro(CoreMem2Unl, Mem2FrameUnl,
                               Rectangle{0, 0, (float) CoreMem2Unl.width, (float) CoreMem2Unl.height},
                               {}, 0, WHITE);
                if (framesCounter >= (60 / framesSpeed)) {

                    framesCounter = 0;
                    currentFrame++;
                    if (currentFrame > 7) currentFrame = 8;

                    Mem2FrameUnl.x = (float) (currentFrame / 3) * (float) CoreMem2Unl.width / 3;
                    Mem2FrameUnl.y = (float) (currentFrame % 3) * (float) CoreMem2Unl.height / 3;
                }
            } else if (!CoreMemory2 && CoreMemory1 && !CoreMemory3 && galForw) { //Mem 2 locked
                framesCounter++;
                DrawTexturePro(CoreMem2L, Mem2FrameL,
                               Rectangle{0, 0, (float) CoreMem2L.width, (float) CoreMem2L.height},
                               {}, 0, WHITE);
                if (framesCounter >= (60 / framesSpeed)) {

                    framesCounter = 0;
                    currentFrame++;
                    if (currentFrame > 7) currentFrame = 8;

                    Mem2FrameL.x = (float) (currentFrame / 3) * (float) CoreMem2L.width / 3;
                    Mem2FrameL.y = (float) (currentFrame % 3) * (float) CoreMem2L.height / 3;
                }
            } else if (!CoreMemory1 && !CoreMemory2 && !CoreMemory3 && galForw ||
                       (CoreMemory1 && !CoreMemory2 && !CoreMemory3 &&
                        galForw)) { //All Memories locked or 2 and 3 locked
                framesCounter++;
                DrawTexturePro(blank, blankFrame,
                               Rectangle{0, 0, (float) blank.width, (float) blank.height},
                               {}, 0, WHITE);
                if (framesCounter >= (60 / framesSpeed)) {

                    framesCounter = 0;
                    currentFrame++;
                    if (currentFrame > 7) currentFrame = 8;

                    blankFrame.x = (float) (currentFrame / 3) * (float) blank.width / 3;
                    blankFrame.y = (float) (currentFrame % 3) * (float) blank.height / 3;
                }
            }

            //backward flipping
            if (CoreMemory2 && CoreMemory3 && galBackw) { //Memory 2 and 3 unlocked
                framesCounter++;
                DrawTexturePro(b_CoreMem2Unl, b_Mem2FrameUnl,
                               Rectangle{0, 0, (float) b_CoreMem2Unl.width, (float) b_CoreMem2Unl.height},
                               {}, 0, WHITE);
                if (framesCounter >= (60 / framesSpeed)) {

                    framesCounter = 0;
                    currentFrame++;
                    if (currentFrame > 7) currentFrame = 8;

                    b_Mem2FrameUnl.x = (float) (currentFrame / 3) * (float) b_CoreMem2Unl.width / 3;
                    b_Mem2FrameUnl.y = (float) (currentFrame % 3) * (float) b_CoreMem2Unl.height / 3;
                }
            } else if (CoreMemory2 && !CoreMemory3 && galBackw) { //Memory 2 but not 3
                framesCounter++;
                DrawTexturePro(b_CoreMem2No3, b_Mem2No3Frame,
                               Rectangle{0, 0, (float) b_CoreMem2No3.width, (float) b_CoreMem2No3.height},
                               {}, 0, WHITE);
                if (framesCounter >= (60 / framesSpeed)) {

                    framesCounter = 0;
                    currentFrame++;
                    if (currentFrame > 7) currentFrame = 8;

                    b_Mem2No3Frame.x = (float) (currentFrame / 3) * (float) b_CoreMem2No3.width / 3;
                    b_Mem2No3Frame.y = (float) (currentFrame % 3) * (float) b_CoreMem2No3.height / 3;
                }
            } else if ((!CoreMemory1 && !CoreMemory2 && !CoreMemory3 && galBackw) ||
                       (CoreMemory1 && !CoreMemory2 && !CoreMemory3 &&
                        galBackw)) { //Memories 2 and 3 locked or all memories locked
                framesCounter++;
                DrawTexturePro(b_blank, b_blankFrame,
                               Rectangle{0, 0, (float) b_blank.width, (float) b_blank.height},
                               {}, 0, WHITE);
                if (framesCounter >= (60 / framesSpeed)) {

                    framesCounter = 0;
                    currentFrame++;
                    if (currentFrame > 7) currentFrame = 8;

                    b_blankFrame.x = (float) (currentFrame / 3) * (float) b_blank.width / 3;
                    b_blankFrame.y = (float) (currentFrame % 3) * (float) b_blank.height / 3;
                }
            }

            break;
        case 2:
            if (CoreMemory3 && galForw) { // Mem 3 unlocked
                framesCounter++;
                DrawTexturePro(CoreMem3Unl, Mem3FrameUnl,
                               Rectangle{0, 0, (float) CoreMem3Unl.width, (float) CoreMem3Unl.height},
                               {}, 0, WHITE);
                if (framesCounter >= (60 / framesSpeed)) {

                    framesCounter = 0;
                    currentFrame++;
                    if (currentFrame > 7) currentFrame = 8;

                    Mem3FrameUnl.x = (float) (currentFrame / 3) * (float) CoreMem3Unl.width / 3;
                    Mem3FrameUnl.y = (float) (currentFrame % 3) * (float) CoreMem3Unl.height / 3;
                }
            } else if (!CoreMemory3 && CoreMemory1 && CoreMemory2 && galForw) { //Mem 3 locked
                framesCounter++;
                DrawTexturePro(CoreMem3L, Mem3FrameL,
                               Rectangle{0, 0, (float) CoreMem3L.width, (float) CoreMem3L.height},
                               {}, 0, WHITE);
                if (framesCounter >= (60 / framesSpeed)) {

                    framesCounter = 0;
                    currentFrame++;
                    if (currentFrame > 7) currentFrame = 8;

                    Mem3FrameL.x = (float) (currentFrame / 3) * (float) CoreMem3L.width / 3;
                    Mem3FrameL.y = (float) (currentFrame % 3) * (float) CoreMem3L.height / 3;
                }
            } else if ((!CoreMemory1 && !CoreMemory2 && !CoreMemory3) && galForw ||
                       (CoreMemory1 && !CoreMemory2 && !CoreMemory3) &&
                       galForw) { //All memories locked or 2 and 3 locked
                framesCounter++;
                DrawTexturePro(blank, blankFrame,
                               Rectangle{0, 0, (float) blank.width, (float) blank.height},
                               {}, 0, WHITE);
                if (framesCounter >= (60 / framesSpeed)) {

                    framesCounter = 0;
                    currentFrame++;
                    if (currentFrame > 7) currentFrame = 8;

                    blankFrame.x = (float) (currentFrame / 3) * (float) blank.width / 3;
                    blankFrame.y = (float) (currentFrame % 3) * (float) blank.height / 3;
                }
            }
            break;
    }

}

void Game::GameScreen::drawPreRooms() {
    DrawRectangle(0, 0, 480, 270, BLACK);
    DrawTexturePro(roomTexture, Rectangle{0, 0, (float) roomTexture.width, (float) roomTexture.height},
                   Rectangle{0, 0, (float) roomTexture.width, (float) roomTexture.height},
                   {}, 0, WHITE);
    if (preRoomCounter == 0) {
        if (tutorialUnlocked) {
            DrawTexture(texLevel1Locked, 178, 46, WHITE);
            DrawTexture(texHubDoorClosed, 179, 64, WHITE);
            if (CheckCollisionRecs(player.getCollRec(), preRoomInteracCollision[2])) { // tutorial
                if (hubDoorOpened) {
                    framesCounter++;
                    DrawTexturePro(texHubDoorAnim, hubDoorAnimRec,
                                   Rectangle{107, 64, hubDoorAnimRec.width, hubDoorAnimRec.height},
                                   {}, 0, WHITE);
                    if (framesCounter >= (60 / framesSpeed)) {

                        framesCounter = 0;
                        currentFrame++;

                        if (currentFrame > 2) {
                            currentFrame = 0;
                            hubDoorAnimDone = true;
                        }
                        hubDoorAnimRec.x = (float) currentFrame * (float) texHubDoorAnim.width / 3;
                    }
                }
                DrawTexturePro(galleryInteractionText, Rectangle{0.0f, 0.0f, 42, (float) galleryInteractionText.height},
                               Rectangle{player.getPos().x - 9, player.getPos().y - 23, 42,
                                         (float) galleryInteractionText.height}, {}, 0, WHITE);
            }
        } else if (level1Unlocked) {
            DrawTexture(texTutorialLocked, 106, 46, WHITE);
            DrawTexture(texHubDoorClosed, 107, 64, WHITE);
            if (CheckCollisionRecs(player.getCollRec(), preRoomInteracCollision[0]) && player.compassCollected) { // level
                if (hubDoorOpened) {
                    framesCounter++;
                    DrawTexturePro(texHubDoorAnim, hubDoorAnimRec,
                                   Rectangle{179, 64, hubDoorAnimRec.width, hubDoorAnimRec.height},
                                   {}, 0, WHITE);
                    if (framesCounter >= (60 / framesSpeed)) {

                        framesCounter = 0;
                        currentFrame++;

                        if (currentFrame > 2) {
                            currentFrame = 0;
                            hubDoorAnimDone = true;
                        }
                        hubDoorAnimRec.x = (float) currentFrame * (float) texHubDoorAnim.width / 3;
                    }
                }
                DrawTexturePro(galleryInteractionText, Rectangle{0.0f, 0.0f, 42, (float) galleryInteractionText.height},
                               Rectangle{player.getPos().x - 9, player.getPos().y - 23, 42,
                                         (float) galleryInteractionText.height}, {}, 0, WHITE);
            }
        }
    }
    if (preRoomCounter != 0) {
        if (CheckCollisionRecs(player.getCollRec(), preRoomInteracCollision[0])) { // level
            if (hubDoorOpened) {
                framesCounter++;
                DrawTexturePro(texHubDoorAnim, hubDoorAnimRec,
                               Rectangle{131, 64, hubDoorAnimRec.width, hubDoorAnimRec.height},
                               {}, 0, WHITE);
                if (framesCounter >= (60 / framesSpeed)) {

                    framesCounter = 0;
                    currentFrame++;

                    if (currentFrame > 2) {
                        currentFrame = 0;
                        hubDoorAnimDone = true;
                    }
                    hubDoorAnimRec.x = (float) currentFrame * (float) texHubDoorAnim.width / 3;
                }
            }
            DrawTexturePro(galleryInteractionText, Rectangle{0.0f, 0.0f, 42, (float) galleryInteractionText.height},
                           Rectangle{player.getPos().x - 9, player.getPos().y - 23, 42,
                                     (float) galleryInteractionText.height}, {}, 0, WHITE);
        }
    }
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
    if (preRoomCounter == 0) {
        DrawTexturePro(grandmaFurniture, Rectangle{192, 99, 43, 77}, Rectangle{192, 99, 43, 77}, {}, 0, WHITE);
    }
    if (preRoomCounter == 0 && !tutorialUnlocked) { //Grandma Room
        if (CheckCollisionRecs(player.getCollRec(), npc.interactionBoxNPC)) {  // Compass
            if (IsKeyPressed(KEY_E) && !player.compassCollected) {
                player.compassCollected = true;
                npc.currentFrame = 0;
                npc.frameCounter = 0;
                npc.compassGiven = true;
            }
        }
    }
    if(CheckCollisionRecs(player.getCollRec(), npc.interactionBoxNPC)) {
        DrawTexturePro(galleryInteractionText, Rectangle{0.0f, 0.0f, 42, (float) galleryInteractionText.height},
                       Rectangle{player.getPos().x - 9, player.getPos().y - 23, 42,
                                 (float) galleryInteractionText.height}, {}, 0, WHITE);
    }
    if (CheckCollisionRecs(player.getCollRec(), preRoomInteracCollision[1]) && !tutorialUnlocked) {
        DrawTexturePro(galleryInteractionText, Rectangle{0.0f, 0.0f, 42, (float) galleryInteractionText.height},
                       Rectangle{player.getPos().x - 9, player.getPos().y - 23, 42,
                                 (float) galleryInteractionText.height}, {}, 0, WHITE);
    }
    // Dialogue
    if (dialogueManager.open) {
        switch (preRoomCounter) {
            case 0:
                dialogueManager.drawDialogueBox(preRoomCounter);
                if(tutorialUnlocked) {
                    dialogueManager.drawContinousText(dialogueManager.grannyPreTutorial);
                } else if(!player.compassCollected) {
                    dialogueManager.drawContinousText(dialogueManager.waitForCompass);
                }  else if(player.compassCollected && !compassGiven) {
                    dialogueManager.drawContinousText(dialogueManager.grannyCompass);
                } else if(!CoreMemory1) {
                    dialogueManager.drawContinousText(dialogueManager.grannyPreLevel1);
                } else {
                    dialogueManager.drawContinousText(dialogueManager.grannyAfterLevel1);
                }
                break;
            case 1:
                dialogueManager.drawDialogueBox(preRoomCounter);
                if(!CoreMemory2) {
                    dialogueManager.drawContinousText(dialogueManager.adultPreLevel2);
                } else {
                    dialogueManager.drawContinousText(dialogueManager.adultAfterLevel2);
                }
                break;
            case 2:
                dialogueManager.drawDialogueBox(preRoomCounter);
                if(!CoreMemory3) {
                    dialogueManager.drawContinousText(dialogueManager.teenPreLevel3);
                } else {
                    dialogueManager.drawContinousText(dialogueManager.teenAfterLevel3);
                }
                break;
        }
    }
    /*
    for(auto &f: preRoomInteracCollision) {
        DrawRectangleRec(f, MAGENTA);
    }*/
}

void Game::GameScreen::pauseScreenControls() {
    if ((IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) && (pauseButtonCounter < pauseScreenButtons.size() - 1)) {
        pauseButtonCounter++;
    } else if ((IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) && (pauseButtonCounter > 0)) {
        pauseButtonCounter--;
    }
    if (pauseButtonCounter == 0) { // resume
        if (IsKeyPressed(KEY_ENTER)) {
            gamePaused = false;
        }
    } else if (pauseButtonCounter == 1) { // gallery
        if (IsKeyPressed(KEY_ENTER)) {
            display = 3;
            currentFrame = 0;
            galCounter = 0;
            pauseButtonCounter = 0;
            wasInGame = true;
            hasBeenPlayed = false;
        }
    } else if (pauseButtonCounter == 2) { // menu
        if (IsKeyPressed(KEY_ENTER)) {
            if (!furnitureTextures.empty() && !furnitureCollision.empty() &&
                !interacCollision.empty()) { // Wenn man vom Hub weggeht
                furnitureCollision.clear();
                furnitureTextures.clear();
                interacCollision.clear();
            }
            display = 0;
            delay = 1;
            currentFrame = 0;
            framesCounter = 0;
            pauseButtonCounter = 0;
            hasBeenPlayed = false;
            gamePaused = false;
        }
    }
}

void Game::GameScreen::drawPauseScreen() {
    pauseFrameCounter++;
    if (pauseFrameCounter >= (6 / pauseFrameSpeed)) {

        pauseFrameCounter = 0;
        pauseCurrentFrame++;

        if (pauseCurrentFrame > 51) pauseCurrentFrame = 0;

        pauseScreenRec.x = (float) pauseCurrentFrame * (float) pauseScreen.width / 52;
    }
    DrawTexturePro(pauseScreen, pauseScreenRec,
                   Rectangle{0, 0, pauseScreenRec.width, pauseScreenRec.height},
                   {}, 0, WHITE);
    if (pauseButtonCounter == 0) {
        pauseScreenButtons[0].setPos(168, (int) pauseScreenButtons[0].getPos().y);
        pauseScreenButtons[0].setTexture(texResumeHighlightB);
    } else {
        pauseScreenButtons[0].setPos(175, (int) pauseScreenButtons[0].getPos().y);
        pauseScreenButtons[0].setTexture(texResumeB);
    }
    if (pauseButtonCounter == 1) {
        pauseScreenButtons[1].setTexture(texGalleryHighlightB);
    } else pauseScreenButtons[1].setTexture(texGalleryB);
    if (pauseButtonCounter == 2) {
        pauseScreenButtons[2].setPos(174, (int) pauseScreenButtons[2].getPos().y);
        pauseScreenButtons[2].setTexture(texMenuHighlightB);
    } else {
        pauseScreenButtons[2].setPos(175, (int) pauseScreenButtons[2].getPos().y);
        pauseScreenButtons[2].setTexture(texMenuB);
    }
    DrawTexture(pauseScreenButtons[0].getTexture(), (int) pauseScreenButtons[0].getPos().x, (int) pauseScreenButtons[0].getPos().y, WHITE);
    DrawTexture(pauseScreenButtons[1].getTexture(), (int) pauseScreenButtons[1].getPos().x, (int) pauseScreenButtons[1].getPos().y, WHITE);
    DrawTexture(pauseScreenButtons[2].getTexture(), (int) pauseScreenButtons[2].getPos().x, (int) pauseScreenButtons[2].getPos().y, WHITE);
}

void Game::GameScreen::GameOverControls() {
    if ((IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) && (gameOverCounter < gameOverButtons.size() - 1)) {
        gameOverCounter++;
    } else if ((IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) && (gameOverCounter > 0)) {
        gameOverCounter--;
    }
    if (gameOverCounter== 1 && IsKeyPressed(KEY_ENTER)) { //Return to menu
        display = 0;
        hasBeenPlayed = false;
    }
    if (gameOverCounter== 0 && IsKeyPressed(KEY_ENTER)) { //Restart the level
        clearLevel();
        generateMap();
        hotbarDataLoaded = false;
        display = 1;
        hasBeenPlayed = false;
    }
}

void Game::GameScreen::galControls() {
    if ((IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) && galCounter > 0) {
        galCounter--;
        currentFrame = 0;
        galBackw = true;
        galForw = false;
        //This prevents the animations bugging out on flag change
        b_blankFrame.x = 0;
        b_blankFrame.y = 0;
        b_Mem1No2Frame.x = 0;
        b_Mem1No2Frame.y = 0;
        b_Mem2No3Frame.x = 0;
        b_Mem2No3Frame.y = 0;
        b_Mem1FrameUnl.x = 0;
        b_Mem1FrameUnl.y = 0;
        b_Mem2FrameUnl.x = 0;
        b_Mem2FrameUnl.y = 0;
    }
    if ((IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) && galCounter < 2) {
        galCounter++;
        currentFrame = 0;
        galBackw = false;
        galForw = true;
        //This prevents the animations bugging out on flag change
        blankFrame.x = 0;
        blankFrame.y = 0;
        Mem2FrameUnl.x = 0;
        Mem2FrameUnl.y = 0;
        Mem3FrameUnl.x = 0;
        Mem3FrameUnl.y = 0;
        Mem2FrameL.x = 0;
        Mem2FrameL.y = 0;
        Mem3FrameL.x = 0;
        Mem3FrameL.y = 0;
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
    if (display != 0 && display != 10 && (display != 11 || (display == 11 && cutsceneNumber != 0)))
        StopSound(titleTrack);
    if (display != 1) StopSound(inGameTrack);
    switch (display) {
        case (0):
            // additional Menu Music/Sounds
            if (!IsSoundPlaying(titleTrack)) PlaySound(titleTrack);
            if ((IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) && (counter < menuButtons.size() - 1)) {
                PlaySound(hover);
            } else if ((IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) && (counter > 0)) {
                PlaySound(hover);
            }
            if (IsKeyPressed(KEY_ENTER)) {
                PlaySound(select);
            }
            break;
        case (1):
            // Level Music  and Sounds
            if (!IsSoundPlaying(inGameTrack)) PlaySound(inGameTrack);
            if (!gamePaused) {
                if (!sounds.empty()) sounds.clear();
                if (!IsSoundPlaying(catWalk) && player.moving) {
                    PlaySound(catWalk);
                } else if (!player.moving) {
                    StopSound(catWalk);
                }
                if ((IsKeyDown(KEY_LEFT_CONTROL) || IsKeyDown(KEY_RIGHT_CONTROL)) && !hasBeenPlayed && player.digging &&
                    (player.diggingUp || player.diggingLeft || player.diggingDown || player.diggingRight)) {
                    if (!IsSoundPlaying(dig)) PlaySound(dig);
                    hasBeenPlayed = true;
                }
                if (player.diggingDone == player.lives > 0) {
                    hasBeenPlayed = false;
                }
                if (player.r0l1 == 0 && ((player.idleFrame >= 6 && player.idleFrame <= 25) ||
                                         (player.idleFrame >= 36 && player.idleFrame <= 57))) {
                    if (!IsSoundPlaying(catLick)) {
                        PlaySound(catLick);
                    }
                } else if (player.r0l1 == 1 && ((player.idleFrame >= 38 && player.idleFrame <= 59) ||
                                                (player.idleFrame >= 70 && player.idleFrame <= 90))) {
                    if (!IsSoundPlaying(catLick)) {
                        PlaySound(catLick);
                    }
                } else {
                    StopSound(catLick);
                    if (player.idleFrame >= 96) {
                        if (!IsSoundPlaying(purr)) {
                            PlaySound(purr);
                        }
                    } else {
                        if (IsSoundPlaying(purr)) StopSound(purr);
                    }
                }
                if (IsKeyPressed(KEY_M) && !IsSoundPlaying(meow)) PlaySound(meow);
                if (!tutorialUnlocked) { // door doesn't open in the tutorial
                    if (collected == maxMemories) {
                        if (!levelDoorOpened) {
                            if (!IsSoundPlaying(doorOpen)) PlaySound(doorOpen);
                            for (auto &i: doorList) {
                                if (collected == maxMemories && !levelDoorOpened) {
                                    i.open = true;
                                    i.isOpening = true;
                                } else {
                                    i.open = false;
                                    i.isOpening = false;
                                }
                            }
                            levelDoorOpened = true;
                        }
                    }
                } else {
                    for (auto &i: doorList) {
                        i.open = true;
                    }
                }
                if (playMemorySound) {
                    PlaySound(memoryGathered);
                    playMemorySound = false;
                }
                boulderSound = false;
                for (auto &boulder: boulderList) {
                    if (boulder.falling) {
                        boulderSound = true;
                    }
                }
                if (boulderSound) {
                    if (!IsSoundPlaying(movingBoulder)) {
                        PlaySound(movingBoulder);
                    }
                } else {
                    StopSound(movingBoulder);
                }
                enemySound = false;
                for (auto &mE: mortalList) {
                    if (mE.active) {
                        enemySound = true;
                        break;
                    }
                }
                if (!enemySound) {
                    for (auto &iE: immortalList) {
                        if (iE.active) {
                            enemySound = true;
                            break;
                        }
                    }
                }
                if (enemySound) {
                    if (!IsSoundPlaying(flame)) {
                        PlaySound(flame);
                    }
                } else {
                    StopSound(flame);
                }
            } else {
                if (sounds.empty()) {
                    sounds = {catWalk, dig, catLick, purr, meow, memoryGathered, movingBoulder, flame};
                }
                for (auto &s: sounds) {
                    if (IsSoundPlaying(s)) StopSound(s);
                }
                if ((IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) &&
                    (pauseButtonCounter < pauseScreenButtons.size() - 1)) {
                    PlaySound(hover);
                } else if ((IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) && (pauseButtonCounter > 0)) {
                    PlaySound(hover);
                }
                if (IsKeyPressed(KEY_ENTER)) {
                    PlaySound(select);
                }
            }
            break;
        case (2):
            // Hub Music and Sounds
            if (!IsSoundPlaying(catWalk) && player.moving) {
                PlaySound(catWalk);
            } else if (!player.moving) {
                StopSound(catWalk);
            }
            if (player.idleFrame >= 10) {
                if (!IsSoundPlaying(purr)) {
                    PlaySound(purr);
                }
            } else {
                if (IsSoundPlaying(purr)) StopSound(purr);
            }
            if (IsKeyPressed(KEY_M) && !IsSoundPlaying(meow)) PlaySound(meow);
            if (CheckCollisionRecs(player.getCollRec(), interacCollision[1])) { // Raum 1
                if (!hubDoorOpened) {
                    if (IsKeyPressed(KEY_E)) {
                        if (!IsSoundPlaying(doorOpen)) PlaySound(doorOpen);
                    }
                } else if (CheckCollisionRecs(player.getCollRec(), interacCollision[2])) { // Raum 2
                    if (level2Unlocked) {
                        if (!hubDoorOpened) {
                            if (IsKeyPressed(KEY_E)) {
                                if (!IsSoundPlaying(doorOpen)) PlaySound(doorOpen);
                            }
                        }
                    }
                } else if (CheckCollisionRecs(player.getCollRec(), interacCollision[3])) { // Raum 3
                    if (level3Unlocked) {
                        if (!hubDoorOpened) {
                            if (IsKeyPressed(KEY_E)) {
                                if (!IsSoundPlaying(doorOpen)) PlaySound(doorOpen);
                            }
                        }
                    }
                }
            }
            break;
        case (3):
            // Gallery Music and Sounds
            if (!hasBeenPlayed) {
                PlaySound(openGallery);
                hasBeenPlayed = true;
            }
            if ((IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) && galCounter > 0) {
                PlaySound(galleryFlip);
            }
            if ((IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) && galCounter < 2) {
                PlaySound(galleryFlip);
            }
            break;
        case (4):
            // GameOver Music and Sounds
            if (IsSoundPlaying(flame)) StopSound(flame);
            if (IsSoundPlaying(movingBoulder)) StopSound(movingBoulder);
            break;
        case (5): // NPC Room
            if (!IsSoundPlaying(catWalk) && player.moving) {
                PlaySound(catWalk);
            } else if (!player.moving) {
                StopSound(catWalk);
            }
            if (player.idleFrame >= 10) {
                if (!IsSoundPlaying(purr)) {
                    PlaySound(purr);
                }
            } else {
                if (IsSoundPlaying(purr)) StopSound(purr);
            }
            if (IsKeyPressed(KEY_M) && !IsSoundPlaying(meow)) PlaySound(meow);
            if (CheckCollisionRecs(player.getCollRec(), preRoomInteracCollision[0])) { // Level
                if (preRoomCounter == 0 && !level1Unlocked) {
                    //do nothing
                } else {
                    if(preRoomCounter == 0 && !player.compassCollected) {
                        //do nothing
                    } else {
                        if (!hubDoorOpened) {
                            if (IsKeyPressed(KEY_E)) {
                                if (!IsSoundPlaying(doorOpen)) PlaySound(doorOpen);
                                if (IsSoundPlaying(catWalk)) StopSound(catWalk);
                                if (IsSoundPlaying(purr)) StopSound(purr);
                            }
                        }
                    }
                }
            } else {
                if (preRoomCounter == 0) {
                    if (CheckCollisionRecs(player.getCollRec(), preRoomInteracCollision[2])) { // Tutorial
                        if (tutorialUnlocked) {
                            if (!hubDoorOpened) {
                                if (IsKeyPressed(KEY_E)) {
                                    if (!IsSoundPlaying(doorOpen)) PlaySound(doorOpen);
                                    if (IsSoundPlaying(catWalk)) StopSound(catWalk);
                                    if (IsSoundPlaying(purr)) StopSound(purr);
                                }
                            }
                        }
                    }
                }
            }
            if (CheckCollisionRecs(player.getCollRec(), preRoomInteracCollision[1])) { // Tutorial
                if (IsKeyPressed(KEY_E)) {
                    if (IsSoundPlaying(catWalk)) StopSound(catWalk);
                    if (IsSoundPlaying(purr)) StopSound(purr);
                }
            }
            break;
        case (10):
            // additional StartScreen Music/Sounds
            if (!IsSoundPlaying(titleTrack)) PlaySound(titleTrack);
            if (IsKeyPressed(KEY_SPACE)) PlaySound(select);
            break;
        case (11):
            // additional Cutscene Music/Sounds
            if (cutsceneNumber == 0) {
                if (!IsSoundPlaying(titleTrack)) PlaySound(titleTrack);
            } else if(cutsceneNumber == memoryPasteAnim1 || cutsceneNumber == memoryPasteAnim2 || cutsceneNumber == memoryPasteAnim3) {
                if(!hasBeenPlayed) {
                    if(!IsSoundPlaying(galleryPaste)) PlaySound(galleryPaste);
                    hasBeenPlayed = true;
                }
            }
            break;
    }
}

void Game::GameScreen::ProcessInput() {
    if (IsKeyPressed(KEY_ENTER) && display == 0) { //switch to level
        if (counter == 0) {

            if (tutorialUnlocked) {
                nextDisplay = 5;
                cutsceneNumber = 5;//intro, somehow using the enum or renaming it causes issues und changes some files im not intending to so im not touching that
                display = 11;
                preRoomCounter = 0;
                initializePreRoomElements();
                currentFrame = 0;
                hubDoorOpened = false;
                hubDoorAnimDone = false;
            } else {
                display = 2;
                currentFrame = 0;
                framesCounter = 0;
                initializeHubElements();
                roomCounter = 0;
            }
        }
        if (counter == 1) {
            display = 3;
            drawGallery();
            currentFrame = 0;
            galCounter = 0;
            galForw = true;
            galBackw = false;
        }
        if (counter == 2) {
            CloseWindow();
        }
    } else {
        if (IsKeyPressed(KEY_SPACE) && display == 10) {
            cutsceneManager.drawCutscene(0);
            display = 11;
            nextDisplay = 0;
            delay = 1;
            currentFrame = 0;
        }
    }
    if (display == 1 && player.lives != 0 && IsKeyPressed(KEY_ESCAPE) && !riegelModeOn && !dialogueManager.open) {
        gamePaused = true;
    }
    bool riegelButtonPressed = false;
    if(IsKeyPressed(KEY_B) && display == 1 && player.lives != 0 && !riegelModeOn && !player.moving && !player.digging && !gamePaused) {
        riegelModeOn = true;
        riegelButtonPressed = true;
    }
    if(IsKeyPressed(KEY_B) && display == 1 && player.lives != 0 && riegelModeOn && !riegelButtonPressed && !IsMouseButtonDown(MOUSE_BUTTON_LEFT)) riegelModeOn = false;
    if (display == 3 && wasInGame && IsKeyPressed(KEY_ESCAPE)) {
        display = 1;
        hotbarDataLoaded = false;
        generateMap();
        currentFrame = 0;
        wasInGame = false;
        gamePaused = false;
    }
    if (IsKeyPressed(KEY_ESCAPE) && !wasInHub && display != 1 && display != 10 && display != 11 && !wasInGame && !dialogueManager.open) { //switch to menu
        if (!furnitureTextures.empty() && !furnitureCollision.empty() &&
            !interacCollision.empty()) { // Wenn man vom Hub weggeht
            furnitureCollision.clear();
            furnitureTextures.clear();
            interacCollision.clear();
        }
        display = 0;
        delay = 1;
        currentFrame = 0;
        framesCounter = 0;
        bookAnimDone = false;
    } else if (IsKeyPressed(KEY_ESCAPE) && wasInHub) {
        display = 2;
        initializeHubElements();
        roomCounter = 0;
        wasInHub = false;
        hasBeenPlayed = false;
    }
}

void Game::GameScreen::Update() {
    // Game code here. Interactions etc.
    playMusicAndSounds();
    ProcessInput();
    if (display == 0) { // menu
        menuControls();
    } else if (display == 1) { // level
        if (!gamePaused) {
            if(!riegelModeOn) {
                finalDirtTexture();
                playerInteractions();
                boulderFall();
                canMortalMove();
                canImmortalMove();
            } else RiegelPush();
        } else {
            pauseScreenControls();
        }
        if (!player.active) {
            display = 4;
            hasBeenPlayed = false;
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
    } else if (display == 5) {
        preRoomPlayerInteractions();
    } else if (display != 2 || display != 3) {
        wasInHub = false;
    }
}

void Game::GameScreen::Draw() {
    switch (display) {
        case (0):
            if (levelLoaded) DeloadLevelTextures();
            if (hubLoaded) DeloadHubTextures();
            if (galleryLoaded) DeloadGalleryTextures();
            if (preRoomLoaded) DeloadRoomTextures();
            if (!menuLoaded) {
                LoadMenuTextures();
            }
            drawMenu();
            break;
        case (1):
            if (menuLoaded) DeloadMenuTextures();
            if (hubLoaded) DeloadHubTextures();
            if (galleryLoaded) DeloadGalleryTextures();
            if (preRoomLoaded) DeloadRoomTextures();
            if (!levelLoaded) {
                LoadLevelTextures();
            }
            drawLevel();
            if (gamePaused) {
                drawPauseScreen();
            }
            if (player.compassCollected) {
                drawCompass();
            }
            break;
        case (2):
            if (levelLoaded) DeloadLevelTextures();
            if (menuLoaded) DeloadMenuTextures();
            if (galleryLoaded) DeloadGalleryTextures();
            if (preRoomLoaded) DeloadRoomTextures();
            if (!hubLoaded) {
                LoadHubTextures();
            }
            drawHub();
            break;
        case (3):
            if (levelLoaded) DeloadLevelTextures();
            if (hubLoaded) DeloadHubTextures();
            if (menuLoaded) DeloadMenuTextures();
            if (preRoomLoaded) DeloadRoomTextures();
            if (!galleryLoaded) {
                LoadGalleryTextures();
            }
            drawGallery();
            break;
        case (4):
            if (menuLoaded) DeloadMenuTextures();
            if (hubLoaded) DeloadHubTextures();
            if (galleryLoaded) DeloadGalleryTextures();
            if (preRoomLoaded) DeloadRoomTextures();
            if (!levelLoaded) {
                LoadLevelTextures();
            }
            drawGameOver();
            break;
        case 5:
            if (menuLoaded) DeloadMenuTextures();
            if (levelLoaded) DeloadLevelTextures();
            if (hubLoaded) DeloadHubTextures();
            if (galleryLoaded) DeloadGalleryTextures();
            if (!preRoomLoaded) {
                LoadRoomTextures();
            }
            drawPreRooms();
            if (player.compassCollected) {
                drawCompass();
            }
            break;
        case (10): //unused rn, problems with texture
            if (levelLoaded) DeloadLevelTextures();
            if (hubLoaded) DeloadHubTextures();
            if (galleryLoaded) DeloadGalleryTextures();
            if (preRoomLoaded) DeloadRoomTextures();
            if (!menuLoaded) {
                LoadMenuTextures();
            }
            drawStartScreen();
            break;
        case (11):
            cutsceneManager.drawCutscene(cutsceneNumber);
            if (cutsceneManager.cutsceneDone) {
                display = nextDisplay;
                cutsceneManager.cutsceneDone = false;
                hasBeenPlayed = false;
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
