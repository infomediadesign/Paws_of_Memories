#pragma once

#include "../Sprite.h"

enum age {
    grandmaSprite,
    adultSprite,
    teenSprite
};

namespace Game {
    class NPC : public Sprite {
    public:
        int age = 0;

        Texture2D grandmaAnim = LoadTexture("assets/graphics/Animation/Sheets/NPC/Colorful (new)/Grandmother/Idle_animation_Colorful-sheet.png");
        Texture2D adultAnim = LoadTexture("assets/graphics/Animation/Sheets/NPC/Colorful (new)/Adult/Idle_animation_Colorful_sheet.png");
        Texture2D teenAnim = LoadTexture("assets/graphics/Animation/Sheets/NPC/Colorful (new)/Teeanger/Idle_animation_Colorful-Sheet.png");
        Texture2D compassAnim = LoadTexture("assets/graphics/Animation/Sheets/NPC/Colorful (new)/Grandmother/Giving_compass-sheet.png");
        bool compassGiven = false;
        bool compassAnimDone = false;
        //float width = 24;
        Rectangle frameRecNPC = {0, 0, 24, 24};
        Rectangle interactionBoxNPC = {};
        int frameSpeed = 1;
        int frameCounter = 0;
        int currentFrame = 0;

        void initialiseNPC(int posX, int posY, int lifetime);
        void drawNPC();
    };
}
