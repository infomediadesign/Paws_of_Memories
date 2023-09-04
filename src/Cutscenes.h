#pragma once

#include <vector>
#include "raylib.h"
#include "string"

enum cutscene {
    startToMenuTransition,
    levelTransition,
    memoryPasteAnim1,
    memoryPasteAnim2,
    memoryPasteAnim3
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
        Texture2D memoryPaste1 = LoadTexture("assets/graphics/Animation/Sheets/Gallery/Memory1-sheet.png");
        Rectangle memoryPaste1Rec = {0.0f, 0.0f, (float) memoryPaste1.width / 6, (float) memoryPaste1.height / 6};
        Texture2D memoryPaste2 = LoadTexture("assets/graphics/Animation/Sheets/Gallery/Memory2-sheet.png");
        Rectangle memoryPaste2Rec = {0.0f, 0.0f, (float) memoryPaste2.width / 6, (float) memoryPaste2.height / 6};
        Texture2D memoryPaste3 = LoadTexture("assets/graphics/Animation/Sheets/Gallery/Memory3-sheet.png");
        Rectangle memoryPaste3Rec = {0.0f, 0.0f, (float) memoryPaste3.width / 6, (float) memoryPaste3.height / 6};


        std::vector<Texture2D> cutsceneList = {startToMenu, levelTrans, memoryPaste1, memoryPaste2, memoryPaste3};
        std::vector<Rectangle> recList = {startMenuRec, levelTransRec, memoryPaste1Rec, memoryPaste2Rec, memoryPaste3Rec};
    };
}