#ifndef ENGINE_H
#define ENGINE_H

#include <memory>
#include <stack>

#include <SFML/Graphics/RenderWindow.hpp>

#include "../include/game.hpp"
#include "../include/States/gameState.hpp"
#include "../include/States/stateIntroSFML.hpp"



class Engine {
    private:
        Game game;
        std::stack< std::unique_ptr< GameState > > states;

        void changeState( std::unique_ptr< GameState > state );
        void gameLoop( void );
        void popState( void );
        void pushInitialState( void );
        void pushState( std::unique_ptr< GameState > state );

    public:
        Engine();
        virtual ~Engine();

        void startGame( void );
};

#endif // GAME_H
