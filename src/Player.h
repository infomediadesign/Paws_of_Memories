//
// Created by konst on 21.04.2023.
//

#include "raylib.h"

#ifndef RAYLIBSTARTER_PLAYER_H
#define RAYLIBSTARTER_PLAYER_H

#endif //RAYLIBSTARTER_PLAYER_H

namespace Game {
    struct Player{
    public:

        Player(int playerX, int playerY);

        Vector2 pos = {0, 0};
        Texture2D player= LoadTexture("assets/graphics/cat.png");

        int lives = 3;
        int speed = 25; //A tile is 25 pixels big

        void move();

        Vector2 getPos();

        void setPos(int inputX, int inputY);

        Texture2D getTexture();

        void setTexture(Texture2D image);

        void take(int direction);

        bool spaceAvailable(Vector2 vector);
    };
}
