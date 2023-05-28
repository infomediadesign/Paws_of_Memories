//
// Created by konst on 21.04.2023.
//

#include "raylib.h"
#include "config.h"
#include "Player.h"

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
    // statement after && makes sure that the player can't move past borders

    if (target_x < pos.x && target_x != 0) { pos.x -= 3; } //left
    if (target_x > pos.x && target_x !=912) { pos.x += 3; } //right
    if (target_y > pos.y && target_x !=492) { pos.y += 3; } //down
    if (target_y < pos.y && target_y != 60) { pos.y -= 3; } //up

    //Problem fixed: Durch den Tastendruck wurde das movement auf "true" gesetzt.
    // es kann jedoch nur neuer input genommen werden wenn moving "false" ist, deswegen konnte kein weiterer input genommen werden.


    // Setting flags for movement and animation to false once target area has been reached or if target area is past borders
    if (target_x == pos.x && target_y == pos.y) { // Problem with misaligned movement fixed by jointing these with &&
        moving = false;
        animation_left = false;
        animation_right = false;
        animation_up = false;
        animation_down = false;
    }

    if (target_x == 0 || target_x ==912 || target_x ==492 || target_y ==60 && pos.x % tileSize == 0 && pos.y % tileSize == 0 ) { //modulo geht nicht weil pos float ist
        moving =false;
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

   if (!moving && r0l1 == 0){ //Idle Animation right
        if (framesCounter >= (60 / framesSpeed)) {

            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 3) currentFrame = 0;

            frameRec_idleRight.x = (float) currentFrame * (float) player_idleRight.width / 4;

        }
    }

    if (!moving && r0l1 == 1){ //Idle Animation left
        if (framesCounter >= (60 / framesSpeed)) {

            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 3) currentFrame = 0;

            frameRec_idleLeft.x = (float) currentFrame * (float) player_idleLeft.width / 4;

        }
    }

    //Handle input
    if (IsKeyDown(KEY_A) && !moving) { // Left
        moving = true;
        animation_left = true;
        target_x = pos.x - speed;
        r0l1=1; // 1 = links, für idle animation
    }

    if (IsKeyDown(KEY_D) && !moving) { // Right
        moving = true;
        animation_right = true;
        target_x = pos.x + speed;
        r0l1=0; //0 = rechts, für idle animation
    }

    if (IsKeyDown(KEY_W) && !moving) { // Up
        moving = true;
        animation_up = true;
        target_y = pos.y - speed;
    }

    if (IsKeyDown(KEY_S) && !moving) { // Down
        moving = true;
        animation_down = true;
        target_y = pos.y + speed;
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

Vector2 Game::Player::getPos() {
    return pos;
}

void Game::Player::setPos(float inputX, float inputY) {
    pos.x = inputX;
    pos.y = inputY;
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