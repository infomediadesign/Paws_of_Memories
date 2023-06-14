//
// Created by Nicole on 26.04.2023.
//

// I copied the code from dirt.h and tried to rewrite it according to what the boulder should do.
// I created Boulders in the main file. X and y should be reviewed as I don't know what I am doing. l.47

#pragma once
#include "raylib.h"
#include "Sprite.h"
enum direction{
    FallUp,
    FallDown,
    FallLeft,
    FallRight
};

namespace Game {
    struct Boulder : public Sprite {
    public:
        Boulder(int boulderX, int boulderY);
        int direction;

        //Boulder();

        //Texture2D boulder = LoadTexture("assets/graphics/testimage.png"); //currently same picture that is used in "Dirt.h"
        /*bool destroyed = false;*/ // Commented this bit with hopes of making the boulder indestructible

        bool canBoulderMove(Game::Boulder, Vector2);

        void fall();
    };
}