//
// Created by konst on 02.05.2023.
//

#pragma once

namespace Game {
    class Screen {
    public:
        virtual void ProcessInput() = 0;

        virtual void Update() = 0;

        virtual void Draw() = 0;
    };
}