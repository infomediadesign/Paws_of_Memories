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
        float mouseOffsetX;
        float mouseOffsetY;
        bool selected = false;

        Vector2 trueMouse;

        void move();

        void ColUpdate();

        void drawRiegel();

        int directionR;
        int size = 1;
        bool moving;
    };
}