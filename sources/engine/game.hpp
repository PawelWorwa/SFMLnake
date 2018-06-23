#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "textureManager.hpp"
#include "audio.hpp"
#include "texture.hpp"
#include "version.hpp"

class Game {
    private:
        static const int WIDTH = 1200;
        static const int HEIGHT = 800;
        static const int FPS = 30;

        bool exitGame;
        sf::RenderWindow window;
        TextureManager textureManager;
        SoundManager soundManager;

        void createWindow ();
        void loadSounds ();
        void loadTextures ();

    public:
        Game ();
        virtual ~Game ();

        void setExitGame ();
        TextureManager &getTextureManager ();
        SoundManager &getSoundManager ();
        sf::RenderWindow &getWindow ();
        bool isExitGame ();
};

#endif // GAME_H
