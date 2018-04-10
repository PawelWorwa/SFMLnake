#ifndef STATEMAINGAME_H
#define STATEMAINGAME_H

#include <SFML/Window/Event.hpp>

#include "states/gameState.hpp"
#include "engine/game.hpp"

#include "states/game/gameSprites.hpp"
#include "snake.hpp"
#include "states/game/fruit.hpp"
#include "states/game/score.hpp"
#include "states/game/field.hpp"

// todo refactor this monolith class
class StateMainGame : public GameState {
    private:
        static const int FIELD_ROWS  = 10;
        static const int FIELD_CELLS = 10;
        static const int TURN_DURATION = 500; //ms
        static const int FIELD_OFFSET  = 10; //% todo change name - its space left for score

        Game& game;
        GameSprites sprites;
        Field field;
        Fruit fruit;
        Snake snake;
        Score score;

        sf::Clock clock;
        sf::Texture& getGameTextures();
        sf::Vector2f getPlayableFieldSize();

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
