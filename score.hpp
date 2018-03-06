#ifndef SFMLNAKE_SCORE_HPP
#define SFMLNAKE_SCORE_HPP

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Score {
    private:
        static const int SCORE_TEXT_WIDTH = 300; // px
        static const int DIGIT_WIDTH      = 105; // px

        float        scale;
        unsigned int score;
        sf::Texture& texture;

        void drawScoreText( sf::RenderWindow& window );
        void drawScoreNumbers( sf::RenderWindow& window );
        sf::Sprite getScoreSprite( int number );
        std::string toString( int number );

    public:
        explicit Score( sf::Texture& texture );
        virtual ~Score();

        void draw( sf::RenderWindow& window );
        void increaseScore();
        void fitToScreen( float maxHeight );
};

#endif //SFMLNAKE_SCORE_HPP
