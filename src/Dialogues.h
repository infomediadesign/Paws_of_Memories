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
    void drawContinousText(std::string fileName);
    void dialogueSkip();
    void resetState();

    Texture2D adultTalking = LoadTexture("assets/graphics/Animation/Sheets/NPC/Colorful (new)/Adult/Adult_talking-sheet.png");
    Texture2D adultBlinking = LoadTexture("assets/graphics/Animation/Sheets/NPC/Colorful (new)/Adult/Adult_blinking-sheet.png");
    Texture2D grandmaTalking = LoadTexture("assets/graphics/Animation/Sheets/NPC/Colorful (new)/Grandmother/Grandma_talking.png");
    Texture2D teenTalking = LoadTexture("assets/graphics/Animation/Sheets/NPC/Colorful (new)/Teeanger/Teenager_talking-sheet.png");
    Texture2D teenBlinking = LoadTexture("assets/graphics/Animation/Sheets/NPC/Colorful (new)/Teeanger/Teenager_blinking-sheet.png");

    std::vector<Texture2D> dBoxes;
    std::string grannyPreTutorial = "assets/textFiles/Granny_pre_Tutorial.txt";
    std::string waitForCompass = "assets/textFiles/Wait_for_compass.txt";
    std::string grannyPreLevel1 = "assets/textFiles/Granny_pre_level1.txt";
    std::string grannyCompass = "assets/textFiles/Granny_compass_text.txt";
    std::string grannyAfterLevel1 = "assets/textFiles/Granny_after_level1.txt";
    std::string adultPreLevel2 = "assets/textFiles/Adult_pre_level2.txt";
    std::string adultAfterLevel2 = "assets/textFiles/Adult_after_level2.txt";
    std::string teenPreLevel3 = "assets/textFiles/Teen_pre_level3.txt";
    std::string teenAfterLevel3 = "assets/textFiles/Teen_after_level3.txt";
    std::vector<std::string> textFiles = {grannyPreTutorial, waitForCompass, grannyPreLevel1, grannyCompass, grannyAfterLevel1, adultPreLevel2, adultAfterLevel2, teenPreLevel3, teenAfterLevel3};
    Texture2D drawnTexture;
    bool open = false;
    bool dialogueDone = false;
    bool dialogueTextDone = false;
    bool skipped = false;
    std::string conversion;
    int charCounter = 0;
    int lineCount = 1;
    std::string saveLine1; // necessary for some reason, or the lines get overwritten
    std::string saveLine2; // necessary for some reason, or the lines get overwritten
    std::string saveLine3; // necessary for some reason, or the lines get overwritten
    const char *finalOutput1; // Output of corresponding line
    const char *finalOutput2; // Output of corresponding line
    const char *finalOutput3; // Output of corresponding line
    const char *finalOutput4; // Output of corresponding line
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