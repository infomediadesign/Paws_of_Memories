#include "Riegel.h"


Game::Riegel::Riegel(int RiegelX, int RiegelY) {
    this->setPos(RiegelX, RiegelY);
}

void Game::Riegel::bewegen(){
    // Objekt 1 - x-Achse
    float object1X = GetScreenWidth() / 2;
    float object1Y = GetScreenHeight() / 2;


    // Objekt 2 - y-Achse
    float object2X = GetScreenWidth() / 2 - 150;
    float object2Y = GetScreenHeight() / 2;


    bool isDragging1 = false; // Flag für Objekt 1
    bool isDragging2 = false; // Flag für Objekt 2


    // Eingabe abfragen
    Vector2 mousePosition = GetMousePosition();

    // Objektverschiebung
    if (!isDragging1 && !isDragging2) {
        if (CheckCollisionPointRec(mousePosition, {object1X, object1Y, 24, 24}) &&
            IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            // Objekt 1 wird verschoben
            isDragging1 = true;
        } else if (CheckCollisionPointRec(mousePosition, {object2X, object2Y, 24, 24}) &&
                   IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            // Objekt 2 wird verschoben
            isDragging2 = true;
        }
    } else {
        if (IsMouseButtonUp(MOUSE_LEFT_BUTTON)) {
            // Maustaste losgelassen - Verschiebung beenden
            isDragging1 = false;
            isDragging2 = false;
        }
    }

    // Objektverschiebung für Objekt 1 (x-Achse)
    if (isDragging1) {
         pos.x -= (24 / 2);

    }

    // Objektverschiebung für Objekt 2 (y-Achse)
    if (isDragging2) {
        pos.y -= (24 / 2);
    }


}