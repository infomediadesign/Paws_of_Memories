//
// Created by konst on 15.05.2023.
//

#include "raylib.h"

#ifndef RAYLIBSTARTER_SPRITES_H
#define RAYLIBSTARTER_SPRITES_H
#endif //RAYLIBSTARTER_SPRITES_H

/*
 * This classwill work as follows:
 * It will be inherited by all game objects (player, boulder...)
 * - it has a vector2 pos, which will be used by each game object
 * - same goes for the texture
 * - also a bool weather the texture is active or not
 */

namespace Game {
    struct Sprite {
        Vector2 pos;
        Texture2D texture{};
        bool active = true;

        Sprite() = default;
    };
}