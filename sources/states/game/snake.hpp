#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "gameSprites.hpp"
#include "direction.hpp"

class Snake {
    private:
        bool moved;
        bool suspendGrowth;

        GameSprites &sprites;
        std::vector< sf::Sprite > parts;
        Direction currentDirection;
        Direction newDirection;

        Direction randomDirection ();
        void orientateHead ( sf::Sprite &head );
        void orientateHeadUp ( sf::Sprite &head );
        void orientateHeadRight ( sf::Sprite &head );
        void orientateHeadDown ( sf::Sprite &head );
        void orientateHeadLeft ( sf::Sprite &head );
        void moveBodyParts();
        sf::Vector2f getNewHeadPosition ();

    public:
        explicit Snake ( GameSprites &sprites );
        virtual ~Snake ();

        void createHead ( sf::Vector2f position );
        void draw ( sf::RenderWindow &window );
        void setNewDirection ( Direction direction );
        void move ();

        bool isMoved ();
        bool isSuspendGrowth () const;
        void setMoved ( bool moved );

        sf::FloatRect getHeadElementFloatRect ();
        std::vector< sf::Sprite > getParts();
        void grow ();
        void deleteLastPart();
};

#endif // SNAKE_H
