#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "gameSprites.hpp"

class Snake {
    private:
        GameSprites& sprites;

        std::vector< sf::Sprite > parts;

    public:
        explicit Snake( GameSprites& sprites );
        virtual ~Snake();

        void create( void );
        void draw( sf::RenderWindow& window );
};

#endif // SNAKE_H
