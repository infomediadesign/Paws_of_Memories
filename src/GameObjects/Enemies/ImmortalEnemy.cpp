//
// Created by konst on 06.08.2023.
//

#include "ImmortalEnemy.h"

game::ImmortalEnemy::ImmortalEnemy(int posX, int posY) {
    this->setPos((float) posX, (float) posY);
    this->setTexture(texIdle);
    this->setCollRec((float) posX, (float) posY, 24, 24);
    this->moveSpeed = 1;
    this->destructable = false;
}

void game::ImmortalEnemy::move() {
    switch (direction) {
        case moveUp:
            this->pos.y -= moveSpeed;
            break;
        case moveLeft:
            this->pos.x -= moveSpeed;
            break;
        case moveDown:
            this->pos.y += moveSpeed;
            break;
        case moveRight:
            this->pos.x += moveSpeed;
            break;
    }
}

void game::ImmortalEnemy::updateEnemy() {
    this->setCollRec(this->getPos().x, this->getPos().y, 24, 24);
}

void game::ImmortalEnemy::moveAnimation() {
    framesCounter++;
    switch (direction) {
        case moveUp:
            if (framesCounter >= (13 / framesSpeed)) {

                framesCounter = 0;
                currentFrame++;

                if (currentFrame > 8) currentFrame = 0;

                recUp.x = (float) currentFrame * (float) texUp.width / 9;
            }
            break;
        case moveLeft:
            if (framesCounter >= (13 / framesSpeed)) {

                framesCounter = 0;
                currentFrame++;

                if (currentFrame > 8) currentFrame = 0;

                recLeft.x = (float) currentFrame * (float) texLeft.width / 9;
            }
            break;
        case moveDown:
            if (framesCounter >= (13 / framesSpeed)) {

                framesCounter = 0;
                currentFrame++;

                if (currentFrame > 8) currentFrame = 0;

                recDown.x = (float) currentFrame * (float) texDown.width / 9;
            }
            break;
        case moveRight:
            if (framesCounter >= (13 / framesSpeed)) {

                framesCounter = 0;
                currentFrame++;

                if (currentFrame > 8) currentFrame = 0;

                recRight.x = (float) currentFrame * (float) texRight.width / 9;
            }
            break;
    }
}

void game::ImmortalEnemy::idleAnimation() {
    framesCounter++;
    if (framesCounter >= (13 / framesSpeed)) {

        framesCounter = 0;
        currentFrame++;

        if (currentFrame > 8) currentFrame = 0;

        recIdle.x = (float) currentFrame * (float) texIdle.width / 9;
    }
}

void game::ImmortalEnemy::huntPlayer() {
    // no code yet so for now
    move();
}

void game::ImmortalEnemy::drawEnemy() {
    switch (direction) {
        case idle:
            DrawTexturePro(texIdle, recIdle, this->getCollRec(), {}, 0, WHITE);
            break;
        case moveUp:
            DrawTexturePro(texUp, recUp, this->getCollRec(), {}, 0, WHITE);
            break;
        case moveLeft:
            DrawTexturePro(texLeft, recLeft, this->getCollRec(), {}, 0, WHITE);
            break;
        case moveDown:
            DrawTexturePro(texDown, recDown, this->getCollRec(), {}, 0, WHITE);
            break;
        case moveRight:
            DrawTexturePro(texRight, recRight, this->getCollRec(), {}, 0, WHITE);
            break;
    }
}
