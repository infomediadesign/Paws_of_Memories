//
// Created by konst on 18.04.2023.
//

#pragma once
#include "raylib.h"
#include "../Sprite.h"

namespace Game {
    struct Dirt : public Sprite{
    public:
        Dirt(int dirtX, int dirtY);

        bool upClear = false;
        bool leftClear = false;
        bool downClear = false;
        bool rightClear = false;

        bool vanished = false;
        int frameSpeed = 1;
        int frameCounter = 0;
        int currentFrame = 0;

        Rectangle frameRec_dirtT{};

        Rectangle adjRecUp{};
        Rectangle adjRecLeft{};
        Rectangle adjRecDown{};
        Rectangle adjRecRight{};

        Rectangle getadjRecUp();
        Rectangle getadjRecLeft();
        Rectangle getadjRecDown();
        Rectangle getadjRecRight();
        void vanishAnimation();
    };
}
