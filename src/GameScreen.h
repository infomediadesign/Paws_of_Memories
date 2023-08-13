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
#include "GameObjects/NPC.h"

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

        bool menuLoaded = false;
        bool levelLoaded = false;
        bool hubLoaded = false;
        bool galleryLoaded = false;

        Texture2D dirtT;
        Texture2D dirtVanishAnim;
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

        Texture2D background;
        Rectangle backgroundFrame;
        Texture2D logo;
        Rectangle logoFrame;
        Texture2D CoreMem1;
        Rectangle Mem1Frame;
        Texture2D CoreMem2;
        Rectangle Mem2Frame;
        Texture2D CoreMem3;
        Rectangle Mem3Frame;
        Texture2D compass;
        Rectangle compassRec;
        Texture2D GameOver;
        Rectangle GameOverFrame;

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
        int backgroundDelay = 0;
        int mortalStruggle = 0;

        // sth is wrong with the texture, ot the way our animations work
        Texture2D startScreen;
        Rectangle startScreenRec;


        Texture2D menu;
        Texture2D start;
        Texture2D startH;
        Texture2D gallery;
        Texture2D galleryH;
        Texture2D exit;
        Texture2D exitH;

        Game::Button logoB = {Game::ScreenWidth/3-20, Game::ScreenHeight/9, {}};
        Game::Button startB = {Game::ScreenWidth/3+6, Game::ScreenHeight/9*5, {}};
        Game::Button galleryB = {Game::ScreenWidth/3, Game::ScreenHeight/9*6, {}};
        Game::Button exitB = {Game::ScreenWidth/3-1, Game::ScreenHeight/9*7, {}};

        std::vector<Button> menuButtons = {startB, galleryB, exitB};
        int counter;

        Texture2D hub;
        Texture2D hubFurniture;
        Rectangle texPlantTop; // Der Teil, der über der Katze ist.
        Rectangle texChairLamp;  // Der Teil, der über der Katze ist.
        Rectangle texTable;  // Der Teil, der über der Katze ist.
        Rectangle texBox;  // Der Teil, der über der Katze ist.
        Rectangle texCatTree;  // Der Teil, der über der Katze ist.
        //Rectangle texTable2; //if necessary
        //Rectangle texShelf; // If secret room is desired
        std::vector<Rectangle> furnitureTextures;
        Texture2D galleryInteractionText;
        Texture2D bookOutline;
        Texture2D bookAnimation;
        Rectangle bookFrameRec;
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

        Texture2D hotbar;
        Texture2D hotbarLevel;
        Texture2D hotbarArea;
        bool hotbarDataLoaded = false;

        NPC npc;

        LevelData levelData;
        int *levelLayout;

        Cutscenes cutsceneManager;
        Dialogues dialogueManager;

        Sound titleTrack;
        std::vector<Sound> musicTracks = {titleTrack};
        std::vector<Sound> sounds = {};

        void readLevelData();

        GameScreen();

        void LoadMenuTextures();
        void LoadLevelTextures();
        void LoadHubTextures();
        void LoadGalleryTextures();
        //void LoadRoomTextures();
        void DeloadMenuTextures();
        void DeloadLevelTextures();
        void DeloadHubTextures();
        void DeloadGalleryTextures();
        //void DeloadRoomTextures();

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