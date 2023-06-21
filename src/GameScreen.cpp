//
// Created by konst on 01.05.2023.
//

#include "raylib.h"
#include "LevelData.h"
#include "GameScreen.h"

Game::GameScreen::GameScreen() {
    InitPlayer(24, 54);
}

void Game::GameScreen::LoadTextures() {
    player->getTexture();
    wall1 = LoadTexture("assets/graphics/Template/Wall_and_Door/Cracked_Wall_1.png");
    wall2 = LoadTexture("assets/graphics/Template/Wall_and_Door/wall_2.png");
    wall3 = LoadTexture("assets/graphics/Template/Wall_and_Door/wall_3.png");
    dirt->setTexture(LoadTexture("assets/graphics/Template/Tiles/Tiles.png"));
    memory->setTexture(LoadTexture("assets/graphics/Animation/Sheets/Objects/Polaroid-Sheet.png"));
}

void Game::GameScreen::InitPlayer(int valueX, int valueY) {
    Vector2 playerStartPosition;
    //playerStartPosition.x = array place;
    //playerStartPosition.y = array place;
    //for now:
    playerStartPosition.x = valueX;
    playerStartPosition.y = valueY;
    player->setPos(playerStartPosition.x, playerStartPosition.y);
    player->active = true;
    player->collRectangle = {player->getPos().x, player->getPos().y, 24, 24};
}

void Game::GameScreen::generateMap() {
    // import Level Data, in this case an array, from LevelData.h. Use the functions from the class (not working yet)
    levelData;
    // It should create the current level
    float renderScale{}; //those two are relevant to drawing and code-cleanliness
    renderScale = std::min(GetScreenHeight() /
                           (float) 480, //Calculates how big or small the canvas has to be rendered.
                           GetScreenWidth() / (float) 270);
    int layout[(Game::ScreenHeight / 24) - 1][(Game::ScreenWidth / 24)] =
            {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
             6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 4, 2, 2, 2, 2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 2, 2, 2, 2, 2, 2, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 2, 2, 2, 2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,
             6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6};

    Rectangle frameRec_Wall = {0.0f, 0.0f, (float) wall1.width, (float) wall1.height};
    Rectangle *wallSize = new Rectangle;

    Rectangle frameRec_dirtT = {0.0f, 0.0f, (float) dirt->getTexture().width, (float) dirt->getTexture().height};
    Rectangle *dirtTSize = new Rectangle;
    //TEXTURE FOR MEMORIES TO TEST LEVEL CREATION

    Rectangle frameRec_Memories = {0.0f, 0.0f, (float) memory->getTexture().width / 7, (float) memory->getTexture().height};
    Rectangle *memoriesSize = new Rectangle;
    wallSize->height = frameRec_Wall.height * renderScale;
    wallSize->width = frameRec_Wall.width * renderScale;
    dirtTSize->height = frameRec_dirtT.height * renderScale;
    dirtTSize->width = frameRec_dirtT.width * renderScale;
    memoriesSize->height = frameRec_Memories.height * renderScale;
    memoriesSize->width = frameRec_Memories.width * renderScale;

    for (int i = 0; i < (Game::ScreenHeight / 24-1); i++) {
        for (int z = 0; z < (Game::ScreenWidth / 24); z++) {
            Vector2 coordinates = {float(z * 24), float(i * 24 + 30)};
            coordinates.x *= -1 * renderScale;
            coordinates.y *= -1 * renderScale;
            if (tiles[i][z] == 0) {
                //Draw Nothing
            } else if (tiles[i][z] == 1) {
                //Draw Player
            } else if (tiles[i][z] == 2) {
                //Draw Dirt
                DrawTexturePro(dirt->getTexture(), frameRec_dirtT, *dirtTSize, coordinates, 0, WHITE);
            } else if (tiles[i][z] == 3) {
                //Draw Boulder
            } else if (tiles[i][z] == 4) {
                //Draw Memory -=- No animation implemented yet -=-
                //Game::Memory *memory = new Game::Memory(coordinates.x, coordinates.y);
                //memory->setTexture(memories);
                //memory->setPos(-coordinates.x, -coordinates.y);
                DrawTexturePro(memory->getTexture(), frameRec_Memories, *memoriesSize, coordinates, 0, WHITE);
            } else if (tiles[i][z] == 5) {
                //Draw Enemy
            } else if (tiles[i][z] == 6) {
                //Draw Wall
                DrawTexturePro(wall1, frameRec_Wall, *wallSize, coordinates, 0, WHITE);
                /*int w = rand()%(3-1+1);randomizer
                if(w==1)DrawTexturePro(wall1, frameRec_Wall, *wallSize, coordinates, 0, WHITE);
                if(w==2)DrawTexturePro(wall2, frameRec_Wall, *wallSize, coordinates, 0, WHITE);
                if(w==3)DrawTexturePro(wall3, frameRec_Wall, *wallSize, coordinates, 0, WHITE);*/
            } else {}
        }
    }

    /*
     * Array rules:
     * 0 = Nothing
     * 1 = Player
     * 2 = Dirt
     * 3 = Boulder
     * 4 = Memory
     * 5 = Enemy
     * 6 = Wall
     * 7 = Exit
     */
}

void Game::GameScreen::ProcessInput() {
    // player Input here, just what the button presses do, not the interactions
    player->updatePlayer();
}

void Game::GameScreen::Update() {
    // Game code here. Interactions etc.
}

void Game::GameScreen::Draw() {
    // Draw the canvas + background
}