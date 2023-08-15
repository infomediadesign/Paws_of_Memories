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
        Texture2D texIdle = LoadTexture("assets/graphics/Animation/Sheets/Enemies/Enemy_2_(Indestructible)/Purple (Final)/Idle_Animation-Sheet.png");
        Texture2D texUp = LoadTexture("assets/graphics/Animation/Sheets/Enemies/Enemy_2_(Indestructible)/Purple (Final)/Movement_back-Sheet.png");
        Texture2D texLeft = LoadTexture("assets/graphics/Animation/Sheets/Enemies/Enemy_2_(Indestructible)/Purple (Final)/Movement_left-Sheet.png");
        Texture2D texDown = LoadTexture("assets/graphics/Animation/Sheets/Enemies/Enemy_2_(Indestructible)/Purple (Final)/Movement_front-Sheet.png");
        Texture2D texRight = LoadTexture("assets/graphics/Animation/Sheets/Enemies/Enemy_2_(Indestructible)/Purple (Final)/Movement_right-Sheet.png");

        //FrameRecs
        Rectangle recIdle = {0, 0, (float) texIdle.width / 9, (float) texIdle.height};
        Rectangle recUp = {0, 0, (float) texUp.width / 9, (float) texUp.height};
        Rectangle recLeft = {0, 0, (float) texLeft.width / 9, (float) texLeft.height};
        Rectangle recDown = {0, 0, (float) texDown.width / 9, (float) texDown.height};
        Rectangle recRight = {0, 0, (float) texRight.width / 9, (float) texRight.height};
    };
}