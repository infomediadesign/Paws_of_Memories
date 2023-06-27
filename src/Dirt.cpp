//
// Created by konst on 18.04.2023.
//

#include "Dirt.h"

Game::Dirt::Dirt(int dirtX, int dirtY) {
    setPos(dirtX, dirtY);
    setCollRec(this->getPos().x, this->getPos().y, 24, 24);
}

//Game::Dirt::Dirt() {}