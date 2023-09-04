#pragma once

#include "../Sprite.h"

namespace Game {
    class Riegel : public Sprite {
    public:
        Riegel(int posX, int posY);

        float renderScale = 1;

        void move();

        void ColUpdate();

        void PlaceUpdate();

        //void MoveOnlyOne();

        float ymove = 0;
        float xmove = 0;

        bool WriegelCanMove = true;
        bool SriegelCanMove = true;

    };
}