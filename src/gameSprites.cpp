#include "gameSprites.hpp"

GameSprites::GameSprites( sf::Texture& texture ) : texture( texture ) {
    createSprites();
}

GameSprites::~GameSprites() {
}

void GameSprites::createSprites( void ) {
    int width  = texture.getSize().x / TEXTURE_ROWS;
    int height = texture.getSize().y / TEXTURE_CELLS;

    addSprite( BORDER_DOWN,  sf::IntRect( 0, 0, width, height ) );
    addSprite( BORDER_UP,    sf::IntRect( width, 0, width, height ) );
    addSprite( BORDER_RIGHT, sf::IntRect( 2 * width, 0, width, height ) );
    addSprite( BORDER_LEFT,  sf::IntRect( 3 * width, 0, width, height ) );
    addSprite( FIELD,        sf::IntRect( 0, height, width, height ) );
    addSprite( FRUIT,        sf::IntRect( width, height, width, height ) );
    addSprite( SNAKE_BODY,   sf::IntRect( 2 * width, height, width, height ) );
    addSprite( SNAKE_FACE,   sf::IntRect( 3 * width, height, width, height ) );
}

void GameSprites::addSprite( SpriteType type, sf::IntRect intRect ) {
    sf::Sprite sprite;
    sprite.setTexture( texture );
    sprite.setTextureRect( intRect );
    sprites[type] = sprite;
}

sf::Sprite GameSprites::getSprite( SpriteType type ) {
    return sprites[type];
}

sf::Vector2f GameSprites::getSpriteDimensions( void ) {
    float textureWidth  = texture.getSize().x;
    float textureHeight = texture.getSize().y;

    return sf::Vector2f( textureWidth / TEXTURE_ROWS, textureHeight / TEXTURE_CELLS );
}

void GameSprites::resizeSprites( sf::Vector2f resolution, sf::Vector2f gameFieldSize ) {
    sf::Vector2f spriteDimensions = getSpriteDimensions();
    float targetWidth  = resolution.x / gameFieldSize.x;
    float targetHeight = resolution.y / gameFieldSize.y;
    float xScale = targetWidth  * 100.0f / spriteDimensions.x;
    float yScale = targetHeight * 100.0f / spriteDimensions.y;

    for( size_t i = 0; i < NR_OF_SPRITES; ++i ) {
        sf::Sprite sprite = sprites[i];
        sprite.setScale( xScale / 100.0f, yScale / 100.0f );
        sprites[i] = sprite;
    }
}
