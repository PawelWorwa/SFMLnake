#ifndef SFMLNAKE_SOUNDMANAGER_HPP
#define SFMLNAKE_SOUNDMANAGER_HPP

#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

#include <string>
#include <map>

#include "audio.hpp"

class SoundManager {
    private :
        std::map< std::string, sf::SoundBuffer > soundBuffers;
        std::map< std::string, sf::Sound > sounds;
        sf::Music backgroundTheme;

        void initMusic ();
        void stopMusic ();


    public:
        SoundManager ();
        virtual ~SoundManager ();

        void addSound ( const std::string &key );
        bool isPlaying ( const std::string &key );
        void stopSound( const std::string &key );
        void playSound ( const std::string &key );

        void playMusic ();
        void changeMusicState();
};


#endif //SFMLNAKE_SOUNDMANAGER_HPP
