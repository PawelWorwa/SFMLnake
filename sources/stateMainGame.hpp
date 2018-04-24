#ifndef STATEMAINGAME_H
#define STATEMAINGAME_H

#include <SFML/Window/Event.hpp>
#include <SFML/AUDIO/Sound.hpp>

#include "states/gameState.hpp"
#include "engine/game.hpp"

#include "states/game/gameSprites.hpp"
#include "states/game/snake.hpp"
#include "states/game/fruit.hpp"
#include "states/game/score.hpp"
#include "states/game/field.hpp"
#include "../Collision.hpp"

class StateMainGame : public GameState {
    private:
        static const int FIELD_ROWS = 10;
        static const int FIELD_CELLS = 10;
        static const int TURN_DURATION_MS = 500;
        static const int FIELD_OFFSET_PERCENT = 10;

        Game &game;
        GameSprites sprites;
        Field field;
        Fruit fruit;
        Snake snake;
        Score score;
        Collision collision;

        bool gameOverPlayed;
        sf::Sound eatSound;
        sf::Sound endSound;
        sf::Clock clock;
        sf::Texture &getGameTextures ();
        sf::Vector2f getPlayableFieldSize ();

        void handlePlayerInput ();
        bool isGameOver();
        void handleSnakeMovement();
        void handleMusic();
        void handleFruit();
        void turnRestart();


        bool gameOver;

    public:
        explicit StateMainGame ( Game &game );
        ~StateMainGame () override;

        std::unique_ptr< GameState > getNextState () override;
        void draw () override;
        void handleInput () override;
        void update () override;
        void stopState () override;
};

#endif // STATEMAINGAME_H
