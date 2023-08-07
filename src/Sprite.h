//
// Created by konst on 15.05.2023.
//

#pragma once
#include "raylib.h"

/*
 * This classwill work as follows:
 * It will be inherited by all game objects (player, boulder...)
 * - it has a vector2 pos, which will be used by each game object
 * - same goes for the texture
 * - also a bool weather the texture is active or not
 */

namespace Game {
    struct Sprite {
        Vector2 pos = {}; //vererbt Positionen an alle Objekte
        Texture2D texture = {}; //vererbt eine Textur an alle Objekte
        Rectangle collRectangle = {}; //vererbt ein Rectangle an alle Objekte, für collision
        Rectangle adjRectangle = {}; //vererbt ein Rectangle an alle Objekte, für benachbarte Felder
        bool active = true; //vererbt einen bool, ob das Objekt aktiv ist oder nicht (zestört/tod...)

        Sprite() = default;

        Vector2 getPos() {return this->pos;}
        Texture2D getTexture() {return this->texture;}
        Rectangle getCollRec() {return this->collRectangle;}
        Rectangle getAdjRec() {return this->adjRectangle;}

        void setPos(float inputX, float inputY) {this->pos.x = inputX; this->pos.y = inputY;}
        void setTexture(Texture2D input) {this->texture = input;}
        void setCollRec(float posX, float posY, float width, float heigth) {this->collRectangle= {posX, posY, width, heigth};}
        void setAdjRec(float posX, float posY, float width, float heigth) {this->adjRectangle= {posX, posY, width, heigth};}
    };
}