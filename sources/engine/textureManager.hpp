#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <map>
#include <string>

#include "color.hpp"
#include "soundManager.hpp"

class TextureManager {
    private:
        std::map< std::string, sf::Texture > textures;

    public:
        TextureManager();
        virtual ~TextureManager();

        void addTexture( const std::string& key );
        sf::Texture& getTexture( const std::string& key );
};

#endif // TEXTUREMANAGER_H
