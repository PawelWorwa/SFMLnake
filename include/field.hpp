#ifndef FIELD_H
#define FIELD_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "gameSprites.hpp"

class Field {
    private:
        sf::Vector2f fieldSize;
        GameSprites& sprites;
        std::vector< sf::Sprite > field;

        void addSprite( int row, int cell, SpriteType type );

    public:
        explicit Field( sf::Vector2f fieldSize, GameSprites& sprites );
        virtual ~Field();

        void draw( sf::RenderWindow& window );
        void create( void );
};

#endif // FIELD_H
