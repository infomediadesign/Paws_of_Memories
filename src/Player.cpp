//
// Created by konst on 21.04.2023.
//

#include <iostream>
#include "raylib.h"
#include "config.h"
#include "Player.h"

void Game::Player::updatePlayer() {
    this->setCollRec(this->getPos().x, this->getPos().y, 24, 24);
    if (IsKeyDown(KEY_W)) {
        this->setAdjRec(this->getPos().x, this->getPos().y - 24, 24, 24);
    } else if (IsKeyDown(KEY_A)) {
        this->setAdjRec(this->getPos().x - 24, this->getPos().y, 24, 24);
    } else if (IsKeyDown(KEY_D)) {
        this->setAdjRec(this->getPos().x + 24, this->getPos().y, 24, 24);
    } else if (IsKeyDown(KEY_S)) {
        this->setAdjRec(this->getPos().x, this->getPos().y + 24, 24, 24);
    } else {
        this->setAdjRec({},{},{},{}); // wenn keine direction angegeben ist, soll es default nicht da sein
    }
}

void Game::Player::move() {
//grabbing commands implemented in the checks (destroy dirt/ grab memory from adjacent space)
    Vector2 check;
    framesCounter++;

    if(IsKeyDown(KEY_W) && (IsKeyDown(KEY_A) || IsKeyDown(KEY_S) || IsKeyDown(KEY_D)) ||
    IsKeyDown(KEY_A) && (IsKeyDown(KEY_D) || IsKeyDown(KEY_S)) || IsKeyDown(KEY_D) && IsKeyDown(KEY_S)){
        twoKeysPressed = true;
    } else {
        twoKeysPressed = false;
    }

    //Movement
    //Move the player

    if (target_x < pos.x) { pos.x -= 1.5; } //left
    if (target_x > pos.x) { pos.x += 1.5; } //right
    if (target_y > pos.y) { pos.y += 1.5; } //down
    if (target_y < pos.y) { pos.y -= 1.5; } //up

    // Setting flags for movement and animation to false once target area has been reached or if target area is past borders
    if (target_x == pos.x && target_y == pos.y) { // Problem with misaligned movement fixed by jointing these with &&
        moving = false;
        animation_left = false;
        animation_right = false;
        animation_up = false;
        animation_down = false;
    }

    //Animation
    if (animation_left) {
        if (framesCounter >= (60 / framesSpeed)) {

            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 3) currentFrame = 0;

            frameRec_left.x = (float) currentFrame * (float) player_left.width / 4;
        }
    }

    if (animation_right) {
        if (framesCounter >= (60 / framesSpeed)) {

            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 3) currentFrame = 0;

            frameRec_right.x = (float) currentFrame * (float) player_right.width / 4;
        }
    }

    if (animation_up) {
        if (framesCounter >= (60 / framesSpeed)) {

            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 3) currentFrame = 0;

            frameRec_back.x = (float) currentFrame * (float) player_back.width / 4;
        }
    }

    if (animation_down) {
        if (framesCounter >= (60 / framesSpeed)) {

            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 3) currentFrame = 0;

            frameRec_front.x = (float) currentFrame * (float) player_front.width / 4;
        }
    }

    if (IdleTimer = 0) {
        if (!moving && r0l1 == 0) { //Idle Animation right
            if (framesCounter >= (60 / framesSpeed)) {

                framesCounter = 0;
                currentFrame++;

                if (currentFrame > 3) currentFrame = 0;

                frameRec_idleRight.x = (float) currentFrame * (float) player_idleRight_PawUp.width / 4;

            }
        }
    }
    if (0 < IdleTimer < 4) {
        if (!moving && r0l1 == 0) { //Idle Animation right
            if (framesCounter >= (60 / framesSpeed)) {

                framesCounter = 0;
                currentFrame++;

                if (currentFrame > 3) currentFrame = 0;

                frameRec_idleRight.x = (float) currentFrame * (float) player_idleRight_Lick.width / 4;

            }
        }
    }
    if (IdleTimer == 4) {
        if (!moving && r0l1 == 0) { //Idle Animation right
            if (framesCounter >= (60 / framesSpeed)) {

                framesCounter = 0;
                currentFrame++;

                if (currentFrame > 3) currentFrame = 0;

                frameRec_idleRight.x = (float) currentFrame * (float) player_idleRight_PawDown.width / 4;

            }
        }
    }


    if (!moving && r0l1 == 1) { //Idle Animation left
        if (framesCounter >= (60 / framesSpeed)) {

            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 3) currentFrame = 0;

            frameRec_idleLeft.x = (float) currentFrame * (float) player_idleLeft_PawDown.width / 4;

        }
    }

    //Handle input
    if (IsKeyDown(KEY_A) && !moving && !twoKeysPressed) { // Left
        moving = true;
        r0l1 = 1; // 1 = links, für idle animation
        animation_left = true;
        target_x = pos.x - (float) speed;
        previousPosition.x = pos.x;
        previousPosition.y = pos.y;
    }

    if (IsKeyDown(KEY_D) && !moving && !twoKeysPressed) { // Right
        moving = true;
        r0l1 = 0;
        animation_right = true;
        target_x = pos.x + (float) speed;
        previousPosition.x = pos.x;
        previousPosition.y = pos.y;
    }

    if (IsKeyDown(KEY_W) && !moving && !twoKeysPressed) { // Up
        moving = true;
        animation_up = true;
        target_y = pos.y - (float) speed;
        previousPosition.x = pos.x;
        previousPosition.y = pos.y;
    }

    if (IsKeyDown(KEY_S) && !moving && !twoKeysPressed) { // Down
        moving = true;
        animation_down = true;
        target_y = pos.y + (float) speed;
        previousPosition.x = pos.x;
        previousPosition.y = pos.y;
    }
}

Game::Player::~Player() {
    delete this;
}