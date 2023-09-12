#pragma once
#include "Enemy.h"

namespace game {
    class ImmortalEnemy : public Game::Enemy {
    public:
        ImmortalEnemy(int posX, int posY);
        void move() override;
        void updateEnemy() override;
        void moveAnimation() override;
        void idleAnimation() override;
        void huntPlayer() override;
        void drawEnemy() override;

        bool hasEaten = false;
        bool mortalGenerated = false;
        int struggle = 0;

        //Textures
        Texture2D texIdle;
        Texture2D texUp;
        Texture2D texLeft;
        Texture2D texDown;
        Texture2D texRight;

        //FrameRecs
        Rectangle recIdle;
        Rectangle recUp;
        Rectangle recLeft;
        Rectangle recDown;
        Rectangle recRight;
    };
}