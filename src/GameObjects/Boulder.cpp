//
// Created by Nicole on 26.04.2023.
//

#include "Boulder.h"
//decide direction by checking texture? or manual?

Game::Boulder::Boulder(int boulderX, int boulderY, int dir) {
    this->setPos((float) boulderX, (float) boulderY);
    this->direction = dir;
}

void Game::Boulder::fall() {
    falling = true;
    switch (direction) {
        case FallDown:
            pos.y += 1;
            break;
        case FallUp:
            pos.y -= 1;
            break;
        case FallLeft:
            pos.x -= 1;
            break;
        case FallRight:
            pos.x += 1;
            break;
    }
}

void Game::Boulder::updateBoulder() {
    this->collRectangle = {this->getPos().x, this->getPos().y, 24, 24};
    switch (direction) {
        case FallDown:
            this->setAdjRec(this->getPos().x, this->getPos().y + 24, 24, 24);
            break;
        case FallUp:
            this->setAdjRec(this->getPos().x, this->getPos().y - 24, 24, 24);
            break;
        case FallLeft:
            this->setAdjRec(this->getPos().x - 24, this->getPos().y, 24, 24);
            break;
        case FallRight:
            this->setAdjRec(this->getPos().x + 24, this->getPos().y, 24, 24);
            break;
    }
}

void Game::Boulder::drawBoulder() {
    if(falling) {
        frameCounter++;
        if (frameCounter >= (6 / frameSpeed)) {

            frameCounter = 0;
            currentFrame++;

            if (currentFrame > 4) {
                currentFrame = 0;
            }

            frameRec_Boulder.x = (float) currentFrame * (float) texture.width / 5;
        }
        DrawTexturePro(texture, frameRec_Boulder,
                       Rectangle{this->getPos().x, this->getPos().y, 24, 24},
                       {}, 0, WHITE);
    } else {
        frameCounter = 0;
        currentFrame = 0;
        frameRec_Boulder.x = (float) currentFrame * (float) texture.width / 5;
        DrawTexturePro(texture, frameRec_Boulder,
                       Rectangle{this->getPos().x, this->getPos().y, 24, 24},
                       {}, 0, WHITE);
    }
}
