#pragma once

#include "../Sprite.h"

namespace Game {
    class Enemy : public Sprite {
    public:
        virtual void move() = 0;
        virtual void updateEnemy() = 0;
        virtual void moveAnimation() = 0;
        virtual void idleAnimation() = 0;
    };
}