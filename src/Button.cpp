#include "Button.h"


Game::Button::Button(int valX, int valY, Texture2D texture) {
    setPos(valX, valY);
    setTexture(texture);
}

void Game::Button::setPos(int valX, int valY) {
    this->pos.x = (float) valX;
    this->pos.y = (float) valY;
}

Vector2 Game::Button::getPos() {
    return pos;
}

void Game::Button::setTexture(Texture2D newTexture) {
    this->texture = newTexture;
}

Texture2D Game::Button::getTexture() {
    return texture;
}