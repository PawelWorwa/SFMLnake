#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "color.hpp"

#include <map>
#include <string>

class ResourceManager {
    private:
        std::map< std::string, sf::Texture > textures;
        std::map< std::string, sf::SoundBuffer > buffers;

    public:
        ResourceManager();
        virtual ~ResourceManager();

        void addSound( const std::string& key );
        void addTexture( const std::string& key );
        sf::SoundBuffer& getSoundBuffer( const std::string& key );
        sf::Texture& getTexture( const std::string& key );
};

#endif // RESOURCEMANAGER_H
