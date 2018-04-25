#include "textureManager.hpp"

TextureManager::TextureManager() = default;

TextureManager::~TextureManager() {
    textures.clear();
}

void TextureManager::addTexture( const std::string& key ) {
    sf::Image image;
    image.loadFromFile( key );
    image.createMaskFromColor( Color::MASK );

    sf::Texture texture;
    texture.loadFromImage( image );
    textures[key] = texture;
}

sf::Texture& TextureManager::getTexture( const std::string& key ) {
    return textures.at( key );
}
