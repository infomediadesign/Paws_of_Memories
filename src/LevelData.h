//
// Created by konst on 02.05.2023.
//

#pragma once

#include <string>
#include <vector>
#include "raylib.h"
#include "config.h"

enum level{
    Hub,
    level1Raum1,
    level1Raum2,
    level1Raum3,
    level1Raum4,
    level2Raum1,
    level2Raum2,
    level2Raum3,
    level2Raum4,
    level3Raum1,
    level3Raum2,
    level3Raum3,
    level3Raum4,
};

namespace Game {
    struct LevelData {
    public:
        LevelData();
        int levelLayout[((Game::ScreenHeight / 24) - 1)*((Game::ScreenWidth / 24))];
        int tileCounter = 0;
        std::vector<std::string> fileNames = {"assets/maps/TestLevel.tmj","assets/maps/Level_1.1.tmj"};
        std::vector<std::string> tilesets = {};
        int currentLevel;

        void createLevel(std::string levelFile); // give the level, create the levelLayout
        int * returnLevelLayout(); //this is supposed to return the level as an array
    };
}