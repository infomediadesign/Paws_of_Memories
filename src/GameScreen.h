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

namespace Game {
    class GameScreen  : public Screen{
    private:
        //int tiles[(Game::ScreenHeight / 24) - 1 + (Game::ScreenWidth / 24)]; make a function that defines this? for level creation
        Player player;
        std::vector<Dirt> dirtList;
        std::vector<Memory> memoryList;
        std::vector<Boulder> boulderList;
        std::vector<Wall> wallList;

        Texture2D dirtT;
        Rectangle frameRec_dirtT;
        Texture2D memories;
        Rectangle frameRec_Memories;
        Texture2D boulder;
        Rectangle frameRec_Boulder;
        Texture2D crackedWall;
        Texture2D wall2;
        Texture2D wall3;
        Rectangle frameRec_Wall;

        Texture2D background = LoadTexture("assets/graphics/Animation/Sheets/Background/Background Animation - mit Color Palette.png");
        Rectangle backgroundFrame = {0.0f, 0.0f, (float) background.width / 11, (float) background.height};
        int collected = 0;

        GameScreen();

        void LoadTextures(); //necessary?

        void InitPlayer(int valueX, int valueY); //use LevelData for this?

        void generateMap(); //use LevelData for this?
    public:
        static Screen *getInstance() {
            static GameScreen instance;
            return &instance;
        }

        ~GameScreen();

        void ProcessInput() override;

        void Update() override;

        void Draw() override;

    };
}