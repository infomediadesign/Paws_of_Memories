#include "Riegel.h"
#include <cmath>

Game::Riegel::Riegel(int RiegelX, int RiegelY, int dir) {
    this->setPos((float) RiegelX, (float) RiegelY);
    this->directionR = dir;
    ColUpdate();

}

void Game::Riegel::ColUpdate() {
    Vector2 mousePosition = GetMousePosition();
    int xOne = (int) this->getPos().x;
    int xCor = (xOne / 24) * 24;
    if (xOne % 24 > 11) {
        xCor += 24;
    }
    int yOne = (int) this->getPos().y;
    int yCor = ((yOne - 30) / 24) * 24 + 30;
    if ((yOne - 30) % 24 > 11) {
        yCor += 24;
    }
    switch (directionR) {
        case Waagerecht:
            this->collRectangle = {this->getPos().x, this->getPos().y, 24 * (float) size, 24};
            this->adjDetection1 = {(float) xCor, this->getPos().y, 24, 24};
            this->adjDetection2 = {(float) xCor + (size * 24 - 24), this->getPos().y, 24, 24};

            xmove = mousePosition.x;
            if (xmove > mousePosition.x) { // @Till these things don't work
                this->setAdjRec(this->getPos().x - 2, this->getPos().y, 24, 24);
            } else if (xmove < mousePosition.x) {
                this->setAdjRec(this->getPos().x + 2, this->getPos().y, 24, 24);
            } else {
                this->setAdjRec({}, {}, {}, {}); // wenn keine direction angegeben ist, soll es default nicht da sein
            }
            break;
        case Senkrecht:
            this->collRectangle = {this->getPos().x, this->getPos().y, 24, 24 * (float) size};
            this->adjDetection1 = {this->getPos().x, (float) yCor, 24, 24};
            this->adjDetection2 = {this->getPos().x, (float) yCor + (size * 24 - 24), 24, 24};

            if (CheckCollisionPointRec(mousePosition, {pos.x, pos.y, 24, 24})) {
                ymove = mousePosition.y;
                if (ymove > mousePosition.y) { // @Till these things don't work
                    this->setAdjRec(this->getPos().x, this->getPos().y - 2, 24, 24);
                } else if (ymove < mousePosition.y) {
                    this->setAdjRec(this->getPos().x, this->getPos().y + 2, 24, 24);
                } else {
                    this->setAdjRec({}, {}, {},
                                    {}); // wenn keine direction angegeben ist, soll es default nicht da sein
                }
            }
            break;
    }
}

void Game::Riegel::PlaceUpdate() {

}

void Game::Riegel::move() {
    // Eingabe abfragen
    Vector2 mousePosition = GetMousePosition();

    mousePosition.x /= renderScale;
    mousePosition.y /= renderScale;


    //std::cout << mousePosition.x << mousePosition.y << std::endl;
    if (WriegelCanMove && directionR == Waagerecht) {
        if (CheckCollisionPointRec(mousePosition, {pos.x, pos.y, 24, 24}) &&
            IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            this->pos.x = mousePosition.x - (float) 24 / 2;
        }
        if (CheckCollisionPointRec(mousePosition, {pos.x, pos.y, 24, 24}) &&
            IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
            int xOne = (int) this->getPos().x;
            int xCor = (xOne / 24) * 24;
            if (xOne % 24 > 11) {
                xCor += 24;
            }
            this->pos.x = (float) xCor;
        }
    }
    if (SriegelCanMove && directionR == Senkrecht) {
        if (CheckCollisionPointRec(mousePosition, {pos.x, pos.y, 24, 24}) &&
            (IsMouseButtonDown(MOUSE_LEFT_BUTTON))) {
            this->pos.y = mousePosition.y - (float) 24 / 2;
        }
        if (CheckCollisionPointRec(mousePosition, {pos.x, pos.y, 24, 24}) &&
            IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
            int yOne = (int) this->getPos().y;
            int yCor = ((yOne - 30) / 24) * 24 + 30;
            if ((yOne - 30) % 24 > 11) {
                yCor += 24;
            }
            this->pos.y = (float) yCor;
        }
    }
}

void Game::Riegel::drawRiegel() {
    switch (directionR) {
        case Waagerecht:
            DrawTexturePro(this->texture, Rectangle{0, 0, 24, 24},
                           Rectangle{this->getPos().x, this->getPos().y, 24, 24}, {}, 0, WHITE);
            if (size == 2) {
                DrawTexturePro(this->texture, Rectangle{48, 0, 24, 24},
                               Rectangle{this->getPos().x + 24, this->getPos().y, 24, 24}, {}, 0, WHITE);
            }
            if (size == 3) {
                DrawTexturePro(this->texture, Rectangle{24, 0, 24, 24},
                               Rectangle{this->getPos().x + 24, this->getPos().y, 24, 24},
                               {}, 0, WHITE);
                DrawTexturePro(this->texture, Rectangle{48, 0, 24, 24},
                               Rectangle{this->getPos().x + 48, this->getPos().y, 24, 24}, {}, 0, WHITE);
            }
            if (size == 4) {
                DrawTexturePro(this->texture, Rectangle{24, 0, 24, 24},
                               Rectangle{this->getPos().x + 24, this->getPos().y, 24, 24},
                               {}, 0, WHITE);
                DrawTexturePro(this->texture, Rectangle{24, 0, 24, 24},
                               Rectangle{this->getPos().x + 48, this->getPos().y, 24, 24},
                               {}, 0, WHITE);
                DrawTexturePro(this->texture, Rectangle{48, 0, 24, 24},
                               Rectangle{this->getPos().x + 72, this->getPos().y, 24, 24}, {}, 0, WHITE);
            }
            break;
        case Senkrecht:
            DrawTexturePro(this->texture, Rectangle{0, 0, 24, 24},
                           Rectangle{this->getPos().x, this->getPos().y, 24, 24}, {}, 0, WHITE);
            if (size == 2) {
                DrawTexturePro(this->texture, Rectangle{0, 48, 24, 24},
                               Rectangle{this->getPos().x, this->getPos().y + 24, 24, 24}, {}, 0, WHITE);
            }
            if (size == 3) {
                DrawTexturePro(this->texture, Rectangle{0, 24, 24, 24},
                               Rectangle{this->getPos().x, this->getPos().y + 24, 24, 24},
                               {}, 0, WHITE);
                DrawTexturePro(this->texture, Rectangle{0, 48, 24, 24},
                               Rectangle{this->getPos().x, this->getPos().y + 48, 24, 24}, {}, 0, WHITE);
            }
            if (size == 4) {
                DrawTexturePro(this->texture, Rectangle{0, 24, 24, 24},
                               Rectangle{this->getPos().x, this->getPos().y + 24, 24, 24},
                               {}, 0, WHITE);
                DrawTexturePro(this->texture, Rectangle{0, 24, 24, 24},
                               Rectangle{this->getPos().x, this->getPos().y + 48, 24, 24},
                               {}, 0, WHITE);
                DrawTexturePro(this->texture, Rectangle{0, 48, 24, 24},
                               Rectangle{this->getPos().x, this->getPos().y + 72, 24, 24}, {}, 0, WHITE);
            }
            break;
    }
}





