#pragma once

#include "Sprite.h"

namespace Game {
    class Riegel : public Sprite{
    public:
        Riegel(int posX, int posY);


        float renderScale = 1;
        void move();

        float target_x = pos.x;
        float target_y = pos.y;

        bool twoRiegleMove;
        bool canMove = true;
    };
}