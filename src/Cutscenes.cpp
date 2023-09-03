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

                recList[1].x = (float) currentFrame * (float) cutsceneList[1].width / 52;

                if (currentFrame > 51) {
                    cutsceneDone = true;
                    currentFrame = 0;
                }
            }
            break;
        case memoryPasteAnim1: // case 2
            break;
        case memoryPasteAnim2: // case 3
            break;
        case memoryPasteAnim3: // case 4
            break;
    }
}