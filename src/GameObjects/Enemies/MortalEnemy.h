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
        //Textures
        Texture2D texDeath = LoadTexture("assets/graphics/Animation/Sheets/Enemies/Enemy_1_(Destructible)/Defeated_Animation-Sheet.png");
        Texture2D texIdle = LoadTexture("assets/graphics/Animation/Sheets/Enemies/Enemy_1_(Destructible)/Idle_animation-Sheet.png");
        Texture2D texUp = LoadTexture("assets/graphics/Animation/Sheets/Enemies/Enemy_1_(Destructible)/Movement_back-Sheet.png");
        Texture2D texLeft = LoadTexture("assets/graphics/Animation/Sheets/Enemies/Enemy_1_(Destructible)/Movement_left-Sheet.png");
        Texture2D texDown = LoadTexture("assets/graphics/Animation/Sheets/Enemies/Enemy_1_(Destructible)/Movement_front-Sheet.png");
        Texture2D texRight = LoadTexture("assets/graphics/Animation/Sheets/Enemies/Enemy_1_(Destructible)/Movement_right-Sheet.png");

        //FrameRecs
        Rectangle recDeath = {0, 0, (float) texDeath.width / 6, (float) texDeath.height};
        Rectangle recIdle = {0, 0, (float) texIdle.width / 9, (float) texIdle.height};
        Rectangle recUp = {0, 0, (float) texUp.width / 9, (float) texUp.height};
        Rectangle recLeft = {0, 0, (float) texLeft.width / 9, (float) texLeft.height};
        Rectangle recDown = {0, 0, (float) texDown.width / 9, (float) texDown.height};
        Rectangle recRight = {0, 0, (float) texRight.width / 9, (float) texRight.height};
    };
}