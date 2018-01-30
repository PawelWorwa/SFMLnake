#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <memory>

class GameState {
    public:
        GameState() : running( true ) {};
        virtual ~GameState() {};

        bool isRunning( void ) { return running; };

        virtual std::unique_ptr< GameState > getNextState( void ) = 0;
        virtual void stopState( void ) = 0;
        virtual void handleInput( void ) = 0;
        virtual void update( void ) = 0;
        virtual void draw( void ) = 0;

    protected:
        bool running;
};

#endif // GAMESTATE_H
