//
// Created by Nicole on 26.04.2023.
//

// I copied the code from dirt.h and tried to rewrite it according to what the boulder should do.
// I created Boulders in the main file. X and y should be reviewed as I don't know what I am doing. l.47

#pragma once
#include "raylib.h"
#include "Sprite.h"

namespace Game {
    struct Boulder : public Sprite {
    public:
        Boulder(int boulderX, int boulderY); //never used??

        //Boulder();

        //Texture2D boulder = LoadTexture("assets/graphics/testimage.png"); //currently same picture that is used in "Dirt.h"
        /*bool destroyed = false;*/ // Commented this bit with hopes of making the boulder indestructible

        void setPos(int inputX, int inputY);

        Vector2 getPos();

        Texture2D getTexture();

        void setTexture(Texture2D image);

        bool canBoulderMove(Game::Boulder, Vector2);

        //void fall();
    };
}