#ifndef FIELD_H
#define FIELD_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include "gameSprites.hpp"

class Field {
    private:
        GameSprites& sprites;
        sf::RenderTexture fieldTexture;

        void addSprite( int row, int cell, SpriteType type );

    public:
        explicit Field( sf::Vector2u screenDimensions, GameSprites& sprites );
        virtual ~Field();

        void create( sf::Vector2i fieldSize );
        void draw( sf::RenderWindow& window );
};
#endif // FIELD_H
