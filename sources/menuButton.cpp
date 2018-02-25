#include "menuButton.hpp"

MenuButton::MenuButton( sf::Texture& texture ) : texture( texture ) {
    state = ButtonState::NORMAL;
}

MenuButton::~MenuButton() = default;

void MenuButton::addSprite( sf::IntRect intRet, ButtonState state ) {
    sf::Sprite sprite;
    sprite.setTexture( texture );
    sprite.setTextureRect( intRet );
    sprites[state] = sprite;
}

void MenuButton::setPosition( sf::Vector2f position ) {
    this->position = position;
}

void MenuButton::draw( sf::RenderWindow& window ) {
    sf::Sprite currentSprite = sprites[state];
    currentSprite.setPosition( position );

    if (isHoovered( window )) {
        state = ButtonState::PRESSED;

    } else {
        state = ButtonState::NORMAL;
    }

    window.draw( currentSprite );
}

bool MenuButton::isHoovered( sf::RenderWindow& window ) {
    sf::Sprite currentSprite = sprites[state];
    currentSprite.setPosition( position );

    sf::FloatRect spriteRect = currentSprite.getGlobalBounds();
    sf::Vector2f mousePos = window.mapPixelToCoords( sf::Mouse::getPosition( window ));

    return spriteRect.contains( mousePos );
}

bool MenuButton::isClicked( sf::RenderWindow& window ) {
    bool mousePressed = sf::Mouse::isButtonPressed( sf::Mouse::Left );
    return (mousePressed && isHoovered( window ));
}
