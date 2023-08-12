//
// Created by konst on 11.08.2023.
//

#include "NPC.h"

void Game::NPC::initialiseNPC(int posX, int posY, int lifetime) {
    this->setPos((float) posX, (float) posY);
    this->setCollRec((float) posX + 2, (float) posY + 12, 18, 0);
    this->interactionBoxNPC = {(float) posX-4, (float) posY, 32, 24};
    this->age = lifetime;
    switch (age) {
        case 0:
            this->setTexture(grandmaAnim);
            break;
        case 1:
            this->setTexture(adultAnim);
            break;
        case 2:
            this->setTexture(teenAnim);
            break;

    }
}

void Game::NPC::drawNPC() {
    frameCounter++;
    switch (age) {
        case 0:
            if(compassAnimDone || (!compassGiven && !compassAnimDone)) {
                if (frameCounter >= (60 / frameSpeed)) {

                    frameCounter = 0;
                    currentFrame++;

                    if (currentFrame > 1) currentFrame = 0;

                    frameRecNPC.x = (float) currentFrame * (float) texture.width / 2;
                }
                DrawTexturePro(texture, frameRecNPC,
                               Rectangle{this->getPos().x, this->getPos().y, 24, frameRecNPC.height},
                               {}, 0, WHITE);
                break;
            }  else {
                this->setTexture(compassAnim);
                DrawTexturePro(compassAnim, frameRecNPC,
                               Rectangle{this->getPos().x, this->getPos().y, 24, frameRecNPC.height},
                               {}, 0, WHITE);
                if (frameCounter >= (12 / frameSpeed)) {

                    frameCounter = 0;
                    currentFrame++;
                    frameRecNPC.x = (float) (currentFrame % 4) * (float) texture.width / 4;
                    frameRecNPC.y = currentFrame/4 * (float) texture.height / 3;

                    if (currentFrame > 11) {
                        currentFrame = 0;
                        compassAnimDone = true;
                        this->setTexture(grandmaAnim);
                        break;
                    }

                }
                break;
            }
        case 1:
            if (frameCounter >= (60 / frameSpeed)) {

                frameCounter = 0;
                currentFrame++;

                if (currentFrame > 1) currentFrame = 0;

                frameRecNPC.x = (float) currentFrame * (float) texture.width / 2;
            }
            DrawTexturePro(texture, frameRecNPC,
                           Rectangle{this->getPos().x, this->getPos().y, 24, frameRecNPC.height},
                           {}, 0, WHITE);
            break;
        case 2:
            if (frameCounter >= (60 / frameSpeed)) {

                frameCounter = 0;
                currentFrame++;

                if (currentFrame > 1) currentFrame = 0;

                frameRecNPC.x = (float) currentFrame * (float) texture.width / 2;
            }
            DrawTexturePro(texture, frameRecNPC,
                           Rectangle{this->getPos().x, this->getPos().y, 24, frameRecNPC.height},
                           {}, 0, WHITE);
            break;
    }
}
