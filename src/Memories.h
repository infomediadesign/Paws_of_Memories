//
// Created by Nicole on 28.04.2023.
//
// I copied the code from Dirt.h and changed it accordingly

#include "raylib.h"

#ifndef RAYLIBSTARTER_MEMORIES_H
#define RAYLIBSTARTER_MEMORIES_H

#endif //RAYLIBSTARTER_MEMORIES_H

namespace Game {
    struct Memory {
    public:
        Memory(int memoryX, int memoryY);

        //Memory();

        Vector2 pos = {0, 0};
        Texture2D memory = LoadTexture("assets/graphics/testimage.png"); //Image needs to be defined
        bool collected = false; //swapped "destroyed" for "collected", because we will probably differentiate these functions

        void setPos(int inputX, int inputY);

        Vector2 getPos();

        Texture2D getTexture();

        void setTexture(Texture2D image);
    };
}
