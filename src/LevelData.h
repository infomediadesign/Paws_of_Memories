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
        std::vector<std::string> fileNames = {"assets/maps/test_level_tabea.tmj","assets/maps/Level 1.1.tmj", "assets/maps/structure/level_1_1.tmj", "assets/maps/structure/level_1_2_trash.tmj", "assets/maps/structure/level_1_3_trash.tmj", "assets/maps/structure/level_2_1_trash.tmj", "assets/maps/structure/level_2_2_trash.tmj", "assets/maps/structure/level_2_3_trash.tmj", "assets/maps/structure/level_3_1_trash.tmj", "assets/maps/structure/level_3_2_trash.tmj", "assets/maps/structure/level_3_3_trash.tmj"};
        // new one
        //std::vector<std::string> fileNames = {"assets/maps/structure/level_1_1.tmj", "assets/maps/structure/level_1_2_trash.tmj", "assets/maps/structure/level_1_3_trash.tmj", "assets/maps/structure/level_2_1_trash.tmj", "assets/maps/structure/level_2_2_trash.tmj", "assets/maps/structure/level_2_3_trash.tmj", "assets/maps/structure/level_3_1_trash.tmj", "assets/maps/structure/level_3_2_trash.tmj", "assets/maps/structure/level_3_3_trash.tmj"};
        // not needed
        //std::vector<std::string> tilesets = {};

        void createLevel(std::string levelFile); // give the level, create the levelLayout
        int * returnLevelLayout(); //this is supposed to return the level as an array
    };
}