//
// Created by konst on 15.05.2023.
//

#include "raylib.h"

#ifndef RAYLIBSTARTER_SPRITES_H
#define RAYLIBSTARTER_SPRITES_H
#endif //RAYLIBSTARTER_SPRITES_H

namespace Game {
    struct Sprite {
        Vector2 pos = {0.0f, 0.0f};
        Texture2D texture{};
        bool active = true;

        Sprite() = default;
    };
}