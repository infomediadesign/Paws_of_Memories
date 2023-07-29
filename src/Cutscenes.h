#pragma once

#include "raylib.h"
#include "string"

enum cutscene {
    startToMenu
};

namespace Game {
    class Cutscenes {
    public:
        Cutscenes();
        void drawCutscene(int scene);
        bool cutsceneDone = false;
    private:
        int currentFrame = 0;
        int framesCounter = 0;
        int framesSpeed = 10;
        Texture2D startToMenu = LoadTexture("assets/graphics/Animation/Sheets/Background/Startscreen/Start_Screen_switch_animation.png");
        Rectangle startMenuRec = {0.0f, 0.0f, (float) startToMenu.width / 25, (float) startToMenu.height};
    };
}