//
// Created by konst on 02.05.2023.
//

#pragma once

#include <string>
#include <vector>
#include "raylib.h"
#include "config.h"

namespace Game {
    struct LevelData {
    public:
        LevelData();
        int levelLayout[((Game::ScreenHeight / 24) - 1)*((Game::ScreenWidth / 24))];
        int tileCounter = 0;
        std::vector<std::string> fileNames = {"assets/maps/level/level_0_1.tmj", "assets/maps/level/level_0_2.tmj", "assets/maps/level/level_0_3.tmj", "assets/maps/level/level_1_1.tmj", "assets/maps/level/level_1_2.tmj", "assets/maps/level/level_1_3.tmj", "assets/maps/level/level_2_1.tmj", "assets/maps/level/level_2_2.tmj", "assets/maps/level/level_2_3.tmj", "assets/maps/level/level_3_1.tmj", "assets/maps/level/level_3_2.tmj", "assets/maps/level/level_3_3.tmj"};

        void createLevel(std::string levelFile); // give the level, create the levelLayout
        int * returnLevelLayout(); //this is supposed to return the level as an array
    };
}