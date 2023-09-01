//
// Created by picos on 05.07.2023.
//

#include "Door.h"

Game::Door::Door(int posX, int posY, int type) {
    this->setPos((float) posX, (float) posY);
    this->setCollRec(this->getPos().x, this->getPos().y, 24, 24);
    this->type = type;
}

void Game::Door::drawDoor() {
    if (!open) {
        frameRec = {0, 0, 24, 24};
        DrawTexturePro(this->getTexture(), frameRec,
                       Rectangle{this->getPos().x, this->getPos().y, frameRec.width, frameRec.height},
                       {}, 0, WHITE);
    } else if (open && isOpening) {
        frameCounter++;
        if (frameCounter >= (6 / frameSpeed)) {

            frameCounter = 0;
            currentFrame++;

            if(currentFrame == 2) isOpening = false;

            frameRec.x = (float) currentFrame * (float) this->getTexture().width / 3;
        }
        DrawTexturePro(this->getTexture(), frameRec,
                       Rectangle{this->getPos().x, this->getPos().y, frameRec.width, frameRec.height},
                       {}, 0, WHITE);
    } else if (open && !isOpening) {
        frameRec = {48, 0, 24, 24};
        DrawTexturePro(this->getTexture(), frameRec,
                       Rectangle{this->getPos().x, this->getPos().y, frameRec.width, frameRec.height},
                       {}, 0, WHITE);
    }
}
