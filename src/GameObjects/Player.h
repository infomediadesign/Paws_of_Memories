//
// Created by konst on 21.04.2023.
//

#pragma once
#include "raylib.h"
#include "../Sprite.h"

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
        //idle move links
        Texture2D player_idleLeft = LoadTexture("assets/graphics/Animation/Sheets/Cat/idle/Idle complete/idle_animation_links_complete-Sheet.png");
        Texture2D idleLeft = LoadTexture("assets/graphics/Animation/Sheets/Cat/idle/Idle complete/idle_animation_links_complete-Sheet.png");
        Texture2D sleepingLeft = LoadTexture("assets/graphics/Animation/Sheets/Cat/Seitenschnitt/idle/Idle left/idle_animation_left_sleeping-Sheet.png");
        //idle move rechts
        Texture2D player_idleRight = LoadTexture("assets/graphics/Animation/Sheets/Cat/idle/Idle complete/idle_animation_right_complete-Sheet.png");
        Texture2D idleRight = LoadTexture("assets/graphics/Animation/Sheets/Cat/idle/Idle complete/idle_animation_right_complete-Sheet.png");
        Texture2D sleepingRight = LoadTexture("assets/graphics/Animation/Sheets/Cat/Seitenschnitt/idle/Idle right/idle_animation_right_sleeping-Sheet.png");
        int sideDelay = 0;

        //normal walk
        Texture2D player_back = LoadTexture("assets/graphics/Animation/Sheets/Cat/Walk/Cat_Walk_Back.png");
        Texture2D player_front = LoadTexture("assets/graphics/Animation/Sheets/Cat/Walk/Cat_Walk_Front.png");
        Texture2D player_left = LoadTexture("assets/graphics/Animation/Sheets/Cat/Walk/Cat_Walk_Left.png");
        Texture2D player_right = LoadTexture("assets/graphics/Animation/Sheets/Cat/Walk/Cat_Walk_Right.png");// Texture loading
        // Death Animation
        Texture2D playerDeath_left = LoadTexture("assets/graphics/Animation/Sheets/Cat/Death/Paws_Of_Memories_Death_left-Sheet.png");
        Texture2D playerDeath_right = LoadTexture("assets/graphics/Animation/Sheets/Cat/Death/Paws_Of_Memories_Death_right-Sheet.png");
        Rectangle frameRec_deathLeft = {0.0f, 0.0f, (float) playerDeath_left.width / 23, (float) playerDeath_left.height};
        Rectangle frameRec_deathRight = {0.0f, 0.0f, (float) playerDeath_right.width / 23, (float) playerDeath_right.height};
        // Digging Animation
        Texture2D player_digUp = LoadTexture("assets/graphics/Animation/Sheets/Cat/Seitenschnitt/Dig/Cat_Dig_Back-Sheet.png");
        Texture2D player_digLeft = LoadTexture("assets/graphics/Animation/Sheets/Cat/Seitenschnitt/Dig/Cat_Dig_Left-Sheet.png");
        Texture2D player_digDown = LoadTexture("assets/graphics/Animation/Sheets/Cat/Seitenschnitt/Dig/Cat_Dig_Front-Sheet.png");
        Texture2D player_digRight = LoadTexture("assets/graphics/Animation/Sheets/Cat/Seitenschnitt/Dig/Cat_Dig_Right-Sheet.png");
        // ZU EINEM MACHEN UND DANN RICHTIG ZUWEISEN?
        Rectangle frameRec_digUp = {0.0f, 0.0f, (float) player_digUp.width / 9, (float) player_digUp.height};
        Rectangle frameRec_digLeft = {0.0f, 0.0f, (float) player_digLeft.width / 9, (float) player_digLeft.height};
        Rectangle frameRec_digDown = {0.0f, 0.0f, (float) player_digDown.width / 9, (float) player_digDown.height};
        Rectangle frameRec_digRight = {0.0f, 0.0f, (float) player_digRight.width / 9, (float) player_digRight.height};
        bool diggingUp = false;
        bool diggingLeft = false;
        bool diggingDown = false;
        bool diggingRight = false;

        //idle move rechts
        Rectangle frameRec_iR = {0.0f, 0.0f, (float) player_idleRight.width / 96, (float) player_idleRight.height};
        //idle move links
        Rectangle frameRec_iL = {0.0f, 0.0f, (float) player_idleLeft.width / 96, (float) player_idleLeft.height};
        //normal walk
        // ZU EINEM MACHEN UND DANN RICHTIG ZUWEISEN?
        Rectangle frameRec_back = {0.0f, 0.0f, (float) player_back.width / 4, (float) player_back.height};
        Rectangle frameRec_front = {0.0f, 0.0f, (float) player_front.width / 4, (float) player_front.height};
        Rectangle frameRec_left = {0.0f, 0.0f, (float) player_left.width / 4, (float) player_left.height};
        Rectangle frameRec_right = {0.0f, 0.0f, (float) player_right.width / 4, (float) player_right.height};

        //HUB
        //Textures
        Texture2D hubUp = LoadTexture("assets/graphics/Animation/Sheets/Cat/TopDown/Walk/Cat_Walk_Back.png");
        Texture2D hubLeft = LoadTexture("assets/graphics/Animation/Sheets/Cat/TopDown/Walk/Cat_Walk_Left-Sheet.png");
        Texture2D hubDown = LoadTexture("assets/graphics/Animation/Sheets/Cat/TopDown/Walk/Cat_Walk_Front.png");
        Texture2D hubRight = LoadTexture("assets/graphics/Animation/Sheets/Cat/TopDown/Walk/Cat_Walk_Right-Sheet.png");
        Texture2D hubIdleLeft = LoadTexture("assets/graphics/Animation/Sheets/Cat/TopDown/Idle/Idle left/idle_left_sitting.png");
        Texture2D hubIdleRight = LoadTexture("assets/graphics/Animation/Sheets/Cat/TopDown/Idle/Idle right/idle_right_sitting.png");
        Texture2D idleLeftSitting = LoadTexture("assets/graphics/Animation/Sheets/Cat/TopDown/Idle/Idle left/idle_left_sitting.png");
        Texture2D idleLeftLaying = LoadTexture("assets/graphics/Animation/Sheets/Cat/TopDown/Idle/Idle left/idle_left_laying.png");
        Texture2D idleLeftSleeping = LoadTexture("assets/graphics/Animation/Sheets/Cat/TopDown/Idle/Idle left/Idle_left_sleeping.png");
        Texture2D idleRightSitting = LoadTexture("assets/graphics/Animation/Sheets/Cat/TopDown/Idle/Idle right/idle_right_sitting.png");
        Texture2D idleRightLaying = LoadTexture("assets/graphics/Animation/Sheets/Cat/TopDown/Idle/Idle right/idle_right_laying.png");
        Texture2D idleRightSleeping = LoadTexture("assets/graphics/Animation/Sheets/Cat/TopDown/Idle/Idle right/Idle_right_sleeping.png");
        //FrameRecs
        // ZU EINEM MACHEN UND DANN RICHTIG ZUWEISEN?
        Rectangle rec_HubUp = {0.0f, 0.0f, (float) hubUp.width / 4, (float) hubUp.height};
        Rectangle rec_HubLeft = {0.0f, 0.0f, (float) hubLeft.width / 4, (float) hubLeft.height};
        Rectangle rec_HubDown = {0.0f, 0.0f, (float) hubDown.width / 4, (float) hubDown.height};
        Rectangle rec_HubRight = {0.0f, 0.0f, (float) hubRight.width / 4, (float) hubRight.height};

        Rectangle rec_HubIdleLeft = {0.0f, 0.0f, (float) idleLeftLaying.width / 5, (float) idleLeftLaying.height};
        Rectangle rec_HubIdleRight = {0.0f, 0.0f, (float) idleRightLaying.width / 5, (float) idleRightLaying.height};

        bool twoKeysPressed = true;
        bool canMove = false;

        float target_x = pos.x;
        float target_y = pos.y;

        Vector2 previousPosition = {};
        //KeyboardKey test; for switch case; unused

        int currentFrame = 0;
        int framesCounter = 0;
        int framesSpeed = 1;
        int idleFrame = 0;
        int idleCount = 0;
        int IdleDelay = 0;

        int idleSpeed = 1;
        int lives = 3;
        int speed = 24; //A tile is 24 pixels big
        int r0l1 = 0;
        bool moving = false;
        bool animation_left = false;
        bool animation_right = false;
        bool animation_up = false;
        bool animation_down = false;
        bool digging = false;
        bool compassCollected = false;
        KeyboardKey desiredDirection;
        bool diggingDone = true;

        //~Player();

        void updatePlayer();

        void move();
        void moveDigAnimation();
        void idleAnimation();
        void deathAnimation();

        void hubMove();
        void hubMoveAnimation();
        void hubIdleAnimation();

        void drawPlayer();
        void drawPlayerHub();
    };
}
