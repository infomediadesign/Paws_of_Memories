#include <iostream>
#include "Riegel.h"


Game::Riegel::Riegel(int RiegelX, int RiegelY) {
    this->setPos(RiegelX, RiegelY);
}
//
void Game::Riegel::move() {

    // Eingabe abfragen
    Vector2 mousePosition = GetMousePosition();

    renderScale = std::min((float) GetScreenHeight() /
                           (float) 480, //Calculates how big or small the canvas has to be rendered.
                           (float) GetScreenWidth() / (float) 270);

//
    mousePosition.x /= renderScale*1.6999f;
    mousePosition.y /= renderScale*1.6999f;

    std::cout << mousePosition.x << mousePosition.y << std::endl;
    if (CheckCollisionPointRec(mousePosition, { pos.x, pos.y, 24, 24 }) &&
        IsMouseButtonDown(MOUSE_LEFT_BUTTON))
    {

        this->pos.x = mousePosition.x - 24 / 2;
    }
}