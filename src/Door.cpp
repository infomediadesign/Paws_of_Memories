//
// Created by picos on 05.07.2023.
//

#include "Door.h"

Game::Door::Door(int posX, int posY) {
    setPos(posX, posY);
    setCollRec(this->getPos().x, this->getPos().y, 24, 24);

}
