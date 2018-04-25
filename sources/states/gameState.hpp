#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <memory>

class GameState {
    public:
        GameState() : stateRunning( true ) {};
        virtual ~GameState() = default;

        bool isStateRunning() { return stateRunning; };

        virtual std::unique_ptr< GameState > getNextState() = 0;
        virtual void stopState() = 0;
        virtual void handleInput() = 0;
        virtual void update() = 0;
        virtual void draw() = 0;

    protected:
        bool stateRunning;
};

#endif // GAMESTATE_H