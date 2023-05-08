//
// Created by Nicole on 28.04.2023.
//
#include "Memories.h"
#include "raylib.h"
#pragma once


Game::Memory::Memory(int memoryX, int memoryY) {
    setPos(memoryX, memoryY);
}

//Game::Memory::Memory() {}

Vector2 Game::Memory::getPos() {
    return pos;
}

void Game::Memory::setPos(int inputX, int inputY) {
    pos.x = inputX;
    pos.y = inputY;
}

Texture2D Game::Memory::getTexture() {
    return memory;
}

void Game::Memory::setTexture(Texture2D image) {
    memory =  image;
}
