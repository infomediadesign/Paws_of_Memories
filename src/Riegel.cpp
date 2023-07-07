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


    // Eingabe abfragen
    Vector2 mousePosition = GetMousePosition();

    mousePosition.x /= renderScale;
    mousePosition.y /= renderScale;


    //std::cout << mousePosition.x << mousePosition.y << std::endl;

    if (CheckCollisionPointRec(mousePosition, {pos.x, pos.y, 24, 24}) &&
        IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {

        this->pos.x = mousePosition.x - 24 / 2;
    }

}





