#include "Riegel.h"


Game::Riegel::Riegel(int RiegelX, int RiegelY) {
    this->setPos((float) RiegelX, (float) RiegelY);
    ColUpdate();

}

void Game::Riegel::ColUpdate() {
    Vector2 mousePosition = GetMousePosition();
    this->collRectangle = {this->getPos().x, this->getPos().y, 24, 24};

    if (WriegelCanMove) {
        xmove = mousePosition.x;
        if (xmove > mousePosition.x) {
            this->setAdjRec(this->getPos().x - 2, this->getPos().y, 24, 24);
        } else if (xmove < mousePosition.x) {
            this->setAdjRec(this->getPos().x + 2, this->getPos().y, 24, 24);
        } else {
            this->setAdjRec({}, {}, {}, {}); // wenn keine direction angegeben ist, soll es default nicht da sein
        }
    }

    if (SriegelCanMove) {
        if (CheckCollisionPointRec(mousePosition, {pos.x, pos.y, 24, 24})) {
            ymove = mousePosition.y;
            if (ymove > mousePosition.y) {
                this->setAdjRec(this->getPos().x, this->getPos().y - 2, 24, 24);
            } else if (ymove < mousePosition.y) {
                this->setAdjRec(this->getPos().x, this->getPos().y + 2, 24, 24);
            } else {
                this->setAdjRec({}, {}, {}, {}); // wenn keine direction angegeben ist, soll es default nicht da sein
            }
        }
    }
}

    void Game::Riegel::PlaceUpdate() {

    }

    void Game::Riegel::move() {
        setCollRec(this->getPos().x, this->getPos().y, 24, 24);


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





