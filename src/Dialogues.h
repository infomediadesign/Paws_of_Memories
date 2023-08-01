#pragma once

#include <vector>
#include <string>

class Dialogues {
    std::vector<std::string> dialogueFile;

    Dialogues();

    void drawDialogue(std::string fileName);

    //void drawCutsceneDialogue(std::string fileName); Wenn nötig
};