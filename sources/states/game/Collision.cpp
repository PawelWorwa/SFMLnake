#include "Collision.hpp"

Collision::Collision() = default;

Collision::~Collision() = default;

bool Collision::withFruit( sf::FloatRect fruitBoundingBox, sf::FloatRect snakeHeadBoundingBox ) {
    return snakeHeadBoundingBox.intersects( fruitBoundingBox );
}

bool Collision::withBorders( sf::FloatRect snakeHeadBoundingBox, sf::Vector2u gameFieldDimensions ) {
    bool leftBorderCrossed = snakeHeadBoundingBox.left < 0;
    bool rightBorderCrossed = snakeHeadBoundingBox.left + snakeHeadBoundingBox.width > gameFieldDimensions.x;
    bool upBorderCrossed = snakeHeadBoundingBox.top < 0;
    bool downBorderCrossed = snakeHeadBoundingBox.top + snakeHeadBoundingBox.height > gameFieldDimensions.y;

    return ( leftBorderCrossed || rightBorderCrossed || upBorderCrossed || downBorderCrossed );
}

bool Collision::withSnake( Snake snake ) {
    if ( snake.isSuspendGrowth()) {
        return false;
    }

    for ( unsigned int i = 0; i < snake.getParts().size() - 1; ++i ) {
        sf::Sprite bodyPart = snake.getParts().at( i );
        sf::FloatRect partBoundingBox = bodyPart.getGlobalBounds();

        if ( snake.getHeadElementFloatRect().intersects( partBoundingBox )) {
            return true;
        }
    }

    return false;
}

bool Collision::withFruit( sf::FloatRect fruitBoundingBox, std::vector< sf::Sprite > snakeBodyParts ) {
    for ( const sf::Sprite &part : snakeBodyParts ) {
        if ( withFruit( fruitBoundingBox, part.getGlobalBounds())) {
            return true;
        }
    }

    return false;
}
