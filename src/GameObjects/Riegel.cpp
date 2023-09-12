#include "Riegel.h"
#include <cmath>
#include <iostream>

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
            break;
        case Senkrecht:
            this->collRectangle = {this->getPos().x, this->getPos().y, 24, 24 * (float) size};
            this->adjDetection1 = {this->getPos().x, (float) yCor, 24, 24};
            this->adjDetection2 = {this->getPos().x, (float) yCor + (size * 24 - 24), 24, 24};
            break;
    }
}

void Game::Riegel::move() {
    // Eingabe abfragen
    Vector2 mousePosition = GetMousePosition();

    mousePosition.x /= renderScale;
    mousePosition.y /= renderScale;


    //std::cout << mousePosition.x << mousePosition.y << std::endl;
    if (directionR == Waagerecht) {
        if (CheckCollisionPointRec(mousePosition, getCollRec()) &&
            IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            this->mouseOffsetX = mousePosition.x - this->getPos().x;
        }
        if (CheckCollisionPointRec(mousePosition, getCollRec()) &&
            IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            this->pos.x = mousePosition.x - mouseOffsetX;
        }
        if (CheckCollisionPointRec(mousePosition, getCollRec()) &&
            IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
            int xOne = (int) this->getPos().x;
            int xCor = (xOne / 24) * 24;
            if (xOne % 24 > 11) {
                xCor += 24;
            }
            this->pos.x = (float) xCor;
        }
    }
    if (directionR == Senkrecht) {
        if (CheckCollisionPointRec(mousePosition, getCollRec()) &&
            IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            this->mouseOffsetY = mousePosition.y - this->getPos().y;
        }
        if (CheckCollisionPointRec(mousePosition, getCollRec()) &&
            (IsMouseButtonDown(MOUSE_LEFT_BUTTON))) {
            this->pos.y = mousePosition.y - mouseOffsetY;
        }
        if (CheckCollisionPointRec(mousePosition, getCollRec()) &&
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





