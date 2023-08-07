//
// Created by konst on 11.06.2023.
//

#include "Wall.h"

Game::Wall::Wall(int posX, int posY) {
    setPos((float) posX, (float) posY);
    setCollRec(this->getPos().x, this->getPos().y, 24, 24);
}