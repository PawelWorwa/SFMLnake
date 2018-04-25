#include "soundManager.hpp"

SoundManager::SoundManager() {
    initMusic();
}

SoundManager::~SoundManager() {
    sounds.clear();
    soundBuffers.clear();
}

void SoundManager::initMusic() {
    backgroundTheme.openFromFile( Audio::GAME_THEME );
    backgroundTheme.setLoop( true );
}

void SoundManager::stopMusic() {
    backgroundTheme.stop();
}

void SoundManager::playMusic() {
    sf::SoundSource::Status status = backgroundTheme.getStatus();
    if ( status != sf::SoundSource::Status::Playing ) {
        backgroundTheme.play();
    }
}



void SoundManager::changeMusicState() {
    sf::SoundSource::Status status = backgroundTheme.getStatus();
    if ( status == sf::SoundSource::Status::Stopped ) {
        playMusic();

    } else {
        stopMusic();
    }
}

void SoundManager::addSound( const std::string &key ) {
    sf::SoundBuffer buffer;
    buffer.loadFromFile( key );
    soundBuffers[key] = buffer;

    sf::Sound sound( soundBuffers.at( key ));
    sounds[key] = sound;
}

void SoundManager::playSound( const std::string &key ) {
    sf::Sound &sound = sounds.at( key );
    sound.play();
}

bool SoundManager::isPlaying( const std::string &key ) {
    const sf::Sound &sound = sounds.at( key );
    return ( sound.getStatus() == sf::SoundSource::Status::Playing );
}

void SoundManager::stopSound( const std::string &key ) {
    sf::Sound &sound = sounds.at( key );
    if ( sound.getStatus() == sf::SoundSource::Status::Playing ) {
        sound.stop();
    }
}