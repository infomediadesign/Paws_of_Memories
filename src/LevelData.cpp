//
// Created by konst on 02.05.2023.
//

#include "LevelData.h"
#include "nlohmann/json.hpp"
#include "fstream"

Game::LevelData::LevelData() {}

/*void setSpawn() {

}*/

void createLevelLayout() {

}

int *Game::LevelData::returnLevelLayout(std::string levelFile) {
    std::ifstream tilesetDescriptionFile(levelFile);
    nlohmann::json tilesetDescription = nlohmann::json::parse("assets/maps/BigTileset.json");
    tilesetDescriptionFile.close();

    std::ifstream levelMapFile(levelFile);
    nlohmann::json levelMap = nlohmann::json::parse("assets/maps/BigTileset.json");
    levelMapFile.close();

    Texture2D tileAtlasTexture = LoadTexture((tilesetDescription["image"].get<std::string>()).c_str());

    Vector2 vec = {0, 0};
    Rectangle rec = {0, 0, levelMap["tilewidth"], levelMap["tileheight"]};

    for (auto const &layer : levelMap["layers"]) {
        if (layer["type"] == "tilelayer" && layer["visible"]) {
            for (auto const &tileId : layer["data"]) {
                if (tileId != 0) { //Code für was er tun soll; Hier drawed er die benötigte Textur
                    rec.x = (float) ((int) tileId - 1 % (int) tilesetDescription["columns"]) *
                            (float) levelMap["tilewidth"];
                    rec.y = (float) floor((float) tileId / (float) tilesetDescription["columns"]) *
                            (float) levelMap["tilewidth"];

                    DrawTextureRec(tileAtlasTexture, rec, vec, WHITE);
                }

                vec.x += (float) levelMap["tilewidth"]; //geht zum  nächsten Tile
                if (vec.x >= (float) layer["width"] * (float) levelMap["tilewidth"]) { //geht zur nächsten Reihe, wenn er am Ende angekommen ist
                    vec.x = 0;
                    vec.y += (float) levelMap["tileheight"];
                }
            }
        }
    }
    // return level array
    return nullptr;
}

void Game::LevelData::updateLevelLayout(int position, int value) {
    levelLayout[position] = value;
}
