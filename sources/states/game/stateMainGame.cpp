#include "stateMainGame.hpp"
#include "../menu/stateMainMenu.hpp"

StateMainGame::StateMainGame( Game &game )
        : game( game ),
          sprites( getGameTextures()),
          field( sf::Vector2u( game.getWindow().getSize()), sprites ),
          fruit( sprites ),
          snake( sprites ),
          score( game.getTextureManager().getTexture( Texture::SCORE_TEXTURES ))
{
    this->playedEndSound = false;
    this->gameOver = false;
    this->gameWon = false;
    this->fruitsToWin = FIELD_ROWS * FIELD_CELLS - 1; //head

    sprites.fitToScreen( getPlayableFieldSize(), sf::Vector2f( FIELD_ROWS, FIELD_CELLS ));
    field.create( sf::Vector2i( FIELD_ROWS, FIELD_CELLS ));
    fruit.create();
    fruit.randomizePosition( sf::Vector2f( rand() % FIELD_ROWS, rand() % FIELD_CELLS ));
    snake.createHead( sf::Vector2f( FIELD_ROWS / 2, FIELD_CELLS / 2 ));
    score.fitToScreen( FIELD_OFFSET_PERCENT * game.getWindow().getSize().y / 100.0f );

    clock.restart();
}

StateMainGame::~StateMainGame() = default;

std::unique_ptr< GameState > StateMainGame::getNextState() {
    std::unique_ptr< GameState > mainMenuState( new StateMainMenu( game ));
    return std::move( mainMenuState );
}

void StateMainGame::draw() {
    sf::RenderWindow &window = game.getWindow();
    field.draw( window );
    fruit.draw( window );
    snake.draw( window );
    score.draw( window );

    if ( gameWon ) {
        drawTexture( Texture::VICTORY );

    } else if ( gameOver ) {
        drawTexture( Texture::GAME_OVER );
    }
}

void StateMainGame::drawTexture( std::string textureName ) {
    const sf::Texture &texture = game.getTextureManager().getTexture( textureName );
    float height = texture.getSize().x;
    float width = texture.getSize().y;

    sf::Sprite sprite;
    sprite.setTexture( texture );
    sprite.setOrigin( height / 2, width / 2 );

    sf::RenderWindow &window = game.getWindow();
    sprite.setPosition( window.getSize().x / 2, window.getSize().y / 2 );

    window.draw( sprite );
}

void StateMainGame::handleInput() {
    sf::RenderWindow &window = game.getWindow();
    sf::Event event;
    while ( window.pollEvent( event )) {
        switch ( event.type ) {
            case sf::Event::Closed :
                stopState();
                window.close();
                break;

            case sf::Event::KeyPressed :
                if ( gameOver || gameWon ) {
                    stopState();
                }

                handlePlayerInput();
                handleMusic();
                break;

            default :
                break;
        }
    }
}

void StateMainGame::update() {
    if ( score.getScore() == fruitsToWin ) {
        gameWon = true;

    } else if ( !gameOver && !isCollision()) {
        int turnDuration = clock.getElapsedTime().asMilliseconds();
        if ( turnDuration <= TURN_DURATION_MS ) {
            handleSnakeMovement();
            handleFruit();

        } else {
            turnRestart();
        }

    } else {
        gameOver = true;
        if ( !playedEndSound ) {
            game.getSoundManager().playSound( Audio::END );
            playedEndSound = true;
        }

        snake.deleteBodyPart();
    }
}

void StateMainGame::stopState() {
    bool isPlaying = game.getSoundManager().isPlaying( Audio::END );
    if ( isPlaying ) {
        game.getSoundManager().stopSound( Audio::END );
    }

    stateRunning = false;
}

sf::Texture &StateMainGame::getGameTextures() {
    return game.getTextureManager().getTexture( Texture::MAIN_GAME_TEXTURES );
}

sf::Vector2f StateMainGame::getPlayableFieldSize() {
    sf::RenderWindow &window = game.getWindow();
    float width = window.getSize().x;
    float height = window.getSize().y;
    float offset = FIELD_OFFSET_PERCENT * height / 100.0f;

    return {width, height - offset};
}

void StateMainGame::handlePlayerInput() {
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) && snake.getDirection() != Direction::RIGHT ) {
        snake.setNewDirection( Direction::LEFT );

    } else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) && snake.getDirection() != Direction::DOWN ) {
        snake.setNewDirection( Direction::UP );

    } else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) && snake.getDirection() != Direction::LEFT ) {
        snake.setNewDirection( Direction::RIGHT );

    } else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Down ) && snake.getDirection() != Direction::UP ) {
        snake.setNewDirection( Direction::DOWN );
    }
}

bool StateMainGame::isCollision() {
    unsigned int x = game.getWindow().getSize().x;
    unsigned int y = game.getWindow().getSize().y - ( FIELD_OFFSET_PERCENT * game.getWindow().getSize().y / 100 );
    bool isCollisionWithBorders = collision.withBorders( snake.getHeadElementFloatRect(), {x, y} );
    bool isCollisionWithSnake = collision.withSnake( snake );

    return ( isCollisionWithBorders || isCollisionWithSnake );
}

void StateMainGame::handleSnakeMovement() {
    if ( !snake.isMoved()) {
        snake.move();
        snake.setMoved( true );
    }
}

void StateMainGame::handleFruit() {
    bool isFruitEaten = collision.withFruit( fruit.getFloatRect(), snake.getHeadElementFloatRect());
    if ( isFruitEaten ) {
        snake.grow();
        randomizeFruit();
        score.increaseScore();
        game.getSoundManager().playSound( Audio::EAT );
    }
}

void StateMainGame::turnRestart() {
    clock.restart();
    snake.setMoved( false );
}

void StateMainGame::handleMusic() {
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::M )) {
        game.getSoundManager().changeMusicState();
    }
}

void StateMainGame::randomizeFruit() {
    while ( true ) {
        fruit.randomizePosition( sf::Vector2f( rand() % FIELD_ROWS, rand() % FIELD_CELLS ));
        if ( !collision.withFruit( fruit.getFloatRect(), snake.getParts())) {
            break;
        }
    }
}