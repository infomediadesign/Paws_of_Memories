//
// Created by konst on 01.05.2023.
//

#pragma once

#include <memory>
#include <vector>
#include "Screen.h"
#include "Player.h"
#include "Dirt.h"
#include "Boulder.h"
#include "Memories.h"
#include "config.h"
#include "Wall.h"
#include "Button.h"
#include "Door.h"
#include "LevelData.h"
#include "Riegel.h"
#include "Door.h"
#include "Cutscenes.h"

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
        Texture2D gal = LoadTexture("assets/graphics/Animation/Sheets/Gallery/Memory1-sheet.png");
        Rectangle galFrame = {0.0f, 0.0f, (float) gal.width, (float) gal.height};
        Texture2D compass = LoadTexture("assets/graphics/Animation/Sheets/Objects/Compass_received-Sheet.png");
        Rectangle compassRec = {0.0f, 0.0f, (float) compass.width/6, (float) compass.height/3};
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
        Font testFont = LoadFont("assets/graphics/Text/Fonts/Zeldadx.fon");

        Game::Button logoB {Game::ScreenWidth/3-20, Game::ScreenHeight/9, logo};
        Game::Button startB {Game::ScreenWidth/3+6, Game::ScreenHeight/9*5, start};
        Game::Button galleryB {Game::ScreenWidth/3, Game::ScreenHeight/9*6, gallery};
        Game::Button exitB {Game::ScreenWidth/3-1, Game::ScreenHeight/9*7, exit};

        std::vector<Button> menuButtons = {startB, galleryB, exitB};
        int counter;

        Texture2D hub = LoadTexture("assets/graphics/Background/Home screen backgrounds new/Start Screen background 2.png");

        LevelData levelData;
        int *levelLayout;

        Cutscenes cutsceneManager;

        void readLevelData();

        GameScreen();

        void LoadTextures();

        void InitPlayer(int valueX, int valueY);

        void generateMap(); //use LevelData for this

        void playerInteractions();

        void RiegelPush();

        void boulderFall();

        void clearLevel();

        void drawCompass();

        void drawLevel();

        void drawStartScreen(); //problems with texture?

        void drawMenu();

        void drawHub();

        void drawGallery();

        void galControls();

        void menuControls();

        void canPlayerMove();

        void canRiegelMove();

        void finalDirtTexture();

        void hubPlayerInteractions();

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

        float rScale;
    };
}