#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "gameSprites.hpp"
#include "direction.hpp"

class Snake {
    private:
        const unsigned int HEAD_ELEMENT = parts.size();

        GameSprites& sprites;
        std::vector< sf::Sprite > parts;
        bool moved;
        Direction currentDirection;
        Direction newDirection;


        Direction randomDirection();
        void orientateHead( sf::Sprite& head );
        void orientateHeadUp( sf::Sprite& head );
        void orientateHeadRight( sf::Sprite& head );
        void orientateHeadDown( sf::Sprite& head );
        void orientateHeadLeft( sf::Sprite& head );

    public:
        explicit Snake( GameSprites& sprites );
        virtual ~Snake();

        void create();
        void draw( sf::RenderWindow& window );
        void setNewDirection( Direction direction );
        void move();

        bool isMoved();
        void setMoved( bool moved );
};

#endif // SNAKE_H
