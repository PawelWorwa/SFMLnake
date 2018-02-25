#include "stateMainGame.hpp"

StateMainGame::StateMainGame( Game& game )
        : game( game ),
          sprites( getGameTextures()),
          field( sf::Vector2f( FIELD_ROWS, FIELD_CELLS ), sprites ),
          snake( sprites )
{
    sprites.resizeSprites( getWindowSize(), sf::Vector2f( FIELD_ROWS, FIELD_CELLS ));
    field.create();
    snake.create();

    clock.restart();
}

StateMainGame::~StateMainGame() = default;

std::unique_ptr< GameState > StateMainGame::getNextState() {
    return nullptr;
}

void StateMainGame::draw() {
    sf::RenderWindow& window = game.getWindow();
    field.draw( window );
    snake.draw( window );
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
        if ( !snake.isMoved() ) {
//            if ( newDir == Direction::LEFT )
//                snake.setNewDirection( Direction::LEFT );
//            if ( newDir == Direction::UP )
//                snake.setNewDirection( Direction::UP );
//            if ( newDir == Direction::RIGHT )
//                snake.setNewDirection( Direction::RIGHT );
//            if ( newDir == Direction::DOWN )
//                snake.setNewDirection( Direction::DOWN );


            snake.move();
            snake.setMoved( true );
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

sf::Vector2f StateMainGame::getWindowSize() {
    sf::RenderWindow& window = game.getWindow();
    float width = window.getSize().x;
    float height = window.getSize().y;

    return { width, height };
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
