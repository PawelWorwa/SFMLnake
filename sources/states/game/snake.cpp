#include "gameSprites.hpp"
#include "snake.hpp"

Snake::Snake ( GameSprites &sprites )
        : sprites( sprites )
{
    moved = false;
    suspendGrowth = false;

    currentDirection = randomDirection();
    newDirection = currentDirection;
}

Snake::~Snake () = default;

void Snake::setNewDirection ( Direction direction ) {
    this->newDirection = direction;
}

bool Snake::isMoved () {
    return moved;
}

void Snake::setMoved ( bool moved ) {
    this->moved = moved;
}

void Snake::draw ( sf::RenderWindow &window ) {
    for ( const auto &bodyPart : parts )
    {
        window.draw( bodyPart );
    }

    unsigned int headIndex = parts.size() - 1;
    sf::Sprite head = parts.at( headIndex );
    orientateHead( head );
    window.draw( head );
}

void Snake::createHead ( sf::Vector2f position ) {
    sf::Sprite headSprite = sprites.getSprite( SpriteType::SNAKE_FACE );
    float width = headSprite.getLocalBounds().width * headSprite.getScale().x;
    float height = headSprite.getLocalBounds().height * headSprite.getScale().y;
    headSprite.setPosition( position.x * width, position.y * height );

    parts.push_back( headSprite );
}

Direction Snake::randomDirection () {
    return static_cast<Direction>(rand() % Direction::LAST);
}

void Snake::orientateHeadUp ( sf::Sprite &head ) {
    float width = head.getLocalBounds().width;
    head.setOrigin( width, 0.0f );
    head.setScale( head.getScale().y, head.getScale().x );
    head.rotate( 270 );
}

void Snake::orientateHeadRight ( sf::Sprite &head ) {
    head.setOrigin( 0.0f, 0.0f );
    head.setScale( head.getScale().x, head.getScale().y );
    head.rotate( 0 );
}

void Snake::orientateHeadDown ( sf::Sprite &head ) {
    float height = head.getLocalBounds().height;
    head.setOrigin( 0.0f, height );
    head.setScale( head.getScale().y, head.getScale().x );
    head.rotate( 90 );
}

void Snake::orientateHeadLeft ( sf::Sprite &head ) {
    float width = head.getLocalBounds().width;
    float height = head.getLocalBounds().height;
    head.setOrigin( width, height );
    head.setScale( head.getScale().x, head.getScale().y );
    head.rotate( 180 );
}

void Snake::orientateHead ( sf::Sprite &head ) {
    switch ( currentDirection )
    {
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

void Snake::move () {
    moveBodyParts();
    currentDirection = newDirection;
    sf::Vector2f position = getNewHeadPosition();

    unsigned int headIndex = parts.size() - 1;
    sf::Sprite head = parts.at( headIndex );
    head.setPosition( position.x, position.y );
    parts.at( headIndex ) = head;
}

void Snake::moveBodyParts () {
    if ( !suspendGrowth )
    {
        for ( unsigned int i = 0; i < parts.size() - 1; ++i )
        {
            sf::Vector2f nextPos = parts.at( i + 1 ).getPosition();
            parts.at( i ).setPosition( nextPos );
        }
    }
    suspendGrowth = false;
}

sf::Vector2f Snake::getNewHeadPosition () {
    unsigned int headIndex = parts.size() - 1;
    sf::Sprite head = parts.at( headIndex );
    float xMovement = head.getLocalBounds().width * head.getScale().x;
    float yMovement = head.getLocalBounds().height * head.getScale().y;

    sf::Vector2f position = head.getPosition();
    if ( currentDirection == Direction::RIGHT )
    {
        position.x += xMovement;

    } else if ( currentDirection == Direction::DOWN )
    {
        position.y += yMovement;

    } else if ( currentDirection == Direction::LEFT )
    {
        position.x -= xMovement;

    } else if ( currentDirection == Direction::UP )
    {
        position.y -= yMovement;
    }

    return position;
}

sf::FloatRect Snake::getHeadElementFloatRect () {
    unsigned int headIndex = parts.size() - 1;
    sf::Sprite headElement = parts.at( headIndex );
    return headElement.getGlobalBounds();
}

void Snake::grow () {
    unsigned int headIndex = parts.size() - 1;
    sf::Sprite lastPart = parts.at( headIndex );
    sf::Vector2f lastPosition = lastPart.getPosition();
    lastPart = sprites.getSprite( SpriteType::SNAKE_BODY );
    lastPart.setPosition( lastPosition );
    parts.at( headIndex ) = lastPart;

    sf::Sprite newPart = sprites.getSprite( SpriteType::SNAKE_FACE );
    newPart.setPosition( lastPosition.x, lastPosition.y );

    parts.push_back( newPart );
    suspendGrowth = true;
}

std::vector< sf::Sprite > Snake::getParts () {
    return parts;
}

bool Snake::isSuspendGrowth () const {
    return suspendGrowth;
}

void Snake::deleteLastPart () {
    if ( parts.size() > 1 )
    {
        parts.erase( parts.begin());
    }
}