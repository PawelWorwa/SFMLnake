#ifndef SFMLNAKE_COLLISION_HPP
#define SFMLNAKE_COLLISION_HPP

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "snake.hpp"

class Collision {
    public:
        Collision ();
        virtual ~Collision ();

        bool withFruit ( sf::FloatRect fruitBoundingBox, sf::FloatRect snakeHeadBoundingBox );
        bool withBorders ( sf::FloatRect snakeHeadBoundingBox, sf::Vector2u gameFieldDimensions );
        bool withSnake ( Snake snake );
};


#endif //SFMLNAKE_COLLISION_HPP
