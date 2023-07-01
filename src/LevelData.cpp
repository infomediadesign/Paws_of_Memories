//
// Created by konst on 02.05.2023.
//

#include "LevelData.h"
#include "nlohmann/json.hpp"
#include "fstream"

Game::LevelData::LevelData() {}

/*void setSpawn() {

}*/

void Game::LevelData::createLevel(std::string levelFile) {
    std::ifstream levelMapFile(levelFile);
    nlohmann::json levelMap = nlohmann::json::parse(levelMapFile);
    levelMapFile.close();

    Vector2 vec = {0, 0};

    tileCounter = 0;
    for (auto const &layer : levelMap["layers"]) {
        if (layer["type"] == "tilelayer" && layer["visible"]) {
            for (auto const &tileId : layer["data"]) {
                if (tileId != 0) { //Code für was er tun soll; Hier drawed er die benötigte Textur
                    if(tileId == 2 || tileId == 3) { //Walls
                        levelLayout[tileCounter] = 6;
                    }
                    if(tileId == 1) { //Dirt
                        levelLayout[tileCounter] = 2;
                    }
                    if(tileId == 6) { //Player
                        levelLayout[tileCounter] = 1;
                    }
                    if(tileId == 10) { //Memories
                        levelLayout[tileCounter] = 4;
                    }
                    if(tileId == 9) { //Boulder
                        levelLayout[tileCounter] = 3;
                    }
                    if(tileId == 7) { //Enemy
                        levelLayout[tileCounter] = 5;
                    }
                    if(tileId == 5) { //Door
                        levelLayout[tileCounter] = 7;
                    }
                }

                vec.x += (float) levelMap["tilewidth"]; //geht zum  nächsten Tile
                if (vec.x >= (float) layer["width"] * (float) levelMap["tilewidth"]) { //geht zur nächsten Reihe, wenn er am Ende angekommen ist
                    vec.x = 0;
                    vec.y += (float) levelMap["tileheight"];
                }
                tileCounter++;
            }
        }
    }
}

int *Game::LevelData::returnLevelLayout() {
    return levelLayout;
}
