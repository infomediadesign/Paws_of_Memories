#pragma once

#include "raylib.h"

namespace Game {
    class Button{
    private:
        Vector2 pos{};
        Texture2D texture{};
    public:
        Button(int valX, int valY, Texture2D texture);

        void setPos(int valX, int valY);
        Vector2 getPos();
        void setTexture(Texture2D newTexture);
        Texture2D getTexture();
    };
}