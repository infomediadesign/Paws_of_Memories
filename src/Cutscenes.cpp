#include "Cutscenes.h"

Game::Cutscenes::Cutscenes() {

}

void Game::Cutscenes::drawCutscene(int scene) {
    switch (scene) {
        default:
            framesCounter++;
            if (framesCounter >= (60 / framesSpeed)) {

                framesCounter = 0;
                currentFrame++;

                startMenuRec.x = (float) currentFrame * (float) startToMenu.width / 25;

                if (currentFrame > 24) {
                    cutsceneDone = true;
                    currentFrame = 0;
                }
            }
            if(!cutsceneDone) {
                DrawTexturePro(startToMenu, startMenuRec,
                               Rectangle{0, 0, startMenuRec.width, startMenuRec.height},
                               {}, 0, WHITE);
            }
            break;
    }
}