#include <sstream>
#include "score.hpp"

Score::Score( sf::Texture& texture )
        : texture( texture )
{
    this->scale = 0.0f;
    this->score = 0;
}

Score::~Score() = default;

void Score::draw( sf::RenderWindow& window ) {
    drawScoreText( window );
    drawScoreNumbers( window );
}

void Score::increaseScore() {
    score++;
}

std::string Score::toString( int number ) {
    std::stringstream stream;
    stream << number;
    return stream.str();
}

sf::Sprite Score::getScoreSprite( int number ) {
    int rectLeft = SCORE_TEXT_WIDTH + DIGIT_WIDTH * number;
    sf::IntRect textureRectangle( rectLeft, 0, DIGIT_WIDTH, texture.getSize().y );

    sf::Sprite sprite;
    sprite.setTexture( texture );
    sprite.setTextureRect( textureRectangle );
    sprite.setScale( scale, scale );

    return sprite;
}

void Score::drawScoreText( sf::RenderWindow& window ) {
    int textureHeight = texture.getSize().y;

    sf::Sprite scoreText;
    scoreText.setTexture( texture );
    scoreText.setTextureRect( sf::IntRect( 0, 0, SCORE_TEXT_WIDTH, textureHeight ));
    scoreText.setScale( scale, scale );

    float xPos = 25; // space
    float yPos = window.getSize().y - textureHeight * scale;
    scoreText.setPosition( xPos, yPos );

    window.draw( scoreText );
}

void Score::drawScoreNumbers( sf::RenderWindow& window ) {
    int index = 0;
    std::vector< sf::Sprite > scoreSprites;
    for ( char& character : toString( score )) {
        int number = ( int ) character - 48; // in ascii code numbers start from 48
        sf::Sprite sprite = getScoreSprite( number );

        int space = 25;
        int spriteOffset = static_cast<int>(index * sprite.getGlobalBounds().width);
        float xPos = space + SCORE_TEXT_WIDTH + spriteOffset;
        float yPos = window.getSize().y - texture.getSize().y * scale;

        sprite.setPosition( xPos, yPos );
        window.draw( sprite );

        index++;
    }
}

void Score::fitToScreen( float maxHeight ) {
    float currentHeight = texture.getSize().y;
    scale = (currentHeight * maxHeight / 100.0f ) / 100.0f;
}