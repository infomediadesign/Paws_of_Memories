//
// Created by Nicole on 26.04.2023.
//


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