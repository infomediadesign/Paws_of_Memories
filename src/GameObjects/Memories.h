//
// Created by Nicole on 28.04.2023.
//
// I copied the code from Dirt.h and changed it accordingly

#pragma once
#include "raylib.h"

#include "../Sprite.h"

namespace Game {
    struct Memory : public Sprite {
    public:
        Memory(int memoryX, int memoryY);

        bool collected = false; //swapped "destroyed" for "collected", because we will probably differentiate these functions
    };
}
