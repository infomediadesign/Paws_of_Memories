//
// Created by Nicole on 28.04.2023.
//
#include "Memories.h"
#include "raylib.h"
#pragma once


Game::Memory::Memory(int memoryX, int memoryY) {
    setPos((float) memoryX, (float) memoryY);
    setCollRec(this->getPos().x, this->getPos().y, 24, 24);
}

void Game::Memory::drawMemory() {
    frameCounter++;
    if (frameCounter >= (6 / frameSpeed)) {

        frameCounter = 0;

        if (delay == 0) currentFrame++;
        if (currentFrame == 6) delay++;

        if (delay == 20) {
            delay = 0;
            currentFrame = 0;
        }

        frameRec.x = (float) currentFrame * (float) this->getTexture().width / 7;
    }
    DrawTexturePro(this->getTexture(), frameRec,
                   Rectangle{this->getPos().x, this->getPos().y, frameRec.width, frameRec.height},
                   {}, 0, WHITE);
}
