#include "gameSprites.hpp"
#include "snake.hpp"
#include <iostream>
Snake::Snake( GameSprites& sprites )
        : sprites( sprites ),
          moved( false )
{
    currentDirection = randomDirection();
    newDirection = currentDirection;

    headElementIndex = 0;
}

Snake::~Snake() = default;

void Snake::draw( sf::RenderWindow& window ) {
    // body
    for ( unsigned int i = 0; i < parts.size(); ++i ) {
        window.draw( parts.at( i ));
    }

    // head
    sf::Sprite head = parts.at( headElementIndex );
    orientateHead( head );
    window.draw( head );
}

void Snake::create( sf::Vector2f position ) {
    sf::Sprite headSprite = sprites.getSprite( SpriteType::SNAKE_FACE );
    float width  = headSprite.getLocalBounds().width  * headSprite.getScale().x;
    float height = headSprite.getLocalBounds().height * headSprite.getScale().y;
    headSprite.setPosition( position.x * width, position.y * height );

    parts.push_back( headSprite );
}

void Snake::setNewDirection( Direction direction ) {
    this->newDirection = direction;
}

Direction Snake::randomDirection() {
    return static_cast<Direction>(rand() % Direction::LAST);
}

void Snake::orientateHeadUp( sf::Sprite& head ) {
    float width = head.getLocalBounds().width;
    head.setOrigin( width, 0.0f );
    head.setScale( head.getScale().y, head.getScale().x );
    head.rotate( 270 );
}

void Snake::orientateHeadRight( sf::Sprite& head ) {
    head.setOrigin( 0.0f, 0.0f );
    head.setScale( head.getScale().x, head.getScale().y );
    head.rotate( 0 );
}

void Snake::orientateHeadDown( sf::Sprite& head ) {
    float height = head.getLocalBounds().height;
    head.setOrigin( 0.0f, height );
    head.setScale( head.getScale().y, head.getScale().x );
    head.rotate( 90 );
}

void Snake::orientateHeadLeft( sf::Sprite& head ) {
    float width = head.getLocalBounds().width;
    float height = head.getLocalBounds().height;
    head.setOrigin( width, height );
    head.setScale( head.getScale().x, head.getScale().y );
    head.rotate( 180 );
}

void Snake::orientateHead( sf::Sprite& head ) {
    switch ( currentDirection ) {
        case Direction::RIGHT :
            orientateHeadRight( head );
            break;

        case Direction::UP:
            orientateHeadUp( head );
            break;

        case Direction::DOWN:
            orientateHeadDown( head );
            break;

        case Direction::LEFT:
            orientateHeadLeft( head );
            break;

        case Direction::LAST:
            break;
    }
}

void Snake::move() {
    sf::Sprite head = parts.at( headElementIndex );
    float xMovement = head.getLocalBounds().width * head.getScale().x;
    float yMovement = head.getLocalBounds().height * head.getScale().y;


    if(!stopGrowth) {
        for ( unsigned int i = 0; i < parts.size() - 1; ++i ) {
            sf::Vector2f nextPos = parts.at( i + 1 ).getPosition();
            parts.at( i ).setPosition( nextPos );
        }
    }
    stopGrowth = false;


    sf::Vector2f position = head.getPosition();
    currentDirection = newDirection;
    if ( currentDirection == Direction::RIGHT ) {
        position.x += xMovement;

    } else if ( currentDirection == Direction::DOWN ) {
        position.y += yMovement;

    } else if ( currentDirection == Direction::LEFT ) {
        position.x -= xMovement;

    } else if ( currentDirection == Direction::UP ) {
        position.y -= yMovement;
    }

    head.setPosition( position.x, position.y );
    parts.at( headElementIndex ) = head;
}

bool Snake::isMoved() {
    return moved;
}

void Snake::setMoved( bool moved ) {
    this->moved = moved;
}

sf::FloatRect Snake::getHeadElementFloatRect() {
    sf::Sprite headElement =  parts.at( headElementIndex );
    return headElement.getGlobalBounds();
}

void Snake::grow() {
    sf::Sprite lastPart = parts.at( headElementIndex );
    sf::Vector2f lastPosition = lastPart.getPosition();
    lastPart = sprites.getSprite( SpriteType::SNAKE_BODY );
    lastPart.setPosition( lastPosition );
    parts.at( headElementIndex ) = lastPart;

    sf::Sprite newPart = sprites.getSprite( SpriteType::SNAKE_FACE );
    newPart.setPosition( lastPosition.x, lastPosition.y );

    parts.push_back( newPart );
    headElementIndex++;
    stopGrowth = true;
}