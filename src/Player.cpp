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
    if (animation_left == true) {
        if (framesCounter >= (60 / framesSpeed)) {

            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 3) currentFrame = 0;

            frameRec_left.x = (float) currentFrame * (float) player_left.width / 4;
        }
    }

    if (animation_right == true) {
        if (framesCounter >= (60 / framesSpeed)) {

            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 3) currentFrame = 0;

            frameRec_right.x = (float) currentFrame * (float) player_right.width / 4;
        }
    }

    if (animation_up == true) {
        if (framesCounter >= (60 / framesSpeed)) {

            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 3) currentFrame = 0;

            frameRec_back.x = (float) currentFrame * (float) player_back.width / 4;
        }
    }

    if (animation_down == true) {
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
        target_x = pos.x - speed;
        previousPosition.x = pos.x;
        previousPosition.y = pos.y;
    }

    if (IsKeyDown(KEY_D) && !moving && !twoKeysPressed) { // Right
        moving = true;
        r0l1 = 0;
        animation_right = true;
        target_x = pos.x + speed;
        previousPosition.x = pos.x;
        previousPosition.y = pos.y;
    }

    if (IsKeyDown(KEY_W) && !moving && !twoKeysPressed) { // Up
        moving = true;
        animation_up = true;
        target_y = pos.y - speed;
        previousPosition.x = pos.x;
        previousPosition.y = pos.y;
    }

    if (IsKeyDown(KEY_S) && !moving && !twoKeysPressed) { // Down
        moving = true;
        animation_down = true;
        target_y = pos.y + speed;
        previousPosition.x = pos.x;
        previousPosition.y = pos.y;
    }


    //grabbing commands implemented in the checks (destroy dirt/ grab memory from adjacent space)
    if (IsKeyDown(KEY_LEFT_CONTROL) || IsKeyDown(KEY_RIGHT_CONTROL)) {
        if (IsKeyDown(KEY_W) && !IsKeyDown(KEY_D) && !IsKeyDown(KEY_S) && !IsKeyDown(KEY_A)) {
            check.x = getPos().x;
            check.y = getPos().y - speed;
            if (spaceAvailable(check)) {}
        } else if (IsKeyDown(KEY_A) && !IsKeyDown(KEY_W) && !IsKeyDown(KEY_D) && !IsKeyDown(KEY_S)) {
            check.x = getPos().x - speed;
            check.y = getPos().y;
            int r0l1 = 1;
            if (spaceAvailable(check)) {}
        } else if (IsKeyDown(KEY_S) && !IsKeyDown(KEY_W) && !IsKeyDown(KEY_D) && !IsKeyDown(KEY_A)) {
            check.x = getPos().x + speed;
            check.y = getPos().y;
            if (spaceAvailable(check)) {}
        } else if (IsKeyDown(KEY_D) && !IsKeyDown(KEY_S) && !IsKeyDown(KEY_A) && !IsKeyDown(KEY_W)) {
            check.x = getPos().x;
            check.y = getPos().y + speed;
            int r0l1 = 0;
            if (spaceAvailable(check)) {}
        }
    }
}

Game::Player::~Player() {
    delete this;
}

bool Game::Player::spaceAvailable(Vector2 vector) {
    /* At the moment the player can always take, since the conditions cannot be properly programmed at this point
     * This bool will be used to check for unmovable places(boulders,walls and potentially enemies)
     */

    return true;
}

void Game::Player::take(int direction) {
    /* At the moment the player can always take, since the conditions cannot be properly programmed at this point
     * Will need a case for:
     * - dirt (destroy corresponding entity)
     * - memory (inherit the memory, add to count (and delete it))
     * - boulder (don't do anything (can't grab boulders))
     * - enemy (??? don't do anything (can't grab enemies)?)
     * - wall(don't do anything (can't grab walls))
     */


    //Vector2 memoryLocation = Memory().getPos();

    if (direction == 0) {
        //check up
        //Vector2 dirtLocation = Dirt(pos.x, pos.y + speed).getPos();
        if (pos.y + speed /*== dirtLocation.y*/ && pos.x /*== dirtLocation.x*/) {
            //Dirt(pos.x, pos.y);
            //} else if(pos.y + speed == memoryLocation.y && pos.x == memoryLocation.x) {}
        } else if (direction == 1) {
            //check left

        } else if (direction == 2) {
            //check down

        } else if (direction == 3) {
            //check right

        }
    }
}