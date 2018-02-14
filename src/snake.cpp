#include "snake.hpp"

Snake::Snake( GameSprites& sprites ) : sprites( sprites ) {
}

Snake::~Snake() {
}

void Snake::draw( sf::RenderWindow& window ) {
    for( unsigned int i = 0; i < parts.size(); ++i ) {
        window.draw( parts.at(i) );
    }
}

void Snake::create( void ) {
    sf::Sprite head = sprites.getSprite( SpriteType::SNAKE_FACE );
    parts.push_back( head );
}
