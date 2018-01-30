#include "../include/engine.hpp"

Engine::Engine() {
}

Engine::~Engine() {
    while ( !states.empty() ) {
        states.pop();
    }
}

void Engine::startGame( void ) {
    pushInitialState();
    gameLoop();
}

void Engine::pushInitialState( void ) {
    std::unique_ptr< GameState > introState( new StateIntroSFML( game ) );
    pushState( std::move( introState ) );
}

void Engine::gameLoop( void ) {
    sf::RenderWindow &window = game.getWindow();
    while ( window.isOpen() ) {
        if ( !states.top()->isRunning() ) {
            std::unique_ptr< GameState > nextState = states.top()->getNextState();
            changeState( std::move( nextState ) );
        }

        if ( !game.isExitGame() ) {
            states.top()->handleInput();
            states.top()->update();

            window.clear( sf::Color::Black );
            states.top()->draw();
            window.display();

        } else {
            window.close();
        }
    }
}

void Engine::popState( void ) {
    if ( !states.empty() ) {
        states.pop();
    }
}

void Engine::pushState( std::unique_ptr< GameState > state ) {
    states.push( std::move( state ) );
}

void Engine::changeState( std::unique_ptr< GameState > state ) {
    popState();
    pushState( std::move( state ) );
}
