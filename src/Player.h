//
// Created by konst on 21.04.2023.
//

#include "raylib.h"

#ifndef RAYLIBSTARTER_PLAYER_H
#define RAYLIBSTARTER_PLAYER_H

#endif //RAYLIBSTARTER_PLAYER_H

namespace Game {
    struct Player {
    public:

        Player(int playerX, int playerY);
        Vector2 pos_pl = {48.0f, 108.0f}; //changed this so player doesn't slide up

        Texture2D player;
        Texture2D player_idleLeft = LoadTexture("assets/graphics/Animation/Sheets/Cat/idle/Idle left/idle_animation_left_paw_down-Sheet.png");
        Texture2D player_idleRight = LoadTexture("assets/graphics/Animation/Sheets/Cat/idle/Idle right/idle_animation_right_paw_down-Sheet.png");
        Texture2D player_back = LoadTexture("assets/graphics/Animation/Sheets/Cat/Walk/Cat_Walk_Back.png");
        Texture2D player_front = LoadTexture("assets/graphics/Animation/Sheets/Cat/Walk/Cat_Walk_Front.png");
        Texture2D player_left = LoadTexture("assets/graphics/Animation/Sheets/Cat/Walk/Cat_Walk_Left.png");
        Texture2D player_right = LoadTexture("assets/graphics/Animation/Sheets/Cat/Walk/Cat_Walk_Right.png");// Texture loading

        Rectangle frameRec_idleRight = {0.0f, 0.0f, (float) player_back.width / 4, (float) player_back.height};
        Rectangle frameRec_idleLeft = {0.0f, 0.0f, (float) player_back.width / 4, (float) player_back.height};
        Rectangle frameRec_back = {0.0f, 0.0f, (float) player_back.width / 4, (float) player_back.height};
        Rectangle frameRec_front = {0.0f, 0.0f, (float) player_front.width / 4, (float) player_front.height};
        Rectangle frameRec_left = {0.0f, 0.0f, (float) player_left.width / 4, (float) player_left.height};
        Rectangle frameRec_right = {0.0f, 0.0f, (float) player_right.width / 4, (float) player_right.height};

bool twoKeysPressed;

        int currentFrame = 0;
        int framesCounter = 0;
        int framesSpeed = 10;

        int lives = 3;
        int speed = 48; //A tile is 25 pixels big
        int r0l1 = 0;
        bool moving = false;

        float target_x = pos_pl.x;
        float target_y = pos_pl.y;


        int image_speed = 0;


        void move();

        Vector2 getPos();

        void setPos(float inputX, float inputY);

        Texture2D getTexture();

        void setTexture(Texture2D image);

        void take(int direction);

        bool spaceAvailable(Vector2 vector);


    };
}
