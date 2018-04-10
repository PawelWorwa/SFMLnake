#include "stateMainGame.hpp"

StateMainGame::StateMainGame( Game& game )
        : game( game ),
          sprites( getGameTextures()),
          field( sf::Vector2u(game.getWindow().getSize()), sprites ),
          fruit( sprites ),
          snake( sprites ),
          score( game.getResManager().getTexture( Texture::SCORE_TEXTURES ))
{
    sprites.resizeSprites( getPlayableFieldSize(), sf::Vector2f( FIELD_ROWS, FIELD_CELLS ));

    field.create( sf::Vector2i( FIELD_ROWS, FIELD_CELLS ));

    fruit.create();
    fruit.randomizePosition( sf::Vector2f( rand() % FIELD_ROWS, rand() % FIELD_CELLS ));

    snake.create( sf::Vector2f( FIELD_ROWS / 2, FIELD_CELLS / 2 ));

    score.fitToScreen(  FIELD_OFFSET * game.getWindow().getSize().y / 100.0f );

    clock.restart();
}

StateMainGame::~StateMainGame() = default;

std::unique_ptr< GameState > StateMainGame::getNextState() {
    return nullptr;
}

void StateMainGame::draw() {
    sf::RenderWindow& window = game.getWindow();
    field.draw( window );
    fruit.draw( window );
    snake.draw( window );
    score.draw( window );
}

void StateMainGame::handleInput() {
    sf::RenderWindow& window = game.getWindow();

    sf::Event event;
    while ( window.pollEvent( event )) {
        switch ( event.type ) {
            case sf::Event::Closed :
                stopState();
                window.close();
                break;

            case sf::Event::KeyPressed :
                handlePlayerInput();
                break;

            default :
                break;
        }
    }
}

void StateMainGame::update() {
    int currentTurnDuration = clock.getElapsedTime().asMilliseconds();
    if ( currentTurnDuration <= TURN_DURATION ) {
        if ( !snake.isMoved()) {
            snake.move();
            snake.setMoved( true );
        }

        sf::FloatRect snakeHeadFloatRect = snake.getHeadElementFloatRect();
        bool isFruitEaten = fruit.isColliding( snakeHeadFloatRect );
        if ( isFruitEaten ) {
            snake.grow();
            fruit.randomizePosition( sf::Vector2f( rand() % FIELD_ROWS, rand() % FIELD_CELLS ));
            score.increaseScore();
        }

    } else {
        clock.restart();
        snake.setMoved( false );
    }
}

void StateMainGame::stopState() {
}

sf::Texture& StateMainGame::getGameTextures() {
    return game.getResManager().getTexture( Texture::MAIN_GAME_TEXTURES );
}

sf::Vector2f StateMainGame::getPlayableFieldSize() {
    sf::RenderWindow& window = game.getWindow();
    float width = window.getSize().x;
    float height = window.getSize().y;
    float offset = FIELD_OFFSET * height / 100.0f;

    return { width, height - offset };
}

void StateMainGame::handlePlayerInput() {
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