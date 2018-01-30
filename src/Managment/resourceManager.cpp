#include "../../include/Managment/resourceManager.hpp"

ResourceManager::ResourceManager() {
}

ResourceManager::~ResourceManager() {
    textures.clear();
    buffers.clear();
}

void ResourceManager::addTexture( const std::string &key ) {
    sf::Image image;
    image.loadFromFile( key );
    image.createMaskFromColor( Color::MASK );

    sf::Texture texture;
    texture.loadFromImage( image );
    textures[key] = texture;
}

void ResourceManager::addSound( const std::string &key ) {
    sf::SoundBuffer buffer;
    buffer.loadFromFile( key );
    buffers[key] = buffer;
}

void ResourceManager::addFont( const std::string &key ) {
    sf::Font font;
    font.loadFromFile( key );
    fonts[key] = font;
}

sf::Texture& ResourceManager::getTexture( const std::string &key ) {
    return textures.at( key );
}

sf::SoundBuffer& ResourceManager::getSoundBuffer( const std::string &key ) {
    return buffers.at( key );
}

sf::Font& ResourceManager::getFont( const std::string &key ) {
    return fonts.at( key );
}
