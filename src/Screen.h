//
// Created by konst on 02.05.2023.
//

#ifndef RAYLIBSTARTER_SCREEN_H
#define RAYLIBSTARTER_SCREEN_H

#endif //RAYLIBSTARTER_SCREEN_H

namespace Game {
    class Screen {
    public:
        virtual void ProcessInput() = 0;

        virtual void Update() = 0;

        virtual void Draw() = 0;
    };
}