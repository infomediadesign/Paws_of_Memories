#pragma once
#include "raylib.h"
#include "../Sprite.h"
enum direction{
    FallUp,
    FallDown,
    FallLeft,
    FallRight
};

namespace Game {
    struct Boulder : public Sprite {
    public:
        Boulder(int boulderX, int boulderY, int dir);
        int direction;
        int frameSpeed = 1;
        int frameCounter = 0;
        int currentFrame = 0;

        Rectangle frameRec_Boulder = {0, 0, 0, 0};

        void updateBoulder();
        void fall();
        void drawBoulder();
    };
}