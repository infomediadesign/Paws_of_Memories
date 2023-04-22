//
// Created by konst on 21.04.2023.
//

#include "raylib.h"

#include "Player.h"

Game::Player::Player(int playerX, int playerY)  {
    setPos(playerX, playerY);
}

void Game::Player::move() {
    //grabbing commands implemented in the checks (destroy dirt/ grab memory from adjacent space)
    Vector2 check;

    if(IsKeyDown(KEY_LEFT_CONTROL) || IsKeyDown(KEY_RIGHT_CONTROL)) {
        if (IsKeyDown(KEY_W)) {
            check.x = getPos().x;
            check.y = getPos().y - speed;
            if(spaceAvailable(check)) {}
        } else if (IsKeyDown(KEY_A)) {
            check.x = getPos().x - speed;
            check.y = getPos().y;
            if(spaceAvailable(check)) {}
        } else if (IsKeyDown(KEY_S)) {
            check.x = getPos().x + speed;
            check.y = getPos().y;
            if(spaceAvailable(check)) {}
        } else if (IsKeyDown(KEY_D)) {
            check.x = getPos().x;
            check.y = getPos().y + speed;
            if(spaceAvailable(check)) {}
        }
    } else {//wasd commands; simple movement
        if (IsKeyDown(KEY_W)) {
            check.x = getPos().x;
            check.y = getPos().y - speed;
            if (spaceAvailable(check)) {
                pos.y -= speed;
            }
        } else if (IsKeyDown(KEY_A)) {
            check.x = getPos().x - speed;
            check.y = getPos().y;
            if (spaceAvailable(check)) {
                pos.x -= speed;
            }
        } else if (IsKeyDown(KEY_S)) {
            check.x = getPos().x + speed;
            check.y = getPos().y;
            if (spaceAvailable(check)) {
                pos.y += speed;
            }
        } else if (IsKeyDown(KEY_D)) {
            check.x = getPos().x;
            check.y = getPos().y + speed;
            if (spaceAvailable(check)) {
                pos.x += speed;
            }
        }
    }
}

Vector2 Game::Player::getPos()  {
    return pos;
}

void Game::Player::setPos(int inputX,  int inputY)  {
    pos.x = inputX;
    pos.y = inputY;
}



Texture2D Game::Player::getTexture()  {
    return player;
}

void Game::Player::setTexture(Texture2D image)  {
    player =  image;
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