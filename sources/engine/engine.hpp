#ifndef ENGINE_H
#define ENGINE_H

#include <memory>
#include <stack>

#include <SFML/Graphics/RenderWindow.hpp>

#include "game.hpp"
#include "../states/gameState.hpp"
#include "../states/intro/stateIntroSFML.hpp"

class Engine {
    private:
        Game game;
        std::stack< std::unique_ptr< GameState > > states;

        void changeState( std::unique_ptr< GameState > state );
        void gameLoop();
        void popState();
        void pushInitialState();
        void pushState( std::unique_ptr< GameState > state );

    public:
        Engine();
        virtual ~Engine();

        void startGame();
};

#endif // GAME_H
