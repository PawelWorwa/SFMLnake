#include "game.hpp"

Game::Game () {
    exitGame = false;

    createWindow();
    loadSounds();
    loadTextures();
}

Game::~Game () = default;

sf::RenderWindow &Game::getWindow () {
    return window;
};

TextureManager &Game::getTextureManager () {
    return textureManager;
};

void Game::setExitGame () {
    exitGame = true;
}

bool Game::isExitGame () {
    return exitGame;
}

void Game::loadSounds () {
    soundManager.addSound( Audio::SFML_INTRO );
    soundManager.addSound( Audio::EAT );
    soundManager.addSound( Audio::END );
}

void Game::loadTextures () {
    textureManager.addTexture( Texture::SFML_LOGO );
    textureManager.addTexture( Texture::MAIN_MENU_BACKGROUND );
    textureManager.addTexture( Texture::MAIN_MENU_BUTTONS );
    textureManager.addTexture( Texture::MAIN_GAME_TEXTURES );
    textureManager.addTexture( Texture::SCORE_TEXTURES );
    textureManager.addTexture( Texture::GAME_OVER );
    textureManager.addTexture( Texture::VICTORY );
}

void Game::createWindow () {
    window.create( sf::VideoMode( WIDTH, HEIGHT ), "SFMLnake v " PROJECT_VERSION);
    window.setFramerateLimit( FPS );
    window.setKeyRepeatEnabled( false );
}

SoundManager &Game::getSoundManager () {
    return soundManager;
}
