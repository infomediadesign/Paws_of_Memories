//
// Created by konst on 18.04.2023.
//

#include "Dirt.h"

Game::Dirt::Dirt(int dirtX, int dirtY) {
    setPos((float) dirtX, (float) dirtY);
    setCollRec(this->getPos().x, this->getPos().y, 24, 24);
    adjRecUp = {this->getPos().x, this->getPos().y-24, 2, 2};
    adjRecLeft = {this->getPos().x-24, this->getPos().y, 2, 2};
    adjRecDown = {this->getPos().x, this->getPos().y+24, 2, 2};
    adjRecRight = {this->getPos().x+24, this->getPos().y, 2, 2};
}

Rectangle Game::Dirt::getadjRecUp() {
    return this->adjRecUp;
}

Rectangle Game::Dirt::getadjRecLeft() {
    return this->adjRecLeft;
}

Rectangle Game::Dirt::getadjRecDown() {
    return this->adjRecDown;
}

Rectangle Game::Dirt::getadjRecRight() {
    return this->adjRecRight;
}

void Game::Dirt::vanishAnimation() {
    DrawTexturePro(texture, frameRec_dirtT,
                   Rectangle{this->getPos().x, this->getPos().y, 24, 24},
                   {}, 0, WHITE);
    frameCounter++;
    if (frameCounter >= (10 / frameSpeed)) {

        frameCounter = 0;
        currentFrame++;

        if (currentFrame > 2) {
            this->vanished = true;
        }

        frameRec_dirtT.x = (float) currentFrame * (float) texture.width / 3;
    }
}
