#pragma once

#include <vector>
#include "raylib.h"
#include "string"

enum cutscene {
    startToMenuTransition,
    levelTransition,
    gameOverScreen
};

namespace Game {
    class Cutscenes {
    public:
        Cutscenes();
        void drawCutscene(int scene);
        bool cutsceneDone = false;
        int cutscene;
    private:
        int currentFrame = 0;
        int framesCounter = 0;
        int framesSpeed = 10;
        Texture2D startToMenu = LoadTexture("assets/graphics/Animation/Sheets/Background/Startscreen/Start_Screen_switch_animation.png");
        Rectangle startMenuRec = {0.0f, 0.0f, (float) startToMenu.width / 5, (float) startToMenu.height / 5};
        Texture2D levelTrans = LoadTexture("assets/graphics/Animation/Sheets/Screens/Leveltransfer_animation_paws.png");
        Rectangle levelTransRec = {0.0f, 0.0f, (float) startToMenu.width, (float) startToMenu.height};
        Texture2D gameOver = LoadTexture("assets/graphics/Animation/Sheets/Screens/GameOver_Screen-Sheet.png");
        Rectangle gameOverRec = {0.0f, 0.0f, (float) gameOver.width / 2, (float) startToMenu.height};

        std::vector<Texture2D> cutsceneList = {startToMenu, levelTrans, gameOver};
        std::vector<Rectangle> recList = {startMenuRec, levelTransRec, gameOverRec};
    };
}