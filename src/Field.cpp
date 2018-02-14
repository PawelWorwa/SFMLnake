#include "field.hpp"

Field::Field( sf::Vector2f fieldSize, GameSprites& sprites )
    :   fieldSize( fieldSize ),
        sprites( sprites )
{
}

Field::~Field() {
}

void Field::create( void ) {
    for( int i = 0; i < fieldSize.y; ++i ) {
        for( int j = 0; j < fieldSize.x; ++j ) {
            addSprite( i, j, SpriteType::FIELD );

            if( j == 0) {
                addSprite( i, j, SpriteType::BORDER_UP );
            }

            if( j == fieldSize.x - 1) {
                addSprite( i, j, SpriteType::BORDER_DOWN );
            }

            if( i == 0) {
                addSprite( i, j, SpriteType::BORDER_LEFT );
            }

            if( i == fieldSize.y - 1) {
                addSprite( i, j, SpriteType::BORDER_RIGHT );
            }
        }
    }
}

void Field::draw( sf::RenderWindow& window ) {
    for( unsigned int i = 0; i < field.size(); ++i ) {
        window.draw( field.at(i) );
    }
}

void Field::addSprite( int row, int cell, SpriteType type ) {
    sf::Sprite sprite = sprites.getSprite( type );
    float xPos = sprite.getTextureRect().width  * row  * sprite.getScale().x;
    float yPos = sprite.getTextureRect().height * cell * sprite.getScale().y;

    sprite.setPosition( sf::Vector2f( xPos, yPos ) );
    field.push_back( sprite );
}
