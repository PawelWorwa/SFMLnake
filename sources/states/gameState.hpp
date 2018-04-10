#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <memory>

class GameState {
    public:
        GameState() : running( true ) {};
        virtual ~GameState() = default;

        bool isRunning() { return running; };

        virtual std::unique_ptr< GameState > getNextState() = 0;
        virtual void stopState() = 0;
        virtual void handleInput() = 0;
        virtual void update() = 0;
        virtual void draw() = 0;

    protected:
        bool running;
};

#endif // GAMESTATE_H