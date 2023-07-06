#pragma once

namespace Game {
    class Screen {
    public:
        virtual void ProcessInput() = 0;

        virtual void Update() = 0;

        virtual void Draw() = 0;

        virtual void setRScale(float) = 0;
    };
}