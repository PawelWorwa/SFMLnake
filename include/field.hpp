#ifndef FIELD_H
#define FIELD_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "gameSprites.hpp"

class Field {
    private:
        static const int FIELD_ROWS  = 10;
        static const int FIELD_CELLS = 10;

        GameSprites& sprites;
        sf::Vector2f fieldSize;
        std::vector< sf::Sprite > field;

        void createField( sf::Vector2f fieldSize );
        void addSprite( int row, int cell, SpriteType type );

    public:
        explicit Field( GameSprites& sprites, sf::Vector2f fieldSize );
        virtual ~Field();

        void draw( sf::RenderWindow& window );
};

#endif // FIELD_H
