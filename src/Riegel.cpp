#include <iostream>
#include "Riegel.h"


Game::Riegel::Riegel(int RiegelX, int RiegelY) {
    this->setPos(RiegelX, RiegelY);
}

void Game::Riegel::move() {

    // Eingabe abfragen
    Vector2 mousePosition = GetMousePosition();

    std::cout << mousePosition.x << mousePosition.y << std::endl;
    if (CheckCollisionPointRec(mousePosition, { pos.x, pos.y, 24, 24 }) &&
        IsMouseButtonDown(MOUSE_LEFT_BUTTON))
    {

        this->pos.x = mousePosition.x - 24 / 2;
    }
}