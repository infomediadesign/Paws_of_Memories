//
// Created by picos on 05.07.2023.
//

#include "Door.h"

Game::Door::Door(int posX, int posY, int type) {
    this->setPos((float) posX, (float) posY);
    this->setCollRec(this->getPos().x, this->getPos().y, 24, 24);
    this->type = type;
}