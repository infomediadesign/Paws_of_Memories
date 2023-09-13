#pragma once

#include <vector>
#include "raylib.h"
#include "string"

enum cutscene {
    startToMenuTransition,
    levelTransition,
    memoryPasteAnim1,
    memoryPasteAnim2,
    memoryPasteAnim3,
    intro,
    outro
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
        Rectangle levelTransRec = {0.0f, 0.0f, (float) levelTrans.width/ 13, (float) levelTrans.height/4};
        Texture2D memoryPaste1 = LoadTexture("assets/graphics/Animation/Sheets/Gallery/Memory1-sheet.png");
        Rectangle memoryPaste1Rec = {0.0f, 0.0f, (float) memoryPaste1.width / 6, (float) memoryPaste1.height / 6};
        Texture2D memoryPaste2 = LoadTexture("assets/graphics/Animation/Sheets/Gallery/Memory2-sheet.png");
        Rectangle memoryPaste2Rec = {0.0f, 0.0f, (float) memoryPaste2.width / 6, (float) memoryPaste2.height / 6};
        Texture2D memoryPaste3 = LoadTexture("assets/graphics/Animation/Sheets/Gallery/Memory3-sheet.png");
        Rectangle memoryPaste3Rec = {0.0f, 0.0f, (float) memoryPaste3.width / 6, (float) memoryPaste3.height / 6};
        //intro
        int currentIntroPart = 0;
        Texture2D intro1 = LoadTexture("assets/graphics/Animation/Sheets/Screens/Intro/Intro_1.png");
        Rectangle intro1Rec = {0.0f, 0.0f, (float) intro1.width, (float) intro1.height};
        Texture2D intro2 = LoadTexture("assets/graphics/Animation/Sheets/Screens/Intro/Intro_2.png");
        Rectangle intro2Rec = {0.0f, 0.0f, (float) intro2.width/7, (float) intro2.height/7};
        Texture2D intro3 = LoadTexture("assets/graphics/Animation/Sheets/Screens/Intro/Intro_3.png");
        Rectangle intro3Rec = {0.0f, 0.0f, (float) intro3.width/7, (float) intro3.height/7};
        Texture2D intro4 = LoadTexture("assets/graphics/Animation/Sheets/Screens/Intro/Intro_4.png");
        Rectangle intro4Rec = {0.0f, 0.0f, (float) intro4.width/7, (float) intro4.height/7};
        //outro
        Texture2D outro1 = LoadTexture("assets/graphics/Animation/Sheets/Screens/Outro/Outro_1.png");
        Rectangle outro1Rec = {0.0f, 0.0f, (float) outro1.width/6, (float) outro1.height/10};
        Texture2D outro2 = LoadTexture("assets/graphics/Animation/Sheets/Screens/Outro/Outro_2.png");
        Rectangle outro2Rec = {0.0f, 0.0f, (float)  outro2.width/6, (float) outro2.height/10};
        Texture2D outro3 = LoadTexture("assets/graphics/Animation/Sheets/Screens/Outro/Outro_3.png");
        Rectangle outro3Rec = {0.0f, 0.0f, (float)  outro3.width/6, (float) outro3.height/10};
        Texture2D outro4 = LoadTexture("assets/graphics/Animation/Sheets/Screens/Outro/Outro_4.png");
        Rectangle outro4Rec = {0.0f, 0.0f, (float)  outro4.width/6, (float) outro4.height/10};
        Texture2D outro5 = LoadTexture("assets/graphics/Animation/Sheets/Screens/Outro/Outro_5.png");
        Rectangle outro5Rec = {0.0f, 0.0f, (float)  outro5.width/6, (float) outro5.height/10};
        Texture2D outro6 = LoadTexture("assets/graphics/Animation/Sheets/Screens/Outro/Outro_6.png");
        Rectangle outro6Rec = {0.0f, 0.0f, (float)  outro6.width/6, (float) outro6.height/10};


        std::vector<Texture2D> cutsceneList = {startToMenu, levelTrans, memoryPaste1, memoryPaste2, memoryPaste3, intro1, intro2, intro3, intro4, outro1, outro2,outro3, outro4, outro5, outro6 };
        std::vector<Rectangle> recList = {startMenuRec, levelTransRec, memoryPaste1Rec, memoryPaste2Rec, memoryPaste3Rec, intro1Rec, intro2Rec, intro3Rec, intro4Rec, outro1Rec, outro2Rec, outro3Rec,
        outro4Rec, outro5Rec, outro6Rec};
    };
}