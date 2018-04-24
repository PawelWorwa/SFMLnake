#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Audio/Music.hpp>

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
        sf::Music gameTheme;

        void createWindow();
        void initMusic();
        void loadSounds();
        void loadTextures();
        void playMusic();
        void stopMusic();

    public:
        Game();
        virtual ~Game();

        void setExitGame();
        ResourceManager& getResManager();
        sf::RenderWindow& getWindow();
        bool isExitGame();
        void handleMusic();
};

#endif // GAME_H
