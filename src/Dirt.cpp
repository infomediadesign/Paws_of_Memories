//
// Created by konst on 18.04.2023.
//

#include "Dirt.h"

Game::Dirt::Dirt(int dirtX, int dirtY) {
    setPos(dirtX, dirtY);
}

//Game::Dirt::Dirt() {}

Vector2 Game::Dirt::getPos() {
    return pos;
}

void Game::Dirt::setPos(int inputX, int inputY) {
    pos.x = inputX;
    pos.y = inputY;
}

Texture2D Game::Dirt::getTexture() {
    return texture;
}

void Game::Dirt::setTexture(Texture2D image) {
    texture =  image;
}

void Game::Dirt::setRectangle(float posX, float posY, float width, float heigth) {
    collRectangle = {posX, posY, width, heigth};
}

Rectangle Game::Dirt::getRectangle() {
    return collRectangle;
}