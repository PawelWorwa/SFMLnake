#include <SFML/System/Vector2.hpp>
#include "gameSprites.hpp"
#include "field.hpp"

Field::Field( sf::Vector2u screenDimensions, GameSprites &sprites )
        : sprites(sprites)
{
    fieldTexture.create(screenDimensions.x, screenDimensions.y);
    fieldTexture.clear();
    fieldTexture.display();
}

Field::~Field() = default;

void Field::create( sf::Vector2i fieldSize ) {
    for (int i = 0; i < fieldSize.y; ++i) {
        for (int j = 0; j < fieldSize.x; ++j) {
            addSprite(i, j, SpriteType::FIELD);

            if (j == 0) {
                addSprite(i, j, SpriteType::BORDER_UP);
            }

            if (j == fieldSize.x - 1) {
                addSprite(i, j, SpriteType::BORDER_DOWN);
            }

            if (i == 0) {
                addSprite(i, j, SpriteType::BORDER_LEFT);
            }

            if (i == fieldSize.y - 1) {
                addSprite(i, j, SpriteType::BORDER_RIGHT);
            }
        }
    }
}

void Field::draw( sf::RenderWindow &window ) {
    const sf::Texture& texture = fieldTexture.getTexture();
    sf::Sprite sprite( texture );
    window.draw( sprite );
}

void Field::addSprite( int row, int cell, SpriteType type ) {
    sf::Sprite sprite = sprites.getSprite(type);
    float xPos = sprite.getTextureRect().width * row * sprite.getScale().x;
    float yPos = sprite.getTextureRect().height * cell * sprite.getScale().y;

    sprite.setPosition(sf::Vector2f(xPos, yPos));
    fieldTexture.draw( sprite );
}