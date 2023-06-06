//
// Created by konst on 21.04.2023.
//

#pragma once
#include "raylib.h"
#include "Sprite.h"

/*
 * This class is just supposed to make the controls and necessary variables for the player:
 * - movement
 * - digging
 * - pushing (?)
 * - using abilities
 */

namespace Game {
    struct Player : public Sprite{ // player inherits variables from the Sprite header
    public:
        //
        Texture2D player;
        //idle move links
        Texture2D player_idleLeft_PawUp = LoadTexture("assets/graphics/Animation/Sheets/Cat/idle/Idle left/idle_animation_left_paw_up-Sheet.png");
        Texture2D player_idleLeft_Lick = LoadTexture("assets/graphics/Animation/Sheets/Cat/idle/Idle left/idle_animation_left_licking-Sheet.png");
        Texture2D player_idleLeft_PawDown = LoadTexture("assets/graphics/Animation/Sheets/Cat/idle/Idle left/idle_animation_left_paw_down-Sheet.png");

        //idle move rechts
        Texture2D player_idleRight_PawUp = LoadTexture("assets/graphics/Animation/Sheets/Cat/idle/Idle right/idle_animation_right_paw_up-Sheet.png");
        Texture2D player_idleRight_Lick = LoadTexture("assets/graphics/Animation/Sheets/Cat/idle/Idle right/idle_animation_right_licking-Sheet.png");
        Texture2D player_idleRight_PawDown = LoadTexture("assets/graphics/Animation/Sheets/Cat/idle/Idle right/idle_animation_right_paw_down-Sheet.png");

        //normal walk
        Texture2D player_back = LoadTexture("assets/graphics/Animation/Sheets/Cat/Walk/Cat_Walk_Back.png");
        Texture2D player_front = LoadTexture("assets/graphics/Animation/Sheets/Cat/Walk/Cat_Walk_Front.png");
        Texture2D player_left = LoadTexture("assets/graphics/Animation/Sheets/Cat/Walk/Cat_Walk_Left.png");
        Texture2D player_right = LoadTexture("assets/graphics/Animation/Sheets/Cat/Walk/Cat_Walk_Right.png");// Texture loading

        //Rectangle zeichnen
        //idle move links
        Rectangle frameRec_idleRight = {0.0f, 0.0f, (float) player_back.width / 4, (float) player_back.height};
        //idle move rechts
        Rectangle frameRec_idleLeft = {0.0f, 0.0f, (float) player_back.width / 4, (float) player_back.height};
        //normal walk
        Rectangle frameRec_back = {0.0f, 0.0f, (float) player_back.width / 4, (float) player_back.height};
        Rectangle frameRec_front = {0.0f, 0.0f, (float) player_front.width / 4, (float) player_front.height};
        Rectangle frameRec_left = {0.0f, 0.0f, (float) player_left.width / 4, (float) player_left.height};
        Rectangle frameRec_right = {0.0f, 0.0f, (float) player_right.width / 4, (float) player_right.height};

bool twoKeysPressed;

        float target_x = pos.x;
        float target_y = pos.y;

        Vector2 previousPosition;
        //KeyboardKey test; for switch case; unused

        int currentFrame = 0;
        int framesCounter = 0;
        int framesSpeed = 10;

        int lives = 3;
        int speed = 24; //A tile is 48 pixels big
        int r0l1 = 0;
        int IdleTimer = 4;
        bool moving = false;
        bool animation_left = false;
        bool animation_right = false;
        bool animation_up = false;
        bool animation_down = false;

        void move();

        Vector2 getPos();

        void setPos(float inputX, float inputY);

        Texture2D getTexture();

        void setTexture(Texture2D image);

        Rectangle getRectangle();

        void setRectangle(float posX, float posY, float width, float heigth);

        void take(int direction);

        bool spaceAvailable(Vector2 vector);
    };
}
