#pragma once

#include "../Sprite.h"

namespace Game {
    class Riegel : public Sprite {
    public:
        enum directionR{
            Waagerecht,
            Senkrecht
        };
        Riegel(int posX, int posY, int dir);

        float renderScale = 1;

        void move();

        void ColUpdate();

        void PlaceUpdate();

        void drawRiegel();

        //void MoveOnlyOne();

        int directionR;
        int size = 1;
        bool moving;

        float ymove = 0;
        float xmove = 0;

        bool WriegelCanMove = true;
        bool SriegelCanMove = true;

    };
}