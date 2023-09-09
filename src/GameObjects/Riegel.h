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

        Rectangle adjDetection1 = {}; //oben/links
        Rectangle adjDetection2 = {}; //unten/rechts

        int originalX;
        int originalY;
        bool selected = false;

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