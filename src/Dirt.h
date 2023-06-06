//
// Created by konst on 18.04.2023.
//

#pragma once
#include "raylib.h"
#include "Sprite.h"

namespace Game {
    struct Dirt : public Sprite{
    public:
        Dirt(int dirtX, int dirtY);

        //Dirt();

        void setPos(int inputX, int inputY);

        Vector2 getPos();

        Texture2D getTexture();

        void setTexture(Texture2D image);

        Rectangle getRectangle();

        void setRectangle(float posX, float posY, float width, float heigth);
    };
}
