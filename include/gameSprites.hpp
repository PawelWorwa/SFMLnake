#ifndef GAMESPRITES_H
#define GAMESPRITES_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "spriteType.hpp"

#include <array>

class GameSprites {
    private:
        static const int TEXTURE_ROWS  = 4;
        static const int TEXTURE_CELLS = 2;
        static const int NR_OF_SPRITES = TEXTURE_ROWS * TEXTURE_CELLS;

        std::array< sf::Sprite, NR_OF_SPRITES > sprites;
        sf::Texture& texture;

        void addSprite( SpriteType type, sf::IntRect intRect );
        void createSprites( void );

    public:
        explicit GameSprites( sf::Texture& texture );
        virtual ~GameSprites();

        sf::Sprite getSprite( SpriteType type );
        sf::Vector2f getSpriteSize( void );
};

#endif // GAMESPRITES_H
