//
// Created by Nicole on 28.04.2023.
//
#include "Memories.h"
#include "raylib.h"
#pragma once


Game::Memory::Memory(int memoryX, int memoryY) {
    setPos(memoryX, memoryY);
    setCollRec(this->getPos().x, this->getPos().y, 24, 24);
}
