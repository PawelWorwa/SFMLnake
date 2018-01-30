#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "../include/Managment/font.hpp"
#include "../include/Managment/resourceManager.hpp"
#include "../include/Managment/sound.hpp"
#include "../include/Managment/texture.hpp"

class Game {
    private:
        static const int WIDTH   = 800;
        static const int HEIGHT  = 600;
        static const int FPS     = 30;

        bool exitGame;
        sf::RenderWindow window;
        ResourceManager manager;

        void loadSounds( void );
        void loadTextures( void );
        void loadFonts( void );

    public:
        Game();
        virtual ~Game();

        void setExitGame( void );
        ResourceManager& getResManager( void );
        sf::RenderWindow& getWindow( void );
        bool isExitGame( void );
};

#endif // GAME_H
