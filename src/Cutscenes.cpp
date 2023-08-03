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
            framesCounter++;
            if (framesCounter >= (60 / framesSpeed)) {

                framesCounter = 0;
                currentFrame++;

                recList[0].x = (float) currentFrame * (float) cutsceneList[0].width / 25;

                if (currentFrame > 24) {
                    cutsceneDone = true;
                    currentFrame = 0;
                }
            }
            DrawTexturePro(cutsceneList[0], recList[0],
                           Rectangle{0, 0, recList[0].width, recList[0].height},
                           {}, 0, WHITE);
            break;
        case levelTransition: // case 1
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
            DrawTexturePro(cutsceneList[1], recList[1],
                           Rectangle{0, 0, recList[1].width, recList[1].height},
                           {}, 0, WHITE);
            break;
        case gameOverScreen: // case 2
            // Anpassen, konstanter Screen? repeating? in Gamesceen?
            framesCounter++;
            if (framesCounter >= (60 / framesSpeed)) {

                framesCounter = 0;
                currentFrame++;

                recList[2].x = (float) currentFrame * (float) cutsceneList[2].width / 2;

                if (currentFrame > 1) {
                    cutsceneDone = true;
                    currentFrame = 0;
                }
            }
            DrawTexturePro(cutsceneList[2], recList[2],
                           Rectangle{0, 0, recList[2].width, recList[2].height},
                           {}, 0, WHITE);
            break;
    }
}