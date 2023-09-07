//
// Created by konst on 29.07.2023.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include "Dialogues.h"

Dialogues::Dialogues() {

}

void Dialogues::drawDialogueBox(int lifetime) {
    frameCounter++;
    switch (dialogue) {
        case 0:
            if (frameCounter >= (6 / frameSpeed)) {

                frameCounter = 0;

                if(!dialogueTextDone) {
                    drawnTexture = grandmaTalking;
                    frameRec = {(float) (currentFrame % 9) * 480, 0, 480, 270};
                    currentFrame++;
                } else {
                    dialogueDone = true;
                    frameRec = {0, 0, 480, 270};
                }
            } else if (currentFrame == 0 && frameCounter < 2) {
                drawnTexture = grandmaTalking;
            }
            DrawTexturePro(drawnTexture, frameRec, Rectangle{0, 0, frameRec.width, frameRec.height}, {}, 0, WHITE);
            break;
        case 1:
            if (frameCounter >= (6 / frameSpeed)) {

                frameCounter = 0;

                if(!dialogueTextDone) {
                    drawnTexture = adultTalking;
                    frameRec = {(float) (currentFrame % 9) * 480, 0, 480, 270};
                    currentFrame++;
                } else {
                    dialogueDone = true;
                    drawnTexture = adultBlinking;
                    frameRec = {(float) (currentFrame % 2) * 480, 0, 480, 270};
                    if(currentFrame % 2) {
                        currentFrame++;
                    } else {
                        dialogueDelay++;
                        if (dialogueDelay == 30) {
                            currentFrame++;
                            dialogueDelay = 0;
                        }
                    }
                }
            } else if (currentFrame == 0 && frameCounter < 2) {
                drawnTexture = adultTalking;
            }
            DrawTexturePro(drawnTexture, frameRec, Rectangle{0, 0, frameRec.width, frameRec.height}, {}, 0, WHITE);
            break;
        case 2:
            if (frameCounter >= (6 / frameSpeed)) {

                frameCounter = 0;

                if(!dialogueTextDone) {
                    drawnTexture = teenTalking;
                    frameRec = {(float) (currentFrame % 9) * 480, 0, 480, 270};
                    currentFrame++;
                } else {
                    dialogueDone = true;
                    drawnTexture = teenBlinking;
                    frameRec = {(float) (currentFrame % 2) * 480, 0, 480, 270};
                    if(currentFrame % 2) {
                        currentFrame++;
                    } else {
                        dialogueDelay++;
                        if (dialogueDelay == 30) {
                            currentFrame++;
                            dialogueDelay = 0;
                        }
                    }
                }
            } else if (currentFrame == 0 && frameCounter < 2) {
                drawnTexture = teenTalking;
            }
            DrawTexturePro(drawnTexture, frameRec, Rectangle{0, 0, frameRec.width, frameRec.height}, {}, 0, WHITE);
            break;
    }
}

void Dialogues::drawDialogueText(std::string fileName) {
    std::ifstream file;
    file.open(fileName);

    if(!file.fail()) {
        std::stringstream buffer;
        buffer << file.rdbuf();
        std::string content;
        content = buffer.str(); // somehow make this load continuously
        const char *output = content.c_str();
        // if(ganze Text message geladen) {dialogueTextDone = true;}
        DrawTextPro(testFont, output, Vector2{140, 180}, {}, 0, 10, 1, BLACK);
        if(!open) {
            file.close();
        }
    } else {
        file.close();
        //dialogueTextDone = true;
    }
}

void Dialogues::dialogueSkip() { // all dialogues end at frame 9
    currentFrame = 9;
    dialogueTextDone = true;
    skipped = true;
}

void Dialogues::drawContinousText(std::string fileName) {
    std::ifstream file;
    file.open(fileName);
    if(!file.fail()) {
        std::stringstream buffer;
        buffer << file.rdbuf();
        std::string content;
        content = buffer.str();
        // frame by frame
        if (frameCounter >= (5 / frameSpeed) && charCounter < content.length() && !skipped) {
            if(content.at(charCounter) == '\n') {
                lineCount++;
                if(lineCount == 2) saveLine1 = conversion;
                if(lineCount == 3) saveLine2 = conversion;
                if(lineCount == 4) saveLine3 = conversion;
                conversion = "";
                if(lineCount == 2) finalOutput1 = saveLine1.c_str();
                if(lineCount == 3) finalOutput2 = saveLine2.c_str();
                if(lineCount == 4) finalOutput3 = saveLine3.c_str();
            } else {
                switch (lineCount) {
                    case 1:
                        conversion.push_back(content.at(charCounter));
                        finalOutput1 = conversion.c_str();
                        break;
                    case 2:
                        conversion.push_back(content.at(charCounter));
                        finalOutput2 = conversion.c_str();
                        break;
                    case 3:
                        conversion.push_back(content.at(charCounter));
                        finalOutput3 = conversion.c_str();
                        break;
                    case 4:
                        conversion.push_back(content.at(charCounter));
                        finalOutput4 = conversion.c_str();
                        break;
                }
            }
            charCounter++;
        }
        if(charCounter >= content.length() && !skipped) {
            dialogueTextDone = true;
        }
        if(skipped) {
            int line = 1;
            std::string convert;
            for(char i : content) {
                if (i == '\n') {
                    line++;
                    if (line == 2) saveLine1 = convert;
                    if (line == 3) saveLine2 = convert;
                    if (line == 4) saveLine3 = convert;
                    convert = "";
                    if (line == 2) finalOutput1 = saveLine1.c_str();
                    if (line == 3) finalOutput2 = saveLine2.c_str();
                    if (line == 4) finalOutput3 = saveLine3.c_str();
                } else {
                    switch (line) {
                        case 1:
                            convert.push_back(i);
                            finalOutput1 = convert.c_str();
                            break;
                        case 2:
                            convert.push_back(i);
                            finalOutput2 = convert.c_str();
                            break;
                        case 3:
                            convert.push_back(i);
                            finalOutput3 = convert.c_str();
                            break;
                        case 4:
                            convert.push_back(i);
                            finalOutput4 = convert.c_str();
                            break;
                    }
                }
            }
        }
        DrawTextPro(testFont, finalOutput1, Vector2{140, 162}, {}, 0, 32, 0, BLACK);
        DrawTextPro(testFont, finalOutput2, Vector2{140, 175}, {}, 0, 32, 0, BLACK);
        DrawTextPro(testFont, finalOutput3, Vector2{140, 188}, {}, 0, 32, 0, BLACK);
        DrawTextPro(testFont, finalOutput4, Vector2{140, 201}, {}, 0, 32, 0, BLACK);
        if(!dialogueTextDone) {
            interactText = pressToSkip.c_str();
        } else {
            interactText = pressToClose.c_str();
        }
        DrawTextPro(testFont, interactText, Vector2{292, 215}, {}, 0, 32, 0, BLACK);
    } else {
     file.close();
     dialogueTextDone = true;
    }}

void Dialogues::resetState() {
    open = false;
    dialogueDone = false;
    dialogueTextDone = false;
    currentFrame = 0;
    frameCounter = 0;
    conversion = "";
    saveLine1 = "";
    saveLine2 = "";
    saveLine3 = "";
    finalOutput1 = "";
    finalOutput2 = "";
    finalOutput3 = "";
    finalOutput4 = "";
    lineCount = 1;
    charCounter = 0;
    skipped = false;
}
