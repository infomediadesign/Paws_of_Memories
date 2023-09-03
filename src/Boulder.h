#pragma once
#include "raylib.h"
#include "Sprite.h"
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
        void updateBoulder();
        int direction;
        void fall();
    };
}