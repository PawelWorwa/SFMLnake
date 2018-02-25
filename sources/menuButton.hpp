#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>

#include "buttonState.hpp"

#include <array>

class MenuButton {
    private:
        static const int NR_OF_STATES = 2;

        ButtonState state;

        std::array< sf::Sprite, NR_OF_STATES > sprites;
        sf::Texture& texture;
        sf::Vector2f position;

        bool isHoovered( sf::RenderWindow& window );

    public:
        explicit MenuButton( sf::Texture& texture );
        virtual ~MenuButton();

        void addSprite( sf::IntRect intRet, ButtonState state );
        void draw( sf::RenderWindow& window );
        bool isClicked( sf::RenderWindow& window );
        void setPosition( sf::Vector2f position );
};

#endif // MENUBUTTON_H
