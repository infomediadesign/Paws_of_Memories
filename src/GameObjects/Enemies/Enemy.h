#pragma once

#include "../../Sprite.h"

namespace Game {
    class Enemy : public Sprite {
    public:
        virtual void move() = 0;
        virtual void updateEnemy() = 0;
        virtual void moveAnimation() = 0;
        virtual void idleAnimation() = 0;
        virtual void huntPlayer() = 0;
        virtual void drawEnemy() = 0;
        float moveSpeed = 1;
        bool destructable = false;
        int direction = 0;
        bool playerDetected = false;
        int framesCounter = 0;
        int framesSpeed = 1;
        int currentFrame = 0;

        enum direction {
            idle,
            moveUp,
            moveLeft,
            moveDown,
            moveRight
        };
    };
}