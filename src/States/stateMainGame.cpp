#include "stateMainGame.hpp"

StateMainGame::StateMainGame( Game &game )
    :   game( game ),
        sprites( getGameTextures() ),
        field( sf::Vector2f( FIELD_ROWS, FIELD_CELLS ), sprites ),
        snake( sprites )
{
    sprites.resizeSprites( getWindowSize(), sf::Vector2f( FIELD_ROWS, FIELD_CELLS ) );
    field.create();
    snake.create();
}

StateMainGame::~StateMainGame() {
}

std::unique_ptr< GameState > StateMainGame::getNextState( void ) {
    return nullptr;
}

void StateMainGame::draw( void ) {
   sf::RenderWindow &window = game.getWindow();
   field.draw( window );
   snake.draw( window );
}

void StateMainGame::handleInput( void ) {
    sf::RenderWindow &window = game.getWindow();

    sf::Event event;
    while ( window.pollEvent( event ) ) {
        switch ( event.type ) {
        case sf::Event::Closed :
            stopState();
            window.close();
            break;

        default :
            break;
        }
    }
}

void StateMainGame::update( void ) {
}

void StateMainGame::stopState( void ) {
}

sf::Texture& StateMainGame::getGameTextures( void ) {
    return game.getResManager().getTexture( Texture::MAIN_GAME_TEXTURES );
}

sf::Vector2f StateMainGame::getWindowSize( void ) {
    sf::RenderWindow &window = game.getWindow();
    float width = window.getSize().x;
    float height = window.getSize().y;
    return sf::Vector2f( width, height );
}
