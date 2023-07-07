#include <iostream>
#include "Riegel.h"


Game::Riegel::Riegel(int RiegelX, int RiegelY) {
    this->setPos(RiegelX, RiegelY);

}
void Game::Riegel::MoveOnlyOne(){

}
void Game::Riegel::ColUpdate(){

}
void Game::Riegel::PlaceUpdate(){

}

void Game::Riegel::move() {
    setCollRec(this->getPos().x, this->getPos().y, 24, 24);
