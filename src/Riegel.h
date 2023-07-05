#pragma once

#include "Sprite.h"

namespace Game {
    class Riegel : public Sprite{
    public:
        Riegel(int posX, int posY);

        void bewegen();

        float target_x = pos.x;
        float target_y = pos.y;
    };
}