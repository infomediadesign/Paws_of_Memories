#include "Riegel.h"


Game::Riegel::Riegel(int RiegelX, int RiegelY, int dir) {
    this->setPos((float) RiegelX, (float) RiegelY);
    this->direction = dir;
    ColUpdate();

}

void Game::Riegel::ColUpdate() {
    Vector2 mousePosition = GetMousePosition();
    switch (direction) {
        case Wagerecht:
            this->collRectangle = {this->getPos().x, this->getPos().y, 24 * (float) size, 24};
            xmove = mousePosition.x;
            if (xmove > mousePosition.x) {
                this->setAdjRec(this->getPos().x - 2, this->getPos().y, 24, 24);
            } else if (xmove < mousePosition.x) {
                this->setAdjRec(this->getPos().x + 2, this->getPos().y, 24, 24);
            } else {
                this->setAdjRec({}, {}, {}, {}); // wenn keine direction angegeben ist, soll es default nicht da sein
            }
            break;
        case Senkrecht:
            this->collRectangle = {this->getPos().x, this->getPos().y, 24,  24 * (float) size};
            if (CheckCollisionPointRec(mousePosition, {pos.x, pos.y, 24, 24})) {
                ymove = mousePosition.y;
                if (ymove > mousePosition.y) {
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
    ColUpdate();


    // Eingabe abfragen
    Vector2 mousePosition = GetMousePosition();

    mousePosition.x /= renderScale;
    mousePosition.y /= renderScale;


    //std::cout << mousePosition.x << mousePosition.y << std::endl;
    if (WriegelCanMove) {
        if (CheckCollisionPointRec(mousePosition, {pos.x, pos.y, 24, 24}) &&
            IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            this->pos.x = mousePosition.x - (float) 24 / 2;
        }
    }
    if (SriegelCanMove) {
        if (CheckCollisionPointRec(mousePosition, {pos.x, pos.y, 24, 24}) &&
            IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            this->pos.y = mousePosition.y - (float) 24 / 2;
        }
    }
}

void Game::Riegel::drawRiegel() {
    switch (direction) {
        case Wagerecht:
            DrawTexturePro(this->texture, Rectangle{0, 0, 24, 24},
                           Rectangle{this->getPos().x, this->getPos().y, 24, 24}, {}, 0, WHITE);
            if (size == 2) {
                DrawTexturePro(this->texture, Rectangle{48, 0, 24, 24},
                               Rectangle{this->getPos().x + 24, this->getPos().y, 24, 24}, {}, 0, WHITE);
            }
            if (size == 3) {
                DrawTexturePro(this->texture, Rectangle{24, 0, 24, 24},
                               Rectangle{this->getPos().x+24, this->getPos().y, 24, 24},
                               {}, 0, WHITE);
                DrawTexturePro(this->texture, Rectangle{48, 0, 24, 24},
                               Rectangle{this->getPos().x + 48, this->getPos().y, 24, 24}, {}, 0, WHITE);
            }
            if (size == 4) {
                DrawTexturePro(this->texture, Rectangle{24, 0, 24, 24},
                               Rectangle{this->getPos().x+24, this->getPos().y, 24, 24},
                               {}, 0, WHITE);
                DrawTexturePro(this->texture, Rectangle{24, 0, 24, 24},
                               Rectangle{this->getPos().x+48, this->getPos().y, 24, 24},
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
                               Rectangle{this->getPos().x , this->getPos().y+ 24, 24, 24}, {}, 0, WHITE);
            }
            if (size == 3) {
                DrawTexturePro(this->texture, Rectangle{0, 24, 24, 24},
                               Rectangle{this->getPos().x, this->getPos().y+24, 24, 24},
                               {}, 0, WHITE);
                DrawTexturePro(this->texture, Rectangle{0, 48, 24, 24},
                               Rectangle{this->getPos().x, this->getPos().y+ 48, 24, 24}, {}, 0, WHITE);
            }
            if (size == 4) {
                DrawTexturePro(this->texture, Rectangle{0, 24, 24, 24},
                               Rectangle{this->getPos().x, this->getPos().y+24, 24, 24},
                               {}, 0, WHITE);
                DrawTexturePro(this->texture, Rectangle{0, 24, 24, 24},
                               Rectangle{this->getPos().x, this->getPos().y+48, 24, 24},
                               {}, 0, WHITE);
                DrawTexturePro(this->texture, Rectangle{0, 48, 24, 24},
                               Rectangle{this->getPos().x, this->getPos().y+ 72, 24, 24}, {}, 0, WHITE);
            }
            break;
    }
}





