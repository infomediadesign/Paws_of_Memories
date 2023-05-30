//
// Created by konst on 02.05.2023.
//

#include "raylib.h"
#include "config.h"

#ifndef RAYLIBSTARTER_LEVELDATA_H
#define RAYLIBSTARTER_LEVELDATA_H
#endif //RAYLIBSTARTER_LEVELDATA_H

namespace Game {
    struct LevelData {
    public:
        LevelData();
        Vector2 playerStartPos;
        //int levelLayout[(Game::ScreenHeight / 48) - 1 + (Game::ScreenWidth / 48)] = {};

        // original level will never be changed (for resetting the game, the original level layout
        // current level will be overwritten for the save files (level progress etc.)
        int originalLevel[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
        int currentLevel[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
        // which level was the player in before after saving/quitting
        int lastLevel;

        void setSpawn();
        int * returnLevelLayout(int);
        void updateLevelLayout(int);
    };
}