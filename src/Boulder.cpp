//
// Created by Nicole on 26.04.2023.
//

// I copied the Code from "Dirt.cpp" and tried to change it accordingly.

#include <vector> //compiler told me to include this so I could use the "std"-thing in l.34
#include "Boulder.h"
#include "Dirt.h" // Included Dirt head as Boulder movement is dependant on Dirt

Game::Boulder::Boulder(int boulderX, int boulderY) {
    setPos(boulderX, boulderY);
}

Vector2 Game::Boulder::getPos() {
    return pos;
}

void Game::Boulder::setPos(int inputX, int inputY) {
    pos.x = inputX;
    pos.y = inputY;
}

Texture2D Game::Boulder::getTexture() {
    return boulder;
}

void Game::Boulder::setTexture(Texture2D image) {
    boulder =  image;
}

//Here I am trying to make the boulder move when the dirt around it disappears. I used chat gpt for help.

// checking if boulder can move
bool canBoulderMove(Game::Boulder boulder, std::vector<Game::Dirt>& dirtVector) {
    for (auto& dirt : dirtVector) {

        // checking if there is dirt next to the boulder
        if (dirt.getPos().x == boulder.getPos().x - 1 && dirt.getPos().y == boulder.getPos().y ||
            dirt.getPos().x == boulder.getPos().x + 1 && dirt.getPos().y == boulder.getPos().y ||
            dirt.getPos().x == boulder.getPos().x && dirt.getPos().y == boulder.getPos().y - 1 ||
            dirt.getPos().x == boulder.getPos().x && dirt.getPos().y == boulder.getPos().y + 1) {
            return false; // If Dirt is next to the boulder it can't be moved
        }
    }
    return true; // If there is no Dirt next to the boulder it can be moved
}

//I didn't manage to implement movement
