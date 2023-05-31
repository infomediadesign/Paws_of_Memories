//
// Created by konst on 18.04.2023.
//

#pragma once
#include "raylib.h"

namespace Game {
    struct Dirt {
    public:
        Dirt(int dirtX, int dirtY);

        //Dirt();

        Vector2 pos = {0, 0};
        Texture2D dirt = LoadTexture("assets/graphics/testimage.png");
        bool destroyed = false;

        void setPos(int inputX, int inputY);

        Vector2 getPos();

        Texture2D getTexture();

        void setTexture(Texture2D image);
    };
}
