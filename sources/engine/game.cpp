#include "game.hpp"

Game::Game () {
    exitGame = false;

    createWindow();
    loadSounds();
    loadTextures();
    initMusic();
}

Game::~Game () = default;

sf::RenderWindow &Game::getWindow () {
    return window;
};

ResourceManager &Game::getResManager () {
    return manager;
};

void Game::setExitGame () {
    exitGame = true;
}

bool Game::isExitGame () {
    return exitGame;
}

void Game::loadSounds () {
    manager.addSound( Sound::SFML_INTRO );
    manager.addSound( Sound::EAT );
    manager.addSound( Sound::END );
}

void Game::loadTextures () {
    manager.addTexture( Texture::SFML_LOGO );
    manager.addTexture( Texture::MAIN_MENU_BACKGROUND );
    manager.addTexture( Texture::MAIN_MENU_BUTTONS );
    manager.addTexture( Texture::MAIN_GAME_TEXTURES );
    manager.addTexture( Texture::SCORE_TEXTURES );
}

void Game::createWindow () {
    window.create( sf::VideoMode( WIDTH, HEIGHT ), "SFMLnake v0.9" );
    window.setFramerateLimit( FPS );
    window.setKeyRepeatEnabled( false );
}

void Game::stopMusic () {
    gameTheme.stop();
}

void Game::playMusic () {
    gameTheme.play();
}

void Game::initMusic () {
    gameTheme.openFromFile( Sound::GAME_THEME );
    gameTheme.setLoop( true );
}

void Game::handleMusic () {
    sf::SoundSource::Status status = gameTheme.getStatus();
    if (status == sf::SoundSource::Status::Stopped) {
        playMusic();

    } else {
        stopMusic();
    }
}