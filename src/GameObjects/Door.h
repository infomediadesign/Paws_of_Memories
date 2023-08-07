//
// Created by Nicole on 05.07.2023.
//
#pragma once

#include "../Sprite.h"

enum type {
    roomEntrance,
    roomExit,
};

namespace Game {
    class Door : public Sprite{
    public:
        Door(int posX, int posY, int type);
        bool open = false;
        int type;
    };
}

