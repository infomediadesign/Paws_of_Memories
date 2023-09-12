#include "Cutscenes.h"
#include "GameScreen.h"

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

                recList[0].x = (currentFrame / 5) * (float) cutsceneList[0].width / 5;
                recList[0].y = (currentFrame % 5) * (float) cutsceneList[0].height / 5;

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

                recList[1].x = (currentFrame % 13) * (float) cutsceneList[1].width / 13;
                recList[1].y = (currentFrame / 13) * (float) cutsceneList[1].height / 4;

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

                recList[2].x = (currentFrame % 6) * (float) cutsceneList[2].width / 6;
                recList[2].y = (currentFrame / 6) * (float) cutsceneList[2].height / 6;

                if (currentFrame > 35 && currentFrame <= 40) {
                    recList[2].x = 5 * (float) cutsceneList[2].width / 6;
                    recList[2].y = 5 * (float) cutsceneList[2].height / 6;
                }
                if (currentFrame > 40) {
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

                recList[3].x = (currentFrame % 6) * (float) cutsceneList[3].width / 6;
                recList[3].y = (currentFrame / 6) * (float) cutsceneList[3].height / 6;

                if (currentFrame > 35 && currentFrame <= 40) {
                    recList[3].x = 5 * (float) cutsceneList[3].width / 6;
                    recList[3].y = 5 * (float) cutsceneList[3].height / 6;
                }
                if (currentFrame > 40) {
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

                recList[4].x = (currentFrame % 6) * (float) cutsceneList[4].width / 6;
                recList[4].y = (currentFrame / 6) * (float) cutsceneList[4].height / 6;


                if (currentFrame > 35 && currentFrame <= 40) {
                    recList[4].x = 5 * (float) cutsceneList[4].width / 6;
                    recList[4].y = 5 * (float) cutsceneList[4].height / 6;
                }
                if (currentFrame > 40) {
                    currentFrame = 0;
                    cutsceneDone = true;
                }
            }
            break;
        case intro: //case 5

        switch(currentIntroPart){
            case 0:
                framesCounter++;
                DrawTexturePro(cutsceneList[5], recList[5],//intro 1
                               Rectangle{0, 0, recList[5].width, recList[5].height},
                               {}, 0, WHITE);

                if (framesCounter >= (60 / framesSpeed)) {//intro 1

                    framesCounter = 0;
                    currentFrame++;

                    recList[5].x = (currentFrame) * (float) cutsceneList[5].width;
                    if (currentFrame > 1 && currentFrame <= 5) {
                        recList[5].x = 5 * (float) cutsceneList[5].width ;
                    }
                    if (currentFrame == 5){
                        currentFrame = 0;
                        currentIntroPart++;
                    }
                }
                break;
            case 1:
                framesCounter++;
                DrawTexturePro(cutsceneList[6], recList[6],//intro 2
                               Rectangle{0, 0, recList[6].width, recList[6].height},
                               {}, 0, WHITE);
                if (framesCounter >= (60 / framesSpeed)) {//intro 2

                    framesCounter = 0;
                    currentFrame++;

                    recList[6].x = (currentFrame % 7) * (float) cutsceneList[6].width / 7;
                    recList[6].y = (currentFrame / 7) * (float) cutsceneList[6].height / 7;

                    if (currentFrame > 48){
                        currentFrame = 0;
                        currentIntroPart++;
                    }
                }
                break;
            case 2:
                framesCounter++;
                DrawTexturePro(cutsceneList[7], recList[7],//intro 3
                               Rectangle{0, 0, recList[7].width, recList[7].height},
                               {}, 0, WHITE);
                if (framesCounter >= (60 / framesSpeed)) {//intro 3

                    framesCounter = 0;
                    currentFrame++;

                    recList[7].x = (currentFrame % 7) * (float) cutsceneList[7].width / 7;
                    recList[7].y = (currentFrame / 7) * (float) cutsceneList[7].height / 7;

                    if (currentFrame > 48){
                        currentFrame = 0;
                        currentIntroPart++;
                    }
                }
                break;
            case 3:
                framesCounter++;
                DrawTexturePro(cutsceneList[8], recList[8],//intro 4
                               Rectangle{0, 0, recList[8].width, recList[8].height},
                               {}, 0, WHITE);
                if (framesCounter >= (60 / framesSpeed)) {//intro 4

                    framesCounter = 0;
                    currentFrame++;

                    recList[8].x = (currentFrame % 7) * (float) cutsceneList[8].width / 7;
                    recList[8].y = (currentFrame / 7) * (float) cutsceneList[8].height / 7;

                    if (currentFrame > 48) {
                        currentFrame = 0;
                        currentIntroPart++;
                    }
                }
                break;
            case 4:
                DrawTexturePro(cutsceneList[1], recList[1],
                               Rectangle{0, 0, recList[1].width, recList[1].height},
                               {}, 0, WHITE);
                framesCounter++;
                if (framesCounter >= (60 / framesSpeed)) {

                    framesCounter = 0;
                    currentFrame++;

                    recList[1].x = (currentFrame % 13) * (float) cutsceneList[1].width / 13;
                    recList[1].y = (currentFrame / 13) * (float) cutsceneList[1].height / 4;

                    if (currentFrame > 51) {
                        cutsceneDone = true;
                        currentFrame = 0;
                    }
                }
                break;

        }
    }
}
