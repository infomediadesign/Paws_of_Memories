//
// Created by Nicole on 26.04.2023.
//

// I copied the Code from "Dirt.cpp" and tried to change it accordingly.

#include <vector> //compiler told me to include this so I could use the "std"-thing in l.34
#include "Boulder.h"
#include "Dirt.h" // Included Dirt head as Boulder movement is dependant on Dirt

Game::Boulder::Boulder(int boulderX, int boulderY) {
    this->setPos(boulderX, boulderY);
}

void Game::Boulder::fall() {
    //Vector2 right = {this->getPos().x + 24, this->getPos().y};
    //Vector2 left = {this->getPos().x - 24, this->getPos().y};
    if(this->pos.y <= 222) { //condition for falling down --> Either check through vectors, or by collision
        pos.y += 2;
    }
}

//Here I am trying to make the boulder move when the dirt around it disappears. I used chat gpt for help.

// checking if boulder can move
bool canBoulderMove(Game::Boulder boulder, std::vector<Game::Dirt>& dirtVector) {
    for (auto& dirt : dirtVector) {

        // checking if there is dirt next to the boulder
        if (dirt.getPos().x == boulder.getPos().x - 24 && dirt.getPos().y == boulder.getPos().y ||
            dirt.getPos().x == boulder.getPos().x + 24 && dirt.getPos().y == boulder.getPos().y ||
            dirt.getPos().x == boulder.getPos().x && dirt.getPos().y == boulder.getPos().y - 24/* ||
            dirt.getPos().x == boulder.getPos().x && dirt.getPos().y == boulder.getPos().y + 1
            Der Boulder kann nicht nach oben fallen oder?*/) {
            return false; // If Dirt is next to the boulder it can't be moved
        }
        // requires checks for other boulders, walls, memories, the player in some situations aswell
    }
    return true; // If there is no Dirt next to the boulder it can be moved
}

//I didn't manage to implement movement
