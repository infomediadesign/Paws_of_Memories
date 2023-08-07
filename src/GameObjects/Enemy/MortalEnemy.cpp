//
// Created by konst on 06.08.2023.
//

#include "MortalEnemy.h"

game::MortalEnemy::MortalEnemy(int posX, int posY) {
    this->setPos((float) posX, (float) posY);
    this->setTexture(texIdle);
    this->setCollRec((float) posX, (float) posY, 24, 24);
}

void game::MortalEnemy::move() {

}

void game::MortalEnemy::updateEnemy() {

}

void game::MortalEnemy::moveAnimation() {

}

void game::MortalEnemy::idleAnimation() {

}

void game::MortalEnemy::deathAnimation() {

}
