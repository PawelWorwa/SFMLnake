#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "resourceManager.hpp"
#include "sound.hpp"
#include "texture.hpp"

class Game {
    private:
        static const int WIDTH  = 800;
        static const int HEIGHT = 600;
        static const int FPS    = 30;

        bool exitGame;
        sf::RenderWindow window;
        ResourceManager manager;

        void createWindow();
        void loadSounds();
        void loadTextures();

    public:
        Game();
        virtual ~Game();

        void setExitGame();
        ResourceManager& getResManager();
        sf::RenderWindow& getWindow();
        bool isExitGame();
};

#endif // GAME_H
