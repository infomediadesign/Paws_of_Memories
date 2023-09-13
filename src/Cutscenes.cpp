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
                case memoryPasteAnim3: // case 4 this includes the outro as they are played back to back
                    switch (currentOutroPart) {
                        case 0:
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
                                currentOutroPart++;
                            }
                        }
                        break;
                        case 1://outro part 1
                            DrawTexturePro(cutsceneList[9], recList[9],
                                           Rectangle{0, 0, recList[9].width, recList[9].height},
                                           {}, 0, WHITE);
                            framesCounter++;
                            if (framesCounter >= (60 / framesSpeed)) {

                                framesCounter = 0;
                                currentFrame++;

                                recList[9].x = (currentFrame % 6) * (float) cutsceneList[9].width / 6;
                                recList[9].y = (currentFrame / 6) * (float) cutsceneList[9].height / 10;

                                if (currentFrame > 59) {
                                    currentFrame = 0;
                                    currentOutroPart++;
                                }
                            }
                            break;
                        case 2://outro part 2

                            DrawTexturePro(cutsceneList[10], recList[10],
                                           Rectangle{0, 0, recList[10].width, recList[10].height},
                                           {}, 0, WHITE);
                            framesCounter++;
                            if (framesCounter >= (60 / framesSpeed)) {

                                framesCounter = 0;
                                currentFrame++;

                                recList[10].x = (currentFrame % 6) * (float) cutsceneList[10].width / 6;
                                recList[10].y = (currentFrame / 6) * (float) cutsceneList[10].height / 10;

                                if (currentFrame > 59) {
                                    currentFrame = 0;
                                    currentOutroPart++;
                                }
                            }
                            break;
                        case 3://outro part 3

                            DrawTexturePro(cutsceneList[11], recList[11],
                                           Rectangle{0, 0, recList[11].width, recList[11].height},
                                           {}, 0, WHITE);
                            framesCounter++;
                            if (framesCounter >= (60 / framesSpeed)) {

                                framesCounter = 0;
                                currentFrame++;

                                recList[11].x = (currentFrame % 6) * (float) cutsceneList[11].width / 6;
                                recList[11].y = (currentFrame / 6) * (float) cutsceneList[11].height / 10;

                                if (currentFrame > 59) {
                                    currentFrame = 0;
                                    currentOutroPart++;
                                }
                            }
                            break;
                        case 4://outro part 4

                            DrawTexturePro(cutsceneList[12], recList[12],
                                           Rectangle{0, 0, recList[12].width, recList[12].height},
                                           {}, 0, WHITE);
                            framesCounter++;
                            if (framesCounter >= (60 / framesSpeed)) {

                                framesCounter = 0;
                                currentFrame++;

                                recList[12].x = (currentFrame % 6) * (float) cutsceneList[12].width / 6;
                                recList[12].y = (currentFrame / 6) * (float) cutsceneList[12].height / 10;

                                if (currentFrame > 59) {
                                    currentFrame = 0;
                                    currentOutroPart++;
                                }
                            }
                            break;
                        case 5://outro part 5

                            DrawTexturePro(cutsceneList[13], recList[13],
                                           Rectangle{0, 0, recList[13].width, recList[13].height},
                                           {}, 0, WHITE);
                            framesCounter++;
                            if (framesCounter >= (60 / framesSpeed)) {

                                framesCounter = 0;
                                currentFrame++;

                                recList[13].x = (currentFrame % 6) * (float) cutsceneList[13].width / 6;
                                recList[13].y = (currentFrame / 6) * (float) cutsceneList[13].height / 10;

                                if (currentFrame > 59) {
                                    currentFrame = 0;
                                    currentOutroPart++;
                                }
                            }
                            break;
                        case 6://outro part 6
                            DrawTexturePro(cutsceneList[14], recList[14],
                                           Rectangle{0, 0, recList[14].width, recList[14].height},
                                           {}, 0, WHITE);
                            framesCounter++;
                            if (framesCounter >= (60 / framesSpeed)) {

                                framesCounter = 0;
                                currentFrame++;

                                recList[14].x = (currentFrame % 6) * (float) cutsceneList[14].width / 6;
                                recList[14].y = (currentFrame / 6) * (float) cutsceneList[14].height / 10;

                                if (currentFrame > 59) {
                                    currentFrame = 0;
                                    currentOutroPart++;
                                    cutsceneDone = true;
                                }
                            }
                            break;
                        case 7://level trans
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
                        default:
                            cutsceneDone = true;
                    }
            break;
        case intro: //case 5

        switch(currentIntroPart){
            case 0://intro part 1
                framesCounter++;
                DrawTexturePro(cutsceneList[5], recList[5],
                               Rectangle{0, 0, recList[5].width, recList[5].height},
                               {}, 0, WHITE);

                if (framesCounter >= (60 / framesSpeed)) {

                    framesCounter = 0;
                    currentFrame++;

                    recList[5].x = (currentFrame) * (float) cutsceneList[5].width;
                    if (currentFrame > 1 && currentFrame <= 48) {
                        recList[5].x = (currentFrame) * (float) cutsceneList[5].width;
                        recList[5].x = (currentFrame) * (float) cutsceneList[5].height;
                    }
                    if (currentFrame > 48){
                        currentFrame = 0;
                        currentIntroPart++;
                    }
                }
                break;
            case 1://intro part 2
                framesCounter++;
                DrawTexturePro(cutsceneList[6], recList[6],
                               Rectangle{0, 0, recList[6].width, recList[6].height},
                               {}, 0, WHITE);
                if (framesCounter >= (60 / framesSpeed)) {

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
            case 2://intro part 3
                framesCounter++;
                DrawTexturePro(cutsceneList[7], recList[7],
                               Rectangle{0, 0, recList[7].width, recList[7].height},
                               {}, 0, WHITE);
                if (framesCounter >= (60 / framesSpeed)) {

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
            case 3://intro part 4
                framesCounter++;
                DrawTexturePro(cutsceneList[8], recList[8],
                               Rectangle{0, 0, recList[8].width, recList[8].height},
                               {}, 0, WHITE);
                if (framesCounter >= (60 / framesSpeed)) {

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
            case 4://level transfer because it was at the end of the intro
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
            default:
                cutsceneDone = true;

        }
        break;
    }
}
