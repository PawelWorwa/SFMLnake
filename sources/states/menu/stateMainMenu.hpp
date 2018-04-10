#ifndef STATEMAINMENU_H
#define STATEMAINMENU_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>

#include "buttonState.hpp"
#include "../gameState.hpp"
#include "../../stateMainGame.hpp"
#include "../../engine/game.hpp"
#include "menuButton.hpp"

class StateMainMenu : public GameState {
    private:
        static const int BUTTON_TEXTURE_ROWS  = 2;
        static const int BUTTON_TEXTURE_CELLS = 3;
        static const int BUTTON_LOCATION_OFFSET = 10; //%

        sf::Sprite background;
        Game& game;

        MenuButton playButton;
        MenuButton trophiesButton;
        MenuButton quitButton;

        void createButtons();
        sf::Texture& getButtonsTexture();
        void prepareBackground();

    public:
        explicit StateMainMenu( Game& game );
        ~StateMainMenu() override;

        std::unique_ptr< GameState > nextState;
        std::unique_ptr< GameState > getNextState() override;
        void draw() override;
        void handleInput() override;
        void update() override;
        void stopState() override;
};

#endif // STATEMAINMENU_H
