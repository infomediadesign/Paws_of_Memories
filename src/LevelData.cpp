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
                    if(tileId == 7) { //Walls
                        levelLayout[tileCounter] = 6;
                    } else if(tileId == 1 || tileId == 2 || tileId == 3 || tileId == 4 || tileId == 8 || tileId == 9 || tileId == 10 || tileId == 15  || tileId == 16 || tileId == 17 || tileId == 18 || tileId == 22 || tileId == 23|| tileId == 24 ) { //Dirt
                        levelLayout[tileCounter] = 2;
                    } else if(tileId == 13) { //Player. Spawnt aktuell auf der falschen Stelle da es 2x 20 gibt
                        levelLayout[tileCounter] = 1;
                    } else if(tileId == 12) { //Memories
                        levelLayout[tileCounter] = 4;
                    } else if(tileId == 29 || tileId == 30 || tileId == 31 || tileId == 32 ) { //Boulder
                        levelLayout[tileCounter] = 3;
                    } else if(tileId == 6) { //Enemy
                        levelLayout[tileCounter] = 5;
                    } else if(tileId == 28) { //Door wrong number
                        levelLayout[tileCounter] = 7;
                    } else {
                        levelLayout[tileCounter] = 0;
                    }
                } else {
                    levelLayout[tileCounter] = 0;
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
