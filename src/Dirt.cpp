//
// Created by konst on 18.04.2023.
//

#include "Dirt.h"

Game::Dirt::Dirt(int dirtX, int dirtY) {
    setPos(dirtX, dirtY);
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