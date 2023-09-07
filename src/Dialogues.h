#pragma once

#include <vector>
#include <string>
#include "raylib.h"

enum dialogue {
    grandma,
    adult,
    teen
};

class Dialogues {
public:
    std::vector<std::string> dialogueFile;

    Dialogues();

    void drawDialogueBox(int lifetime);
    void drawDialogueText(std::string fileName);
    void drawContinousText(std::string fileName);
    void dialogueSkip();
    void resetState();

    Texture2D adultTalking = LoadTexture("assets/graphics/Animation/Sheets/NPC/Colorful (new)/Adult/Adult_talking-sheet.png");
    Texture2D adultBlinking = LoadTexture("assets/graphics/Animation/Sheets/NPC/Colorful (new)/Adult/Adult_blinking-sheet.png");
    Texture2D grandmaTalking = LoadTexture("assets/graphics/Animation/Sheets/NPC/Colorful (new)/Grandmother/Grandma_talking.png");
    Texture2D teenTalking = LoadTexture("assets/graphics/Animation/Sheets/NPC/Colorful (new)/Teeanger/Teenager_talking-sheet.png");
    Texture2D teenBlinking = LoadTexture("assets/graphics/Animation/Sheets/NPC/Colorful (new)/Teeanger/Teenager_blinking-sheet.png");

    std::vector<Texture2D> dBoxes;
    std::vector<std::string> textFiles;
    Texture2D drawnTexture;
    bool open = false;
    bool dialogueDone = false;
    bool dialogueTextDone = false;
    bool skipped = false;
    std::string conversion;
    int charCounter = 0;
    int lineCount = 1;
    std::string saveLine1;
    std::string saveLine2;
    std::string saveLine3;
    const char *finalOutput1;
    const char *finalOutput2;
    const char *finalOutput3;
    const char *finalOutput4;
    const char *interactText;
    std::string pressToSkip = "Press 'Enter' to skip.";
    std::string pressToClose = "Press 'Enter' to close.";
    Font testFont = LoadFont("assets/graphics/Text/Fonts/Cloude_Regular_1.02.ttf");
    int dialogueDelay = 0;
    int dialogue = 0;
    int frameSpeed = 1;
    int frameCounter = 0;
    int currentFrame = 0;
    Rectangle frameRec = {0, 0, 480, 270};

    //void drawCutsceneDialogue(std::string fileName); Wenn nötig
};