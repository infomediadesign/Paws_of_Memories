#pragma once

#include "Enemy.h"

namespace game {
    class MortalEnemy : public Game::Enemy {
    public:
        MortalEnemy(int posX, int posY);
        void move() override;
        void updateEnemy() override;
        void moveAnimation() override;
        void idleAnimation() override;
        void huntPlayer() override;
        void deathAnimation();
        void drawEnemy() override;

        bool dead = false;
        bool deathAnimDone = false;
        bool memoryGenerated = false;
        int struggle = 0;
        //Textures
        Texture2D texDeath;
        Texture2D texIdle;
        Texture2D texUp;
        Texture2D texLeft;
        Texture2D texDown;
        Texture2D texRight;

        //FrameRecs
        Rectangle recDeath;
        Rectangle recIdle;
        Rectangle recUp;
        Rectangle recLeft;
        Rectangle recDown;
        Rectangle recRight;
    };
}