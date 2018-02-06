#include "field.hpp"

Field::Field( GameSprites& sprites, sf::Vector2f fieldSize )
    :   sprites( sprites ),
        fieldSize( fieldSize ) {
    createField( fieldSize );
}

Field::~Field() {
}

void Field::createField( sf::Vector2f fieldSize ) {
    for( int i = 0; i < FIELD_CELLS; ++i ) {
        for( int j = 0; j < FIELD_ROWS; ++j ) {
            addSprite( i, j, SpriteType::FIELD );

            if( j == 0) {
                addSprite( i, j, SpriteType::BORDER_UP );
            }

            if( j == FIELD_ROWS - 1) {
                addSprite( i, j, SpriteType::BORDER_DOWN );
            }

            if( i == 0) {
                addSprite( i, j, SpriteType::BORDER_LEFT );
            }

            if( i == FIELD_CELLS - 1) {
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
    sf::Vector2f spriteSize = sprites.getSpriteSize();
    float targetWidth  = fieldSize.x / FIELD_ROWS;
    float targetHeight = fieldSize.y / FIELD_CELLS;
    float xSize = targetWidth  * 100.0f / spriteSize.x;
    float ySize = targetHeight * 100.0f / spriteSize.y;

    float xPos = targetWidth  * row;
    float yPos = targetHeight * cell;

    sf::Sprite sprite = sprites.getSprite( type );
    sprite.setScale( xSize / 100.0f, ySize / 100.0f );
    sprite.setPosition( sf::Vector2f( xPos, yPos ) );
    field.push_back( sprite );
}
