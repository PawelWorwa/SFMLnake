#ifndef STATEMAINGAME_H
#define STATEMAINGAME_H

#include <SFML/Window/Event.hpp>
#include <SFML/Audio/Sound.hpp>

#include "../gameState.hpp"
#include "../../engine/game.hpp"

#include "gameSprites.hpp"
#include "snake.hpp"
#include "fruit.hpp"
#include "score.hpp"
#include "field.hpp"
#include "Collision.hpp"

class StateMainGame : public GameState {
    private:
        static const int FIELD_ROWS = 10;
        static const int FIELD_CELLS = 10;
        static const int TURN_DURATION_MS = 300;
        static const int FIELD_OFFSET_PERCENT = 10;

        Game &game;
        GameSprites sprites;
        Field field;
        Fruit fruit;
        Snake snake;
        Score score;
        Collision collision;

        sf::Clock clock;
        sf::Texture &getGameTextures();
        sf::Vector2f getPlayableFieldSize();

        void handlePlayerInput();
        bool isCollision();
        void handleSnakeMovement();
        void handleMusic();
        void handleFruit();
        void turnRestart();
        void randomizeFruit();
        void drawTexture( std::string textureName );

        unsigned int fruitsToWin;
        bool playedEndSound;
        bool gameOver;
        bool gameWon;

    public:
        explicit StateMainGame( Game &game );
        ~StateMainGame() override;

        std::unique_ptr< GameState > getNextState() override;
        void draw() override;
        void handleInput() override;
        void update() override;
        void stopState() override;
};

#endif // STATEMAINGAME_H
