//
// Created by konst on 01.05.2023.
//

#pragma once

#include <memory>
#include "Screen.h"
#include "Player.h"
#include "Dirt.h"
#include "Boulder.h"
#include "Memories.h"
#include "config.h"

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
        int tiles[(Game::ScreenHeight / 24) - 1][(Game::ScreenWidth / 24)];
        std::shared_ptr<Game::Player> player;
        std::shared_ptr<Game::Dirt> dirt;
        std::shared_ptr<Game::Memory> memory;
        Texture2D wall1;
        Texture2D wall2;
        Texture2D wall3;
        std::shared_ptr<Game::Boulder> boulder;

        GameScreen();

        void LoadTextures(); //necessary?

        void InitPlayer(); //use LevelData for this?

        void generateMap(); //use LevelData for this?
    public:
        /*static Screen *getInstance() {
            static GameScreen instance;
            return &instance;
        }*/

        GameScreen(GameScreen const &) = delete;

        void operator=(GameScreen const &) = delete;

        ~GameScreen();

        //void ProcessInput() override;

        //void Update() override;

        //void Draw() override;

    };
}