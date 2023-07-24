//
// Created by konst on 21.04.2023.
//

#include "raylib.h"
#include "Player.h"

/*
 *  MOVEMENT PROBLEMS:
 *  --> The idle animation seems to get displayed for 1 frame after each movement step, because there is a small gap
 *  --> somehow make a delay?
 *  --> add a function that gets called when movement is done, to overwrite the gap?
 */

void Game::Player::updatePlayer() {
    this->setCollRec(this->getPos().x, this->getPos().y, 24, 24);
    if (IsKeyDown(KEY_W) && (IsKeyDown(KEY_A) || IsKeyDown(KEY_S) || IsKeyDown(KEY_D)) ||
        IsKeyDown(KEY_A) && (IsKeyDown(KEY_D) || IsKeyDown(KEY_S)) || IsKeyDown(KEY_D) && IsKeyDown(KEY_S)) {
        twoKeysPressed = true;
    } else {
        twoKeysPressed = false;
    }
    if (!twoKeysPressed) {
        if (IsKeyDown(KEY_W)) {
            this->setAdjRec(this->getPos().x, this->getPos().y - 2, 24, 24);
        } else if (IsKeyDown(KEY_A)) {
            this->setAdjRec(this->getPos().x - 2, this->getPos().y, 24, 24);
        } else if (IsKeyDown(KEY_D)) {
            this->setAdjRec(this->getPos().x + 2, this->getPos().y, 24, 24);
        } else if (IsKeyDown(KEY_S)) {
            this->setAdjRec(this->getPos().x, this->getPos().y + 2, 24, 24);
        } else {
            this->setAdjRec({}, {}, {}, {}); // wenn keine direction angegeben ist, soll es default nicht da sein
        }
    }
}

void Game::Player::move() {
    //grabbing commands implemented in the checks (destroy dirt/ grab memory from adjacent space)
    updatePlayer();

    //Movement
    //Move the player

    if (target_x < pos.x) { pos.x -= 1; } //left
    if (target_x > pos.x) { pos.x += 1; } //right
    if (target_y > pos.y) { pos.y += 1; } //down
    if (target_y < pos.y) { pos.y -= 1; } //up

    if (IsKeyDown(KEY_W) && (IsKeyDown(KEY_A) || IsKeyDown(KEY_S) || IsKeyDown(KEY_D)) ||
        IsKeyDown(KEY_A) && (IsKeyDown(KEY_D) || IsKeyDown(KEY_S)) || IsKeyDown(KEY_D) && IsKeyDown(KEY_S)) {
        twoKeysPressed = true;
    } else {
        twoKeysPressed = false;
    }

    if (!moving && !twoKeysPressed && IsKeyDown(KEY_RIGHT_CONTROL) || IsKeyDown(KEY_LEFT_CONTROL)) {
        digging = true;
        if (IsKeyPressed(KEY_W) && !diggingLeft && !diggingDown && !diggingRight) {
            currentFrame = 0;
            diggingUp = true;
        }
        if (IsKeyPressed(KEY_A) && !diggingUp && !diggingDown && !diggingRight) {
            currentFrame = 0;
            diggingLeft = true;
        }
        if (IsKeyPressed(KEY_S) && !diggingLeft && !diggingUp && !diggingRight) {
            currentFrame = 0;
            diggingDown = true;
        }
        if (IsKeyPressed(KEY_D) && !diggingLeft && !diggingDown && !diggingUp) {
            currentFrame = 0;
            diggingRight = true;
        }
    } else {
        digging = false;
    }

    //Handle input
    if (IsKeyDown(KEY_A) && !moving && !twoKeysPressed && !digging && canMove) { // Left
        moving = true;
        r0l1 = 1; // 1 = links, für idle animation
        animation_left = true;
        target_x = pos.x - (float) speed;
        previousPosition.x = pos.x;
        previousPosition.y = pos.y;
    }

    if (IsKeyDown(KEY_D) && !moving && !twoKeysPressed && !digging && canMove) { // Right
        moving = true;
        r0l1 = 0;
        animation_right = true;
        target_x = pos.x + (float) speed;
        previousPosition.x = pos.x;
        previousPosition.y = pos.y;
    }

    if (IsKeyDown(KEY_W) && !moving && !twoKeysPressed && !digging && canMove) { // Up
        moving = true;
        animation_up = true;
        target_y = pos.y - (float) speed;
        previousPosition.x = pos.x;
        previousPosition.y = pos.y;
    }

    if (IsKeyDown(KEY_S) && !moving && !twoKeysPressed && !digging && canMove) { // Down
        moving = true;
        animation_down = true;
        target_y = pos.y + (float) speed;
        previousPosition.x = pos.x;
        previousPosition.y = pos.y;
    }

    // Setting flags for movement and animation to false once target area has been reached or if target area is past borders
    if (target_x == pos.x && target_y == pos.y) { // Problem with misaligned movement fixed by jointing these with &&
        moving = false;
        animation_left = false;
        animation_right = false;
        animation_up = false;
        animation_down = false;
    }
}

void Game::Player::moveDigAnimation() {
    framesCounter++;
    if (animation_left) {
        if (framesCounter >= (10 / framesSpeed)) {

            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 3) currentFrame = 0;

            frameRec_left.x = (float) currentFrame * (float) player_left.width / 4;
        }
    }
    if (animation_right) {
        if (framesCounter >= (10 / framesSpeed)) {

            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 3) currentFrame = 0;

            frameRec_right.x = (float) currentFrame * (float) player_right.width / 4;
        }
    }
    if (animation_up) {
        if (framesCounter >= (10 / framesSpeed)) {

            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 3) currentFrame = 0;

            frameRec_back.x = (float) currentFrame * (float) player_back.width / 4;
        }
    }
    if (animation_down) {
        if (framesCounter >= (10 / framesSpeed)) {

            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 3) currentFrame = 0;

            frameRec_front.x = (float) currentFrame * (float) player_front.width / 4;
        }
    }
    /*
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
    */

    //Digging Animation
    if (diggingUp) {
        if (framesCounter >= (4 / framesSpeed)) {

            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 8) {
                currentFrame = 0;
                diggingUp = false;
            }

            frameRec_digUp.x = (float) currentFrame * (float) player_digUp.width / 9;
        }
    }
    if (diggingLeft) {
        if (framesCounter >= (4 / framesSpeed)) {

            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 8) {
                currentFrame = 0;
                diggingLeft = false;
                r0l1 = 1;
            }

            frameRec_digLeft.x = (float) currentFrame * (float) player_digLeft.width / 9;
        }
    }
    if (diggingDown) {
        if (framesCounter >= (4 / framesSpeed)) {

            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 8) {
                currentFrame = 0;
                diggingDown = false;
            }

            frameRec_digDown.x = (float) currentFrame * (float) player_digDown.width / 9;
        }
    }
    if (diggingRight) {
        if (framesCounter >= (4 / framesSpeed)) {

            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 8) {
                currentFrame = 0;
                diggingRight = false;
                r0l1 = 0;
            }

            frameRec_digRight.x = (float) currentFrame * (float) player_digRight.width / 9;
        }
    }
}

void Game::Player::idleAnimation() {
    // USE DELAY OR STH TO KEEP THE CAT SLEEPING
    idleCount++;
    if (r0l1 == 0) { //Idle Animation right
        if (idleCount >= (6 / idleSpeed)) {

            idleCount = 0;
            idleFrame++;

            if (idleFrame > 95) idleFrame = 0;

            frameRec_iR.x = (float) idleFrame * (float) player_idleRight.width / 96;

        }
    }

    if (r0l1 == 1) { //Idle Animation left
        if (idleCount >= (6 / idleSpeed)) {

            idleCount = 0;
            idleFrame++;

            if (idleFrame > 95) idleFrame = 0;

            frameRec_iL.x = (float) idleFrame * (float) player_idleLeft.width / 96;

        }
    }
}

void Game::Player::deathAnimation() {
    framesCounter++;
    if (r0l1 == 0) {
        if (framesCounter >= (5 / framesSpeed)) {

            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 22) {
                this->active = false;
                currentFrame = 0;
            }

            frameRec_deathRight.x = (float) currentFrame * (float) playerDeath_right.width / 23;
        }
    } else {
        if (framesCounter >= (5 / framesSpeed)) {

            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 22) {
                this->active = false;
                currentFrame = 0;
            }

            frameRec_deathLeft.x = (float) currentFrame * (float) playerDeath_left.width / 23;
        }
    }
}

void Game::Player::hubMove() {
    updatePlayer(); // if collision should be different insert bool of hub

    if (IsKeyDown(KEY_W) && (IsKeyDown(KEY_A) || IsKeyDown(KEY_S) || IsKeyDown(KEY_D)) ||
        IsKeyDown(KEY_A) && (IsKeyDown(KEY_D) || IsKeyDown(KEY_S)) || IsKeyDown(KEY_D) && IsKeyDown(KEY_S)) {
        twoKeysPressed = true;
    } else {
        twoKeysPressed = false;
    }

    if(IsKeyDown(KEY_W) && !twoKeysPressed) {
        this->moving = true;
        this->pos.y--;
        this->animation_up = true;
    } else this->animation_up = false;

    if(IsKeyDown(KEY_A) && !twoKeysPressed) {
        r0l1 = 1;
        this->moving = true;
        this->pos.x--;
        this->animation_left = true;
    }else this->animation_left = false;

    if(IsKeyDown(KEY_S) && !twoKeysPressed) {
        this->moving = true;
        this->pos.y++;
        this->animation_down = true;
    }else this->animation_down = false;

    if(IsKeyDown(KEY_D) && !twoKeysPressed) {
        r0l1 = 0;
        this->moving = true;
        this->pos.x++;
        this->animation_right = true;
    } else this->animation_right = false;

    if((!IsKeyDown(KEY_W) && !IsKeyDown(KEY_A) && !IsKeyDown(KEY_S) && !IsKeyDown(KEY_D)) || twoKeysPressed) moving = false;
}

void Game::Player::hubMoveAnimation() {
    framesCounter++;
    if (animation_left) {
        if (framesCounter >= (10 / framesSpeed)) {

            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 3) currentFrame = 0;

            rec_HubLeft.x = (float) currentFrame * (float) hubLeft.width / 4;
        }
    }
    if (animation_right) {
        if (framesCounter >= (10 / framesSpeed)) {

            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 3) currentFrame = 0;

            rec_HubRight.x = (float) currentFrame * (float) hubRight.width / 4;
        }
    }
    if (animation_up) {
        if (framesCounter >= (10 / framesSpeed)) {

            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 3) currentFrame = 0;

            rec_HubUp.x = (float) currentFrame * (float) hubUp.width / 4;
        }
    }
    if (animation_down) {
        if (framesCounter >= (10 / framesSpeed)) {

            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 3) currentFrame = 0;

            rec_HubDown.x = (float) currentFrame * (float) hubDown.width / 4;
        }
    }
}

void Game::Player::hubIdleAnimation() {
    idleCount++;
    if (r0l1 == 0) { //Idle Animation right
        if (idleCount >= (12 / idleSpeed)) {

            idleCount = 0;

            if(idleFrame < 5) {
                hubIdleRight = idleRightSitting;
                rec_HubIdleRight.x = (float) (idleFrame%5) * (float) idleRightSitting.width / 5;
                idleFrame++;
            }
            else if(idleFrame < 10) {
                hubIdleRight = idleRightLaying;
                rec_HubIdleRight.x = (float) (idleFrame%5) * (float) idleRightLaying.width / 5;
                idleFrame++;
            }
            else {
                hubIdleRight = idleRightSleeping;
                rec_HubIdleRight.x = (float) (idleFrame%2) * (float) idleRightSleeping.width / 2;
                IdleDelay++;
                if(IdleDelay == 5) {
                    idleFrame++;
                    IdleDelay = 0;
                }
            }
        }
    }

    if (r0l1 == 1) { //Idle Animation left
        if (idleCount >= (12 / idleSpeed)) {

            idleCount = 0;

            if(idleFrame < 5) {
                hubIdleLeft = idleLeftSitting;
                rec_HubIdleLeft.x = (float) (idleFrame%5) * (float) idleLeftSitting.width / 5;
                idleFrame++;
            }
            else if(idleFrame < 10) {
                hubIdleLeft = idleLeftLaying;
                rec_HubIdleLeft.x = (float) (idleFrame%5) * (float) idleLeftLaying.width / 5;
                idleFrame++;
            }
            else {
                hubIdleLeft = idleLeftSleeping;
                rec_HubIdleLeft.x = (float) (idleFrame%2) * (float) idleLeftSleeping.width / 2;
                IdleDelay++;
                if(IdleDelay == 5) {
                    idleFrame++;
                    IdleDelay = 0;
                }
            }

        }
    }
}

/*Game::Player::~Player() {
    delete this;
}*/