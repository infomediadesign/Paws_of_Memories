//
// Created by konst on 01.05.2023.
//

#include "raylib.h"
#include "LevelData.h"
#include "GameScreen.h"

void Game::GameScreen::LoadTextures() {
    playerTexture = LoadTexture("");
}

void Game::GameScreen::InitPlayer() {
    Vector2 playerStartPosition;
    //playerStartPosition.x = array place;
    //playerStartPosition.y = array place;
    player = std::make_shared<Player>();
    player->setPos(playerStartPosition.x, playerStartPosition.y);
    player->setTexture(playerTexture);
    player->active = true;
}