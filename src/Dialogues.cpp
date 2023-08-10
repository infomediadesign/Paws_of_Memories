//
// Created by konst on 29.07.2023.
//

#include <fstream>
#include <sstream>
#include "Dialogues.h"

Dialogues::Dialogues() {

}

void Dialogues::drawDialogueBox(int lifetime) {
    frameCounter++;
    switch (dialogue) {
        case 0:
            if (frameCounter >= (6 / frameSpeed)) {

                frameCounter = 0;

                /*if(!dialogueTextDone) {
                    drawnTexture = grandmaTalking;
                    frameRec = {(float) (currentFrame % 9) * 480, 0, 480, 270};
                    currentFrame++;
                }*/

                if (currentFrame < 9) {
                    drawnTexture = grandmaTalking;
                    frameRec = {(float) currentFrame * 480, 0, 480, 270};
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

                /*if(!dialogueTextDone) {
                    drawnTexture = adultTalking;
                    frameRec = {(float) (currentFrame % 9) * 480, 0, 480, 270};
                    currentFrame++;
                }*/

                if (currentFrame < 9) {
                    drawnTexture = adultTalking;
                    frameRec = {(float) currentFrame * 480, 0, 480, 270};
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

                /*if(!dialogueTextDone) {
                    drawnTexture = teenTalking;
                    frameRec = {(float) (currentFrame % 9) * 480, 0, 480, 270};
                    currentFrame++;
                }*/

                if (currentFrame < 9) {
                    drawnTexture = teenTalking;
                    frameRec = {(float) currentFrame * 480, 0, 480, 270};
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
}

void Dialogues::drawContinousText(std::string fileName) {
    std::ifstream file;
    file.open(fileName);
    if(!file.fail()) {

    } else {
     file.close();
     dialogueTextDone = true;
    }
}
