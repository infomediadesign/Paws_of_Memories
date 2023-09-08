#include "Cutscenes.h"

Game::Cutscenes::Cutscenes() {

}

void Game::Cutscenes::drawCutscene(int scene) {
    cutscene = scene;
    switch (cutscene) {
        default:
            cutsceneDone = true;
            break;
        case startToMenuTransition: // case 0
            DrawTexturePro(cutsceneList[0], recList[0],
                           Rectangle{0, 0, recList[0].width, recList[0].height},
                           {}, 0, WHITE);
            framesCounter++;
            if (framesCounter >= (60 / framesSpeed)) {

                framesCounter = 0;
                currentFrame++;

                recList[0].x = (currentFrame/5) * (float) cutsceneList[0].width / 5;
                recList[0].y = (currentFrame%5) * (float) cutsceneList[0].height / 5;

                if (currentFrame > 24) {
                    cutsceneDone = true;
                    currentFrame = 0;
                }
            }
            break;
        case levelTransition: // case 1
            DrawTexturePro(cutsceneList[1], recList[1],
                           Rectangle{0, 0, recList[1].width, recList[1].height},
                           {}, 0, WHITE);
            framesCounter++;
            if (framesCounter >= (60 / framesSpeed)) {

                framesCounter = 0;
                currentFrame++;

                recList[1].x = (currentFrame%13) * (float) cutsceneList[1].width / 13;
                recList[1].y = (currentFrame/13) * (float) cutsceneList[1].height / 4;

                if (currentFrame > 51) {
                    cutsceneDone = true;
                    currentFrame = 0;
                }
            }
            break;
        case memoryPasteAnim1: // case 2
            DrawTexturePro(cutsceneList[2], recList[2],
                           Rectangle{0, 0, recList[2].width, recList[2].height},
                           {}, 0, WHITE);
            framesCounter++;
            if (framesCounter >= (60 / framesSpeed)) {

                framesCounter = 0;
                currentFrame++;

                recList[2].x = (currentFrame%6) * (float) cutsceneList[2].width / 6;
                recList[2].y = (currentFrame/6) * (float) cutsceneList[2].height / 6;

                if (currentFrame > 35 && currentFrame <= 40) {
                    recList[2].x = 5 * (float) cutsceneList[2].width / 6;
                    recList[2].y = 5 * (float) cutsceneList[2].height / 6;
                }
                if(currentFrame > 40) {
                    currentFrame = 0;
                    cutsceneDone = true;
                }
            }
            break;
        case memoryPasteAnim2: // case 3
            DrawTexturePro(cutsceneList[3], recList[3],
                           Rectangle{0, 0, recList[3].width, recList[3].height},
                           {}, 0, WHITE);
                    framesCounter++;
                    if (framesCounter >= (60 / framesSpeed)) {

                        framesCounter = 0;
                        currentFrame++;

                        recList[3].x = (currentFrame%6) * (float) cutsceneList[3].width / 6;
                        recList[3].y = (currentFrame/6) * (float) cutsceneList[3].height / 6;

                        if (currentFrame > 35 && currentFrame <= 40) {
                            recList[3].x = 5 * (float) cutsceneList[3].width / 6;
                            recList[3].y = 5 * (float) cutsceneList[3].height / 6;
                        }
                        if(currentFrame > 40) {
                            currentFrame = 0;
                            cutsceneDone = true;
                        }
                    }
            break;
        case memoryPasteAnim3: // case 4
            DrawTexturePro(cutsceneList[4], recList[4],
                           Rectangle{0, 0, recList[4].width, recList[4].height},
                           {}, 0, WHITE);
                            framesCounter++;
                            if (framesCounter >= (60 / framesSpeed)) {

                                framesCounter = 0;
                                currentFrame++;

                                recList[4].x = (currentFrame%6) * (float) cutsceneList[4].width / 6;
                                recList[4].y = (currentFrame/6) * (float) cutsceneList[4].height / 6;


                                if (currentFrame > 35 && currentFrame <= 40) {
                                    recList[4].x = 5 * (float) cutsceneList[4].width / 6;
                                    recList[4].y = 5 * (float) cutsceneList[4].height / 6;
                                }
                                if(currentFrame > 40) {
                                    currentFrame = 0;
                                    cutsceneDone = true;
                                }
                            }
            break;
    }
}