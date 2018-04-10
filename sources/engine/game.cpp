#include "game.hpp"

Game::Game() {
    this->exitGame = false;

    createWindow();
    loadSounds();
    loadTextures();
}

Game::~Game() = default;

sf::RenderWindow& Game::getWindow() {
    return window;
};

ResourceManager& Game::getResManager() {
    return manager;
};

void Game::setExitGame() {
    exitGame = true;
}

bool Game::isExitGame() {
    return exitGame;
}

void Game::loadSounds() {
    manager.addSound( Sound::SFML_INTRO );
}

void Game::loadTextures() {
    manager.addTexture( Texture::SFML_LOGO );
    manager.addTexture( Texture::MAIN_MENU_BACKGROUND );
    manager.addTexture( Texture::MAIN_MENU_BUTTONS );
    manager.addTexture( Texture::MAIN_GAME_TEXTURES );
    manager.addTexture( Texture::SCORE_TEXTURES );
}

void Game::createWindow() {
    window.create( sf::VideoMode( WIDTH, HEIGHT ), "SFMLnake" );
    window.setFramerateLimit( FPS );
    window.setKeyRepeatEnabled( false );
}