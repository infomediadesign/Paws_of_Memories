//
// Created by konst on 01.05.2023.
//

#pragma once

#include <memory>
#include <vector>
#include "Screen.h"
#include "GameObjects/Player.h"
#include "GameObjects/Dirt.h"
#include "GameObjects/Boulder.h"
#include "GameObjects/Memories.h"
#include "config.h"
#include "GameObjects/Wall.h"
#include "Button.h"
#include "GameObjects/Door.h"
#include "LevelData.h"
#include "GameObjects/Riegel.h"
#include "GameObjects/Door.h"
#include "Cutscenes.h"
#include "GameObjects/Enemies/MortalEnemy.h"
#include "GameObjects/Enemies/ImmortalEnemy.h"
#include "Dialogues.h"

/*
 * This class is supposed to deal with all interactions.
 * It also loads in all necessary objects
 * It should:
 *  --> Initiate the level layout (player, dirt...)
 *  --> Deal with the Gameplay (collisions...)
 *  --> Update the screen (graphics...)
 *
 *
 *
 */

/*
enum display {
    startScreen,
    menuScreen,
    levelScreen,
    hubScreen,
    pauseScreen,
    deathScreen,
    optionsScreen,
    cutsceneScreen,
    galleryScreen
};*/

namespace Game {

    class GameScreen  : public Screen{
    private:
        int display = 10;
        int nextDisplay = 10;
        //int tiles[(Game::ScreenHeight / 24) - 1 + (Game::ScreenWidth / 24)]; make a function that defines this? for level creation
        Player player;
        std::vector<Dirt> dirtList;
        std::vector<Memory> memoryList;
        std::vector<Boulder> boulderList;
        std::vector<Wall> wallList;
        std::vector<Door> doorList;
        std::vector<Riegel> riegelList;
        std::vector<game::MortalEnemy> mortalList;
        std::vector<game::ImmortalEnemy> immortalList;

        Texture2D dirtT;
        Texture2D memories;
        Texture2D boulder_down;
        Texture2D boulder_up;
        Texture2D boulder_left;
        Texture2D boulder_right;
        Texture2D crackedWall;
        Texture2D wall2;
        Texture2D wall3;
        Texture2D riegel;
        Texture2D door;
        Rectangle frameRec_Wall;
        Rectangle frameRec_Boulder;
        Rectangle frameRec_Memories;
        Rectangle frameRec_Riegel;
        Rectangle frameRec_Door;

        Texture2D background = LoadTexture("assets/graphics/Animation/Sheets/Background/Background Animation - mit Color Palette.png");
        Rectangle backgroundFrame = {0.0f, 0.0f, (float) background.width / 11, (float) background.height};
        Texture2D logo = LoadTexture("assets/graphics/Animation/Sheets/Logo/Logo-Sheet.png");
        Rectangle logoFrame = {0.0f, 0.0f, (float) logo.width / 9, (float ) logo.height};
        Texture2D CoreMem1 = LoadTexture("assets/graphics/Animation/Sheets/Gallery/Memory1-sheet.png");
        Rectangle Mem1Frame = {0.0f, 0.0f, (float) CoreMem1.width, (float) CoreMem1.height};
        Texture2D CoreMem2 = LoadTexture("assets/graphics/Animation/Sheets/Gallery/Memory2-sheet.png");
        Rectangle Mem2Frame = {0.0f, 0.0f, (float) CoreMem2.width, (float) CoreMem2.height};
        Texture2D CoreMem3 = LoadTexture("assets/graphics/Animation/Sheets/Gallery/Memory3-Sheet.png");
        Rectangle Mem3Frame = {0.0f, 0.0f, (float) CoreMem3.width, (float) CoreMem3.height};
        Texture2D compass = LoadTexture("assets/graphics/Animation/Sheets/Objects/Compass_received-Sheet.png");
        Rectangle compassRec = {0.0f, 0.0f, (float) compass.width/6, (float) compass.height/3};
        Texture2D GameOver = LoadTexture("assets/graphics/Animation/Sheets/Screens/GameOver_Screen-Sheet.png");
        Rectangle GameOverFrame= {0.0f, 0.0f, (float) GameOver.width/2, (float) GameOver.height};

        int compassFrame = 0;
        int compassCounter = 0;

        int delay = 0;
        int currentFrame = 0;
        int framesCounter = 0;
        int framesSpeed = 10;
        int collected = 0;
        int roomCounter = 0;
        int cutsceneNumber = 0;
        int galCounter = 0;
        int deathDelay = 0;

        // sth is wrong with the texture, ot the way our animations work
        Texture2D startScreen = LoadTexture("assets/graphics/Animation/Sheets/Background/Startscreen/Start_Screen_idle_animation-Sheet.png");
        Rectangle startScreenRec = {0.0f, 0.0f, (float) startScreen.width / 59, (float) startScreen.height};


        Texture2D menu = LoadTexture("assets/graphics/Background/Home screen backgrounds new/Start Screen background.png");
        Texture2D start = LoadTexture("assets/graphics/Text/Start Game.png");
        Texture2D startH = LoadTexture("assets/graphics/Text/Start Game- Highlight.png");
        Texture2D gallery = LoadTexture("assets/graphics/Text/Gallery.png");
        Texture2D galleryH = LoadTexture("assets/graphics/Text/Gallery - Highlight.png");
        Texture2D exit = LoadTexture("assets/graphics/Text/Exit Game.png");
        Texture2D exitH = LoadTexture("assets/graphics/Text/Exit Game - Highlight.png");

        Game::Button logoB {Game::ScreenWidth/3-20, Game::ScreenHeight/9, logo};
        Game::Button startB {Game::ScreenWidth/3+6, Game::ScreenHeight/9*5, start};
        Game::Button galleryB {Game::ScreenWidth/3, Game::ScreenHeight/9*6, gallery};
        Game::Button exitB {Game::ScreenWidth/3-1, Game::ScreenHeight/9*7, exit};

        std::vector<Button> menuButtons = {startB, galleryB, exitB};
        int counter;

        Texture2D hub = LoadTexture("assets/graphics/Background/HUB/hub1.png");
        Texture2D hubFurniture = LoadTexture("assets/graphics/Background/HUB/hub_moebel_2.png");
        Rectangle texPlantTop; // Der Teil, der über der Katze ist.
        Rectangle texChairLamp;  // Der Teil, der über der Katze ist.
        Rectangle texTable;  // Der Teil, der über der Katze ist.
        Rectangle texBox;  // Der Teil, der über der Katze ist.
        Rectangle texCatTree;  // Der Teil, der über der Katze ist.
        //Rectangle texTable2; //if necessary
        //Rectangle texShelf; // If secret room is desired
        std::vector<Rectangle> furnitureTextures;
        Texture2D galleryInteractionText = LoadTexture("assets/graphics/Background/HUB/Gallery Book/Book text.png");
        Texture2D bookOutline = LoadTexture("assets/graphics/Background/HUB/Gallery Book/Book_outline.png");
        Texture2D bookAnimation = LoadTexture("assets/graphics/Background/HUB/Gallery Book/Book_animation.png");
        Rectangle bookFrameRec = {0.0f, 0.0f, (float) bookAnimation.width/7, (float) bookAnimation.height};
        bool bookAnim = false;
        bool bookAnimDone = false;

        Rectangle tableBook;
        Rectangle chair1;
        Rectangle lamp;
        Rectangle chair2;
        Rectangle plant;
        Rectangle table2;
        Rectangle box;
        Rectangle clock;
        Rectangle shelf;
        std::vector<Rectangle> furnitureCollision;

        Rectangle galleryInterac;
        Rectangle doorInterac1;
        Rectangle doorInterac2;
        Rectangle doorInterac3;
        std::vector<Rectangle> interacCollision;


        Texture2D hotbar = LoadTexture("assets/graphics/Other/Hotbar/Hotbar.png");
        Texture2D hotbarLevel;
        Texture2D hotbarArea;
        bool hotbarDataLoaded = false;

        LevelData levelData;
        int *levelLayout;

        Cutscenes cutsceneManager;
        Dialogues dialogueManager;

        void readLevelData();

        GameScreen();

        void LoadTextures();

        void InitPlayer(int valueX, int valueY);

        void generateMap(); //use LevelData for this

        void playerInteractions();

        void RiegelPush();

        void boulderFall();

        void canMortalMove();
        void canImmortalMove();

        void clearLevel();

        void drawCompass();

        void drawLevel();

        void drawStartScreen(); //problems with texture?

        void drawMenu();

        void drawHub();

        void drawGallery();

        void drawGameOver();

        void galControls();

        void menuControls();

        void GameOverControls();

        void canPlayerMove();

        void canRiegelMove();

        void finalDirtTexture();

        void hubPlayerInteractions();

        void hubCanPlayerMove();

        void initializeHubElements();

    public:
        static Screen *getInstance() {
            static GameScreen instance;
            return &instance;
        }

        ~GameScreen();

        void ProcessInput() override;

        void Update() override;

        void Draw() override;

        void setRScale(float) override;

        bool close = false;

        bool CoreMemory1 = true;
        bool CoreMemory2 = true;
        bool CoreMemory3 = true;

        float rScale;
    };
}