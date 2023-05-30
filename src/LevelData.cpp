//
// Created by konst on 02.05.2023.
//

#include "LevelData.h"
#include "nlohmann/json.hpp"
#include "fstream"

Game::LevelData::LevelData() {

}

void setSpawn() {

}

void createLevelLayout() {

}

int *Game::LevelData::returnLevelLayout(int input) {
    int currentLevelLayout[(Game::ScreenHeight / 48) - 1 + (Game::ScreenWidth / 48)] = {};
    // search for corresponding Level in text file
    // get level array
    /*std::ifstream tilesetDescriptionFile("assets/maps/TileSet.tsj");
    nlohmann::json tilesetDescription = nlohmann::json::parse(tilesetDescriptionFile);
    tilesetDescriptionFile.close();*/
    //can I get this as an array?
    std::ifstream levelMapFile("assets/maps/TestLevel.tmj.json");
    nlohmann::json levelMap = nlohmann::json::parse(levelMapFile);
    levelMapFile.close();
    // return level array
    return nullptr;
}
