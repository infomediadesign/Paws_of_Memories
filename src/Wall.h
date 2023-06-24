#pragma once

#include "Sprite.h"

namespace Game {
    class Wall : public Sprite{
    public:
        Wall(int posX, int posY);
        Texture2D crackedWall = LoadTexture("assets/graphics/Template/Wall_and_Door/Cracked_Wall_1.png");
        Texture2D wall2 = LoadTexture("assets/graphics/Template/Wall_and_Door/wall_2.png");
        Texture2D wall3 = LoadTexture("assets/graphics/Template/Wall_and_Door/wall_3.png");
    };
}