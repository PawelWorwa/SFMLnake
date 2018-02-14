#ifndef STATEMAINGAME_H
#define STATEMAINGAME_H

#include <SFML/Window/Event.hpp>

#include "../../include/States/gameState.hpp"
#include "../../include/game.hpp"

#include "../../include/gameSprites.hpp"
#include "field.hpp"
#include "snake.hpp"

class StateMainGame : public GameState {
    private:
        static const int FIELD_ROWS  = 10;
        static const int FIELD_CELLS = 10;

        Game &game;
        GameSprites sprites;
        Field field;
        Snake snake;

        sf::Texture& getGameTextures( void );
        sf::Vector2f getWindowSize( void );

    public:
        explicit StateMainGame( Game &game );
        virtual ~StateMainGame();

        std::unique_ptr< GameState > getNextState( void );
        void draw( void );
        void handleInput( void );
        void update( void );
        void stopState( void );
};

#endif // STATEMAINGAME_H
