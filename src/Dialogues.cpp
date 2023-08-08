//
// Created by konst on 29.07.2023.
//

#include "Dialogues.h"

Dialogues::Dialogues() {

}

void Dialogues::drawDialogueBox(int lifetime) {
    frameCounter++;
    switch (dialogue) {
        case 0:
            if (frameCounter >= (6 / frameSpeed)) {

                frameCounter = 0;

                if (currentFrame < 9) {
                    drawnTexture = grandmaTalking;
                    frameRec = {(float) currentFrame * 480, 0, 480, 270};
                    currentFrame++;
                } else {
                    dialogueDone = true;
                    /*  Textur nicht vorhanden
                    drawnTexture = grandmaBlinking;
                    frameRec = {(float) (currentFrame % 2) * 480, 0, 480, 270};
                    dialogueDelay++;
                    if (dialogueDelay == 5) {
                        currentFrame++;
                        dialogueDelay = 0;
                    }*/
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

}

void Dialogues::dialogueSkip() { // all dialogues end at frame 9
    currentFrame = 9;
}
