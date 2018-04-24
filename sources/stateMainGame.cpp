#include "stateMainGame.hpp"

StateMainGame::StateMainGame ( Game &game )
        : game( game ),
          sprites( getGameTextures()),
          field( sf::Vector2u( game.getWindow().getSize()), sprites ),
          fruit( sprites ),
          snake( sprites ),
          score( game.getResManager().getTexture( Texture::SCORE_TEXTURES ))
{
    sprites.fitToScreen( getPlayableFieldSize(), sf::Vector2f( FIELD_ROWS, FIELD_CELLS ));
    field.create( sf::Vector2i( FIELD_ROWS, FIELD_CELLS ));
    fruit.create();
    fruit.randomizePosition( sf::Vector2f( rand() % FIELD_ROWS, rand() % FIELD_CELLS ));
    snake.createHead( sf::Vector2f( FIELD_ROWS / 2, FIELD_CELLS / 2 ));
    score.fitToScreen( FIELD_OFFSET_PERCENT * game.getWindow().getSize().y / 100.0f );

    clock.restart();

    gameOverPlayed = false;
    eatSound.setBuffer( game.getResManager().getSoundBuffer( Sound::EAT ));
    endSound.setBuffer( game.getResManager().getSoundBuffer( Sound::END ));


    gameOver = false;
}

StateMainGame::~StateMainGame () = default;

std::unique_ptr< GameState > StateMainGame::getNextState () {
    return nullptr;
}

void StateMainGame::draw () {
    sf::RenderWindow &window = game.getWindow();
    field.draw( window );
    fruit.draw( window );
    snake.draw( window );
    score.draw( window );
}

void StateMainGame::handleInput () {
    sf::RenderWindow &window = game.getWindow();
    sf::Event event;
    while ( window.pollEvent( event )) {
        switch ( event.type ) {
            case sf::Event::Closed :
                stopState();
                window.close();
                break;

            case sf::Event::KeyPressed :
                handlePlayerInput();
                handleMusic();
                break;

            default :
                break;
        }
    }
}

void StateMainGame::update () {
    if (!gameOver && isGameOver()) {
        gameOver = true;
    }

    if ( !gameOver) {
        int turnDuration = clock.getElapsedTime().asMilliseconds();
        if ( turnDuration <= TURN_DURATION_MS ) {
            handleSnakeMovement();
            handleFruit();

            //todo won condition
        } else {
            turnRestart();
        }

    } else {
        if ( !gameOverPlayed ) {
            endSound.play();
            gameOverPlayed = true;
        }

        snake.deleteLastPart();
        /**
         *  todo - game over state:
         *  - game over title
         */
    }
}

void StateMainGame::stopState () {
}

sf::Texture &StateMainGame::getGameTextures () {
    return game.getResManager().getTexture( Texture::MAIN_GAME_TEXTURES );
}

sf::Vector2f StateMainGame::getPlayableFieldSize () {
    sf::RenderWindow &window = game.getWindow();
    float width = window.getSize().x;
    float height = window.getSize().y;
    float offset = FIELD_OFFSET_PERCENT * height / 100.0f;

    return {width, height - offset};
}

void StateMainGame::handlePlayerInput () {
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Left )) {
        snake.setNewDirection( Direction::LEFT );

    } else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Up )) {
        snake.setNewDirection( Direction::UP );

    } else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Right )) {
        snake.setNewDirection( Direction::RIGHT );

    } else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Down )) {
        snake.setNewDirection( Direction::DOWN );
    }
}

bool StateMainGame::isGameOver () {
    unsigned int x = game.getWindow().getSize().x;
    unsigned int y = game.getWindow().getSize().y - ( FIELD_OFFSET_PERCENT * game.getWindow().getSize().y / 100 );
    bool isCollisionWithBorders = collision.withBorders( snake.getHeadElementFloatRect(), {x, y} );
    bool isCollisionWithSnake = collision.withSnake( snake );

    return ( isCollisionWithBorders || isCollisionWithSnake );
}

void StateMainGame::handleSnakeMovement () {
    if ( !snake.isMoved()) {
        snake.move();
        snake.setMoved( true );
    }
}

void StateMainGame::handleFruit () {
    bool isFruitEaten = collision.withFruit( fruit.getFloatRect(), snake.getHeadElementFloatRect());
    if ( isFruitEaten ) {
        snake.grow();
        // todo - fix random location (collision with snake)
        fruit.randomizePosition( sf::Vector2f( rand() % FIELD_ROWS, rand() % FIELD_CELLS ));
        score.increaseScore();
        eatSound.play();
    }
}

void StateMainGame::turnRestart () {
    clock.restart();
    snake.setMoved( false );
}

void StateMainGame::handleMusic () {
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::M )) {
        game.handleMusic();
    }
}