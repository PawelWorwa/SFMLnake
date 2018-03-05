#ifndef STATEMAINGAME_H
#define STATEMAINGAME_H

#include <SFML/Window/Event.hpp>

#include "gameState.hpp"
#include "game.hpp"

#include "gameSprites.hpp"
#include "field.hpp"
#include "snake.hpp"
#include "fruit.hpp"

class StateMainGame : public GameState {
    private:
        static const int FIELD_ROWS  = 10;
        static const int FIELD_CELLS = 10;

        static const int TURN_DURATION = 500; //ms

        Game& game;
        GameSprites sprites;
        Field field;
        Fruit fruit;
        Snake snake;

        sf::Clock clock;
        sf::Texture& getGameTextures();
        sf::Vector2f getWindowSize();

        unsigned int eatenFruits;

        void handlePlayerInput();

    public:
        explicit StateMainGame( Game& game );
        ~StateMainGame() override;

        std::unique_ptr< GameState > getNextState() override;
        void draw() override;
        void handleInput() override;
        void update() override;
        void stopState() override;
};

#endif // STATEMAINGAME_H
