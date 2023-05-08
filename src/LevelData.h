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
        Vector2 playerStartPos();
        int levelLayout[(Game::ScreenHeight / 48) - 1][(Game::ScreenWidth / 48)] = {};

        int currentLevel[12] = {1,2,3,4,5,6,7,8,9,10,11,12};

        void setSpawn();
        void createLevelLayout();

    };
}