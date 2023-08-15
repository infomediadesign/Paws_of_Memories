//
// Created by konst on 21.04.2023.
//

#include <iostream>
#include "raylib.h"
#include "Player.h"

void Game::Player::updatePlayer() {
    this->setCollRec(this->getPos().x, this->getPos().y, 24, 24);
    switch (GetKeyPressed()) {
        case 87: // KEY_W
            desiredDirection = KEY_W;
            if(!diggingUp && !diggingLeft && !diggingDown && !diggingRight) {
                diggingDone = true;
            }
            break;
        case 65: // KEY_A
            desiredDirection = KEY_A;
            if(!diggingUp && !diggingLeft && !diggingDown && !diggingRight) {
                diggingDone = true;
            }
            break;
        case 83: // KEY_S
            desiredDirection = KEY_S;
            if(!diggingUp && !diggingLeft && !diggingDown && !diggingRight) {
                diggingDone = true;
            }
            break;
        case 68: // KEY_D
            desiredDirection = KEY_D;
            if(!diggingUp && !diggingLeft && !diggingDown && !diggingRight) {
                diggingDone = true;
            }
            break;
    }
    if (!moving && !IsKeyDown(KEY_W) && !IsKeyDown(KEY_A) && !IsKeyDown(KEY_S) && !IsKeyDown(KEY_D)) {
        desiredDirection = KEY_ZERO;
        if(!diggingUp && !diggingLeft && !diggingDown && !diggingRight) {
            diggingDone = true;
        }
    }
    if(moving) {
        diggingDone= true;
    }
    if (desiredDirection != KEY_ZERO && IsKeyDown(KEY_W) && !IsKeyDown(KEY_A) && !IsKeyDown(KEY_S) &&
        !IsKeyDown(KEY_D)) {
        desiredDirection = KEY_W;
    }
    if (desiredDirection != KEY_ZERO && !IsKeyDown(KEY_W) && IsKeyDown(KEY_A) && !IsKeyDown(KEY_S) &&
               !IsKeyDown(KEY_D)) {
        desiredDirection = KEY_A;
    }
    if (desiredDirection != KEY_ZERO && !IsKeyDown(KEY_W) && !IsKeyDown(KEY_A) && IsKeyDown(KEY_S) &&
               !IsKeyDown(KEY_D)) {
        desiredDirection = KEY_S;
    }
    if (desiredDirection != KEY_ZERO && !IsKeyDown(KEY_W) && !IsKeyDown(KEY_A) && !IsKeyDown(KEY_S) &&
               IsKeyDown(KEY_D)) {
        desiredDirection = KEY_D;
    }
    // necessary, so you can only dig 1 at a time
    if (IsKeyDown(KEY_W) && (IsKeyDown(KEY_A) || IsKeyDown(KEY_S) || IsKeyDown(KEY_D)) ||
        IsKeyDown(KEY_A) && (IsKeyDown(KEY_D) || IsKeyDown(KEY_S)) || IsKeyDown(KEY_D) && IsKeyDown(KEY_S)) {
        twoKeysPressed = true;
    } else {
        twoKeysPressed = false;
    }
    if (!diggingUp && !diggingLeft && !diggingDown && !diggingRight) {
        if (desiredDirection == KEY_W) {
            this->setAdjRec(this->getPos().x, this->getPos().y - 2, 24, 24);
        } else if (desiredDirection == KEY_A) {
            this->setAdjRec(this->getPos().x - 2, this->getPos().y, 24, 24);
        } else if (desiredDirection == KEY_D) {
            this->setAdjRec(this->getPos().x + 2, this->getPos().y, 24, 24);
        } else if (desiredDirection == KEY_S) {
            this->setAdjRec(this->getPos().x, this->getPos().y + 2, 24, 24);
        } else {
            this->setAdjRec({}, {}, {}, {}); // wenn keine direction angegeben ist, soll es default nicht da sein
        }
    } else {
        if (digging) {
            if (IsKeyPressed(KEY_W)) {
                this->setAdjRec(this->getPos().x, this->getPos().y - 2, 24, 24);
            } else if (IsKeyPressed(KEY_A)) {
                this->setAdjRec(this->getPos().x - 2, this->getPos().y, 24, 24);
            } else if (IsKeyPressed(KEY_D)) {
                this->setAdjRec(this->getPos().x + 2, this->getPos().y, 24, 24);
            } else if (IsKeyPressed(KEY_S)) {
                this->setAdjRec(this->getPos().x, this->getPos().y + 2, 24, 24);
            }
        }
    }
}

void Game::Player::move() {
    //grabbing commands implemented in the checks (destroy dirt/ grab memory from adjacent space)
    updatePlayer();


    // Setting flags for movement and animation to false once target area has been reached or if target area is past borders
    if (target_x == pos.x && target_y == pos.y) { // Problem with misaligned movement fixed by jointing these with &&
        animation_left = false;
        animation_right = false;
        animation_up = false;
        animation_down = false;
    }

    //Movement
    //Move the player

    if (target_x < pos.x) { pos.x -= 1; } //left
    if (target_x > pos.x) { pos.x += 1; } //right
    if (target_y > pos.y) { pos.y += 1; } //down
    if (target_y < pos.y) { pos.y -= 1; } //up


    if (!moving && (IsKeyDown(KEY_RIGHT_CONTROL) || IsKeyDown(KEY_LEFT_CONTROL))) {
        digging = true;
        if (desiredDirection == KEY_W && !diggingUp && !diggingLeft && !diggingDown && !diggingRight && diggingDone) {
            currentFrame = 0;
            diggingUp = true;
            diggingDone = false;
        }
        if (desiredDirection == KEY_A && !diggingUp && !diggingLeft && !diggingDown && !diggingRight && diggingDone) {
            currentFrame = 0;
            diggingLeft = true;
            diggingDone = false;
        }
        if (desiredDirection == KEY_S && !diggingUp && !diggingLeft && !diggingDown && !diggingRight && diggingDone) {
            currentFrame = 0;
            diggingDown = true;
            diggingDone = false;
        }
        if (desiredDirection == KEY_D && !diggingUp && !diggingLeft && !diggingDown && !diggingRight && diggingDone) {
            currentFrame = 0;
            diggingRight = true;
            diggingDone = false;
        }
    }
    if (!diggingUp && !diggingLeft && !diggingDown && !diggingRight && !IsKeyDown(KEY_RIGHT_CONTROL) && !IsKeyDown(KEY_LEFT_CONTROL)) {
        digging = false;
    }

    //Handle input
    if (desiredDirection == KEY_A && !moving && !digging && canMove) { // Left
        moving = true;
        r0l1 = 1; // 1 = links, für idle animation
        animation_left = true;
        target_x = pos.x - (float) speed;
        previousPosition.x = pos.x;
        previousPosition.y = pos.y;
    }

    if (desiredDirection == KEY_D && !moving && !digging && canMove) { // Right
        moving = true;
        r0l1 = 0;
        animation_right = true;
        target_x = pos.x + (float) speed;
        previousPosition.x = pos.x;
        previousPosition.y = pos.y;
    }

    if (desiredDirection == KEY_W && !moving && !digging && canMove) { // Up
        moving = true;
        animation_up = true;
        target_y = pos.y - (float) speed;
        previousPosition.x = pos.x;
        previousPosition.y = pos.y;
    }

    if (desiredDirection == KEY_S && !moving && !digging && canMove) { // Down
        moving = true;
        animation_down = true;
        target_y = pos.y + (float) speed;
        previousPosition.x = pos.x;
        previousPosition.y = pos.y;
    }

    // Setting flags for movement and animation to false once target area has been reached or if target area is past borders
    if (target_x == pos.x && target_y == pos.y) { // Problem with misaligned movement fixed by jointing these with &&
        moving = false;
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

            if (idleFrame < 96) {
                player_idleRight = idleRight;
                frameRec_iR = {(float) idleFrame * (float) idleRight.width / 96, 0.0f,
                               (float) player_idleRight.width / 96, (float) player_idleRight.height};
                idleFrame++;
            } else {
                player_idleRight = sleepingRight;
                frameRec_iR = {(float) (idleFrame % 2) * (float) sleepingRight.width / 2, 0.0f,
                               (float) sleepingRight.width / 2, (float) sleepingRight.height};
                sideDelay++;
                if (sideDelay == 5) {
                    idleFrame++;
                    sideDelay = 0;
                }
            }
        }
    }

    if (r0l1 == 1) { //Idle Animation left
        if (idleCount >= (6 / idleSpeed)) {

            idleCount = 0;

            if (idleFrame < 96) {
                player_idleLeft = idleLeft;
                frameRec_iL = {(float) idleFrame * (float) idleLeft.width / 96, 0.0f,
                               (float) player_idleLeft.width / 96, (float) player_idleLeft.height};
                idleFrame++;
            } else {
                player_idleLeft = sleepingLeft;
                frameRec_iL = {(float) (idleFrame % 2) * (float) sleepingLeft.width / 2, 0.0f,
                               (float) sleepingLeft.width / 2, (float) sleepingLeft.height};
                sideDelay++;
                if (sideDelay == 5) {
                    idleFrame++;
                    sideDelay = 0;
                }
            }
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
                this->digging = false;
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
                this->digging = false;
                currentFrame = 0;
            }

            frameRec_deathLeft.x = (float) currentFrame * (float) playerDeath_left.width / 23;
        }
    }
}

void Game::Player::hubMove() {
    //updatePlayer(); // if collision should be different insert bool of hub
    if (desiredDirection == KEY_W && canMove) {
        this->moving = true;
        this->pos.y--;
        this->animation_up = true;
    } else this->animation_up = false;

    if (desiredDirection == KEY_A && canMove) {
        r0l1 = 1;
        this->moving = true;
        this->pos.x--;
        this->animation_left = true;
    } else this->animation_left = false;

    if (desiredDirection == KEY_S && canMove) {
        this->moving = true;
        this->pos.y++;
        this->animation_down = true;
    } else this->animation_down = false;

    if (desiredDirection == KEY_D && canMove) {
        r0l1 = 0;
        this->moving = true;
        this->pos.x++;
        this->animation_right = true;
    } else this->animation_right = false;

    if ((!IsKeyDown(KEY_W) && !IsKeyDown(KEY_A) && !IsKeyDown(KEY_S) && !IsKeyDown(KEY_D)))
        moving = false;
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

            if (idleFrame < 5) {
                hubIdleRight = idleRightSitting;
                rec_HubIdleRight.x = (float) (idleFrame % 5) * (float) idleRightSitting.width / 5;
                idleFrame++;
            } else if (idleFrame < 10) {
                hubIdleRight = idleRightLaying;
                rec_HubIdleRight.x = (float) (idleFrame % 5) * (float) idleRightLaying.width / 5;
                idleFrame++;
            } else {
                hubIdleRight = idleRightSleeping;
                rec_HubIdleRight.x = (float) (idleFrame % 2) * (float) idleRightSleeping.width / 2;
                IdleDelay++;
                if (IdleDelay == 5) {
                    idleFrame++;
                    IdleDelay = 0;
                }
            }
        }
    }

    if (r0l1 == 1) { //Idle Animation left
        if (idleCount >= (12 / idleSpeed)) {

            idleCount = 0;

            if (idleFrame < 5) {
                hubIdleLeft = idleLeftSitting;
                rec_HubIdleLeft.x = (float) (idleFrame % 5) * (float) idleLeftSitting.width / 5;
                idleFrame++;
            } else if (idleFrame < 10) {
                hubIdleLeft = idleLeftLaying;
                rec_HubIdleLeft.x = (float) (idleFrame % 5) * (float) idleLeftLaying.width / 5;
                idleFrame++;
            } else {
                hubIdleLeft = idleLeftSleeping;
                rec_HubIdleLeft.x = (float) (idleFrame % 2) * (float) idleLeftSleeping.width / 2;
                IdleDelay++;
                if (IdleDelay == 5) {
                    idleFrame++;
                    IdleDelay = 0;
                }
            }

        }
    }
}

void Game::Player::drawPlayer() {
    if (canMove && lives > 0 && (animation_up || animation_down || animation_right || animation_left)) {
        if (animation_up) {
            idleFrame = 4;
            DrawTexturePro(player_back, frameRec_back, collRectangle, {}, 0, WHITE);
        }
        if (animation_down) {
            idleFrame = 4;
            DrawTexturePro(player_front, frameRec_front, collRectangle, {}, 0, WHITE);
        }
        if (animation_right) {
            idleFrame = 4;
            DrawTexturePro(player_right, frameRec_right, collRectangle, {}, 0, WHITE);
        }
        if (animation_left) {
            idleFrame = 4;
            DrawTexturePro(player_left, frameRec_left, collRectangle, {}, 0, WHITE);
        }
    } else if (lives <= 0) {
        if (r0l1 == 0) {
            DrawTexturePro(playerDeath_right, frameRec_deathRight, collRectangle, {}, 0, WHITE);
        } else {
            DrawTexturePro(playerDeath_left, frameRec_deathLeft, collRectangle, {}, 0, WHITE);
        }
    } else if (diggingUp || diggingLeft || diggingDown || diggingRight) {
        if (diggingRight) {
            idleFrame = 4;
            DrawTexturePro(player_digRight, frameRec_digRight, collRectangle, {}, 0, WHITE);
        }
        if (diggingUp) {
            idleFrame = 4;
            DrawTexturePro(player_digUp, frameRec_digUp, collRectangle, {}, 0, WHITE);
        }
        if (diggingLeft) {
            idleFrame = 4;
            DrawTexturePro(player_digLeft, frameRec_digLeft, collRectangle, {}, 0, WHITE);
        }
        if (diggingDown) {
            idleFrame = 4;
            DrawTexturePro(player_digDown, frameRec_digDown, collRectangle, {}, 0, WHITE);
        }
    } else {
        if (lives > 0 && r0l1 == 0 && !moving && !diggingUp && !diggingLeft &&
            !diggingDown &&
            !diggingRight) {
            DrawTexturePro(player_idleRight, frameRec_iR, collRectangle, {}, 0, WHITE);
        }
        if (lives > 0 && r0l1 == 1 && !moving && !diggingUp && !diggingLeft &&
            !diggingDown &&
            !diggingRight) {
            DrawTexturePro(player_idleLeft, frameRec_iL, collRectangle, {}, 0,
                           WHITE);
        }
    }
}

void Game::Player::drawPlayerHub() {
    if (moving) {
        if (animation_up) {
            idleFrame = 0;
            hubIdleLeft = idleLeftSitting;
            hubIdleRight = idleRightSitting;
            DrawTexturePro(hubUp, rec_HubUp, collRectangle, {}, 0, WHITE);
        }
        if (animation_down) {
            idleFrame = 0;
            hubIdleLeft = idleLeftSitting;
            hubIdleRight = idleRightSitting;
            DrawTexturePro(hubDown, rec_HubDown, collRectangle, {}, 0, WHITE);
        }
        if (animation_right) {
            idleFrame = 0;
            hubIdleLeft = idleLeftSitting;
            hubIdleRight = idleRightSitting;
            DrawTexturePro(hubRight, rec_HubRight, collRectangle, {}, 0, WHITE);
        }
        if (animation_left) {
            idleFrame = 0;
            hubIdleLeft = idleLeftSitting;
            hubIdleRight = idleRightSitting;
            DrawTexturePro(hubLeft, rec_HubLeft, collRectangle, {}, 0, WHITE);
        }
    } else {
        if (r0l1 == 0) {
            DrawTexturePro(hubIdleRight, rec_HubIdleRight, collRectangle, {}, 0,
                           WHITE);
        }
        if (r0l1 == 1) {
            DrawTexturePro(hubIdleLeft, rec_HubIdleLeft, collRectangle, {}, 0,
                           WHITE);
        }
    }
}

/*Game::Player::~Player() {
    delete this;
}*/