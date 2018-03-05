#ifndef SFMLNAKE_FRUIT_HPP
#define SFMLNAKE_FRUIT_HPP

#include <SFML/Graphics/RenderWindow.hpp>

#include "gameSprites.hpp"

class Fruit {
    private:
        GameSprites& sprites;
        sf::Sprite fruit;

    public:
        explicit Fruit( GameSprites& sprites );
        virtual ~Fruit();

        void create();
        void draw( sf::RenderWindow& window );
        void randomizePosition( sf::Vector2f position );

        void eatFruit();

        bool checkCollision( sf::FloatRect floatRect );
};

#endif //SFMLNAKE_FRUIT_HPP
