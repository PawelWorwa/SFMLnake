#include "fruit.hpp"

Fruit::Fruit( GameSprites& sprites ) : sprites( sprites ) {
}

Fruit::~Fruit() = default;

void Fruit::draw( sf::RenderWindow& window ) {
    window.draw( fruit );
}

void Fruit::randomizePosition( sf::Vector2f position ) {
    float width  = fruit.getLocalBounds().width * fruit.getScale().x;
    float height = fruit.getLocalBounds().height * fruit.getScale().y;
    fruit.setPosition( position.x * width, position.y * height );
}

void Fruit::create() {
    fruit = sprites.getSprite( SpriteType::FRUIT );
}

sf::FloatRect Fruit::getFloatRect () {
    return fruit.getGlobalBounds();
}