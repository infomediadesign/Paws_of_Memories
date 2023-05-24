//
// Created by konst on 21.04.2023.
//

#include "raylib.h"
#include "config.h"
#include "Player.h"

Game::Player::Player(int playerX, int playerY) {
    setPos(playerX, playerY);
}

void Game::Player::move() {

    twoKeysPressed = (IsKeyDown(KEY_W) && (IsKeyDown(KEY_A) || IsKeyDown(KEY_D))) ||
                     (IsKeyDown(KEY_S) && (IsKeyDown(KEY_A) || IsKeyDown(KEY_D))) ||
                     (IsKeyDown(KEY_W) && (IsKeyDown(KEY_S))) ||
                     (IsKeyDown(KEY_A) && (IsKeyDown(KEY_D)));
//grabbing commands implemented in the checks (destroy dirt/ grab memory from adjacent space)
    Vector2 check;
    framesCounter++;
    /*
     * MOVEMENT NEEDS TO BE READJUSTED
     * - make movement instantly, then delay the next input
     * - Make an option for continous movement between tiles
     */

    //New Movement

    //Handle Player Movement

    //Move the player

    if (target_x < pos_pl.x) { pos_pl.x -= 2; } //left
    if (target_x > pos_pl.x) { pos_pl.x += 2; } //right
    if (target_y > pos_pl.y) { pos_pl.y += 2; } //down
    if (target_y < pos_pl.y) { pos_pl.y -= 2; } //up

    //Problem fixed: Durch den Tastendruck wurde das movement auf "true" gesetzt.
    // es kann jedoch nur neuer input genommen werden wenn moving "false" ist, deswegen konnte kein weiterer input genommen werden.

    if (target_x == pos_pl.x && target_y == pos_pl.y){ // Problem with misaligned movement fixed by jointing these with &&
        moving = false;
    }
    //Check for destination

    //Handle input
    if (IsKeyDown(KEY_A) && !moving) { // Left //wird aus irgendeinem grund instant ausgelöst
        moving = true;
        target_x = pos_pl.x - speed;
        Texture2D player_left = LoadTexture("assets/graphics/Animation/Sheets/Cat/Walk/Cat_Walk_Left.png");
    }

    if (IsKeyDown(KEY_D) && !moving) { // Right
        moving = true;
        target_x = pos_pl.x + speed;
        Texture2D player_right = LoadTexture("assets/graphics/Animation/Sheets/Cat/Walk/Cat_Walk_Right.png");
    }

    if (IsKeyDown(KEY_W) && !moving) { // Up
        moving = true;
        target_y = pos_pl.y - speed;
        Texture2D player_back = LoadTexture("assets/graphics/Animation/Sheets/Cat/Walk/Cat_Walk_Back.png");
    }

    if (IsKeyDown(KEY_S) && !moving) { // Down
        moving = true;
        target_y = pos_pl.y + speed;
        Texture2D player_front = LoadTexture(
                "assets/graphics/Animation/Sheets/Cat/Walk/Cat_Walk_Front.png");
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
            if (spaceAvailable(check)) {}
        } else if (IsKeyDown(KEY_S) && !IsKeyDown(KEY_W) && !IsKeyDown(KEY_D) && !IsKeyDown(KEY_A)) {
            check.x = getPos().x + speed;
            check.y = getPos().y;
            if (spaceAvailable(check)) {}
        } else if (IsKeyDown(KEY_D) && !IsKeyDown(KEY_S) && !IsKeyDown(KEY_A) && !IsKeyDown(KEY_W)) {
            check.x = getPos().x;
            check.y = getPos().y + speed;

            if (spaceAvailable(check)) {}
        }
    } /*else {//wasd commands; simple movement; Animation included
        if (IsKeyDown(KEY_W)  && !IsKeyDown(KEY_D) && !IsKeyDown(KEY_S) && !IsKeyDown(KEY_A)) {
            if (framesCounter >= (60 / framesSpeed)) {

                framesCounter = 0;
                currentFrame++;

                if (currentFrame > 2) {
                    currentFrame = 0;
                    if (getPos().y > 60) pos_pl.y -= speed;
                }
                frameRec_back.x = (float) currentFrame * (float) player_back.width / 4;
            }
        }
        if (IsKeyDown(KEY_A) && !IsKeyDown(KEY_W) && !IsKeyDown(KEY_D) && !IsKeyDown(KEY_S)) {
            if (framesCounter >= (60 / framesSpeed)) {
                framesCounter = 0;
                currentFrame++;

                if (currentFrame > 2) {
                    currentFrame = 0;
                    if (getPos().x > 0) pos_pl.x -= speed;
                }
                frameRec_left.x = (float) currentFrame * (float) player_left.width / 4;
            }
            r0l1 = 1;
        }
        if (IsKeyDown(KEY_S) && !IsKeyDown(KEY_W) && !IsKeyDown(KEY_D) && !IsKeyDown(KEY_A)) {
            if (framesCounter >= (60 / framesSpeed)) {
                framesCounter = 0;
                currentFrame++;

                if (currentFrame > 2) {
                    currentFrame = 0;
                    if (getPos().y +48< Game::ScreenHeight) pos_pl.y += speed;
                }

                frameRec_front.x = (float) currentFrame * (float) player_front.width / 4;
            }
        }
        if (IsKeyDown(KEY_D) && !IsKeyDown(KEY_S) && !IsKeyDown(KEY_A) && !IsKeyDown(KEY_W)) {
            if (getPos().x +48 < Game::ScreenWidth) {
                if (framesCounter >= (60 / framesSpeed)) {
                    framesCounter = 0;
                    currentFrame++;

                    if (currentFrame > 2) {
                        currentFrame = 0;
                        pos_pl.x += speed;
                    }
                    frameRec_right.x = (float) currentFrame * (float) player_right.width / 4;
                }
            }
            r0l1 = 0;
        }
        else if (IsKeyUp(KEY_W && KEY_A && KEY_S && KEY_D) && r0l1 == 0) { //idle animation right side
            if (framesCounter >= (60 / framesSpeed)) {
                framesCounter = 0;
                currentFrame++;

                if (currentFrame > 3) currentFrame = 0;

                frameRec_idleRight.x = (float) currentFrame * (float) player_idleRight.width / 4;
            }

        }
        else if (IsKeyUp(KEY_W && KEY_A && KEY_S && KEY_D) && r0l1 == 1) { // idle animation left side
            if (framesCounter >= (60 / framesSpeed)) {
                framesCounter = 0;
                currentFrame++;

                if (currentFrame > 3) currentFrame = 0;

                frameRec_idleLeft.x = (float) currentFrame * (float) player_idleLeft.width / 4;
            }
        }
        /*else {
            if (framesCounter >= (60 / framesSpeed)) {
                framesCounter = 0;
                currentFrame++;

                if (currentFrame > 3) currentFrame = 0;

                frameRec_right.x = (float) currentFrame * (float) player_right.width / 4;
            }
        }*/ //potentially unnecessary now?

    // Animation - Already declared in movement, can be deleted, but kept until agreement
    /*
    if (IsKeyDown(KEY_W) && !IsKeyDown(KEY_D) && !IsKeyDown(KEY_S) && !IsKeyDown(KEY_A)) {
        if (framesCounter >= (60 / framesSpeed)) {

            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 3) currentFrame = 0;

            frameRec_back.x = (float) currentFrame * (float) player_back.width / 4;
        }

    } else if (IsKeyDown(KEY_A) && !IsKeyDown(KEY_W) && !IsKeyDown(KEY_D) && !IsKeyDown(KEY_S)) {
        if (framesCounter >= (60 / framesSpeed)) {
            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 3) currentFrame = 0;

            frameRec_left.x = (float) currentFrame * (float) player_left.width / 4;
        }

    } else if (IsKeyDown(KEY_S) && !IsKeyDown(KEY_W) && !IsKeyDown(KEY_D) && !IsKeyDown(KEY_A)) {
        if (framesCounter >= (60 / framesSpeed)) {
            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 3) currentFrame = 0;

            frameRec_front.x = (float) currentFrame * (float) player_front.width / 4;
        }

    } else if (IsKeyDown(KEY_D) && !IsKeyDown(KEY_S) && !IsKeyDown(KEY_A) && !IsKeyDown(KEY_W)) {
        if (framesCounter >= (60 / framesSpeed)) {
            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 3) currentFrame = 0;

            frameRec_right.x = (float) currentFrame * (float) player_right.width / 4;
        }

    } else if (IsKeyUp(KEY_W && KEY_A && KEY_S && KEY_D) && r0l1 == 0) {
        if (framesCounter >= (60 / framesSpeed)) {
            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 3) currentFrame = 0;

            frameRec_idleRight.x = (float) currentFrame * (float) player_idleRight.width / 4;
        }

    } else if (IsKeyUp(KEY_W && KEY_A && KEY_S && KEY_D) && r0l1 == 1) {
        if (framesCounter >= (60 / framesSpeed)) {
            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 3) currentFrame = 0;

            frameRec_idleLeft.x = (float) currentFrame * (float) player_idleLeft.width / 4;
        }

    } else {
        if (framesCounter >= (60 / framesSpeed)) {
            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 3) currentFrame = 0;

            frameRec_right.x = (float) currentFrame * (float) player_right.width / 4;
        }
    }*/
    //}
}

Vector2 Game::Player::getPos() {
    return pos_pl;
}

void Game::Player::setPos(float inputX, float inputY) {
    pos_pl.x = inputX;
    pos_pl.y = inputY;
}


Texture2D Game::Player::getTexture() {
    return player;
}

void Game::Player::setTexture(Texture2D image) {
    player = image;
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
        if (pos_pl.y + speed /*== dirtLocation.y*/ && pos_pl.x /*== dirtLocation.x*/) {
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